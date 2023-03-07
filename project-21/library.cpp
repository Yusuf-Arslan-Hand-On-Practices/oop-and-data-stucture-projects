#include <iostream> 
#include <fstream>  // ifstream, ofstream
#include <cstdlib>  // srand(), rand()
#include <ctime>    // time()
#include <cstdio>   // printf() -- To print matrices formatted

#include "library.h"

using namespace std;

//  ---------------------------------- MATRIX GENERATOR ----------------------------------
// Generate 20 9*9 matrices with random float numbers between 0 and 200
void matrixGenerator()
{
    // Create 20 9*9 matrix with random float numbers between
    // 0 and 200 and write them into the binary file

    // random number generator
    srand(time(NULL));

    // Create a file to write the matrices
    ofstream matrixFile(FILE_NAME, ios::out | ios::binary);

    // Create a random number generator
    srand(time(NULL));

    // Create 20 matrices
    for (int i = 0; i < MATRIX_NUMBER; i++)
    {
        // Create a 9*9 matrix
        double matrix[MATRIX_SIZE][MATRIX_SIZE];

        // Fill the matrix with random numbers
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            for (int k = 0; k < MATRIX_SIZE; k++)
            {
                matrix[j][k] = fRand(0, 200);
            }
        }

        // Write the matrix into the file
        matrixFile.write((char*)matrix, sizeof(matrix));
    }

    // Close the file
    matrixFile.close();
}

// Creates random float numbers between fMin and fMax
// and rounds the result to 3 decimal places
double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    double result =  fMin + f * (fMax - fMin);

    // Round the result to 3 decimal places
    result = (int)(result * 1000 + .5);
    result = (double)result / 1000;
    
    return result;
}

//  ---------------------------------- MATRIX GENERATOR END ----------------------------------


//  ---------------------------------- MATRIX OPERATIONS ----------------------------------
/**
 * It reads the matrices from a binary file.
 * 
 * @param matrixArray The array of matrices that will be read from the file.
 * @param matrixFile The file that contains the matrices in binary format.
 */
void readMatrices(double matrixArray[][MATRIX_SIZE][MATRIX_SIZE])
{
    // Create a file to read the matrices
    ifstream matrixFile(FILE_NAME, ios::in | ios::binary);

    // Read the matrices from the file
    for (int i = 0; i < MATRIX_NUMBER; i++)
    {
        // Read the matrix from the file
        matrixFile.read((char*)matrixArray[i], sizeof(matrixArray[i]));
    }

    // Close the file
    matrixFile.close();
}

/**
 * It takes 2 matrices from the matrixArray and compresses them into a single matrix in the
 * compressedMatrixArray. The compressed matrix is the sum of the 2 matrices that are taken from
 * the matrixArray.
 * 
 * @param matrixArray The array of matrices that will be compressed.
 * @param compressedMatrixArray the array that will hold the compressed matrices
 */
void compressMatrices(double matrixArray[][MATRIX_SIZE][MATRIX_SIZE], double compressedMatrixArray[][MATRIX_SIZE][MATRIX_SIZE])
{
    for (int i = 0; i < MATRIX_NUMBER; i = i + 2)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            for (int k = 0; k < MATRIX_SIZE; k++)
            {
                compressedMatrixArray[i / 2][j][k] = matrixArray[i][j][k] + matrixArray[i + 1][j][k];
            }
        }
    }
}

/**
 * It prints the matrices to the console in tabular form with | as column separator and - as row
 * separator
 * 
 * @param matrixArray The array of matrices that will be printed
 * @param matrixNumber The number of matrices to be printed
 */
void printMatrices(double matrixArray[][MATRIX_SIZE][MATRIX_SIZE], int matrixNumber)
{
    for (int i = 0; i < matrixNumber; i++)
    {
        cout << "\nFrame " << i + 1 << endl;
        cout << "\n|---------|---------|---------|---------|---------|---------|---------|---------|---------|" << endl;
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            cout << "|";
            for (int k = 0; k < MATRIX_SIZE; k++)
            {
                printf(" %7.3f |", matrixArray[i][j][k]);
            }
            cout << endl;
            cout << "|---------|---------|---------|---------|---------|---------|---------|---------|---------|" << endl;
        }
        cout << endl;
    }
}

/**
 * It compresed i and i + 1 matrices into 1 matrix and stores the result in the compressed matrix array
 * 
 * @param matrixArray The array of matrices that we're compressing
 * @param compressedMatrixArray The array that will hold the compressed matrices
 * @param i The index of the matrix in the matrix array
 */
void compressSingleMatrix(double matrixArray[][MATRIX_SIZE][MATRIX_SIZE], double compressedMatrixArray[][MATRIX_SIZE][MATRIX_SIZE], int i)
{
    // Compress 2 matrices into 1 and store the result in the compressed matrix array
    for (int j = 0; j < MATRIX_SIZE; j++)
    {
        for (int k = 0; k < MATRIX_SIZE; k++)
        {
            compressedMatrixArray[i / 2][j][k] = matrixArray[i][j][k] + matrixArray[i + 1][j][k];
        }
    }
}

/**
 * This function prints a single matrix from a 3D array of matrices
 * 
 * @param matrixArray The array of matrices
 * @param i the frame number
 */
void printSingleMatrix(double matrixArray[][MATRIX_SIZE][MATRIX_SIZE], int i)
{
    cout << "\nFrame " << i + 1 << endl;
    cout << "\n|---------|---------|---------|---------|---------|---------|---------|---------|---------|" << endl;
    for (int j = 0; j < MATRIX_SIZE; j++)
    {
        cout << "|";
        for (int k = 0; k < MATRIX_SIZE; k++)
        {
            printf(" %7.3f |", matrixArray[i][j][k]);
        }
        cout << endl;
        cout << "|---------|---------|---------|---------|---------|---------|---------|---------|---------|" << endl;
    }
    cout << endl;
}

/**
 * This function takes a 3D array of doubles and fills it with zeros
 * 
 * @param matrixArray the array of matrices that we're filling with zeros.
 * @param matrixNumber The number of matrices in the array.
 */
void fillMatricesWithZeros(double matrixArray[][MATRIX_SIZE][MATRIX_SIZE], int matrixNumber)
{
    for (int i = 0; i < matrixNumber; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            for (int k = 0; k < MATRIX_SIZE; k++)
            {
                matrixArray[i][j][k] = 0;
            }
        }
    }
}

//  ---------------------------------- MATRIX OPERATIONS END ----------------------------------
