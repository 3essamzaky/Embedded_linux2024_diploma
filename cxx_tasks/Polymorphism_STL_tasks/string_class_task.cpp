#include <iostream>
#include <ostream>
#include "string.h"
class string{
private:
    char *ptr_str;
    int size;
public:
     
    //constructor
    string (const char *str){

        std::cout << __PRETTY_FUNCTION__ << std::endl;
        size = strlen(str);
        ptr_str = new char[size + 1];
        memcpy(ptr_str, str, size+1);

    }

    //copy constructor
    string(const string &obj){

        std::cout << "copy constructor "<< std::endl;
        size = obj.size;
        ptr_str = new char[size + 1];
        memcpy(ptr_str, obj.ptr_str, size+1);
    }

    //move constructor
    string(string &&obj)
    {
        std::cout << "move  "<< std::endl;
        size = obj.size;
        obj.size = 0;
        delete [] ptr_str;
        ptr_str = obj.ptr_str;
        obj.ptr_str = nullptr;
    }
    //move assignment operator
    string &operator=( string &&obj){

        std::cout << "move assignment operator "<< std::endl;
        if(this == &obj){
            return *this;
        }
        delete [] this->ptr_str;
        this->size = obj.size;
        this->ptr_str = obj.ptr_str;
        obj.ptr_str = nullptr;
        obj.size = 0;

        return *this;
    }
    //copy assignment operator
    string &operator=( string &obj){

        std::cout << "copy assignment operator "<< std::endl;
        if(this == &obj)
        {
            return *this;
        }
        delete [] this->ptr_str;
        size = obj.size;
        ptr_str = new char[size + 1];
        memcpy(ptr_str, obj.ptr_str, size+1);
        return *this;


    }

    //destructor
    ~string(){
        std::cout << "destructor "<< std::endl;
        delete [] ptr_str;
    }

    //length
    int length() {

        int count = 0;
        while(*ptr_str != '\0')
        {
            count++;
            ptr_str++;
        }
        return count;
    }
    void print(){
        std::cout << ptr_str << std::endl;
    }
    

    

};




int main()
{

    string name("Essam");

    


    
   



    return 0;
}