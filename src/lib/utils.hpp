#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>

using namespace std;
const double MARGIN = 0.001;
class Linear_Equations {
   private:
      bool is_print;
   const int HIGH = 11;
   const int LOW = -9;

   
   public:

      int ndim;
   float ** matrixA;
   std::vector < float > x_old;
   std::vector < float > x_curr;
   std::vector < float > x;
   std::vector < float > resultB;

   //Construct Funcntion

   Linear_Equations(int _ndim, bool show) {

      ndim = _ndim;
      is_print = show;
      matrixA = new float * [ndim + 1];
      for (int i = 0; i < ndim; i++)
         matrixA[i] = new float[ndim];
         matrixA[ndim] = NULL;
      generate_diagonal_dominant_matrix(); // calling generate_diagonal_dominant_matrix method to make matrixA diagonally Dominant
      for (size_t i = 0; i < ndim; i++) {
         resultB.push_back(0);
         x_old.push_back(0);
         x_curr.push_back(0);
         x.push_back(HIGH + rand() % LOW); // Creating randomically a solution for the system
      }
      for (auto i = 0; i < ndim; i++)
         for (auto j = 0; j < ndim; j++)
            resultB[i] += matrixA[i][j] * x[j]; // Computing the  vector of results the system
   }

   void generate_diagonal_dominant_matrix() {
      for (size_t i = 0; i < ndim; i++) {
         for (size_t j = 0; j < ndim; j++) {
            if (i == j)
               matrixA[i][j] = (LOW * ndim) + static_cast < float > (rand()) / (static_cast < float > (RAND_MAX / (HIGH - LOW))); // Making the diagonally strongly dominant
            else
               matrixA[i][j] = LOW + static_cast < float > (rand()) / (static_cast < float > (RAND_MAX / (HIGH - LOW))); // Continuing to fill the matrix randomically
         }
      }
      return;
   }
   double cosine_similarity() //Computes the cosine similarity (greater is better) between the current vector of x and the true vector of solutions
   {
      double dot = 0.0, denom_a = 0.0, denom_b = 0.0;
      for (unsigned int i = 0u; i < ndim; ++i) {
         dot += x[i] * x_curr[i];
         denom_a += x[i] * x[i];
         denom_b += x_curr[i] * x_curr[i];
      }
      return dot / (sqrt(denom_a) * sqrt(denom_b));
   }

   void print_vector(std::vector < float > _vector, int ndim, std::string msg) {
      std::cout << msg << std::endl;
      for (int j = 0; j < ndim; j++)
         std::cout << _vector[j] << " ";
      std::cout << "\n \n";
   }

   void print_matrix(float ** matrixA, int ndim, std::string msg) // this function will print martix 
   {
      std::cout << msg << std::endl;
      for (int i = 0; i < ndim; i++) {
         for (int j = 0; j < ndim; j++)
         std::cout << matrixA[i][j] << "  ";
         std::cout << std::endl;
      }
   }

   void print_results() // it prints the System and Computes Cosine similarity and also Display Results
   {
      if (is_print)
      {
      std::cout << std::endl;
     // print_matrix(matrixA, ndim, "MATRIX A of COEFFICIENTS ");
      print_vector(x, ndim, "\nACTUAL VALUES OF VECTOR X ");
     //print_vector(resultB, ndim, "RESULTANT VECTOR B");
      print_vector(x_curr, ndim, "COMPUTED VALUES OF VECTOR X BY JACOBI ");
      std::cout << (abs(cosine_similarity()) >= MARGIN ? "Everything fine" : "Something went wrong") << std::endl;
      }
   }

   ~Linear_Equations()

   //free the memory occupied by the matrixA

   {
      // free
      for (int i = 0; i < ndim; i++)
         delete[] matrixA[i]; // delete array within matrixA
      delete[] matrixA; // delete actual matrix
   }

};