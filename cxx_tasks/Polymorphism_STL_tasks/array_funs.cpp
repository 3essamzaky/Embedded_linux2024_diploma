#include <iostream>
#include <array>
#include <utility>


int main(){
    std::array<int,5> arr {1,2,3,5,4};

    std::cout <<  arr.size() << std::endl;
    std::cout <<  arr.front() << std::endl;
    std::cout <<  arr.back() << std::endl;
    std::cout <<  arr.at(4) << std::endl;
    std::cout <<  arr[4] << std::endl;
    auto it = arr.data();
    std::cout << *it << std::endl;
    auto itt = arr.begin();
    std::cout << *itt << std::endl;
    arr.fill(10);

    for(const auto &elm : arr)
    {
        std::cout << elm << " " ;
    }
    std::array<int ,  4> arr2 ;
    //arr2 = arr;           //compilation error
    


    


    return 0;
}