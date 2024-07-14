
from tkinter import *


root = Tk()
root.geometry("400x400+500+200")
root.title("tk") 

v_M = StringVar()
V_N = StringVar()
V=IntVar()
V = IntVar()
def operation():

    if V.get()==1:
        print(f"the sum of {v_M.get()} + {V_N.get()} = {int(v_M.get())+int(V_N.get())}")

    elif V.get()==2:
        print(f"the sub of {v_M.get()} - {V_N.get()} = {int(v_M.get())-int(V_N.get())}")

    else:
        print("choose the operation")


Entry1= Entry(root,textvariable=v_M,bg="white").grid(row=0,column=1)
Label1= Label(root,text="enter the value of M",bg="white").grid(row=0,column=0)

Entry2= Entry(root,textvariable=V_N,bg="white").grid(row=1,column=1)
Label2= Label(root,text="enter the value of N",bg="white").grid(row=1,column=0)

Radiobutton(root, text="sum", variable=V, value=1).grid(row=4,column=0)
Radiobutton(root, text="sub", variable=V, value=2).grid(row=3,column=0)


Button(root, text="validate", command=operation).grid(row=2,column=1)



root.mainloop()