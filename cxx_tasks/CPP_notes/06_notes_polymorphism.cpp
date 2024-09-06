/*

=============== some notes ========================
1- multiple inheritance and hyperid in msiral rule is not valid to use it 

2- when you use the virtiual , behind scene bycreate ptr bypoint to the base class

3-we can see the private when we use friend method or class friend 

4-any thing inside protected u can use it in inherit but dont access it in main

5- why we use override keyword?
-> if there is class base there is a function like that : virtual void print() = 0; and used it in derived
like that : virtual void print() override {} ==> override here will give you error if you override about function not virtual
(when you write pure function and dont write virtual u will get error)

6- we dont write override outside the class

7-The virtual keyword creates a vtable, enabling dynamic binding (late binding) of functions.

8-abstract: means you have a virtual function implemented , the class with at least have one pure virtual function
(Pure virtual function making the class as an abstract class)

9- interface(pure abstract class) : An interface in C++ is a class that only contains pure virtual functions and 
   no data members or concrete (non-pure) functions.

10-pointer to the base class see only the vtable if i want to access it we can use dinamic_cast
Ex:
    int main() {

    base *ptr = new derived;
    ptr->print();  //error because print is in the base class we can solve it by :
    derived *ptr2 = dynamic_cast<derived*>(ptr); //dynamic_cast makes ptr2 not null

    if(ptr2 ) {ptr2->print();}

    return 0;
}

11- it is not allowed to create instance from the interface class
  - base obj; //error 3lshan l pure function
12- in tne inherited calss we must implement all the pure virtual functions

=============== inheritance ========================
Ex: of single inheritance

//base //like create file 
//derived //write data into file
//~derved // reset file 
//~base // delete file

class base{
    std::string name;
    public:
    base(std::string name) : name(name){
        std::cout << " constructor" << std::endl;
    }
    base(){
        std::cout << "defualt base constructor" << std::endl;
    }
    void print(){

        std::cout << "base print" << std::endl;

    }
};
class derived : public base{
    public:
    int id ;
    derived(std::string name ) : base(name){
        std::cout << " constructor" << std::endl;
    }
    derived(){
        std::cout << "defualt derived constructor" << std::endl;
    }
};
int main()
{
    derived d;     //this object coantain = [base]+[derived] 
    
    d.print();
    

    return 0;
}
================== abstract class ========================
#include <iostream>
using namespace std;

class Shape {
public:
    // Pure virtual function making this an abstract class
    virtual void draw() = 0; // Abstract method
};

class Circle : public Shape {
public:
    void draw() override { // Implementing the abstract method
        cout << "Drawing a circle\n";
    }
};

class Square : public Shape {
public:
    void draw() override { // Implementing the abstract method
        cout << "Drawing a square\n";
    }
};

int main() {
    Shape* shape1 = new Circle();
    Shape* shape2 = new Square();

    shape1->draw(); // Output: Drawing a circle
    shape2->draw(); // Output: Drawing a square

    delete shape1;
    delete shape2;
    return 0;
}



*/



















