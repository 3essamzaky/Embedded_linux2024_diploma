import os

data = 0

for bit in range(8):
    mode = input(f"please Enter bit {bit} mode: ").casefold().strip()
    if mode == "in":
        data |= 0<<bit
    elif mode == "out":
        data|= 1<<bit

data_dir = bin(data)


os.system("touch main.c")
with open("main.c",'w')as f:
    f.write("void Init_PORTA_DIR (void){\n")
    f.write(f"DDRA = {data_dir};\n")
    f.write("}")

