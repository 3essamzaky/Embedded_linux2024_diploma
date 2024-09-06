/*****************  notes_stl_p2 ********************************8

================== some notes ====================






====================== array  =====================

** there is no copy in array => u = v;

** arr.begain() ==> btreturn pointer to calss iteriator 
** arr.data()  ==> btreturn pointer to the first element of the array


//the difference between cbegin and begin
-std::array<int, 3> arr = {1, 2, 3};
auto it = arr.begin();
*it = 10; // Modifies the first element of the array
std::cout << arr[0]; // Outputs: 10

-std::array<int, 3> arr = {1, 2, 3};
auto it = arr.cbegin();
// *it = 10; // Error: Cannot modify the element through a const iterator
std::cout << *it; // Outputs: 1




====================== voctor ==========================
** there is copy in vector => u = v

** the difference between emplace and emplace back , emplace you can emplace anywhere in the vector and 
    emplace back you can emplace at the end of the vector only

** emplace_back() ==>> it is behave same as push_back but there is an optimization that
 it will not reallocate the vector if the vector is already big enough.

** emplace() ==>> it is behave same as insert but there is an optimization here

====================== Map ==========================

* key == first  and value == second

** std::map <int ,std::string> m;  //map of int and string
// to insert on it => m.insert({1,"one"}); //this is temperory insert or implaced , m.insert(std::make_pair(1,"one")); //this is explacited insert

** hash table is speed better tree


Notes on codes:
Ex:
struct MyStruct {
    int x;
    MyStruct(int val) : x(val) {
        std::cout << "MyStruct constructed with value " << x << std::endl;
    }
};

int main() {
    std::vector<MyStruct> vec;
    vec.emplace_back(10);            // Constructs MyStruct(10) at the end of the vector
    vec.emplace(vec.begin(), 20);    // Constructs MyStruct(20) at the beginning of the vector

    return 0;
}

-------------------------------------------------------------

Ex:
int main(){
    std::vector<int> v = {1,4,5,2,5};

    for(int i = 0; i < 100; i++){
        auto it = v.begin().base();
        std::cout << "pointer " << it << " SIZE " << v.size() << "capacity " << v.capacity() <<std::endl;

        v.push_back(i);
    }
    return 0;
}
   
--------------------------------------------------------

Ex:
int main(){
    std::vector<int> v = {1,4,5,2,5};

    for(int i = 0; i < 100; i++){
        auto it = v.begin().base();
        std::cout << "pointer " << it << " SIZE " << v.size() << "capacity " << v.capacity() <<std::endl;

        v.emplace_back(i);  //there is optimization  
    }
    return 0;
}
   
--------------------------------------------------------

** vector<int> v = {1,4};       //intializer list => | 5 | 2 |   
** vector<int> v = (5,2);       //5 is the number of elements and 2 is the value of each element


 */