import os
import search


def show():
    filename = "student.txt"
    student_new = []
    if os.path.exists(filename):
        with open(filename, 'r') as rfile:
            student_old = rfile.readlines()
        for list in student_old:
            student_new.append(eval(list))
        if student_new:
            search.show_student(student_new)
    else:
        print("暂未保存数据信息。。。")


