//-----------------------------------------------------------------------//
// Program to test Matrix Class:
// 20-April-2019
//-----------------------------------------------------------------------//
#include "matrix.h"

int main (int argc, char *argv[]) {

//-Working with the class------------------------------------------------//
// Creation of objects
    Matrix A,B,C,D,E; 
  
//  Declaration of a string to use the method to read file
    std::string fileName;   
//  Obtain A elements from file
    A.ReadFile(argc, argv, fileName);
    std::cout << "Matrix Class-------------------------------" << std::endl;
    std::cout << "Matrix A: " << std::endl;
    A.Elements(); //Print A elements

//  B = the transposed matrix of A
    B = A.Transpose();
    std::cout << "Transposed B:" << std::endl;
    B.Elements();

//  C = A + B
    C = A.Add(B);
    std::cout << "Adition A+B:" << std::endl;
    C.Elements();

//  D = A - B
    D = A.Subs(B);
    std::cout << "Substraction A-B:" << std::endl;
    D.Elements();

//  E = A * B
    E = A.Mult(B);
    std::cout << "Multiplication A*B:" << std::endl;
    E.Elements();

//  Identity Matrix
    Matrix I(3,3);  // Initialization of an object with
                    // (int rows, int cols) elements set to 0.
    I.Identity();   // Method that asign 1. to diagonal elements
    std::cout << "Identity I:" << std::endl;
    I.Elements();
    std::cout << "-------------------------------------------" << std::endl;
    return 0;
}

