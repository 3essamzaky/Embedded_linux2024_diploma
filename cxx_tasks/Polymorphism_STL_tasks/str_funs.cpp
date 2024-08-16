#include <iostream>
#include <string>
#include <utility>


int main(){

    //std::string s = "hello";

    //std::string s2(s);                  //copy constructor 
    //std::string s3(std::move(s));      //move constructor
    // std::cout << s3 << std::endl;
    // std::cout << s << std::endl;

    // std::string s2 = s ;                  //copy assigment 
    // std::cout << s2 << std::endl;
    // std::string s2 = std::move(s);        //move assigment 
    // std::cout << s2 << std::endl;

    /**************************************************** */

    // auto it = s.begin();
    // std::cout << *it << std::endl;

    // auto itt = s.begin().base();  //is equal auto it = s.data();
    // std::cout << itt << std::endl;
    // auto it = s.end();
    // std::cout << *(it-1) << std::endl;

    // std::cout << s.back() << std::endl;
    // std::cout << s.size() << std::endl;
    // std::cout << s.empty() << std::endl; 
    // std::cout << s.capacity() << std::endl;
    // s.insert(5,"world");
    // std::cout<< s << std::endl;
    // s.erase(6,1);
    // std::cout<< s << std::endl;
    // s.clear();
    // std::cout << s << std::endl;
    // s.append("hi essam");
    // std::cout << s << std::endl;
    // s.replace(3,6,"yassen");
    // std::cout << s << std::endl;
    // s.resize(3);
    // std::cout << s << std::endl;
    // s.append("Essam");
    // std::cout << s << std::endl;
    // s.resize(9,'?');
    // std::cout << s << std::endl;
    // s.assign("hi abdo");
    // std::cout << s << std::endl;
    // char ch = s.at(3);
    // std::cout <<ch << std::endl;
    // int index = s.find('b');
    // std::cout << index << std::endl;
    // auto sub_str = s.substr(3,6);
    // std::cout << sub_str << std::endl;
    // s.insert(0,1,'b');
    // std::cout << s << std::endl;
    // s.insert(2,"E");
    // std::cout << s << std::endl;

    return 0;
}