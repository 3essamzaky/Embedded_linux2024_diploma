#include <iostream>

class check{

public:
    check(const int *arr, const int size) : ptr_array(arr), array_size(size){}


    void any_value_iseven(const int *arr, const int size);



private:
    const int *ptr_array;
    const int array_size;    
};

void check::any_value_iseven(const int *arr, const int size)
{
    for(int i = 0; i<size;i++)
    {
        if(arr[i] %2 == 0)
        {
            std::cout<< "index "<< i << " is Even and the value is " << arr[i] << std::endl;
        }
    }
    
    
    
}


int main()
{

    int arr[5] = {1,2,3,4,5};
    int array_size = sizeof(arr)/sizeof(arr[0]);

    check obj(arr, array_size);
    obj.any_value_iseven(arr, array_size);
   



    return 0;
}