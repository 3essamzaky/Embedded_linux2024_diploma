
from tkinter import *


root = Tk()
root.geometry("500x500+500+200")
root.title("reverse words") 
root.configure(bg="white")

frame = Frame(root,bg="white",  borderwidth=10)
frame.pack(expand=True, fill="both")
v = StringVar()
def printt():
    word = v.get()
    word = word[::-1]
    print(f"the reversed word is {word}")

    v.set("")


Label = Label(frame, text="enter a word",bg="white")
Label.grid(row=0,column=0)

entry = Entry(frame, textvariable=v)
entry.grid(row=0,column=1)


btn = Button(frame, text="click",command= printt)
btn.grid(row=2,column=0)


root.mainloop()