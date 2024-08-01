#include <iostream>

class check{

public:
    check(const int *arr, const int size) : ptr_array(arr), array_size(size){}


    bool all_Even(const int *arr, const int size);



private:
    const int *ptr_array;
    const int array_size;    
};

bool check::all_Even(const int *arr, const int size)
{
    for(int i = 0; i<size;i++)
    {
        if(arr[i] %2 != 0)
        {
            return false;
        }
    }
    return true;
    
}


int main()
{

    int arr[5] = {1,2,3,4,5};
    int array_size = sizeof(arr)/sizeof(arr[0]);

    check obj{arr, array_size};
    if (obj.all_Even(arr, array_size))
    {
        std::cout<< "All array elements are even"<<std::endl;
    }
    else
    {
        std::cout<< "Not all array elements are even"<<std::endl;
    }



    return 0;
}