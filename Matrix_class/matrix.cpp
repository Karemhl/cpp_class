// Matrix class definition of constructors and methods
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "matrix.h"

//------------------------------------------------------------------//
// Defining the Constructors
//------------------------------------------------------------------//
// Default constructor
Matrix::Matrix(){
    rows_ = 0;
    cols_ = 0;
    std::vector<std::vector<double> > matrix(rows_,std::vector<double>(cols_));
    matrix_ = matrix; 
}

// Constructor to inizialize a matrix of int rows and cols, elements & set to 0.
Matrix::Matrix(int rows,int cols){
   std::vector<std::vector<double> > matrix(rows,std::vector<double>(cols,0.));
   matrix_ = matrix;
   rows_ = rows;
   cols_ = cols;
}

// Constructor from a vector of vectors
Matrix::Matrix(std::vector<std::vector<double> > &matrix){
    matrix_ = matrix;
    rows_ = matrix.size();
    cols_ = matrix[0].size();
}

//------------------------------------------------------------------//
//  Method to read the file given 
//------------------------------------------------------------------//
void Matrix::ReadFile(int &argc, char *argv[], std::string &fileName){
    if(argc == 2){
         fileName = argv[1];
    }
    else {
        std::cout << "Please, give an input file: " << std::endl;
        std::cin  >> fileName;
    }
// With the given string argument we asign an ifstream object: infile 
    std::ifstream infile(fileName, std::ios::in);
    std::vector< std::vector<double> > matrix;
    int matrix_rows;
    infile >> matrix_rows;

// Reading every line and keeping the values in vectors
    std::string line;
    std::getline(infile, line);

    while (std::getline(infile, line)){
    double number;
    number = 0.0;
    std::vector<double> vector;
    std::istringstream actline(line);
    for (int i=0; i < matrix_rows ; i++){
         actline >> number;
         vector.push_back(number);
    }
    matrix.push_back(vector);
    } 

// Close the input file   
    infile.close();

    matrix_ = matrix;
    rows_ = matrix.size();
    cols_ = matrix[0].size();
}

//------------------------------------------------------------------//
// Method to print elements of the matrix object
//------------------------------------------------------------------//
void Matrix::Elements(){
    for(size_t i=0; i < matrix_.size(); ++i){
         for(size_t j=0; j < matrix_[i].size(); ++j){
              std::cout << std::scientific << std::setw(12) 
                        << std::setprecision(3)
                        << matrix_[i][j]; 
         }
    std::cout << std::endl;
    }
}

//------------------------------------------------------------------//
// Method to create an identity matrix given rows and cols
//------------------------------------------------------------------//
void Matrix::Identity(){ 
    for(size_t i=0; i < rows_; ++i){
         for(size_t j=0; j < cols_; ++j){
              if (i == j){
                 matrix_[i][j] = 1.;
              }
         }
    }
}

//------------------------------------------------------------------//
// Method to transpose elements of the matrix object
//------------------------------------------------------------------//
Matrix Matrix::Transpose(){ 

    std::vector<std::vector<double> > transposeMatrix;
//  Declaring and defining the vector with transpose elements
    transposeMatrix.resize(rows_,std::vector<double>(cols_));

    for(size_t i=0; i < transposeMatrix.size(); ++i){
         for(size_t j=0; j < transposeMatrix.size(); ++j){
              transposeMatrix[i][j]=matrix_[j][i];
         }
    }
    Matrix B(transposeMatrix);
    return B;
}

//------------------------------------------------------------------//
// Method to add matrices
//------------------------------------------------------------------//
Matrix Matrix::Add(const Matrix &b){

    std::vector<std::vector<double> > addMatrix;

    if(rows_ == b.rows_ && cols_ == b.cols_){

    //Declaring and defining the vector with add elements
    addMatrix.resize(rows_,std::vector<double>(cols_));
    
    for(size_t i=0; i < addMatrix.size(); ++i){
         for(size_t j=0; j < addMatrix.size(); ++j){
              addMatrix[i][j] = matrix_[i][j] + b.matrix_[i][j];
         }
    }
    Matrix B(addMatrix);
    return B;
    }
    else 
    std::cout << "Error: Cannot add matrices" << std::endl;
    Matrix B(addMatrix);
    return B;
}

//------------------------------------------------------------------//
// Method to substract matrices
//------------------------------------------------------------------//
Matrix Matrix::Subs(const Matrix &b){

    std::vector<std::vector<double> > subsMatrix;

    if(rows_ == b.rows_ && cols_ == b.cols_){

    //Declaring and defining the vector with add elements
    subsMatrix.resize(rows_,std::vector<double>(cols_));

    for(size_t i=0; i < subsMatrix.size(); ++i){
         for(size_t j=0; j < subsMatrix.size(); ++j){
              subsMatrix[i][j] = matrix_[i][j] - b.matrix_[i][j];
         }
    }
    Matrix B(subsMatrix);
    return B;
    }
    else
    std::cout << "Error: Cannot substract matrices" << std::endl;
    Matrix B(subsMatrix);
    return B;
}

//------------------------------------------------------------------//
// Method to multiply matrices
//------------------------------------------------------------------//
Matrix Matrix::Mult(const Matrix &b){                           
    std::vector<std::vector<double> > c(rows_,std::vector<double>(b.cols_));
    // checks if multiplication can be done
    if( rows_ == b.cols_){        
         for(size_t i=0; i < rows_; ++i){
            for(size_t j=0; j < b.cols_; ++j){
                for(size_t k=0; k < rows_; ++k){
                    c[i][j] += matrix_[i][k]*b.matrix_[k][j];
                }
            }
         }
         Matrix C(c);
         return C;
    } 
    else{
        std::cout << "Error: Cannot multiply matrices" << std::endl;
         Matrix C(c);
         return C;
    }
}
