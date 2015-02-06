#include <iostream>
#include "matrix.h"

int main(int argc, char **argv)
{
  
  if(argc < 4)
  {
    std::cout << "Must have dimensions of matrices as inputs to program \n";   
    return -1; 
  }
  
  Matrix Sim(argc, argv);

  return 0;
}
