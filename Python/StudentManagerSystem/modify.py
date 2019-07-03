import show
import os


def modify():
    filename = 'student.txt'
    show.show()
    if os.path.exists(filename):
        with open(filename, 'r') as rfile:
            student_old = rfile.readlines()
    else:
        return
    studentid = input("请输入要修改的学生ID：")
    with open(filename, 'w') as wfile:
        for student in student_old:
            d = dict(eval(student))
            if d['id'] == studentid:
                print("找到了这个学生，可以修改他的信息。")
                while True:
                    try:
                        d['name'] = input("请输入学生姓名：")
                        d['english'] = int(input("请输入英语成绩："))
                        d['python'] = int(input("请输入python成绩："))
                        d['c'] = int(input("请输入c语言成绩："))
                    except:
                        print("您的输入有误，请重新输入。")
                    else:
                        break
                student = str(d)
                wfile.write(student + "\n")
                print("修改成功!")
            else:
                wfile.write(student)
    mark = input("是否继续修改其他学生信息？（y\n")
    if mark == 'y':
        modify()

