#include <iostream>
#include <ctime>
#define SIZE_M 9

// Sekomer & Calrassian, October 2020

void peak_finder_1D(int* arr, int size_N)
{
    // indices
    int start = 0;
    int mid;
    int end = size_N - 1;

    while(start < end)
    {
        mid = (end + start) / 2;
        
        if (mid == 0 || mid == size_N - 1)
        {
            break;
        }
        else if( arr[mid] < arr[mid - 1])  // checking if left is greater than right
        {
            end = mid + 1;  // if it is, updating right pointer
        }

        else if( arr[mid] < arr[mid + 1])  // checking if right is greater than left
        {
            start = mid - 1;  // if it is, updating left pointer
        }

        else
        {
            break;
        }

    }

    std::cout << "peak value: " << arr[mid] << ", location: " <<  mid + 1 << std::endl;
}

void peak_finder_2D(int arr[][SIZE_M], int size_N, int size_M, int mid)
{
    // indices
    int start = 0;
    int end = size_M - 1;
    int max = 0;
    int x = 0;

    // global maximum finding
    for(auto i = 0; i < size_N; i++)
    {
        if(arr[i][mid] > max)
        {
            max = arr[i][mid];
            x = i;
        }
    }

    while(start < end)
    {
        if (mid == 0 || mid == size_M - 1)
        {
            std::cout << "peak value: " << arr[x][mid] << ", location: (" << x + 1 << "," <<  mid + 1 << ")"<< std::endl;
            return;
        }
        
        else if( arr[x][mid] < arr[x][mid-1] )  // checking if left is greater than right
        {
            end = mid + 1;  // if it is, updating right pointer
            mid = (end + start) / 2;
            return peak_finder_2D(arr, size_N, size_M, mid);
        }

        else if( arr[x][mid] < arr[x][mid+1] )  // checking if right is greater than left
        {
            start = mid - 1;  // if it is, updating left pointer
            mid = (end + start) / 2;
            return peak_finder_2D(arr, size_N, size_M, mid);
        }

        else
        {
            std::cout << "peak value: " << arr[x][mid] << ", location: (" << x + 1 << "," <<  mid + 1 << ")"<< std::endl;
            return;
        }
    }
}

int main()
{
    srand(time(NULL));

    const int SIZE_N = 10;
    int array_1D[SIZE_N];
    int array_2D[SIZE_N][SIZE_M];
    for(auto i = 0; i < SIZE_N; i++)
    {
        array_1D[i] = rand() % 100;
        std::cout << array_1D[i] << " " ;
    }
    std::cout << std::endl;
    peak_finder_1D(array_1D, SIZE_N);
    std::cout << std::endl;
    std::cout << std::endl;
    
    for(auto i = 0; i < SIZE_N; i++)
    {
        for(auto j = 0; j < SIZE_M; j++)
        {
            array_2D[i][j] = rand() % 100;
            std::cout << array_2D[i][j] << "   " ;
        }
        std::cout << std::endl;
    }

    int mid_of_array_2D = SIZE_M / 2;
    peak_finder_2D(array_2D, SIZE_N, SIZE_M, mid_of_array_2D);
    
    return 0;
}