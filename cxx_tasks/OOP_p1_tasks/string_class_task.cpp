#include <iostream>
#include <ostream>

class string{

public:
     

    string(const char *str) : ptr_str(str){}
    
    int length() {

        int count = 0;
        while(*ptr_str != '\0')
        {
            count++;
            ptr_str++;
        }
        return count;
    }
    ~string(){}


    
private:
    const char *ptr_str;
};




int main()
{

    string name("Essam");
    std::cout << name.length()<< std::endl;
   



    return 0;
}