//matrix.h

#ifndef _MATRIX_H
#define _MATRIX_H

#include <stdlib.h>
#include <vector>
#include <iostream>
#include <omp.h>

class Matrix
{
  
  private:
    Matrix(); //should not be constructed without arguments

  public:
    
    /*************
     * Functions
     ************/
    
    Matrix(int, char**); //Constructor with command line arguments
    
    void FillMatrices(int, char**);
    void FillFromFile(int, char**);
    void FillRandom();
    void std_multiply();
    void Atranspose();
    void block_multiply();
    void printResult(char**);
    
    /**************
    * Variables
    **************/
    int m;
    int q;
    int n;

    std::vector<double> A;
    std::vector<double> B;
    std::vector<double> C;
}; //end class

#endif
