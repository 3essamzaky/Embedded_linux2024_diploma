/***
================ exceptions handling ========================

** std::exception => is super class of all exceptions
- all exceptions have a what() function that is used to return a string describing the exception

** try block : the block that may throw an exception  
** catch block : the block that handles the exception
** throw keyword : used to throw an exception

** noexpect : When noexcept is used in a function declaration, it tells the compiler (and the programmer) 
             that the function will not throw any exceptions.
             
Note in code:
Ex: 
void fun2() {
    throw "exception";
}
void fun1() {
    try{
        fun2();
    }catch(...)
    {
        throw;  // here is rethrown the exception that was thrown in fun2 
    }
}
int main() try{
    fun1();

    return 0;

}catch(...)
{
    std::cerr << "Exception caught";

}



================ smart pointer ========================
** unique pointer : is ownership of the object that it points to and no other pointer can point to it

**std::unique_ptr<int> ptr = std::make_unique<int>(42)

** std::make_unique<int>(42) //de ely bt7gz fel heep

** no copy in unique pointers 

** ptr.get() // return the row pointer
** ptr.release() // call the destructor 
** ptr.swap(ptr2) // swap the pointers 
** ptr.reset() // reset the pointer and can make it point to a new object  

** unique pointer have to argument the defualt deleter function and the type of the deleter function
ex:
auto fndeleter = [](int* ptr) {
    std::cout << "deleter called" << std::endl;
 delete ptr; };

std::unique_ptr<int,decltype(fndeleter)> p4(new int(3), fndeleter);

**best practise for sockets or file descriptor is to create class with destructor to close socket or file descriptor
otherwise yoi can use std::unique_ptr

** shared pointer : is ownership of the object that it points to and other pointers can point to it
** std::shared_ptr<int> ptr = std::make_shared<int>(42)
   std::shared_ptr<int> ptr2 = ptr; //the two pointer point to 42 

- you can get the number of shared pointers using ptr.use_count()


================ templates ========================
** to use static meber variable in templates
=> Ex: template <typename T, int size>         //static member variable , telling the compiler "hey we exist"
       T container <T,size>:: m_variable;  

//1- basic template single argument
   template <typename T> T div(T a, T b) {return a / b;}
--------------------------------------------------------
//2- basic template multiple arguments
  template <typename T, typename U>
  auto add(T a, U b)-> decltype(a + b) {
    return a + b;   
} 
- -> decltype(a + b) => return type of add(a,b)
---------------------------------------------------------
//3- class template        //this is the primary template

template <typename T> 
class Point {
    public:
    T x;
    point(T x) : x(x) {}
    void print() { std::cout << x << std::endl; }
};
- to call it => Point<int> p(3);   // this before c++17 
- after c++17 => Point p(3); // be auto dedctution
---------------------------------------------------------
//4- class template with standalone function
template <typename T> 
class Point {
    public:
    T x;
    point(T x) : x(x) {}
    template <typename U> 
    void add (U y) { std::cout << x + y << std::endl; }
};
- to call it => Point<int> p(3);
  - p.add(5); auto deduction from c++14 
---------------------------------------------------------
//5- explicit specialization    // any data type except int will go to upper point class if int 
will go to this because it has more priority

template <> 
 class Point<int> {
    public:
    int x;
    point(int x) : x(x) {}
    void print() { std::cout << x << std::endl; }  
}
---------------------------------------------------------
//6- partial specialization         
template <typename T, typename U> // primary template 
struct array {
    public:
    T x;
    U y;
    array(T x, U y) : x(x), y(y) {}
    void print() { std::cout << x << " " << y << std::endl; }
}
tempate <typenaame T> 
struct array<T, int> {  // partial specialization
    public:
    T x;
   int y;
    array(T x, int y) : x(x), y(y) {}
    void print() { std::cout << x << " " << y << std::endl; }
}
---------------------------------------------------------
//7- default template argument
 template <typename T = int,typename U> 
 class Point { 
     public:
     T x;
     U y ;
     point(T x, U y) : x(x), y(y) {}
     void print() { std::cout << x << " " << y << std::endl; }
 }
 point<int> p(3,4);

 //8- const template expression
template <typename T,int size> 
class array {  //size here is a constant
    public:
    T x[size];
    array(){
        for (int i = 0; i < size; i++)
        {
            x[i] = i;
        }
    }
}
array<int, 10> arr; 


//9- variadic template //make function call it self, as it call function the compiler is write it  (generate new function like operating overloading)

void print(){std::cout << " end of print " << std::endl;}
template <typename T, typename... Args>
 void print(T t ,Args... arg){ 
    std::cout << t << std::endl;  // to print first argument(t)
    print(arg...);}   // to print all arguments 

print(1,2,3,4,5.4f);//  should make function print to print all arguments 
print(3,2,3,4,5.4f);
print(1);

================ tuple ========================
std::tuple<int, float,std::string ,std::vector<int>> t(1,2.3,"hello",{1,2,3});

- std::cout << std::get<0>(t) << std::endl;
- std::cout << std::get<1>(t) << std::endl;
- std::cout << std::get<2>(t) << std::endl;
- std::cout << std::get<3>(t)[0] << std::endl;
- std::get<1>(t) = 3.4;

- int x ;
- float y;
- std::string z;
- std::vector<int> v;
 // auto [x,y,z,v] = t;
 -std::tie(x,y,z,v) = t;
 
 std::cout << std::tuple_size<decltype(t)>::value << std::endl;
 std::cout << std::tuple_size_v<decltype(t)> << std::endl; // this is part of meta templates
 std::cout << typeid(std::tuple_elemnet_t<0,decltype(t)>).name() << std::endl; // to print the type of first element

-----std::tie --
bool compareMultipleValue(){
std::string message = "hello";
std::string message2 = "hello";
int nmbr[10];
int nmbr2[10];
return (std::tie(message,nmbr) == std::tie(message2,nmbr2));

}



 */