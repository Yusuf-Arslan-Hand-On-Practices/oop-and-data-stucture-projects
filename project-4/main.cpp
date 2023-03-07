#include <iostream>
#include <fstream>
#include <cstring>

#include "Node.h"
#include "DoublyLinkedList.h"
#include "CircularLinkedList.h"
#include "Flat.h"
#include "Apartment.h"
#include "Street.h"

using namespace std;
using namespace flt;
using namespace aprt;
using namespace strt;


int main(int argc, char *argv[])
{
    flt::Flat* f1 = new flt::Flat(1, 100, 1);
    flt::Flat f2(2, 200, 0);
    flt::Flat f3(3, 300, 0);

    aprt::Apartment a1("A1", 1000);
    aprt::Apartment a2("A2", 1000);
    aprt::Apartment a3("A3", 1000);
    aprt::Apartment a4("A4", 1000);
    
    Street s1;
    s1.add_apartment(a1, "head");
    s1.add_apartment(a2, "head");
    s1.add_apartment(a3, "after_A1");
    s1.add_apartment(a4, "after_A1");

    cout << s1.list_apartments() << endl << endl;  

    // s1.add_flat(*f1, "A1", 0);
    s1.add_flat(f2, "A1", 0);
    s1.add_flat(f3, "A1", 0);

    cout << s1.list_apartments() << endl << endl;  

    return 0;
}














    // aprt::Apartment* a1 = new aprt::Apartment(1);
    // aprt::Apartment* a2 = new aprt::Apartment(2);
    // aprt::Apartment* a3 = new aprt::Apartment(3);
    // aprt::Apartment* a4 = new aprt::Apartment(4);
    // aprt::Apartment* a5 = new aprt::Apartment(5);


    // // a1->print();
    // // aprt::Apartment* a2 = new aprt::Apartment(2);
    // // aprt::Apartment* a3 = new aprt::Apartment(3);

    // cllist::CircularLinkedList<aprt::Apartment>* cll = new cllist::CircularLinkedList<aprt::Apartment>();
    // cll->insertHead(a1);
    // cll->insertHead(a2);
    // // cll->print();
    // cll->insertAfter(a3, a1);

    // /* Printing the list. */
    // // cll->print();

    // /* Removing an element. */
    // cll->removeIfEqual(a1);
    // // cll->print();

    // cll->insertBefore(a4, a3);
    // // cll->print();

    // cll->insertAfter(a5, a3);
    // cll->print();
    // // cll->reversePrint();

    // /* Getting the position of the element a3 in the list. */
    // cout << cll->getPosition(a5) << endl;

    // /* Getting the data of the element in the 2nd position. */
    // cout << "data " <<  *(cll->getData(3)) << endl;

    // aprt::Apartment* a6 = (cll->getData(3));
    // a6->print();
    // a6->setTest(6);

    // /* Printing the size of the list. */
    // cout << " size : " << cll->getSize() << endl;

    // cll->print();


























    // if (argc != 3)
    // {
    //     cout << "Usage: " << argv[0] << " <input_file> <output_file>" << endl;
    //     return 1;
    // }

    // // Open input file
    // ifstream input_file(argv[1]);
    // if (!input_file.is_open())
    // {
    //     cout << "Error: Could not open input file" << endl;
    //     return 1;
    // }

    // // Open output file
    // ofstream output_file(argv[2]);
    // if (!output_file.is_open())
    // {
    //     cout << "Error: Could not open output file" << endl;
    //     return 1;
    // }

    // strt::Street street;
    // aprt::Apartment apartment;
    // flt::Flat flat;


    // string line;
    // while (getline(input_file, line))
    // {
    //     // Check if line has a carriage return
    //     // If so, remove it
    //     if (line[line.length() - 1] == '\r')
    //     {
    //         line = line.substr(0, line.length() - 1);
    //     }
    
    //     if (line.compare("list_apartments") == 0)
    //     {
    //         cout << street.list_apartments() << endl;
    //         // output_file << street.list_apartments() << endl;
    //     }
    //     else if (line.compare("find_sum_of_max_bandwidths") == 0)
    //     {
    //         cout << street.find_sum_of_max_bandwidth() << endl;
    //         // output_file << street.find_sum_of_max_bandwidth() << endl;
    //     }
    //     else
    //     {
    //         std::string ptr = strtok((char *)line.c_str(), "\t");
    //         if (ptr == "add_apartment")
    //         {
    //             std::string name = strtok(NULL, "\t");
    //             std::string pos = strtok(NULL, "\t");
    //             int max_bandwidth = atoi(strtok(NULL, "\t"));

    //             street.add_apartment(aprt::Apartment(name, max_bandwidth), pos);
    //         }
    //         else if (ptr == "remove_apartment")
    //         {
    //             std::string name = strtok(NULL, "\t");
    //             street.remove_apartment(name);
    //         }
    //         else if (ptr =="add_flat")
    //         {
    //             std::string apartment_name = strtok(NULL, "\t");
    //             int pos = atoi(strtok(NULL, "\t"));
    //             int bandwidth = atoi(strtok(NULL, "\t"));
    //             int flat_id = atoi(strtok(NULL, "\t"));
    //             street.add_flat(flt::Flat(flat_id, bandwidth, 0), apartment_name, pos);
    //         }
    //     }
    // }
    
    // input_file.close();
    // output_file.close();
    // return 0;   































