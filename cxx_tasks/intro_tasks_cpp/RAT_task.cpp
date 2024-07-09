#include <iostream> // Include the input/output stream library

int main() // Main function where the execution of the program starts
{
    int rows,l;
    std :: cout << "input number of rows: "<<std::endl;
    std::cin >> rows ;

    for (int i = 1; i<=rows; i++)
    {
        for (int j =1; j<=rows-i; j++)
        {
            std::cout << " ";
            
            
        }
        l=i;
        for (int j = 1; j<=i; j++)
        {
            std::cout << l;
            l--;
            
        }
        std::cout << std::endl;

       
    }
    
}
