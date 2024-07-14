import tkinter


root = tkinter.Tk()
root.geometry("500x500+200+300")
root.title("test")
root.configure(bg="white")
root.resizable(0,0)

def sayHello():
    print("hello")


tkinter.Button(root,command=sayHello, text="say hello").grid(row=0,column=1)
tkinter.Button(root,command=sayHello,text="say hello").grid(row=1,column=0)
tkinter.Button(root,command=sayHello, text="say hello").grid(row=1,column=2)
tkinter.Button(root,command=sayHello, text="say hello").grid(row=2,column=1)

root.mainloop()
