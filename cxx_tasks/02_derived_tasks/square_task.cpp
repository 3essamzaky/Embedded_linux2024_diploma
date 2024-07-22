#include <iostream>




int main() {
    int number = 0;


    std:: cout<<"Enter a number: ";
    std::cin >> number;

    auto square = [](int num)->int{return num*num;};


    std::cout << square(number) << std::endl;

    



    return 0;
}