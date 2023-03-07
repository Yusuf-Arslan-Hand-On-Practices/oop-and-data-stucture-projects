#include <iostream>
#include <fstream>

using namespace std;

#include "MPQ.h"

#define input "input.txt"

int main()
{
    MPQ mpq;
    ifstream fin(input);
    int n;
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, x1, y;
        fin >> x >> y >> x1;
        Comparable c(x, y, x1);
        mpq.insert(c, i);
    }
    mpq.printSkyline();
    return 0;
}