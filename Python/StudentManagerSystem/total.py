import os


def total():
    filename = "student.txt"
    if os.path.exists(filename):
        with open(filename, 'r') as file:
            student_old = file.readlines()
            if student_old:
                print("一共有%d名学生." % len(student_old))
            else:
                print("还没有录入学生信息。")

