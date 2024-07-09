#include <iostream> // Include the input/output stream library



int main() // Main function where the execution of the program starts
{
    int number = 0;
    std :: cout << "input number: ";
    std::cin >> number ;

    int n,arr[10],i=0;
    while (number>0) {
        n = number%10;
        arr[i]= n;
        i++;
        

        number = number/10;
    
    }
    for(int j = i-1;j>=0;j--)
    {
        std::cout<<arr[j];
        if(j!=0)
        std::cout << " + ";


    }
    



    return 0;


    
}
