#include <iostream>
#include <ctime>

// Sekomer & Calrassian, 10 October 2020

void merge_sort(int *, int start, int end);
void merge(int*, int start, int mid, int end);

template <size_t arrSize>
std::ostream& operator<<(std::ostream&, const int (&)[arrSize]);

int main()
{
    srand(time(0));

    const int SIZE = 15;
    int arr[SIZE];

    for(auto i = 0; i < SIZE; ++i)
    {
        arr[i] = rand() % 50;
        std::cout << arr[i] << " " ;
    }
    std::cout << std::endl;

    merge_sort(arr, 0, SIZE - 1);

    std::cout << arr; 

    return 0;
}

void merge_sort(int* arr, int start, int end)
{
    int mid = (start + end) / 2;

    if(start < end)
    {
        merge_sort(arr, 0, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void merge(int* arr, int start, int mid, int end)
{
    const int s1 = mid - start + 1;
    const int s2 = end - mid;

    int sub_1[s1];
    int sub_2[s2];

    for(auto i = start; i <= mid; ++i)
    {
        sub_1[i - start] = arr[i];
    }

    for(auto i = mid + 1; i <= end; ++i)
    {
        sub_2[i - (mid + 1)] = arr[i];        
    }

    // two finger pointer algorithm
    int idx1 = 0, idx2 = 0;

    while(idx1 < s1 and idx2 < s2)
    {
        if(sub_1[idx1] <= sub_2[idx2])        
        {
            arr[start++] = sub_1[idx1++];
        }

        else
        {
            arr[start++] = sub_2[idx2++];
        }    
    }

    // don't have to check the second array, cuz its already
    // on the right side and sorted
    for( ; idx1 < s1; ++idx1)
    {
        arr[start++] = sub_1[idx1];
    }

}

template <size_t arrSize>
std::ostream& operator<<(std::ostream& os, const int (&arr)[arrSize])
{
    for(unsigned int i = 0; i < arrSize; ++i)
    {
        os << arr[i] << " ";        
    }
    return os;
}
