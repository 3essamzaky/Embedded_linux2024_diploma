#include <iostream> // Include the input/output stream library



int main() // Main function where the execution of the program starts
{
    int num;
    std:: cout << "Enter the number: ";
    std::cin >> num;

    std::string num_str = std::to_string(num);

    int digit_count = 0,sum = 0;
    for(char c : num_str){
        digit_count= c - '0';
        sum+= digit_count;

    }
    std:: cout<< "sum of digits of "<< num << " is: " <<sum << std::endl;


    return 0;
 
}
