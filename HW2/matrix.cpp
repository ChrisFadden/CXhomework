//matrix.cpp

#include "matrix.h"
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <omp.h>
#include <xmmintrin.h>
#include <assert.h>

// timer using processor counter
#define WALLCLOCK(time) do {                                 \
    unsigned long long val;                                  \
    volatile unsigned int a, d;                              \
    __asm__ __volatile__("rdtsc" : "=a" (a), "=d" (d) : );   \
    val = ((unsigned long long) a)|(((unsigned long long)d)<<32); \
    (time) = val / 2670000000.;                              \
  } while(0)





Matrix::Matrix(int argc, char** argv)
{

  m = atoi(argv[1]);
  q = atoi(argv[2]);
  n = atoi(argv[3]);
  
  A.resize(m*q);
  B.resize(q*n);
  C.resize(m*n);

  FillMatrices(argc, argv);
  
  double time1, time2;
  
  /*
  t = clock();
  Atranspose();
  t = clock() - t;

  std::cout << "Transposing took me " << ((float)t) / CLOCKS_PER_SEC << " seconds" << std::endl; 
  
  t = clock();*/
  WALLCLOCK(time1);
  std_multiply();
  WALLCLOCK(time2);/*
  t = clock() - t;

  std::cout << "Multiplying took me " << ((float)t) / CLOCKS_PER_SEC << " seconds" << std::endl; 
  */

 // t = clock();
//  block_multiply();
  //t = clock() - t;
  
 // std::cout << "Using blocking, it took me " << ((float)t) / CLOCKS_PER_SEC << " seconds" << std::endl;

  std::cout << "Time elapsed = " << time2 - time1 << std::endl;

  printResult(argv);

}

void Matrix::FillMatrices(int argc, char** argv)
{
  
  if(argc > 4)
  {
    FillFromFile(argc, argv);
  }else
  {
    FillRandom();    
  }

  return;
}

void Matrix::Atranspose()
{
  std::vector<double> tmp(A); //copy A into temporary array
  
  #pragma omp parallel for 
  for(int r = 0; r < m; r++)
    for(int c = 0; c < q; c++)
      A[r + c*q] = tmp[c + r*m]; //transpose A
}

void Matrix::std_multiply()
{
  #pragma omp parallel for 
  for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
    {
      C[i + j*m] = 0;

      for(int k = 0; k < q; k++)
        C[i + j*m] += A[i + k*m] * B[k + j*q];
    }//end j loop

  return;

}//end normal multiply function



void Matrix::FillRandom()
{
  //random seed 
  srand (time(NULL));    
  #pragma omp parallel for 
  for(int i = 0; i < A.size(); i++)
    A[i] = rand();
  #pragma omp parallel for
  for(int j = 0; j < A.size(); j++)
    B[j] = rand();
  
  return;
}

void Matrix::FillFromFile(int argc, char** argv)
{
   
  std::ifstream fileA(argv[4]);
  std::ifstream fileB(argv[5]);
   
  std::string line; 
  int i = 0;

  if( fileA.is_open())
  {
    while( std::getline(fileA,line) ) 
    {
       A[i] = std::stod(line);
       i++;
    }//end while loop
    fileA.close();
  }//end read fileA
  
  i = 0;
  if( fileB.is_open())
  {
    while( std::getline(fileB,line) )
    {
        B[i] = std::stod(line);
        i++;
    }//end while loop
    fileB.close();
  }//end read fileB

  return;
}

void Matrix::printResult(char** argv)
{ 
  std::ofstream fileC;
  fileC.open(argv[6]);

  for(int i = 0; i < C.size(); i++)
    fileC << C[i] << "\n"; 
  
  fileC.close();

  return;
}

void Matrix::block_multiply()
{

  int stride = 50;
  int limit = stride * (m / stride); //ensure that m/stride will at least be rounded to an even integer and scaled
  
  #pragma omp parallel for
  for(int kkk = 0; kkk < limit; kkk += stride)
    for(int jjj = 0; jjj < limit; jjj += stride)
    {
      for(int i = 0; i < m; i++)
        for(int j = jjj; j < jjj + stride; j++)
        {
        C[i + j*m] = 0;
        for(int k = kkk; k < kkk + stride; k++)
          C[i + j*m] += A[i + k*m] * B[k + j*q];
        }//end j loop
    } // end stride loops

  return;
}





