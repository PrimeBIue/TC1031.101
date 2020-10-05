#include "linked_list.h"



int main()
{
    LinkedList<int> list;
    
    Node<int> *node2SortInsert = new Node<int>(27, NULL);

    cout << "Original List: " << endl;
    list.push(1);
    list.push(2);
    list.push(3);
    list.push(3);
    list.push(3);
    list.push(4);
    list.push(5);
    list.print();
    cout << endl;

    cout << "List reversed: " << endl;
    list.Reverse();
    list.print();
    cout << endl;
    
    cout << "List with 2 extra appended numbers at the end: " << endl;
    list.append(6);
    list.append(50);
    list.print();
    cout << endl;


    cout << "List with 0 inserted in index 8: " << endl;
    list.insert_item(0, 8);
    list.print();
    cout << endl;

    cout << "List after deleting the item in index 8: " << endl;
    list.delete_item(8);
    list.print();
    cout << endl;

    cout << "List after using SortInsert to insert 27: " << endl;
    list.SortedInsert(node2SortInsert);
    list.print();
    cout << endl;

    cout << "Times the number 3 appears on the list: " << endl;
    cout << list.count(3);
    cout << endl << endl;

    cout << "List after deleting duplicates: " << endl;
    list.RemoveDuplicates();
    list.print();
    cout << endl;

    cout << "After deleting the list: " << endl;
    list.DeleteList();
    list.print();
    cout << endl;


}