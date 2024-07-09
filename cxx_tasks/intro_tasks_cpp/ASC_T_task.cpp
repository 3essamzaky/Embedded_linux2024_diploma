#include <iostream>


int main(){
    std::cout << "ASCII Code Table:" << std::endl;

    std:: cout<< "+-------------------+" << std::endl;
    std::cout << "| char | ASCII |" << std::endl;
    std:: cout<< "+-------------------+" << std::endl;

    for (int i = 0; i < 127; i++) {
        std::cout <<"|     " << static_cast<char>(i)<< "   |    " <<  i  <<"    | " << std::endl;
    }
    return 0;
}
