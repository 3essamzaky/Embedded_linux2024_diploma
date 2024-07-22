#include <iostream>

int max_arr(int arr[]){

    int max = arr[0];
    for(int i = 0; i < 10; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
    
}


int main() {

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int max = max_arr(arr);
    std::cout << max << std::endl;


    return 0;
}