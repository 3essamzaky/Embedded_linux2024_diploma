#include <iostream>
#include <ostream>



class Integer{

private:
    int num;
public:
    Integer(int num) : num(num){}

    Integer(const Integer &obj){


    }

    //opertor overloading => INT1+=INT2
    Integer &operator+=(const Integer &INT){

        this->num += INT.num;
        return *this;

        
    }

    //opertor overloading => INT1-=INT2
    Integer &operator-=(const Integer &INT){

        this->num -= INT.num;
        return *this;

        
    }
    //opertor overloading => INT1*=INT2
    Integer &operator*=(const Integer &INT){

        this->num *= INT.num;
        return *this;

        
    }
    //opertor overloading => INT1/=INT2
    Integer &operator/=(const Integer &INT){

        this->num /= INT.num;
        return *this;

        
    } 
    //opertor overloading => INT1%=INT2
    Integer &operator%=(const Integer &INT){

        this->num %= INT.num;
        return *this;

        
    }   

    //opertor overloading => x = INT1+INT2
    int operator+(const Integer &INT){
        return this->num + INT.num;

    }
    //opertor overloading => x= INT1-INT2
    int operator-(const Integer &INT){
        return this->num - INT.num;

    }
    //opertor overloading => INT1 = INT2 + x
    Integer &operator+(const int x){

    this->num += x;
        return *this;
        
    }
    Integer &operator=(const Integer &INT){

    this->num = INT.num;
    return *this;
    }
    //opertor overloading =>++INT1;
    Integer &operator++(){
        this->num++;
        return *this;
    }
    //opertor overloading =>--INT1;
    Integer &operator--(){
        this->num--;
        return *this;
    }
    //opertor overloading =>INT1++;
    Integer &operator++(int){

        Integer temp = this->num;
        this->num++;
        return temp;
    }
    //opertor overloading =>INT1--;
    Integer &operator--(int){

        Integer p = this ->num;
        this->num--;
        return p;
    }
    //opertor overloading => INT1 > INT2;;
    bool operator>(const Integer &INT){
        return this->num > INT.num;
    }
    //opertor overloading => INT1 < INT2;;
    bool operator<(const Integer &INT){
        return this->num < INT.num;
    }
    //opertor overloading => INT1 >= INT2;;
    bool operator>=(const Integer &INT){
        return this->num >= INT.num;
    }
    //opertor overloading => INT1 <= INT2;;
    bool operator<=(const Integer &INT){
        return this->num <= INT.num;
    }
    //opertor overloading => INT1 == INT2;;
    bool operator==(const Integer &INT){
        return this->num == INT.num;
    }
    //opertor overloading => INT1 != INT2;;
    bool operator!=(const Integer &INT){
        return this->num != INT.num;
    }
    //opertor overloading => INT1 << value;
    int operator<<(const int value){

        return this->num << value;
    }

    //opertor overloading => INT1 >> value;
    int operator>>(const int value){ 

        return this->num >> value;
    }

    //opertor overloading => INT1 & value;
    int operator&(const int value){

        return this->num & value;
    }

    //opertor overloading => INT1 | value;
    int operator|(const int value){ 

        return this->num | value;
    }

    //opertor overloading => INT1 ^ value;
    int operator^(const int value){

        return this->num ^ value;
    }
    //opertor overloading => INT = value;
    Integer &operator=(const int value){

        this->num = value;
        return *this;
    }



    // std::cout << INT;
    friend std::ostream &operator<<(std::ostream &os, const Integer &INT);


};

std::ostream &operator<<(std::ostream &os, const Integer &INT)
{

        os << INT.num;

        return os;

}


int main()
{
    Integer INT1{10};
    Integer INT2{20};
    int x = 10;

    //INT1 += INT2;
    //INT1-= INT2;
    //INT1*= INT2;
    //INT2/= INT1;
    //x = INT1 + INT2;  
    //x = INT1 - INT2;  
    //INT1 = INT2 + x;
    // INT1++;
    // INT2--;
    // ++INT1;
    // --INT2;
    // INT1 > INT2;
    // INT1 < INT2;
    // INT1 >= INT2;
    // INT1 <= INT2;
    // INT1 == INT2;
    // INT1 != INT2;

    if(INT1 > INT2)
    {
        std::cout<< "INT1 is greater than INT2"<<std::endl;
    }
    else
    {
        std::cout<< "INT1 is not greater than INT2"<<std::endl;
    }
    //std:: cout << INT1<< std::endl;






}