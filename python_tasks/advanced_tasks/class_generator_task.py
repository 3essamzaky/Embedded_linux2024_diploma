import os
from datetime import datetime


x = datetime.now()
date = x.strftime("%Y %B %d - %H:%M%S")


name= input("Please Enter your name: ")
print(f"Hello mr {name}")

calss_name = input("please enter your class name:").strip()
namespace = input("please enter your name space: ").strip()

print(f"your class is {calss_name} and your namespace is {namespace}")

os.system(f"touch {calss_name}.hpp ")
with open(f"{calss_name}.hpp","w") as f_hpp:
    f_hpp.write(f"#pragma once \n/****************************************************/\n\
//\n\
//          copyRight {name} \n\
//\n\
/****************************************************\n*/")
    f_hpp.write(f"/*\n\
author : {name} \n\
date :  {date}  \n\
brief:\n\
*/\n")
    f_hpp.write(f"namespace {namespace}")
    f_hpp.write("{\n")
    f_hpp.write(f"class {calss_name}")
    f_hpp.write("{\n\npublic:\n")
    
    f_hpp.write(f"    {calss_name}::{calss_name}();")
    f_hpp.write(f"\n    {calss_name}::~{calss_name}();\n")
    f_hpp.write("private:\n")
    f_hpp.write("\n};")
    f_hpp.write("\n}")




cpp_file = input(r"do you want the cpp file Y/N :")
if cpp_file == "Y" :
    os.system(f"touch {calss_name}.cpp ")
    with open(f"{calss_name}.cpp","w") as f_cpp:
        f_cpp.write(f"/****************************************************/\n\
//\n\
//          copyRight {name} \n\
//\n\
/****************************************************\n*/")
        f_cpp.write(f"/*\n\
author : {name} \n\
date :  {date}  \n\
brief:\n\
*/\n")
        f_cpp.write(f"#include \"{calss_name}.hpp\" \n\
namespace {namespace}")
        f_cpp.write("{\n")
        f_cpp.write(f"    {calss_name}::{calss_name}()")
        f_cpp.write(r"{}")        
        f_cpp.write(f"\n    {calss_name}::~{calss_name}()")
        f_cpp.write(r"{}")        
        f_cpp.write("\n}")
