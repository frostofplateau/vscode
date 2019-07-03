import os
import show

def delete():
    filename = "studeng.txt"
    mark = True
    while mark:
        studentId = input("请输入要删除的学生ID：")
        if studentId is not "":
            if os.path.exists(filename):
                with open(filename, 'r') as rfile:
                    student_old = rfile.readlines()
            else:
                student_old = []
            ifdel = False
            if student_old:
                with open(filename, 'w') as wfile:
                    d = {}
                    for list in student_old:
                        d = dict(eval(list))
                        if d["id"] != studentId:
                            wfile.write(str(d) + "\n")
                        else:
                            ifdel = True
                    if ifdel:
                        print("ID为%s的学生信息已经被删除。。。" % studentId)
                    else:
                        print("没有找到ID为%s的学生信息..." % studentId)
            else:
                print("无学生信息。")
                break
            show.show()
            inputMark = input("是否继续删除？ （y/n）")
            if inputMark == 'y':
                mark = True
            else:
                mark = False