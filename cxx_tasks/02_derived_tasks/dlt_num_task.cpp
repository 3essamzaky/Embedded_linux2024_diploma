#include <iostream>




int main() {
    

    int arr[5] = {1, 2, 3, 4, 5};
    int New_arr[4];
    int number;

    std:: cout<<"Enter the number that u want to delet: ";
    std::cin >> number;

    int j=0;
    for(int i = 0; i < 5; i++)
    {

        if(arr[i] == number)
        {
            j--;

        }
        else
        {
            New_arr[j] = arr[i];
            

        }
        j++;
    }
    
    std::cout<< "New array is: " << std::endl;
    for(int i : New_arr)
    {
        std::cout << i << std::endl;
    }


    return 0;
}