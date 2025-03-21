#include <iostream>
#include <fstream>
#include <mutex>
#include <string>



class Logger{
public:
    static Logger& get_instance(){
        static Logger instance;
        return instance;
    }
    void log(const std::string &message){
        std::lock_guard<std::mutex> lock(log_mutex);
        if(log_file.is_open()){
            log_file << message << std::endl;
        }else {
            std::cerr <<" log ifle is not open" << std::endl;
        }
    }


    Logger(const Logger &) = delete;
    Logger& operator=(const Logger &) = delete;


private:

    Logger(){
        log_file.open("log.txt", std::ios::out | std::ios::app);
        if (!log_file.is_open()) {
            std::cerr << "Failed to open log file!" << std::endl;
        }
    };
    ~Logger(){
        if (log_file.is_open()) {
            log_file.close();
        }
    };
    std::ofstream log_file;
    std::mutex log_mutex;

};



int main(){
    Logger &logg = Logger::get_instance();

    logg.log("lgggggggggg");
    logg.log("hheeeeeeeeeee");
    return 0;
}