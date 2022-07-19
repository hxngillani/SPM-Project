#include <iostream>
#include <functional>
#include "lib/utils.hpp"
#include "lib/utimer.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cout << "Usage is: " << argv[0] << " Dimension of Matrix , Number of iterations , Check Results[0/1](bool)" << std::endl;
        return (0);
    }
    int ndim = atoi(argv[1]); // Shape of the square matrix and of the vectors
    int Max_iterations = atoi(argv[2]); // Number of Max iiterations to be computed
    bool check = (atoi(argv[3]) == 0 ? false : true); // Boolean flag for debugging/checking purposes

    srand(786);

    // Creation of the Linear System instance
    Linear_Equations les(ndim, check);


    function<void()> Compute_Unknowns = [&]()
    {
        for (size_t row = 0; row < ndim; row++)
        {
            les.x_curr[row] = les.resultB[row];
            for (size_t col = 0; col < ndim; col++)
            {
                if (row != col)
                    les.x_curr[row] = les.x_curr[row]-les.matrixA[row][col] * les.x_old[col];
            }
            les.x_curr[row] = les.x_curr[row] / les.matrixA[row][row];
        }

        les.x_old = les.x_curr;
    };

    {
        /*
        Creation of the Timer instance, at the end of this scope time will be printed
        */
        timer_raii tim("Jacobi sequential Execution " + to_string(ndim) + " Size, " + to_string(Max_iterations) + " iteration and 1 Worker");


        for (size_t iter = 0; iter < Max_iterations; iter++)
        {
            Compute_Unknowns(); //The algorithm itself
        }
    }
    
    // Checking the results of the system
    les.print_results();
}
