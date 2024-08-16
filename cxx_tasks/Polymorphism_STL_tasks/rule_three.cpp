#include <iostream>
#include <cstdio>
#include <cstring>


class string{

    private:
    char *ptr_str = nullptr;
    int size;
    public:

    string(const char *str){
        std::cout << __PRETTY_FUNCTION__<< str << std::endl;
        size = strlen(str);
        ptr_str = new char[size + 1];
        memcpy(ptr_str, str, size+1);
    }

    //copy constructor
    string (const string &obj){

        std::cout << "copy constructor "<< std::endl;

        size = obj.size;
        ptr_str = new char[size + 1];
        memcpy(ptr_str, obj.ptr_str, size+1);
    }

    //copy assignment operator
    string &operator=(const string&obj){

        std::cout << "copy assignment operator "<< std::endl;
        if(this == &obj)
        {
            return *this;
        }

        delete [] ptr_str;
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
};

int main(){ 

    string name("Essam");
    string name1(name);
    string name2("zaki");
    name2 = name1;
    
    
}