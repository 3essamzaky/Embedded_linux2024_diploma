#include <future>
#include <iostream>
#include <deque>
#include <random>

template <typename T> void print_deque(std::deque<T> d){

    for(const auto &elem : d)    
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}



int main(){
    std::deque<int> d {1,3,5,6,7,8};

    std::deque <int> v2(std::move(d));;              
    print_deque(d);
    print_deque(v2);
    std::deque<int> v3 ;
    v3 = v2;      
    print_deque(v3);
    d.assign(2,3);                          // 3 3
    print_deque(d);
    d.push_back(9);                             // 3 3 9
    d.emplace_back(7);                            // 3 3 9 7
    d.push_front(19);                           // 19 3 3 9 7

    auto v_index = d.at(2);        
    std::cout << v_index<< std::endl;             // 5
    std::cout << d.empty() << std::endl;         // 0
    d.resize(7,0);
    print_deque(d);
    d.assign({1,2,34,5});      // 1 2 34 5
    print_deque(d);


    return 0;
}












