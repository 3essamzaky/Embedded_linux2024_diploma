#include <iostream> 


int &f() {
    static int x = 0;
    std::cout<< x << std::endl;
    return x;
}


int main() 
{
    f() = 1;
    //When f() is called, it returns a reference to x.
    //The expression f() = 1; is then interpreted as x = 1;, which sets the value of x to 1.
    //The function also prints the current value of x before the assignment, which is 0
    f() = 0;
    //When f() is called again, it returns a reference to x, which is now 1
    //The expression f() = 0; is then interpreted as x = 0;, which sets the value of x to 0.
    //The function prints the current value of x before the assignment, which is 1


    return 0; 
}