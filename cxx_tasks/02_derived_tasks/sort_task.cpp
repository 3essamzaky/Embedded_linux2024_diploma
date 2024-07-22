#include <algorithm>
#include <iostream>




int main() {
    int arr[10] = {2, 5, 4, 6, 3, 1, 7, 8, 9, 10};
    
    [](int arr[]){ 
        
        for(int i = 0; i < 10; i++){ 
            for(int j = 0; j < 10; j++){

                if(arr[i] > arr[j])
                {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }

            }

        }
    
    ;}(arr);

    std::cout<<"the descending order is: " << std::endl;
    for(int i : arr)
    {
        
        std::cout << i << std::endl;
    }
    [](int arr[]){std::sort(arr, arr + 10);}(arr);
    
    std::cout<<"the ascending order is: " << std::endl;
    for(int i : arr)
    {
        
        std::cout << i << std::endl;
    }


    return 0;
}