/**************************STL_part_1*******************

================= Notes =======================

1- std::string::npos => -1

2- str.replace(7, 3, "Hello")
- find at index 7 and replace 3 characters with "Hello"

** auto raw_string = R("Hello World");       //output : hello world   , the delimiter is (" ") and you can change it ,and this raw_string is const char*
and when you put s at the end and using namespace std::literals; it will be class string 
like that :
using namespace std::literals;
auto raw_string = R("Hello World")s; 


================= string =======================
//constructors
** std::string s = "Hello World";                //const char*

**std::string str(10, 'x');                      //fill  constructor

**std::string s = str;                           //copy constructor

**std::string s = std::move(str);                //move constructor

** std::string str2(s , 7, 5) ==> "World"        //substring constructor

--------------functions-----------
 

** std::string s = "Hello World";

- s.back()                                      //return ref. to the last char
- s.front()                                     //return ref. to the first char
-std::getline(std::cin, str);                   //read a line from cin and store it in str
-std::getline(std::cin, input, ';');            //read a line from cin and store it in str and split it by;



Notes on Code:
ex: 
class Mydata{
public:
    int a;
    int b;
    Mydata(int a, int b):a(a),b(b){std::cout << "constructor" << std::endl;}

    Mydata(std::inthializer_list<int> v){
    
    
    
    std::cout << "initializer_list" << std::endl;
    for(int i : v){

        std::cout << i << std::endl;
    }
    }

};
iint main(){

    Mydata obj{1,2};          //agrregate initialization and it will call initializer_list function
    Mydata obj2({1,2});      //it will call constructor


return 0;
}

 */