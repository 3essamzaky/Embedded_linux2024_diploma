#include <iostream>


class check{

public:

    void check_digit(char c);
};


void check::check_digit(char c)
{
    if(c >= '0' && c <= '9')
    {
        std::cout<< "It is a digit"<<std::endl;
    }
    else
    {
        std::cout<< "It is not a digit"<<std::endl;
    }
}







int main()
{
    
    check obj;
    char character;
    std::cout<< "Enter any character :";
    std::cin>> character;
    obj.check_digit(character);
    

 
    
    return 0;
}
