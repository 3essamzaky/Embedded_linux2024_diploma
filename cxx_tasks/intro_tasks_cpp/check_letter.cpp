#include <iostream> // Include the input/output stream library

void check_letter(char letter)
{
    char arr[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    for (int i = 0; i < 10; i++)
    {
        if (letter == arr[i])
        {
            std::cout << "The letter is a vowel" << std::endl;
            return;
        }
    }
    std::cout << "The letter is a consonant" << std::endl;
}


int main() // Main function where the execution of the program starts
{
    char letter;
    std:: cout << "Enter a letter: ";
    std::cin >> letter;
    check_letter(letter);


    return 0;


    
}
