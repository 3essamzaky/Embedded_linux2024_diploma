/*
================= some notes ================

1-to do truble shooting by valgrind => steps:  1- tldr valgrind and get command number 4
                                               2-command number4 + app. Ex: ./a.out

2- there is anthor tool but lower than valgrind => g++ -fsanitizer=address main.cpp

3-clean before starting when you assiging instance to another instance

4-fno-elide-construcors =>> this flag is used to optimize the the copy process as make any we nedded copy constructor
will be removed  //c++14 bimplement the flag

5-in copy assignment operator , the object is already constructred so we should 
delete the pointer

6- Shallow Copy:
 Shallow copy involves copying the values of an object's data members to another object bit by bit, including pointers.
 However, if the object contains pointers, the shallow copy only copies the pointer addresses, 
 not the data they point to. This means both the original and the copied objects will point to the same memory location.

7-Deep Copy:
 Deep copy involves creating a copy of the original object's data, including dynamically allocated memory.
 If the original object contains pointers, a deep copy will allocate new memory for the copy 
 and then duplicate the actual content that the pointers point to.

8-temporary object(or value ) must pass to const

9- when you return instance will retrun in a temporary object which means this one will be RVALUE
   so you should pass it to - const T&
                         - T&& (RVALUE reference)

10- the return value of std::move is a rvalue   

11- const left value = rvalue

12- if i use pointers or references => you should implement the FIVE RULES:
1-copy constructor
2-copy assignment operator
3-move constructor
4-move assignment operator
5-destructor

13- RULE ZERO: ydlt all constructors ya make them default

14- if you delete any constructor the all constructors will be saad (لنعيش عيشا فل يا نموت احنا الكل)
=============== copy constructor =================

1- if i dont create copy constructor it will be created by default behind the scene //implicit constructor is created by default

2- why the copy constructor is must be reference?
- to avoid ininite recursion(loop)
- As we Calling a copy constructor that's pass by value, leads to the argument being copied,
which calls the copy constructor recursively for creating a copy to pass it

3- why the copy construcotr is must be const?
- for saftey As when you return instance will retrun in a temporary object which means this one will be RVALUE
so you should pass it to - const T&
                        - T&& (RVALUE reference)

4-temporary object(or value ) must pass to const

5- when you return instance will retrun in a temporary object which means this one will be RVALUE
   so you should pass it to - const T&
                         - T&& (RVALUE reference)                        
Notes in the code:
Ex1:
class string {
    
    int size;
    public
    char *ptr_str;
    string( char *str) : ptr_str(str){}

    //create copy constructor
    string (const string &obj){
    
        size = obj.size;
        ptr_str = new char[size+1];       //allocating in heap section respected to the size
        strcpy(ptr_str, obj.ptr_str);
        //memory leakage    
    
   }


//imagine the following code:

string *|temp|* get_instance()
{
    string t1;
    return t1;      //t1 is temporary object createt behind scene and it will be RVALUE
    //temp(t1);    //here copy constructor will be called behind scene
}
int main(){
    string t2(get_instance());   //t2(temp)
    return 0;

    string t3;
    t3 = t2 ;     //assiging which means wil call t3.operator=(t2)
}

=================== value category ==================

** Lvalue : 1- named by programmer 2- has an address  3- initialized with Rvalue or Lvalue  4- has its ownership(means its resonse about its memory)
    EX: 
    int a |*Lvalue*| = 10; |*Rvalue*|

** Rvalue :  1-prgrammer never have a chance to name it 2- it never initialized  3- NO name + temporary 

** Xvalue :   identity + moved

Noted in the code:
Ex1:
int &func(){
    static int x = 0;   // this func return the address of x so that it Lvalue 
    return x;
}

int |* temp *| func2(){
    static int x = 0;        // this func return temp value  so that it Rvalue 
    return x;
}

int main(){ 

    func() = 10;            // here mean func::x = 10
    int a = func();         // here i take the value of x and put it in a
    std::cout << func() << std::endl;

    ------------------------------
    int m = 10;      
    int &temp = m;   //m,temp = 10;

    int l = temp;    //l = 10
    l = 20;          //here i change the value of l to 20 not temp

   --------------------------------

    std::string name = "Essam";            // name is a Lvalue
    std::string name2 = std::move(name);   // name2 is a Lvalue becuase it has a name and address 

    std::cout << name2 << std::endl;       // it works 
    std::cout << name << std::endl;        // it is empty , it is moved to name2 , so lets consider that the name now is a Xvalue
    
   --------------------------------
    T = A ;
    B = move(A);
    - what is the value of A and B ?
    => A was an Lvalue then it becomes an Xvalue 
    => B is an Lvalue
}
====================== type category =======================


1- lvalueRev : is alias of lvalue        
Ex: int y= 5;
    int &x = y;

    //the value category of x is lvalue
    //the type category of x is lvalueRev

    int &temp = 8; //ERROR ? lvalueRev must be initialized with lvalue

2- rvalueRev : is alias of rvalue(movement to the location)     
 -right value reference is a key for optimization for speed

Ex: int &&RvalueRef = 10;  

// wrong explaination 
int &&RvalueRef = 10;
temp = 10;   

//temp -> 0x100 (10)
//rvalueRef -> 0x100 (10)  //this means  rvalueRef is an alias to temp (rvalueRef move to location 0x100 and got 10)

----------------------------

int rvalueRef = std::move(y);  // reference to rvalue , y is a lvalue but the return value of std::move is a rvalue
//sole ownership (wrong explaination on (trival data type))

-------------------------------------
std::string name = "Essam";
std::string &&name2 = std::move(name);     // name2 is alias to name so now name ="essam" and name2 = "essam"
std::string name3 = std::move(name);       // here name is empty and name3 = "essam"
//has sole ownership(the onwer (have it ))
-------------------------------------
string t0("hello");
string t1("world");  

string &&t2(getsting());  //replace temp to t2 (tempهتحل مكان t2) htcancle l step of the temp 

string t3 = std::move(t0); 

Note:copy constructor will be called when you will move instance froom t0(t0 is lvalue ond suould be rvalue so will use std:: move) to t3 


Note:  const int &ref = 10; //behind scene temp = 10 and ref alias to temp so lvaluerefernce = lvalue and it is work

so :  10 is a rvalue and we can make it in temp velue by add const to rvalueref

so : const left value = rvalue

======================= move constructor =====================
2- if i need to convert obj (lvalue ) to be rvalue ==>> use std::move(obj)

//implement the move constructor
string (string &&obj) {
    //1- move trivial data fron t0 to t1
    //2- reset t0
    size = obj.size;
    obj.size = 0;
    str = obj.str;
    obj.str = nullptr;
}
Note: there are priorities in the construcotrs  in this => string name3(std::move(name));
it will call 1-move constructor and it make movement process  , if it doesnt exist ,it will call copy constructor
-> if i want to dont let him go to copy constructor ==>> use ( string &obj) in copy constructor not constructor

Notes in the code:
Ex1:
int main()
{
    string name("Essam");          
    string &&name2(std::move(name));    // name2 repalce with temp name and has the same address of name and it is alias
                                        // and it is make optimization for speed 
                                        // value category of name2 is lvalue
                                        // type  category of name2 is rvalue reference

    string name3(std::move(name));      // name3 will take the onwership of name and it is call move constructor 
                                        // and it make movement process
                                        // value category of name3 is lvalue
                                        // type category of name3 is  T (data type)
    std::cout << name2 << std::endl;
    std::cout << name3 << std::endl;
    std::cout << name << std::endl;
}
=================== Move assignment operator ====================
Ex: name2 = std::move(name)
the implementaion:
    test &operator=( test &&obj)
    {
        if(this == &obj)  //check for self assignment
        {
            return *this;
        }
        delete [] this->ptr_str; //delete old data
        
        this->size = obj.size;
        this->ptr_str = obj.ptr_str;
        obj.size = 0;
        obj.ptr_str = nullptr;
        return *this;
    }

*/


