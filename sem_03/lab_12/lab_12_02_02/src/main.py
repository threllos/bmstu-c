from tkinter import *
from myarray import *


def fibonacci_calc():
    try:
        n = int(fib_txt.get())
    except ValueError:
        fib_lbl2.configure(text="Введите целое число. Пример: '1' или '10'")
    else:
        rc, arr = fibonacci_fill(n)

        if rc == 0:
            s = ""

            if n < 30:
                for i in range(len(arr)):
                    s += str(arr[i]) + ", "

                fib_lbl2.configure(text=s[:-2])
            else:
                fib_lbl2.configure(text="Много чисел")
        else:
            fib_lbl2.configure(text="Ошибка")


def filter_calc():
    try:
        arr = list(map(int, fil_txt.get().split(",")))
    except ValueError:
        fil_lbl2.configure(text="Введите массив. Пример: '1, 2, 3'")
    else:
        result = myfilter(arr)
        s = ""

        if len(result) < 1:
            fil_lbl2.configure(text="Массив пустой")
        elif len(result) < 30:
            for i in range(len(result)):
                s += str(result[i]) + ", "

            fil_lbl2.configure(text=s[:-2])
        else:
            fib_lbl2.configure(text="Много чисел")


window = Tk()
window.title("Лабораторная работа 12")
window.geometry('1000x200')

fib_lbl = Label(window, text="Числа Фибоначчи")
fib_lbl.place(x=0, y=0)
fib_txt = Entry(window,width=10)
fib_txt.place(x=10, y=30)
fib_btn = Button(window, text="Нажать", command=fibonacci_calc)
fib_btn.place(x=80, y=25)
fib_lbl2 = Label(window, text="Введите целое число.")
fib_lbl2.place(x=0, y=60)

fil_lbl = Label(window, text="Фильтр")
fil_lbl.place(x=0, y=100)
fil_txt = Entry(window,width=10)
fil_txt.place(x=10, y=130)
fil_btn = Button(window, text="Нажать", command=filter_calc)
fil_btn.place(x=80, y=125)
fil_lbl2 = Label(window, text="Введите массив.")
fil_lbl2.place(x=0, y=160)

window.mainloop()