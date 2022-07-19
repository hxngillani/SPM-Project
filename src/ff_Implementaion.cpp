#include <iostream>
#include "fastflow/ff/ff.hpp"
#include "fastflow/ff/parallel_for.hpp"
#include "lib/utimer.hpp"
#include "lib/utils.hpp"
using namespace ff;
int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        std::cout << "Usage is: " << argv[0] << " Dimension of Matrix , Number of Max_iterations ,Number Of Workers , Check Results[0/1]" << std::endl;
        return (0);
    }
    int n_dim = atoi(argv[1]); // Shape of the square matrix and of the vectors
    int Max_iterations = atoi(argv[2]); // Number of Max_iterations 
    int nWorkers = atoi(argv[3]); // Max number of workers
    bool check = (atoi(argv[4]) == 0 ? false : true); // Boolean for debugging purposes

    srand(786);

    // Creation of the Linear System instance
    Linear_Equations le(n_dim, check);

    {
        /*
        Creation of the Timer instance, at the end of this scope the destructor will be called and 
        the time will be printed
        */
        timer_raii tim("Jacobi FastFlow Execution With " + std::to_string(n_dim) + " Size, " + std::to_string(Max_iterations)
         + " iteration, " + std::to_string(nWorkers) + " Workers");


        /* 
        Calling the ParallelFor class with spin wait set to false  and spin barrier set
        to true avoid to use the blocking barrier
        */
        ParallelFor pf(nWorkers, false, true);
        for (int i = 0; i < Max_iterations; i++)
        {
            pf.parallel_for(0, n_dim, 1, n_dim / nWorkers, [&](int id)
            {
            le.x_curr[id] = le.resultB[id];
            for (size_t col = 0; col < n_dim; col++)
                {
                    if (id != col)
                    le.x_curr[id] -= le.matrixA[id][col] * le.x_old[col];
                     }
            le.x_curr[id] = le.x_curr[id] / le.matrixA[id][id]; 
            }
            );
            le.x_old = le.x_curr;
        }

    }

    // Checking the results of the system
    le.print_results();
    
    return 0;
}