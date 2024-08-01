#include <iostream>
#include <numeric>

int main() {

    const int size = 1000-10 +1;
    int arr[size];

    std::iota(arr, arr+size, 10);
    
    //print the array
    for(int i = 0; i<size;i++)
    {
        std::cout<< arr[i] << std::endl;
    }
    
    return 0;
}