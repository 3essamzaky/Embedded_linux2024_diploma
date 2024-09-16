#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>

class Command
{
    private:
        std::string buffer;
        
    public:
    
        std::string openTerminal();
        std::string openVScode();
        std::string openCalculator();
        std::string openFolder();
        std::string shutdown();
        std::string reboot();
        std::string logout();
        std::string openBrowser();
        std::string openspotify();
        std::string youtube();
        std::string linkedin();
        std::string github();
        std::string chatgpt();


        

};













#endif  
