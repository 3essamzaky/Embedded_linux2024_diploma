/**
============== some notes ============================

** tirval data types {int , float , double , char , bool }

** use enum class over classic enum to make it more secure

** RAII ==>> (Resource Acquisition Is Initialization )
- this means any thing declard in constructor must be destoryed in destructor

** struct by defualt all in it are public

** class by defualt all in it are private 

** (this) => like self in python btpresent the address of the object

** size of object in class = size of datatypes + vptr if exist + padding

** If we have not defined any constructor, copy constructor, or move constructor in our class,
 then the C++ compiler will automatically create a default constructor with no parameters and empty body.

** Data:: Data(int a){this ->a = a;}      ==     Data:: Data(int a): a(a){}    initializer list

** you can access private members by friend method or class

** C++ RULE 9-3-1 => const member functions shall not return pointers or references to members
 => you cannot return pointer or reference to member  if const it will work => like : const int *getter();
ex: int *getter(){      //ISSUE
    return ptr;         //NOTE => ptr is in private members
}

============== initialization ========================

int x = 0;        // copy initialization
int x2(0);        // direct ini.
int x3{};         // value initialization or uniform initialization   // default = 0
int x4;           // garvage value
char a[3] = {'1','2','3'};  //aggregate initialization
int x2()          // eRROR  => VEXING PARSER


============== struct/class ========================

---------notes -------
form memory side--> members will be allocate in the same scope of object
and function will be in .text section


Notes by code:

struct MyData{
    int ID;
    std::string name;
    void setter(int id, std::string n){
        ID = id;
        name = n;
    }

    MyData(){
        std::cout << "constructor" << std::endl;        // will be executed when at the start of the scope
        ID = 1;
        name = "default";
    }

    ~MyData(){
        std::cout << "destructor" << std::endl;       // will be executed when at the end of the scope
        ID = 0;
        name = "";
    }   
};

Notes by code:
Ex: 
calss MyData{

public:
    MyData(){}                  // this is default constructor
    MyData() = delete ;         // when any one call the defualt instreuctor it will be deleted and will say this the constructor is deleted
 
    MyData(int a, int b){}      // this is parameterized constructor
    int &number;               // must be in initializer list
    const int n ;              // must be in initializer list

private:
    int a;
    int b;
}h


 int main(){
     MyData my = MyData();                // this is default 
     MyData my = MyData(10, 20);          // this is parameterized
       MyData my3 = MyData{10, 20};       // this is aggregate initializer is the same as parameterized but must a,b be in public
     return 0;
}

Notes by code:
// class temp ;  // this is a forward declaration 
// void function(); // this is a forward declaration
Ex:
class MyData{
public:

    MyData(int a,int b):a(a),b(b){}

    int getter(int temp)const{
    //a = 29;  // this will not work => you cannot change the value of const variable(member variable)

    //you can create local variable and change it
    int var = 30;
    var++;

    //you can modify the paranmeter value as well 
    temp++;

    //you can modify static variable
    //you can use mutable if you want to change it
    
    
    return a;
    }
private:
    int a;
    friend class temp;   //temp class can access private members of MyData
    firend void function();  // function can access private members of MyData
    int ID;
};

int main(){
   const MyData data(10, 20);   #const instance can only call const methods(functions)
   MyData data2(30, 40);        #normal instance it will call normal method if there is also const method
    return 0;
}




===================== static member =======================
---------notes -------
** static member store in data section

** static const int variable when you didnt define it in the class and define it outside will be 
store in .rodata and will be global but but when you define it in the class it will be undefined reference

Note by code:
ex: 
class MyData{

public:
    // static member is not related to instance , it is related to class itself
    static int counter;

private:
    
};
int MyData::counter = 1; // defination should be outsude the class && not integral data type
//the same for static const member
// you can access it from the calss and the object like => MyData::counter or obj.counter

======================= static function ===================

Note by code:
class myData{
public:
    static void print(){         // static function is not related to instance it is related to class
        std::cout << "hello" << std::endl;

        // temp = 10; // Error =>  because temp de bta3 anhy abject 
        //number = 10; // OK => because number is static
    }
    static void test(){};
    int temp;  // temp here is related to instance
    static int counter; 
};
void myData::test(){}     // there is no static word outside the class
int myData::counter = 1;

int main(){
    myData::print();
    return 0;
}





 */




