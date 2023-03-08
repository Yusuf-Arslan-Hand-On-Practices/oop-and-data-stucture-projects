#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Project Description:
// Find the placements of a shape in a matrix

// point struct
struct Point
{
    int x;
    int y;
};

// Is matrix valid?
// Any row of vector should have the same number of elements as the first row
bool isMatrixFileValid(vector<vector<char>> matrix)
{
    for (int i = 1; i < matrix.size(); i++)
    {
        if (matrix[i].size() != matrix[0].size())
        {
            return false;
        }
    }
    return true;
}

// Print the matrix
void printMatrix(vector<vector<char>> matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

// to lower case string
string toLowerCase(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}

int longestRowLength(vector<vector<char>> matrix)
{
    int max = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        if (matrix[i].size() > max)
        {
            max = matrix[i].size();
        }
    }
    return max;
}

int main()
{
    // File operations
    string fileName;
    vector<vector<char>> matrix;

    cout << "Please enter the file name:" << endl;
    cin >> fileName;
    ifstream file(fileName);
    // Ask for a valid file name until a valid file is opened
    while (!file)
    {
        cout << "Could not open the file. Please enter a valid file name:" << endl;
        cin >> fileName;
        file.open(fileName);
    }

    // Create the matrix by reading the lines
    string line;
    while (getline(file, line))
    {
        vector<char> row;
        char c;
        for (int i = 0; i < line.length(); i++)
        {
            c = line[i];
            // c should be either - or #, otherwise the file is not valid
            if (c != '-' && c != '#')
            {
                cout << "Erroneous file content. Program terminates." << endl;
                return 0;
            }
            row.push_back(c);
        }
        matrix.push_back(row);
    }

    // Close the file
    file.close();

    // if any rows lenght is not equal to the first row length, then the matrix is not valid
    if (!isMatrixFileValid(matrix))
    {
        cout << "Erroneous file content. Program terminates." << endl;
        return 0;
    }

    // Print the matrix
    cout << "The matrix file contains:" << endl;
    printMatrix(matrix);

    // Read the string query
    string query;
    int placementCount = 0;

    // size of matrix
    int matrixRows = matrix.size();
    int matrixColumns = matrix[0].size();

    // this will hold the coordinates of the stars queried
    vector<Point> stars;
    while (true)
    {
        cout << "Enter the string query for a shape, or \"Quit\" to terminate the program:" << endl;
        cin >> query;
        if (toLowerCase(query) == "quit")
        {
            break;
        }
        // query format: i.e. 1b1b2s//1s2b1s
        // b -> blank, s -> star (asterisk), / ->  new line
        // no check for the validity of the query
        int currentRow = 0;
        int currentColumn = 0;
        for (int i = 0; i < query.length(); i++)
        {
            // find the new line
            if (query[i] == '/')
            {
                currentRow++;
                currentColumn = 0;
            }
            else
            {
                // number of blanks or stars
                int count = query[i] - '0';
                i++;
                char c = query[i];
                if (c == 'b')
                {
                    // skip the blanks
                    currentColumn += count;
                }
                else
                {
                    // add the stars to the vector of star coordinates
                    for (int j = 0; j < count; j++)
                    {
                        Point p;
                        p.x = currentRow;
                        p.y = currentColumn;
                        stars.push_back(p);
                        currentColumn++;
                    }
                }
            }
        }

        // traverse the matrix and find all possible placements
        for (int i = 0; i < matrixRows; i++)
        {
            for (int j = 0; j < matrixColumns; j++)
            {
                // check if the placement is valid
                bool isPlacementValid = true;
                for (int k = 0; k < stars.size(); k++)
                {
                    // coordinates of the star
                    int x = stars[k].x + i;
                    int y = stars[k].y + j;
                    if (x >= matrixRows || y >= matrixColumns || matrix[x][y] == '#')
                    {
                        // if the star is out of the matrix or there is a # in the matrix, then the placement is not valid
                        isPlacementValid = false;
                        break;
                    }
                }
                // if the placement is valid, print it
                if (isPlacementValid)
                {
                    placementCount++;
                    cout << "Placement number" << placementCount << ":" << endl;
                    for (int k = 0; k < stars.size(); k++)
                    {
                        int x = stars[k].x + i;
                        int y = stars[k].y + j;
                        cout << "(" << x << "," << y << ") ";
                    }
                    cout << endl;
                }
            }
        }

        // if no placements found, print message
        if (placementCount == 0)
        {
            cout << "No placements found." << endl;
        }

        placementCount = 0;
        stars.clear();
    }

    return 0;
}
