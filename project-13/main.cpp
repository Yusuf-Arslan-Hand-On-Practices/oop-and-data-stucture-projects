#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "MPQ.cpp"

// This function reads the input file and creates the buildings
// Then it inserts the buildings to the heap, then finds the skyline and prints it to the output file
int main() {
    ifstream input;
    cout << "Enter the input file name: ";
    string filename;
    cin >> filename;
    input.open(filename);
    if (!input) {
        cout << "Unable to open file\n";
        exit(1); // terminate with error
    }

    // Reading the input file and creating the buildings. Then it inserts the buildings to the heap.
    MPQ *heap = new MPQ();
    int n;
    input >> n;
    for (int i = 0; i < n; i++) {
        int x, y, h;
        input >> x >> y >> h;
        Building *building = new Building(new Value(x, y), h);
        heap->insert(building);
    }

    // Find the max label
    Building *maxBuilding = dynamic_cast<Building *>(heap->getMax());
    // Create an array to keep the each point's height
    int *skyline = new int[maxBuilding->label + 1];

    // Initialize the skyline array
    for (int i = 0; i < maxBuilding->label + 1; i++) {
        skyline[i] = 0;
    }

    // Find the skyline
    while (!heap->isEmpty()) {
        Building *building = dynamic_cast<Building *>(heap->pop());
        for (int i = building->value->x; i < building->label; i++) {
            if (skyline[i] < building->value->y) {
                skyline[i] = building->value->y;
            }
        }
    }

    // Print the skyline
    int from = 0;
    int height = skyline[0];

    cout << from << " " << height << endl;
    for (int i = 1; i < maxBuilding->label + 1; i++) {
        if (skyline[i] != height) {
            cout << i << " " << skyline[i] << endl;
            from = i;
            height = skyline[i];
        }
    }

    input.close();
    return 0;
}