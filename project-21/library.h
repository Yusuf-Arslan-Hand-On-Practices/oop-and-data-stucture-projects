#include <iostream>

using namespace std;

#define MATRIX_SIZE 9               // Size of the matrices NxN
#define MATRIX_NUMBER 20            // Number of matrices to be generated, it have to be 'even' to be compressed
#define FILE_NAME "matrices.bin"    // Name of the file to store the matrices

double fRand(double fMin, double fMax);
void matrixGenerator();
void readMatrices(double matrixArray[][MATRIX_SIZE][MATRIX_SIZE]);
void compressMatrices(double matrixArray[][MATRIX_SIZE][MATRIX_SIZE], double compressedMatrixArray[][MATRIX_SIZE][MATRIX_SIZE]);
void printMatrices(double matrixArray[][MATRIX_SIZE][MATRIX_SIZE], int matrixNumber);
void compressSingleMatrix(double matrixArray[][MATRIX_SIZE][MATRIX_SIZE], double compressedMatrixArray[][MATRIX_SIZE][MATRIX_SIZE], int i);
void printSingleMatrix(double matrixArray[][MATRIX_SIZE][MATRIX_SIZE], int i);
void fillMatricesWithZeros(double matrixArray[][MATRIX_SIZE][MATRIX_SIZE], int matrixNumber);
