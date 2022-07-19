#include <iostream>
#include <vector>
#include <thread>
#include <barrier>
#include <functional>
#include "lib/utimer.hpp"
#include "lib/utils.hpp"

using namespace std;


int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        std::cout << "Usage is: " << argv[0] << " Dimension of Matrix , Number of iterations ,Number Of Workers , Check Results[0/1]" << std::endl;
        return (0);
    }
    int n_dim = atoi(argv[1]); // Shape of the square matrix and of the vectors
    int iterations = atoi(argv[2]); // Number of iterations 
    int nWorkers = atoi(argv[3]); // Max number of workers 
    bool check = (atoi(argv[4]) == 0 ? false : true); // Boolean for debugging purposes

    srand(786);

    // Creation of the Linear System instance
    Linear_Equations le(n_dim, check);
    
    // Using the library functional to create the updating function to be given to the std::barrier

    //Initialization of the barrier with lambda function and nWorkers
    barrier sync_point(nWorkers, 
    [&](){le.x_old = le.x_curr;}
    );

    /*
    Here i am Using Library Functiuonal for implementing the core function of the algorithm with the barrier at 
    the bottom, this function will to every thread. 
    */
    function<void(int)> Compute_Unknowns = [&](int id)
    {
        for (int t = 0; t < iterations; t++)
        {
            for (int row = id; row < n_dim; row+=nWorkers)  //cyclic Distribution of Work among workers
            {
                le.x_curr[row] = le.resultB[row];
                for (size_t col = 0; col < n_dim; col++)
                {
                    if (row != col)
                        le.x_curr[row] = le.x_curr[row]-le.matrixA[row][col] * le.x_old[col];
                }
                le.x_curr[row] = le.x_curr[row] / le.matrixA[row][row];
            }
            sync_point.arrive_and_wait();
        }
        return;
    };

    {
        /*
        Creation of the Timer instance, at the end of this scope the destructor will be called and 
        the time will be printed
        */
        timer_raii tim("Jacobi Threads Execution With " + to_string(n_dim) + " Size, " + to_string(iterations) + " iteration, " + to_string(nWorkers) + " Workers");
        vector<thread> tids(nWorkers);

        //Starting...
        for (int i = 0; i < nWorkers; ++i)
        {
            tids[i] = thread(Compute_Unknowns, i);
        }
        // ...and joining the threads
        for (auto &t : tids)
        { // await thread termination
            t.join();
    
    }
    //Time instance distructor will be called at that point
    }

    // Checking the results of the system
    le.print_results();
}