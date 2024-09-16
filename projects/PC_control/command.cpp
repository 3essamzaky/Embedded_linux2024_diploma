#include "command.hpp"

// Function to open the terminal using the "terminator" command
std::string Command::openTerminal(){
    std::string result;
    // Open a pipe to execute the "terminator" command
    FILE *fp = popen("terminator", "r");
    if(fp == NULL){
        // Error handling if the popen function fails
        perror("popen error");
        return "failed to open terminal";
    }
    // Buffer to store the output of the command
    char buffer[1024];
    // Read the output and append it to the result string
    while(fgets(buffer, sizeof(buffer), fp) != nullptr){
        result.append(buffer);
    }
    // Close the pipe
    pclose(fp);
    return result;
}

// Function to open the calculator using the "gnome-calculator" command
std::string Command::openCalculator(){
    std::string result;
    // Execute the "gnome-calculator" command
    FILE *fp = popen("gnome-calculator", "r");
    if(fp == NULL){
        perror("popen error");
        return "failed to open calculator";
    }
    char buffer[1024];
    while(fgets(buffer, sizeof(buffer), fp) != nullptr){
        result.append(buffer);
    }
    pclose(fp);
    return result;
}

// Function to open Visual Studio Code using the "code" command
std::string Command::openVScode(){
    std::string result;
    // Execute the "code" command to open VS Code
    FILE *fp = popen("code", "r");
    if(fp == NULL){
        perror("popen error");
        return "failed to open vscode";
    }
    char buffer[1024];
    while(fgets(buffer, sizeof(buffer), fp) != nullptr){
        result.append(buffer);
    }
    pclose(fp);
    return result;
}

// Function to open a file explorer using the "nautilus" command
std::string Command::openFolder(){
    std::string result;
    // Execute the "nautilus" command to open a folder
    FILE *fp = popen("nautilus", "r");
    if(fp == NULL){
        perror("popen error");
        return "failed to open folder";
    }
    char buffer[1024];
    while(fgets(buffer, sizeof(buffer), fp) != nullptr){
        result.append(buffer);
    }
    pclose(fp);
    return result;
}

// Function to shut down the system using the "shutdown -h now" command
std::string Command::shutdown(){
    std::string result;
    // Execute the shutdown command
    FILE *fp = popen("shutdown -h now", "r");
    if(fp == NULL){
        perror("popen error");
        return "failed to shutdown";
    }
    char buffer[1024];
    while(fgets(buffer, sizeof(buffer), fp) != nullptr){
        result.append(buffer);
    }
    pclose(fp);
    return result;
}

// Function to reboot the system using the "reboot" command
std::string Command::reboot(){
    std::string result;
    // Execute the reboot command
    FILE *fp = popen("reboot", "r");
    if(fp == NULL){
        perror("popen error");
        return "failed to reboot";
    }
    char buffer[1024];
    while(fgets(buffer, sizeof(buffer), fp) != nullptr){
        result.append(buffer);
    }
    pclose(fp);
    return result;
}

// Function to log out of the session using the "gnome-session-quit" command
std::string Command::logout(){
    std::string result;
    // Execute the logout command
    FILE *fp = popen("gnome-session-quit --logout --no-prompt", "r");
    if(fp == NULL){
        perror("popen error");
        return "failed to logout";
    }
    char buffer[1024];
    while(fgets(buffer, sizeof(buffer), fp) != nullptr){
        result.append(buffer);
    }
    pclose(fp);
    return result;
}

// Function to open the Firefox browser using the "firefox" command
std::string Command::openBrowser(){
    std::string result;
    // Execute the "firefox" command to open the browser
    FILE *fp = popen("firefox", "r");
    if(fp == NULL){
        perror("popen error");
        return "failed to open browser";
    }
    char buffer[1024];
    while(fgets(buffer, sizeof(buffer), fp) != nullptr){
        result.append(buffer);
    }
    pclose(fp);
    return result;
}

// Function to open Spotify using the "spotify" command
std::string Command::openspotify(){
    std::string result;
    // Execute the "spotify" command
    FILE *fp = popen("spotify", "r");
    if(fp == NULL){
        perror("popen error");
        return "failed to open spotify";
    }
    char buffer[1024];
    while(fgets(buffer, sizeof(buffer), fp) != nullptr){
        result.append(buffer);
    }
    pclose(fp);
    return result;
}

// Function to open YouTube in the browser using "xdg-open"
std::string Command::youtube(){
    std::string result;
    // Execute the "xdg-open" command to open YouTube
    FILE *fp = popen("xdg-open https://www.youtube.com/", "r");
    if(fp == NULL){
        perror("popen error");
        return "failed to open youtube";
    }
    char buffer[1024];
    while(fgets(buffer, sizeof(buffer), fp) != nullptr){
        result.append(buffer);
    }
    pclose(fp);
    return result;
}

// Function to open LinkedIn in the browser using "xdg-open"
std::string Command::linkedin(){
    std::string result;
    // Execute the "xdg-open" command to open LinkedIn
    FILE *fp = popen("xdg-open https://www.linkedin.com/feed/", "r");
    if(fp == NULL){
        perror("popen error");
        return "failed to open linkedin";
    }
    char buffer[1024];
    while(fgets(buffer, sizeof(buffer), fp) != nullptr){
        result.append(buffer);
    }
    pclose(fp);
    return result;
}

// Function to open GitHub in the browser using "xdg-open"
std::string Command::github(){
    std::string result;
    // Execute the "xdg-open" command to open GitHub
    FILE *fp = popen("xdg-open https://github.com/dashboard", "r");
    if(fp == NULL){
        perror("popen error");
        return "failed to open github";
    }
    char buffer[1024];
    while(fgets(buffer, sizeof(buffer), fp) != nullptr){
        result.append(buffer);
    }
    pclose(fp);
    return result;
}

// Function to open ChatGPT using "xdg-open"
std::string Command::chatgpt(){
    std::string result;
    // Execute the "xdg-open" command to open ChatGPT
    FILE *fp = popen("xdg-open https://chatgpt.com/?model=auto", "r");
    if(fp == NULL){
        perror("popen error");
        return "failed to open chatgpt";
    }
    char buffer[1024];
    while(fgets(buffer, sizeof(buffer), fp) != nullptr){
        result.append(buffer);
    }
    pclose(fp);
    return result;
}
