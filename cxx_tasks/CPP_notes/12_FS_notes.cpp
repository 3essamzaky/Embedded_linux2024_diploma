/************ file system **************************

======================= some notes =====================

-1 int main () {
    std::fstream file("hello.txt", std::ios::in); 

    // std::ios::in: open for reading
    // std::ios::out: open for writing
    // std::ios::app: append to the end of the file
    // std::ios::trunc: discard the file if it already exists
    // std::ios::binary: open the file in binary mode


2- sudo chmod 000 hello.txt  // to dont allow anyone to read or write the file

3- sudo chmod 700 hello.txt // to allow anyone to read or write the file

4- after the moving the file is closed

5- file.rdbuf() : is used to get the stream buffer associated with the file.

6- file.get() : is used to read a single character from the file that the cursor is stopped at it and make the cursor point to the next character .

7- file.seekg(offset,direction)
-  file.seekg(0, std::ios::beg) : char 0 is the beginning of the file
-  file.seekg(0, std::ios::end) : char 0 is the end of the file  //return -1
-  file.seekg(0, std::ios::cur) : the current position of the cursor

8- file.flush() : is used to flush the buffer. //like  press enter

9- you can write like that :
    file << "heello\n"       //append at the cursor position
    or file.write("hhhhhhhhhh",8); 
    file.flush();


======================= notes on codes ===============
Ex. read bufers:

int main() {
    std::fstream file("hello.txt", std::ios::in);
    if (file.is_open()) {
        std::cout << "File is open" << std::endl;
        std::streambuf *buffer = file.rdbuf();

        std::cout << buffer << std::endl;

        // read from the buffer
        std::string str;
        std::getline(buffer, str);
        std::cout << str << std::endl; 
    
    
    }

}
-------------------------------------------------------
ex. get cursor:
int main() {
    std::fstream file("hello.txt", std::ios::in);
    if (file.is_open()) {
        std::cout << "File is open" << std::endl;
        
    else {
        std::cout << "File is not open" << std::endl;
    }
    char x;

    //file.get();   //get the ascii value

    x = file.get();   //happened casting to char
    std::cout << x << std::endl;

    std::array<char,40> arr;
    file.getline(arr.data(), 40);
    std::cout << arr.data() << std::endl;  //print the whole 40 char of line
}
-------------------------------------------------------

ex. seekg:
int main() {
    std::fstream file("hello.txt", std::ios::in);
    if (file.is_open()) {
        std::cout << "File is open" << std::endl;

        file.seekg(0, std::ios::beg);
        std::cout << file.get() << std::endl; file.tellg() : 


-------------------------------------------------------

ex. read bianary: 
std::fstream file("a.out", std::ios::in);
    if (file.is_open()) {
        std::cout << "File is open" << std::endl;

        std::array<char, 15> buffer;
        file.read(buffer.data(),buffer.size()-1); 
        std::cout << "read" << file.gcount() << "bytes." << std::endl;
        for( const auto &c : buffer ) {
          std::printf("%02x ", static_cast<unsigned char>(c));
        }
            

    
    }

 */