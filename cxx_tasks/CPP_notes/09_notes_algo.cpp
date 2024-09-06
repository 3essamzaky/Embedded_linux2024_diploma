/**************************************************************


==================== some notes ==================

** basic tempalte for calling methods from algortims 
- pointer->begin , pointer-> end , value or pointer or function  
- pointer->begin , pointer-> end , pointer , function  

** -unarypred ==> function tsta2bal one arg.
   -bainarypred ==> function tsta2bal two arg.

** some of the methods will have two types {name ,name_if}  //name_if ==> b add function 
example:
std::count_if(n.begin() , n.end() , [](int i){return i>2;})  //count how many times i>2 in vector

** any function returns itrator is pointer

** we use ex: v.erase when we use std::move in vector to avoid leaving "empty" or "dangling" e

==================== some algorithms ==================
Ex:
int main(){
    std::vector<int> v{1,3,6,6,4,3,2,1};

    //std::none_of==> return bool
    //std::any_of ==> return bool
    //std::all_of ==> return bool
    std::cout << std::all_of(n.begin() ,n.end(), [](int i ) {return i<10;})     //all of this vector are less than 10 
              << std::endl;


    std::for_each(n.begin() , n.end() , [](int i){std::cout << i << std::endl;});  //for each element in vector and call this function

    std::count(n.begin() , n.end() , 3)  //count how many times 3 in vector

    std::count_if(n.begin() , n.end() , [](int i){return i>2;})  //count how many times i>2 in vector
    example:
        std::vector<int> v{3,6,6,4,3,2,1};
        std::cout << std::count_if(v.begin() , v.end() , [](int i){return i>2;}) << std::endl;

    
    std::mismatch(n.begin() , n.end() , m.begin() , m.end()) // return pair(first , second) of iterator that mismatched in vector
    example:
        std::vector<int> v{3,6,6,4,3,2,1};
        std::vector<int> v2{4,3,2,1};
        std::mismatch(v.begin() , v.end() , v2.begin() , v2.end()) // will print (3 , 4) 
    
    auto it = std::find(n.begin() , n.end() , 3)  // return iterator that find 3 in vector
    if(it != n.end())
    {
        std::cout << *it << std::endl;   //if i want to print the index => it - n.begin() but you should use std::distance(n.begin() , it)
    }

    std::find_first_of(n.begin() , n.end() , m.begin() , m.end()) // return iterator that find first element in vector m that in vector n
    example:
        std::vector<int> v{3,6,6,4,3,2,1};
        std::vector<int> v2{4,3,2,1};
        std::find_first_of(v.begin() , v.end() , v2.begin() , v2.end()) // will print 3
`   
    std::adjacent_find(n.begin() , n.end())  // return iterator that find two element are same value in vector
    example:
        std::vector<int> v{3,6,6,4,3,2,1};
        std::adjacent_find(v.begin() , v.end()) // will print 6

    std::search(n.begin() , n.end() , m.begin() , m.end())  // btsearch about the the all elements in vector m that in vector n 
    example:
        std::vector<int> v{3,6,6,4,3,2,1};
        std::vector<int> v2{4,3,2,1};
        std::search(v.begin() , v.end() , v2.begin() , v2.end()) // will print 4

    std::lower_bound(n.begin() , n.end() , 3)  
    example:
        std::vector<int> v{1,2,3,4,5};   //must be sorted 
        std::lower_bound(v.begin() , v.end() , 3) //here less than or equal and will print 3 // if 3 doesn't exist will print 2

    std::upper_bound(n.begin() , n.end() , 3)  
    example:
        std::vector<int> v{1,2,3,4,5}
        std::upper_bound(v.begin() , v.end() , 3) // will print 4

    std::binary_search(n.begin() , n.end() , 3)
    example:
        std::vector<int> v{1,2,3,4,5}
        std::binary_search(v.begin() , v.end() , 3) // will print true


    std::find_first_of(n.begin() , n.end() , m.begin() , m.end(), std::greater<int>())   
    example:
        std::vector<int> v{3,6,6,4,3,2,1};
        std::vector<int> v2{4,3,2,1};
        std::find_first_of(v.begin() , v.end() , v2.begin() , v2.end() , std::greater<int>()) // will print 3 //next element after 4

    std::transform(n.begin() , n.end() , n.begin() , [](int i){return i+1;}) // b add 1 to each element in vector n. 
    example:
        std::vector<int> v{3,6,6,4,3,2,1};
        std::transform(v.begin() , v.end() , v.begin() , [](int i){return i+1;})
        std::for_each(v.begin() , v.end() , [](int i){std::cout << i << std::endl;});

    std::transform(n.begin() , n.end() , std::back_inserter(result) , [](int i){return i+1;}) //back inserter bt3ml push_back
    example:
        std::vector<int> v{3,6,6,4,3,2,1};
        std::vector<int> result;
        std::transform(v.begin(),v.end(),std::back_inserter(result),[](int i ){return i+1;});
        std::for_each(result.begin(),result.end(),[](int i ){std::cout << i << std::endl;});

    std::generate(n.begin() , n.end() , [](int i){return i+1;}) 
    example:
        std::vector<int> v{3,6,6,4,3,2,1};
        int value = 1;
        std::generate(v.begin() , v.end(),[&value](){return value++;}); 

    std::min_element(n.begin() , n.end());
    example:
        std::vector<int> v{3,6,6,4,3,2,1};
        std::min_element(v.begin() , v.end()); output: 1

    std::max_element(n.begin() , n.end());
    example:
        std::vector<int> v{3,6,6,4,3,2,1};
        std::max_element(v.begin() , v.end()); output: 6

    std::equal_range(n.begin() , n.end() , number)
    example:    
        std::vector<int> vec = {1, 2, 4, 4, 4, 6, 8, 10}; // Sorted vector

    // Finding the range of the value '4'
    auto range = std::equal_range(vec.begin(), vec.end(), 4);

    std::cout << "First occurrence of 4 is at position: " 
              << std::distance(vec.begin(), range.first) << std::endl;
    std::cout << "Last occurrence of 4 is just before position: " 
              << std::distance(vec.begin(), range.second) << std::endl;

    // Printing elements in the range [range.first, range.second)
    std::cout << "Elements in the equal range of 4: ";
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;  


    std::minmax_element(n.begin() , n.end())
    example:
        std::vector<int> v{3,6,6,4,3,2,1};
        std::minmax_element(v.begin() , v.end());  // output (1 , 6)    

    std::accumulate(n.begin() , n.end() , 1) // 1+3+6+6+4+3+2+1
    example:
        std::vector<int> v{3,6,6,4,3,2,1};
        std::accumulate(v.begin() , v.end() , 1); // output  1+3+6+6+4+3+2+1

    std::iota(n.begin() , n.end() , starting_from) 
    example:
        std::vector<int> v(7);
        std::iota(v.begin() , v.end() , 1); // output  1 2 3 4 5 6 7

    return 0;
}
=================== some build in algorithms ==================

std::plus<int>  // add two int   //like [](int i,int j){return i+j;}
Ex:
    std::plus<int> add
    int result = add(21,3);

std::minus<int>  // sub two int
std::multiplies<int>  // mult two int
std::divides<int>  // div two int
std::modulus<int>  // mod two int











 */