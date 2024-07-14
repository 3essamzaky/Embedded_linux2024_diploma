
from tkinter import *
import threading

root = Tk()
root.geometry("400x400+500+200")
root.title("tk") 

V = IntVar()

def fn_timer_handler():
    global t
    print(V.get())
    t= threading.Timer(1, fn_timer_handler)
    t.start()


Scale(root,from_=0,to=300, variable=V,).pack()
threading.Timer(1, fn_timer_handler).start()


try:
    root.mainloop()
    t.cancel()
except:
    exit()
    pass

