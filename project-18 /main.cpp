#include <iostream>
#include <string>
#include <fstream>
#include <vector>       // to keep track of tokens
#include <sstream>      // to split line into tokens

using namespace std;

#include "AVLTree.h"
#include "LLRBTree.h"
#include "TPBST.h"

/*
    Instructions:
    - insert <category> <key> <data>
    - remove <category> <key>
    - printAllItems
    - printAllItemsInCategory <category>
    - printItem <category> <key>
    - find <category> <key>
    - updateData <category> <key> <newData>
*/

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        cout << "Usage: " << argv[0] << " <input file>" << " <output1 file>" << " <output2 file>" << endl;
        return 1;
    }
    TPBST<AVLTree> tpbst_avl;
    TPBST<LLRBTree> tpbst_llrb;
    
    // Read input file
    ifstream file;
    file.open(argv[1]);
    if (!file.is_open())
    {
        cout << "Error opening file" << endl;
        return 1;
    }

    // output file
    ofstream output1;
    output1.open(argv[2]);
    if (!output1.is_open())
    {
        cout << "Error opening file" << endl;
        return 1;
    }

    // output file
    ofstream output2;
    output2.open(argv[3]);
    if (!output2.is_open())
    {
        cout << "Error opening file" << endl;
        return 1;
    }

    string command;
    string category;
    string key;
    string data;

    string line;
    // Read input file line by line
    while (getline(file, line))
    {
        // Split line into tokens by tab character
        vector<string> tokens;
        stringstream ss(line);
        string token;

        while (getline(ss, token, '\t'))
        {
            tokens.push_back(token);
        }
        command = tokens[0];
        if (command == "insert")
        {
            category = tokens[1];
            key = tokens[2];
            data = tokens[3];
            tpbst_avl.insert(category, key, data);
            tpbst_llrb.insert(category, key, data);
        }
        else if (command == "remove")
        {
            category = tokens[1];
            key = tokens[2];
            tpbst_avl.removeProduct(category, key);
            tpbst_llrb.removeProduct(category, key);
        }
        else if (command == "printAllItems")
        {
            output1 << "command:" << command << endl;
            tpbst_avl.print(output1);
            output2 << "command:" << command << endl;
            tpbst_llrb.print(output2);
        }
        else if (command == "printAllItemsInCategory")
        {
            category = tokens[1];
            output1 << "command:" << command << '\t' << category << endl;
            tpbst_avl.printCategory(output1, category);
            output2 << "command:" << command << '\t' << category << endl;
            tpbst_llrb.printCategory(output2, category);
        }
        else if (command == "printItem")
        {
            category = tokens[1];
            key = tokens[2];
            output1 << "command:" << command << '\t' << category << '\t' << key << endl;
            tpbst_avl.printProduct(output1, category, key);
            output2 << "command:" << command << '\t' << category << '\t' << key << endl;
            tpbst_llrb.printProduct(output2, category, key);
        }
        else if (command == "find")
        {
            category = tokens[1];
            key = tokens[2];
            output1 << "command:" << command << '\t' << category << '\t' << key << endl;
            tpbst_avl.find(output1, category, key);
            output2 << "command:" << command << '\t' << category << '\t' << key << endl;
            tpbst_llrb.find(output2, category, key);
        }
        else if (command == "updateData")
        {
            category = tokens[1];
            key = tokens[2];
            data = tokens[3];
            tpbst_avl.update(category, key, data);
            tpbst_llrb.update(category, key, data);
        }
    }

    return 0;
}