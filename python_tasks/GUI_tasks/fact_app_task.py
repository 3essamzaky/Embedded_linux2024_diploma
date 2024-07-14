from tkinter import *

root = Tk()
root.geometry("500x500+200+300")
root.title("factorial")
#root.configure(bg="white")
root.resizable(0,0)

v = IntVar()

def get_factorial():
    n = int(v.get())
    fact = 1
    for i in range(1,n+1):
        fact *= i
    print(fact)

Label(root, text="Enter value of intger N: ").grid(row=0)

Entry(root,textvariable=v,bg="white").grid(row=0,column=1)
Button(root, text="Factorial", command=get_factorial).grid(row=2,column=1)
root.mainloop()