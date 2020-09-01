#include <iostream>
#include <vector>
#include <stdlib.h>
#include "search.h"
#include "mytimer.h"



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

int main(){

    
    vector<int> arr;
    //Numeros que se estan buscando
    vector<int> nums = {2000, 4000, 6000, 8000, 10000};
    //Cantidad de numeros en la lista
    int count = 100000;

    srand(time(NULL));

    //Creates a vector with n random numbers from 1 to 100000
    for (size_t i = 0; i < count; i++)
    {
        arr.push_back((int)rand() % 100000);
    }


    //Busqueda secuencial desordenada
    SecuentialSearch<int> secSearch;

    cout << "Busqueda secuencial: " << endl << endl;
    DECLARE_TIMING(t1);
    for (size_t i = 0; i < nums.size(); i++)
    {
        START_TIMING(t1);
        int index = secSearch.search(nums[i], arr);
        STOP_TIMING(t1);
        cout << "Number: " << nums[i] << "\tFound at index: " << index << endl << endl;
        SHOW_TIMING(t1, "Busqueda secuencial: ");
        cout << endl << endl;
    }
    
    //Busqueda secuencial ordenada 1
    
    OrgSecuentialSearch1<int> orgSecSearch1;
    orgSecSearch1.sort_asc(arr);
    cout << "Busqueda secuencial ordenada 1: " << endl << endl;
    DECLARE_TIMING(t2);
    for (size_t i = 0; i < nums.size(); i++)
    {
        
        START_TIMING(t2);
        int index = orgSecSearch1.search(nums[i], arr);
        STOP_TIMING(t2);
        cout << "Number: " << nums[i] << "\tFound at index: " << index << endl << endl;
        SHOW_TIMING(t2, "Busqueda secuencial ordenada 1: ");
        cout << endl << endl;
    }

    //Busqueda secuencial ordenada 2
    OrgSecuentialSearch2<int> orgSecSearch2;
    cout << "Busqueda secuencial ordenada 2: " << endl << endl;
    DECLARE_TIMING(t3);
    for (size_t i = 0; i < nums.size(); i++)
    {
        
        START_TIMING(t3);
        int index = orgSecSearch2.search(nums[i], arr);
        STOP_TIMING(t3);
        cout << "Number: " << nums[i] << "\tFound at index: " << index << endl << endl;
        SHOW_TIMING(t3, "Busqueda secuencial ordenada 2: ");
        cout << endl << endl;
    }

    


    //Busqueda Binaria
    BinarySearch<int> biSearch;
    cout << "Busqueda Binaria: " << endl << endl;
    DECLARE_TIMING(t4);
    for (size_t i = 0; i < nums.size(); i++)
    {
        
        START_TIMING(t4);
        int index = biSearch.search(nums[i], arr);
        STOP_TIMING(t4);
        cout << "Number: " << nums[i] << "\tFound at index: " << index << endl << endl;
        SHOW_TIMING(t4, "Busqueda Binaria: ");
        cout << endl << endl;
    }

    return 0;
}

