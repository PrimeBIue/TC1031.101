#include <iostream>
#include <vector>
#include <stdlib.h>
#include "sorter.h"
#include "mytimer.h"

using namespace std;

template <typename T>
void print_vector(vector<T> arr)
{
    for (size_t i = 0; i < arr.size(); i += 10000)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

int main()
{
    //ramdom seed
    srand(time(NULL));
    //generate random vector array
    vector<int> arr;
    int count = 100000;

    for (size_t i = 0; i < count; i++)
    {
        arr.push_back((int)rand() % 100000);
    }
    
    vector<int> arrSelSort = arr;
    vector<int> arrBubSort = arr;
    vector<int> arrInsSort = arr;
    vector<int> arrMergSort = arr;
    
    

    //create instance of SelectionSort
    cout << endl <<"Sorting by Selection Sort: " << endl;
    DECLARE_TIMING(t1);
    START_TIMING(t1);
    SelectionSort<int> selSort;
    selSort.sort(arrSelSort);
    STOP_TIMING(t1);
    SHOW_TIMING(t1, "Selection Sort:");
    cout << "List using only a value every 10,000 numbers: " << endl;
    print_vector(arrSelSort);


    //create instance of BubbleSort
    cout << endl << "Sorting by Bubble Sort: " << endl;
    DECLARE_TIMING(t2);
    START_TIMING(t2);
    BubbleSort<int> bubSort;
    bubSort.sort(arrBubSort);
    STOP_TIMING(t2);
    SHOW_TIMING(t2, "Bubble Sort:");
    cout << "List using only a value every 10,000 numbers: " << endl;
    print_vector(arrBubSort);
    

    //create instance of InsertionSort
    cout << endl << "Sorting by Insertion Sort: " << endl;
    DECLARE_TIMING(t3);
    START_TIMING(t3);
    InsertionSort<int> insSort;
    insSort.sort(arrInsSort);
    STOP_TIMING(t3);
    SHOW_TIMING(t3, "Insertion Sort:");
    cout << "List using only a value every 10,000 numbers: " << endl;
    print_vector(arrInsSort);


    //create instance of MergeSort
    cout << endl <<"Sorting by Merge Sort: " << endl;
    DECLARE_TIMING(t4);
    START_TIMING(t4);
    MergeSort<int> mergSort;
    mergSort.sort(arrMergSort, 0, arrMergSort.size() - 1);
    STOP_TIMING(t4);
    SHOW_TIMING(t4, "Merge Sort:");
    cout << "List using only a value every 10,000 numbers: " << endl;
    print_vector(arrMergSort);
    return 0;

}


