import show
import search
import os


def sort():
    show.show()
    filename = "student.txt"
    if os.path.exists(filename):
        with open(filename, 'r') as rfile:
            student_old = rfile.readlines()
            student_new = []
        for list in student_old:
            d = dict(eval(list))
            student_new.append(d)
    else:
        return
    ascORdesc = input("请选择（0升序，1降序）:")
    if ascORdesc == "0":
        ascORdescBool = False
    elif ascORdesc == "1":
        ascORdescBool = True
    else:
        print("您的输入有误，请重新输入:")
        sort()
    mode = input("请选择排序方式（1按英语成绩排序，2 按python成绩排序，3 按C语言成绩排序，0 安总成绩排序。")
    if mode == "1":
        student_new.sort(key=lambda x: x["english"], reverse=ascORdescBool)
    elif mode == "2":
        student_new.sort(key=lambda x: x["python"], reverse=ascORdescBool)
    elif mode == "3":
        student_new.sort(key=lambda x: x["c"], reverse=ascORdescBool)
    elif mode == "0":
        student_new.sort(key=lambda x: x["english"]+x["python"]+x["c"], reverse=ascORdescBool)
    else:
        print("输入有误，请重新输入。")
        sort()
    search.show_student(student_new)