#include <iostream>
#include <deque>
#include <iterator>
#include <list>

template <typename T> void print_list(std::list<T> l){

    for(const auto &elem :l)    
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}



int main(){
    std::list<int > l {1,2,3,4,5,4};
    std::list<int> l2 (std::next(begin(l)) ,l.end());
    print_list(l2);
    std::list <int> l3(l2);
    print_list(l3);
    std::list <int > l4 = l3;
    print_list(l4);
    l.assign({1,2,3,4,5,6,7});
    print_list(l);
    auto b = l4.crbegin();
    std::cout << *b << std::endl;
    l.erase(next(std::begin(l)));
    print_list(l);
    l.unique();
    l.sort();
    print_list(l);
    


    return 0;
}

