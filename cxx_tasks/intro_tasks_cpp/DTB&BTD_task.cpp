#include <iostream> // Include the input/output stream library

void decimaltobinary(int dec_num)
{
    int arr[11],i=0;

    while(dec_num!=0)
    {
        arr[i]= dec_num%2;
        i++;
        dec_num = dec_num/2;
    }
    std::cout<< "Binary representation : ";
    for(int j = i-1;j>=0;j--)
    {
        std::cout<<arr[j];
    }
    std::cout<<std::endl;

        



}
int binarytodecimal(int bin_num)
{
    int base = 1;
    int dec_value = 0;

    while(bin_num!=0)
    {
        int n = bin_num%10;

        bin_num = bin_num/10;
        dec_value += n*base;
        base = base*2;

    }
    return  dec_value;


}

int main() // Main function where the execution of the program starts
{   
    int dec_num,bin_num,dec_value;

    std :: cout << "input a decimal number: ";
    std::cin >> dec_num ;

    decimaltobinary(dec_num);

    std :: cout << "input a binary number: ";
    std::cin >> bin_num ;

    dec_value= binarytodecimal(bin_num);

    std :: cout << "decimal value: "<<dec_value<<std::endl;

    return 0;
 
}
