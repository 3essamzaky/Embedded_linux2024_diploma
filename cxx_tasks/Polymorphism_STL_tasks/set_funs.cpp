#include <iostream>
#include <set>

template <typename T> void print_set(std::set<T> s){

    for(const auto &elem : s)    
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}
int main()
{
    std::set <int> s {1,3,5,6,7,8};
    print_set(s);

    s.insert(9);
    print_set(s);

    s.erase(9);
    print_set(s);

    s.clear();
    print_set(s);

    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    print_set(s);

    s.erase(s.begin());
    print_set(s);

    auto it = s.begin();
    std::cout << *it << std::endl;
    it++;
    std::cout << *it << std::endl;

    auto itt = s.end();
    std::cout << *itt << std::endl;
    itt--;
    std::cout << *itt << std::endl;

    auto it2 = s.find(3);
    std::cout << *it2 << std::endl;


    return 0;
}