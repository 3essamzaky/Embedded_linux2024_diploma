#include <iostream>
#include <vector>

template <typename T> void print_vector(std::vector<T> v){

    for(const auto &elem : v)    
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}



int main(){
    std::vector<int> v {1,3,5,6,7,8};

    std::vector <int> v2(std::move(v));;              
    print_vector(v);
    print_vector(v2);
    std::vector<int > v3 ;
    v3 = v2;
    print_vector(v3);
    v.assign(2,3);               // 3 3
    print_vector(v);                    
    v.push_back(9);                  // 3 3 9
    v.emplace_back(7);                 // 3 3 9 7
    auto v_index = v.at(2);
    std::cout << v_index<< std::endl;   // 5
    v.push_back(19);                  // 3 3 9 7 19
    std::cout << v.empty() << std::endl; // 0
    v.resize(7,0);           // 3 3 9 7 19 0 0
    v.reserve(9);
    std::cout << v.capacity() << std::endl;  
    print_vector(v);
    


    return 0;
}












