#include <algorithm>
#include <iostream>




int main()
{
    int arr[10] = {2, 5, 4, 6, 3, 1, 7, 8, 9, 10};

    std::cout<<"the even numbers are: " << std::endl;
    for(int i = 0; i < 10; i++)
        {
            if(arr[i] % 2 == 0)
            {
                std::cout << arr[i] << std::endl;

            }

        }
    std::cout<<"the odd numbers are: " << std::endl;
    for(int i = 0; i < 10; i++)
        {
            if(arr[i] % 2 != 0)
            {
                std::cout << arr[i] << std::endl;

            }

        }
    return 0;

}