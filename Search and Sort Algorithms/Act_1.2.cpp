#include <iostream>
#include <vector>
#include <stdlib.h>
#include "sorter.h"
#include "search.h"

using namespace std;

template <typename T>
void print_vector(vector<T> arr, int N)
{
    for (size_t i = 0; i < arr.size() && i < N; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

int main()
{
    srand(time(NULL));

    vector<int> arr;
    int n;
    int searches;
    cout << "How many elements do you want the list to have?: ";
    cin >> n;
    cout << "How many elements do you wish to search?: ";
    cin >> searches;
    vector<int> nums(searches);
    for (size_t i = 0; i < searches; i++)
    {
        cout << "Please insert the number you are looking for: ";
        cin >> nums[i];
    }

    for (size_t i = 0; i < n; i++)
    {
        arr.push_back((int)rand() % 100);
    }

    //Busqueda secuencial desordenada
    SecuentialSearch<int> secSearch;

    cout << endl <<"Busqueda secuencial (Lista desordenada): " << endl << endl;

    for (size_t i = 0; i < nums.size(); i++)
    {
        int index = secSearch.search(nums[i], arr);
        cout << "Number: " << nums[i] << "\tFound at index: " << index << endl << endl;
        cout << endl << endl;
    }


    int sortId;

    cout << "Which sorting method would you like to use?" << endl;
    cout << "Insertion sort [1]" << endl << "Bubble sort [2]" << endl << "Quick sort [3]" << endl;
    cin >> sortId;

    if(sortId == 1)
    {
        cout << endl << "Sorting by Insertion Sort." << endl << endl;
         InsertionSort<int> insSort;
        insSort.sort(arr);
    }
    else if (sortId == 2)
    {
        cout << endl << "Sorting by Bubble Sort: " << endl << endl;
        BubbleSort<int> bubSort;
        bubSort.sort(arr);
    }
    else if (sortId == 3)
    {
        cout << endl << "Sorting by Quick Sort: " << endl << endl;
        QuickSort<int> qSort;
        qSort.sort(arr, 0, n - 1);
    }
    else
        cout << "Sorry that is not a valid entry.";
    
    BinarySearch<int> biSearch;
    cout << "Busqueda Binaria: " << endl << endl;
    for (size_t i = 0; i < nums.size(); i++)
    {   
        int index = biSearch.search(nums[i], arr);
        cout << "Number: " << nums[i] << "\tFound at index: " << index << endl << endl;
    }

    return 0;
}
