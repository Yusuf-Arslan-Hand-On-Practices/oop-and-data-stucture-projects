#include <iostream>
#include "mpq.h"

using namespace std;

int main()
{
    MPQ mpq("input.txt");
    // Get furthest x value

    int furthest = mpq.getFurthest();
    // Create skyline silhouette
    int skylineSilhouette[furthest + 1];
    
    // Initialize the skyline silhouette
    for (int i = 0; i < furthest + 1; i++)
    {
        skylineSilhouette[i] = 0;
    }

    // While the MPQ is not empty, set the each points heighest
    // value the the skyline silhouette
    while (!mpq.isEmpty())
    {
        Comparable c = mpq.pop();
        for (int i = c.getX(); i < c.getX_(); i++)
        {
            if (c.getY() > skylineSilhouette[i])
            {
                skylineSilhouette[i] = c.getY();
            }
        }
    }

    // Print the skyline silhouette
    cout << 0 << " " << skylineSilhouette[0] << endl;
    
    // Then print the skyline silhouette where the points are different
    for (int i = 1; i < furthest + 1; i++)
    {
        if (skylineSilhouette[i] != skylineSilhouette[i - 1])
        {
            cout << i << " " << skylineSilhouette[i] << endl;
        }
    }
    return 0;
}