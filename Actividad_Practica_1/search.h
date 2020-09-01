#ifndef search_h
#define search_h

#include <iostream>
#include <vector>
#include <stdlib.h>

template <typename T>
class Search
{
    public:
    Search() {};
    ~Search() {};

    void sort_asc(std::vector<T> &arr) 
    {
        for (size_t i = 0; i < arr.size(); i++)
        {
            size_t min = i;
            for (size_t j = i + 1; j < arr.size(); j++)
            {
                if(arr[j] < arr[min])
                    min = j;
            }
            T aux = arr[i];
            arr[i] = arr[min];
            arr[min] = aux; 
        }
    };

    void sort_desc(std::vector<T> &arr)
    {
        for (size_t i = 0; i < arr.size(); i++)
        {
            size_t min = i;
            for (size_t j = i + 1; j < arr.size(); j++)
            {
                if(arr[j] > arr[min])
                    min = j;
            }
            T aux = arr[i];
            arr[i] = arr[min];
            arr[min] = aux; 
        }
    };

    
    virtual T search() {};

};

template <typename T>
class SecuentialSearch : public Search<T>
{
    public:
    SecuentialSearch() {};
    ~SecuentialSearch() {};

    int search(T x, std::vector<T> arr)
    {
        for (size_t i = 0; i < arr.size(); i++)  
            if (arr[i] == x)
                return i;
        return -1;

        
    };
};

template <typename T>
class BinarySearch : public Search<T>
{
    public:
    BinarySearch() {};
    ~BinarySearch() {};

    T search(T x, std::vector<T> arr)
    {
        int left = 0;
        int right = arr.size();
        int middle;
        bool found;
        while(found == false)
        {
            if (right >= left)
            {
            middle = left + (right-left) / 2;
            
              
            if (arr[middle] ==  x)
                return middle;
            else if(arr[middle] > x)
                right = middle - 1;
            else
                left = middle + 1;
            }
            else
                return -1;
        }
        return -1;
    };
        
};



#endif
