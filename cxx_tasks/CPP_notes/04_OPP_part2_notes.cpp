/*
============== some notes ================

**  LCD("hello", 0);      //this is temporary instance  ,this will imdiately destroy after creation

** if u have constructor with one argumrnt u should add explicit to this constructor
Ex:
    Data(std::string msg): msg(msg){}
    SOLVE => explicit Data(std::string msg): msg(msg){}

** use friend operator when you want to access private members of a class

=========== operator overloading =========

* operator overloading form:
  datatype operator operation (argument-list){body} 

Ex1: LCD &operator +=(const std::string &message){
        this->msg += message;
        return *this;

    //datatype => reference LCD because will store in it
    //argument-list => badyha const of adderss ely a addoo
    // *this hreturn to lcd1

Ex2: std::string result = lcd1 + message   //operator+(lcd,std::string)

    solve => std::string operator +(const LCD &lcd1 ,const std::string &message ){
        return lcd1.msg + message
 
        }
ex3:
    lcd1<lcd2  // lcd1.operator<(lcd2)

    solve=> bool operator < (const LCD &l)
                {
                    return this->msg < l.msg;
                }
    // this->msg => t3od l lcd1 
    // l.msg => t3od l lcd2 

Ex:
    ++lcd  => LCD &operator++(){this->curser++ ; return *this}
    ++lcd //lcd.operator++()
    lcd = 1 //lcd.operator=(1)

Ex:
    lcd++  => int operator++(int){
                int temp = this->curser;
                this->cureser++;
                return temp;

    }
    //int =>this is duny int

Notes by code :

class LCD{
    private:
    std::string msg;
    int curser = 0;

    public:
        LCD(std::string msg, int curser = 0) : msg{msg}, curser{curser}{}

    int operator++(int){
        int temp = this->curser;               // operator of => lcd1++;
        this->curser++;
        return temp;
    }               

    bool operator <(const LCD &lcd){

        return this->curser < lcd.curser;      // operator of => lcd1<lcd2
    }

    / ********** /friend operator/ *********** /
    friend std::ostream &operator<<(std::ostream &os, const LCD &lcd);


    bool operator ==(const LCD &lcd){ 
        return std::tie(this->msg, this->curser) == std::tie(lcd.msg, lcd.curser);    // operator of => lcd1==lcd2
    }  
    
};    

// std::cout << std::endl;
std::ostream &operator<<(std::ostream &os, const LCD &lcd){

        os << lcd.msg << " " << lcd.curser;

        return os;
}

int main(){

    LCD lcd1{"welcome to c++",0};
    LCD lcd2{"hello world",1};

    std::vector<LCD> lcds{lcd1, lcd2};
    std::sort(lcds.begin(), lcds.end());

    std::copy(lcds.begin(), lcds.end(), std::ostream_iterator<LCD>(std::cout, "\n"));  // to print the vector
    


    return 0;
}



=========== functor =====================

EX:   void operator()(void){
        std::cout << "hello" << std::endl;}

    //() this is a functor
   //you can call it in the main by the object and carrybractes   obj()

=========== operator conversion =========
form:
    operator std::string(){return msg;}

    //std::string()  => el7aga ely h7ol lyha 
    //{ }  => shkl l conversion
Ex:
if i want 

    std::string message = lcd1;

    solve => operator std::string(){return msg;}

*/





















/************** test ***************************** 





*/



