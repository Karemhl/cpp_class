//------------------------------------------------------------------//
// Program to test Armadillo Library
// 29-April-2019
//------------------------------------------------------------------//
#include <iostream>
#include <armadillo>
using namespace arma;
using namespace std;

int main(int argc, char** argv){

    std::cout << "Armadillo----------------------------------" << std::endl;

// Creation of matrix A of size rows=3,cols=3
    mat A;
    A  << 1.2 << 1.7 << 1.0 << endr
       <<-1.2 << 2.5 <<-2.1 << endr
       << 2.3 << 3.5 <<-7.2 << endr;
    A.print("Matrix A:");

// Check transposed matrix of A
    
    mat B = trans(A);
    B.print("Transposed B:");

// Check Addition
    mat D = A+B;
    D.print("Adition A+B:");

// Check Substraction
    mat E = A-B;
    E.print("Substraction A-B:");

// Check Multiplication
    mat F = A*B;
    F.print("Multiplication A*B:");

// Check identity matrix
    mat I;
    I.eye(3,3);
    I.print("Identity I:");
    std::cout << "-------------------------------------------" << std::endl;

    return 0;
}

