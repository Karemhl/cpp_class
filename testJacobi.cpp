// testJacobi.cpp
// test LinAlgLib library
#include <iostream>
#include <cmath>
#include "LinAlgLib.h"

int main(int argc, char *argv[]) {
    // get file names
    // std::string inpFile, outFile;
    // getFileName(argc, argv, inpFile, outFile);
    // read matrix
    // std::vector<std::vector<double> > matriz {};
    // matriz = readMatrix(inpFile);
    // std::cout << "Matrix read" << std::endl;
    // printMatrix(matriz);
    // Jacobi rotation

    // random matrix
    //int matSize = std::stoi(argv[2]);
    //double inf = std::stod(argv[3]);
    //double sup = std::stod(argv[4]);
    size_t matSize = 6;
    double inf = -10;
    double sup = 10;
    std::cout << "matSize " << matSize << std::endl;
    const std::vector<std::vector<double>> matriz = randomSymMatrix(matSize,inf,sup); 
    std::cout << "Initial matrix" << std::endl;
    printMatrix(matriz);
    int const MAXITER = 1000;
    double const epsilon {1e-12};
    std::vector<std::vector<double> > eigenValue = matriz;
    std::vector<std::vector<double>> eigenVector = Identity(eigenValue.size());     
    for (int iter = 0; iter < MAXITER; ++iter) {
    // safe guard
         if (iter == MAXITER - 1) {
              std::cout << "MAXITER exceeded" << std::endl;
              return(EXIT_FAILURE);
         }
    // look for largest non diagonal element
    // first, zero out diagonal elements
    std::vector<std::vector<double> > eigenZero = eigenValue;
    for (size_t i = 0; i < matriz.size(); ++i)
         eigenZero[i][i] = 0.;
    //printMatrix(eigenZero);     
    double nonDiag {};
    int iMax, jMax;
    for (size_t i = 0; i < eigenZero[i].size()-1; ++i) {
         for (size_t j = i+1; j < eigenZero[i].size(); ++j) {
              if (std::abs(eigenZero[i][j]) > nonDiag) {         
                   nonDiag = std::abs(eigenZero[i][j]);
                   iMax = i;
                   jMax = j;
              }
         }     
    }
    // begin diagonalizing
    double theta;
    if (std::abs(eigenValue[iMax][jMax]) > epsilon) {
         if (std::abs(eigenValue[iMax][iMax]-eigenValue[jMax][jMax]) < epsilon) 
              theta = 0.7853981633974483;
         else {
              theta = atan((2.*eigenValue[iMax][jMax])/
                      (eigenValue[iMax][iMax]-eigenValue[jMax][jMax]))/2.;
         }
         // create U
         std::vector<std::vector<double>> U = Identity(eigenValue.size());     
         U[iMax][iMax] = cos(theta);
         U[jMax][jMax] = U[iMax][iMax];
         U[iMax][jMax] = -sin(theta);
         U[jMax][iMax] = -U[iMax][jMax];
         // diagonalizing
         eigenValue = MatMul(Transpose(U),MatMul(eigenValue,U));
         eigenVector = MatMul(eigenVector,U);
    } // if (std::abs(eigenValue[iMax][jMax]) > epsilon) 
    else {
         std::cout << "In " << iter << " steps" << std::endl;
         // Sort eigenvalues and eigenvectors
         for (size_t i = 0; i < eigenValue.size()-1; ++i) {
              auto iter = i;
              double valor = eigenValue[i][i];
              for (size_t j = i+1; j < eigenValue.size(); ++j) {
                   if (eigenValue[j][j] > valor) {
                        iter = j;
                        valor = eigenValue[j][j];
                   }
              }
              if (iter != i) {
                   eigenValue[iter][iter] = eigenValue[i][i];
                   eigenValue[i][i] = valor;
                   for (size_t j = 0; j < eigenValue.size(); ++j) {
                        valor = eigenVector[j][i];
                        eigenVector[j][i] = eigenVector[j][iter];
                        eigenVector[j][iter] = valor;
                   }
              }
         }

         std::cout << "eigenValue" << std::endl;
         printMatrix(eigenValue);
         std::cout << "eigenVector" << std::endl;
         printMatrix(eigenVector);
         std::cout << "Vec^T A Vec = Val" << std::endl;
         printMatrix(MatMul(Transpose(eigenVector),MatMul(matriz,eigenVector)));
         return(EXIT_SUCCESS);
    }
    } // for (int iter = 0; iter < MAXITER; ++iter) 
}
