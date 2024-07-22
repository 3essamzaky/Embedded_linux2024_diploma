#include <iostream>

int search_number(int number)
{
    int state{} ;
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for(int i = 0; i < 10; i++)
    {
        if(arr[i] == number)
        {
            state =  i;
            break;
        }
        else
        {
            state = -1;
        }
    }

   return state;

}


int main() {

    int number{};
    int state;

    std:: cout<<"Enter a number: ";
    std::cin >> number;

    state = search_number(number);

    if (state == -1)
    {
        std::cout << "number not found" << std::endl;
    }
    else
    {
        std::cout << "number found at index : " << state << std::endl;
    }



    



    return 0;
}