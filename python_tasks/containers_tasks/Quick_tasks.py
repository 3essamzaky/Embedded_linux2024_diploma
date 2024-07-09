#Write a Python program to count the number of lines in a text file.

f = open("file.txt","r")
list = f.readlines()
print(len(list))


#write a Python program to count the Number of words in a file.

fd = open("file.txt","r")
lst = fd.read()

print(f"the number of words are {len(lst.split())} ")



#Write a Python program to write a “list” to a file.

list = ["red","yellow","blue"]

with open("file.txt","w") as my_file:
    my_file.write(" ".join(list))

gg = open("file.txt")    
print(gg.read())
