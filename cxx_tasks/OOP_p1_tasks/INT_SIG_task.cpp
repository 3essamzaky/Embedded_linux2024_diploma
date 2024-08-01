#include <csignal> 
#include <iostream> 



void signal_handler(int sig_nmbr)
{
    std::cout<< "interrupt signal received"<<std::endl;
    exit(sig_nmbr);
}


int main() 
{ 
    signal(SIGINT, signal_handler);
    while (true) {


    
    }
    return 0; 
}