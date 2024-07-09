#include <iostream>


int max_num(int a, int b,int c){
    if(a>b && a>c){
        return a;
    }
    else if(b>a && b>c){
        return b;
    }
    else{
        return c;
    }   
    
}

int main(){ 

    int a =0;
    int b =0;
    int c= 0;
    int max = 0;
    std:: cin>>a;
    std:: cin>>b;  
    std:: cin>>c;
    max = max_num(a,b,c);
    std :: cout<< "the max number is: "<<max<<std::endl;

    

    return 0;

}
  
