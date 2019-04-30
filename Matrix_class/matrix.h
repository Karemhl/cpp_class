// Matrix class definition
#include <iostream>
#include <vector>

class Matrix {
public:
    // Constructors
    Matrix();
    Matrix(int, int);
    Matrix(std::vector<std::vector<double> > &);
    // Method to read a matrix from file
    void ReadFile(int &argc, char *argv[], std::string &fileName);
    // Methods to work with matrices
    void Elements();                       // Print elements
    void Identity();                       // Identity                
    Matrix Transpose();                    // Transpose
    Matrix Add(const Matrix &);            // Addition
    Matrix Subs(const Matrix &);           // Substraction
    Matrix Mult(const Matrix &);           // Multiplication

private:
    size_t rows_;                                                       
    size_t cols_;
    std::vector< std::vector<double> > matrix_;
};
