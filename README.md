# Jacobi 
This is a parallel implementation of the Jacobi algorithm.

## Jacobi method 
 The **Jacobi method** or **Jacobi iterative method** is an algorithm for determining the solutions of a [diagonally dominant]
(https://en.wikipedia.org/wiki/Diagonally_dominant_matrix "Diagonally dominant matrix") [system of linear equations]
(https://en.wikipedia.org/wiki/System_of_linear_equations "System of linear equations").
Each diagonal element is solved for, and an approximate value is plugged in.

## Implementation
In the source code is possible to find different implementation using different parallel framework. The framework supported are:  
  1. Low level thread implementation  
  2. FastFlow  
## Structure
```
📦ProjectSPM2022
📂experiments
  ┣ 📜execute.sh
  ┣ 📜gustaffson.sh
 
📂Report
   📂Documentation
     ┗📂Diagrams
       ┗ ...
     ┣📜Report SPM 
   📂Graphs
    ┗ ...
   📂Results
     ┣📜 Test Results with average # Excel file in which are saved the plots and all 

 📂Src
     📂fastflow
      ┗ ...
     📂cmake-build-debug
      ┗ ...
     📂lib
       ┣📜utils.hpp
       ┣📜utimer.hpp
     📂Build
       ┣📜ff_Implementaion
       ┣📜Sequential_Implementation
       ┣📜Threads_Implementation
    ┣📜ff_Implementaion.cpp
    ┣📜Sequential_Implementation.cpp
    ┣📜Threads_Implementationcpp
    ┣📜Makefile

📜README.md                      

```


# Compiling and running

To compile the program, simply go into src directory where you will find all src files 

open ```bash terminal and type 
make clean hit enter  and then 
make all hit enter
```

Three executable will be created in the build folder, respectively for the sequential, parallel thread and parallel fastflow version.

To run the builds, go to src -- > build folder there you will file all exxcutables

open ```bash terminal from here 
./build/executable n_dim Max_iterations nWorkers check[0/1]
``` 

where

- **n_dim**: Shape of the square matrix and of the vectors.
- **Max_iterations**: Number of cycle to iterate the Jacobi method.
- **nWorkers**: stands for the maximum parallelism degree to be used. Do not specify this if you are running the sequential version.
- **check**: Boolean for testing puposes: [0] => false, the system will not be shown; [1] => true, the system will be printed.