// int main() {

//     dllist::DoublyLinkedList<int> list;
//     list.insertAtPosition(1, 0);
//     list.insertAtPosition(2, 1);
//     list.insertAtPosition(3, 2);
//     list.insertAtPosition(-1, 0);
//     list.insertAtPosition(-2, 4);


//     list.printList();

//     cout << endl;
//     cout << endl;


//     cllist::CircularLinkedList<int> list2;
//     list2.insert(1);
//     list2.insert(2);
//     list2.insert(3);



//     list2.insertBefore(5, 1);
//     list2.printList();
//     list2.insertBefore(6, 3);


//     list2.printList();
//     list2.deleteIfEquals(31);
//     list2.printList();


//     cout << " ------------------------------------- " << endl;
//     cout << endl;


//     // Apartment

//     aprt::Apartment apartment("Apartment1", 100);
//     flt::Flat flat1(1, 10, 1);
//     flt::Flat flat2(2, 20, 0);
//     flt::Flat flat3(3, 30, 0);
//     flt::Flat flat4(4, 80, 0);

//     apartment.addFlat(flat3, 0);
//     apartment.addFlat(flat2, 1);
//     apartment.addFlat(flat1, 0);
//     apartment.addFlat(flat4, 2);

//     cout << apartment.toString() << endl;


//     aprt::Apartment apartment2("Apartment2", 31);

//     apartment2.addFlat(flat3, 0);
//     apartment2.addFlat(flat2, 1);
//     apartment2.addFlat(flat1, 0);
//     apartment2.addFlat(flat4, 2);
//     cout << apartment2.toString() << endl;

//     aprt::Apartment apartment3("Apartment3", 26);

//     apartment3.addFlat(flat3, 0);
//     apartment3.addFlat(flat2, 1);
//     apartment3.addFlat(flat1, 0);
//     apartment3.addFlat(flat4, 2);
//     cout << apartment3.toString() << endl;

//     cout << " ------------------------------------- " << endl;


    
//     strt::Street street;
//     street.add_apartment(apartment, "head");
//     street.add_apartment(apartment2, "after_Apartment1");
//     street.add_apartment(apartment3, "before_Apartment2");
//     street.printStreet();

//     cout << " ----------remove--------------------------- " << endl;

//     street.remove_apartment("Apartment3");
//     street.printStreet();

//     cout << " ----------make flat empty--------------------------- " << endl;

//     street.make_flat_empty("Apartment1", 2);

//     street.printStreet();

    

//     cout << endl << endl;
//     return 0;
// 
