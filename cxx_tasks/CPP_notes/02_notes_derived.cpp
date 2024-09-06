/*
=============== some notes ===================

** use constexpr if  if i wnt the thing happen in compiler time

** lambda in cpp inside btcreate two fun. , 1. operating overloading. 2. constructor fun.

** in lambda if he msh 3arf yt3rf 3la return type ==> brwite after explicit decltype(the thing that return)
ex:
    auto fn = [](auto f, auto g) -> decltype(f +g) {return f+g;};

============ ranged for loop =================
ex:
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    for(int i : arr) { std::cout << i << std::endl; }

============ static cast =====================
ex:
    int a = 10;
    int b = 20;
    float c = static_cast<float>(a) / b;
    std::cout << c << std::endl;

============ const cast ======================
ex:
    const int val = 10;
    const int *ptr = &val;
    
    int *ptr2 = const_cast<int*>(ptr);  //const etshal here only
    *ptr2 = 20;                         //chnged in the address of val

    std::cout << ptr << std::endl;   
    std ::cout << val << std::endl;     // will still 10
    std ::cout << ptr2 << std::endl;

============ lambda exp ======================

[capture list] (parameter list) -> return type { function body }   

//capture list is use it when we do not want to use global variable in lambda
//or when we want th the function see it
// if i want to call it ==>[capture list] (parameter list) -> return type { function body }(retern value)
ex:

    auto add = [](int a, int b) -> int { return a + b; }; 
    auto add = [](int a, int b) -> int { return a + b; }(3, 4);

-------notes -----------
[x]   // Captures x by value
[=]   // this means all local variable takes its by value
[&]  //this means all local variable takes its by reference
** when you take vlaue by ref. you can change it in lambda scope and it will be changed  

Notes by code:
//scope of lambda is standalone scope
Ex:
int main() {
    int x = 10;
    auto lambda = [x]() { // Captures x by value
        std::cout << "Inside lambda, x = " << x << std::endl; // Uses its own scope
    };
    x = 20; // Changing x outside the lambda does not affect the captured value
    lambda(); // Outputs: Inside lambda, x = 10

    std::cout << "Outside lambda, x = " << x << std::endl; //Outputs: Inside lambda, x = 20
    return 0;
}
Notes by code:
//offseet or capture by value is constant in lambda and u can cahnge  it in lambda  scope only be mutable word
Ex:
 int temp = 10;
    [temp](int number)mutable{
        temp = 100;  // need to be mutable to change it
        std::cout << temp << std::endl;   output will be 100
    }(3);
    std::cout << temp << std::endl;  output will be 10

Notes by code:
Ex:
    int temp = 10;
    [&temp](int number){
        temp = 100;  
        std::cout << temp << std::endl;   output will be 100
    }(3);
    std::cout << temp << std::endl;  output will be 100

Notes by code:
//here all local variables takes it by value but val takes it by reference
Ex:
int temp = 10;
int val = 39;
[=,&val](int number){                                               
    temp = 100;  // need to be mutable to change it
    std::cout << temp << std::endl;   output will be 100
}(3);



*/

