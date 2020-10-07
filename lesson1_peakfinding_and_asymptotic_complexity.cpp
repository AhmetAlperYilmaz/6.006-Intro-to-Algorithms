#include <iostream>
#include <ctime>

#define SIZE_M 9

void peak_finder_1D(int* arr, int size_N) // sekomer
{
    // indices
    int start = 0;
    int mid;
    int end = size_N;

    while(start < end)
    {
        mid = (end - start) / 2;

        if( *(arr + mid) < *(arr + mid - 1))  // checking if left is greater than right
        {
            end = *(arr + mid - 1);  // if it is, updating right pointer
        }

        else if( *(arr + mid) < *(arr + mid + 1))  // checking if right is greater than left
        {
            start = *(arr + mid + 1);  // if it is, updating left pointer
        }

        else
        {
            break;
        }

    }

    std::cout << "peak value: " << arr[mid] << ", location: " <<  mid + 1 << std::endl;
}

void peak_finder_2D(int arr[][SIZE_M], int size_N, int size_M) // sekomer and calrassian
{
    // indices
    int start;
    int mid = size_M / 2;
    int end = size_M;
    int max = 0;
    int x = 0;

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
        mid = (end - start) / 2;

        if( arr[x][mid] < arr[x][mid-1])  // checking if left is greater than right
        {
            end = arr[x][mid-1];  // if it is, updating right pointer
        }

        else if( arr[x][mid] < arr[x][mid+1])  // checking if right is greater than left
        {
            start = arr[x][mid+1];  // if it is, updating left pointer
        }

        else
        {
            break;
        }

    }

    std::cout << "peak value: " << arr[x][mid] << ", location: (" << x + 1 << "," <<  mid + 1 << ")"<< std::endl;
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

    peak_finder_1D(array_1D, SIZE_N);
    std::cout << std::endl;
    std::cout << std::endl;
    
    for(auto i = 0; i < SIZE_N; i++)
    {
        for(auto j = 0; j < SIZE_M; j++)
        {
            array_2D[i][j] = rand() % 100;
            std::cout << array_2D[i][j] << " " ;
        }
        std::cout << std::endl;
    }

    peak_finder_2D(array_2D, SIZE_N, SIZE_M);
    
    return 0;
}