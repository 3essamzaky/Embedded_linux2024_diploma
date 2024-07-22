#include <algorithm>
#include <iostream>




int main()
{
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {1, 2, 3, 4, 5};
    int arr3[10];


    for(int i = 0; i < 5; i++)
    {
        arr3[i] = arr1[i];
    }

    for(int i = 0; i < 5; i++)
    {
        arr3[i + 5] = arr2[i];
    }


    for(int i : arr3)
    {
        std::cout << i << std::endl;
    }





    return 0;

}