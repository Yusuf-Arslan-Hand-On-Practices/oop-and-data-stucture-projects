#include <iostream>

#include "student.h"
#include "multiLinkedList.h"


using namespace std;

int main(int argc, char const *argv[])
{
    MultiLinkedList list;
    char comd;
    int id;
    double cgpa;

    cout << "----------- Welcome -----------" << endl << endl;
    while (1)
    {
        cout << "Enter 'i' to insert student informations" << endl;
        cout << "Enter 's' to delete any student's informations" << endl;
        cout << "Enter 'c' or 'd' to print all student informations sorted (CGPA/id)" << endl;
        cout << "Enter 'e' to Exit" << endl;

        cin >> comd;
        
        if (comd == 'i')
        {
            cout << "Enter -1 to exit" << endl;
            while (1)
            {
                cout << "id: ";
                cin >> id;
                if (id == -1)
                {
                    break;
                }

                cout << endl << "CGPA: ";
                cin >> cgpa;
                if (cgpa == -1)
                {
                    break;
                }

                cout << endl;

                Student student(id, cgpa);
                list.add(student);
            }
        }
        else if (comd == 's')
        {
            cout << "Enter the student's id who you want to delete" << endl;
            cin >> id;
            Student student(id, -1);
            list.remove(student);
        }
        else if (comd == 'c')
        {
            list.printCgpa();
        }
        else if (comd == 'd')
        {
            list.print();
        }
        else if (comd == 'e')
        {
            break;
        }
        else
        {
            cout << "Invalid command" << endl;
        }
    }

    return 0;
}


