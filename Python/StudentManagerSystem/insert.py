def insert():
    studentList = []
    mark = True
    while mark:
        id = input("请输入ID（如 1001）： ")
        if not id:
            break
        name = input("请输入名字：")
        if not name:
            break
        try:
            english = int(input("请输入英语成绩："))
            python = int(input("请输入python成绩："))
            c = int(input("请输入C语言成绩："))
        except:
            print("输入无效，不是整型数字，请重新输入。")
            continue
        student = {"id": id, "name": name, "english": english, "python": python, "c": c}
        studentList.append(student)
        inputMark = input("是否继续添加？（y/n）")
        if inputMark == 'y':
            mark = True
        else:
            mark = False
    save(studentList)
    print("学生信息录入完毕！")


def save(student):
    filename = "student.txt"
    try:
        student_txt = open(filename, "a")
    except Exception as e:
        student_txt = open(filename, "w")
    for info in student:
        student_txt.write(str(info) + "\n")
    student_txt.close()

