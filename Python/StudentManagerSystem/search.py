import os

def search():
    """
    :return:
    查找学生信息
    """
    filename = "student.txt"
    mark = True
    student_quary = []
    while mark:
        id = ""
        name = ""
        if os.path.exists(filename):
            mode = input("按ID查输入1，按姓名查输入2:")
            if mode == "1":
                id = input("请输入学生的ID：")
            elif mode == "2":
                name = input("请输入学生的名字：")
            else:
                print("您输入有误，请重新输入：")
                search()
            with open(filename, "r") as file:
                student = file.readlines()
                for list in student:
                    d = dict(eval(list))
                    if id is not "":
                        if d["id"] == id:
                            student_quary.append(d)
                    elif name is not "":
                        if d['name'] == name:
                            student_quary.append(d)
                show_student(student_quary)
                student_quary.clear()
                inputMark = input("是否继续查询？（y/n):")
                if inputMark == "y":
                    mark = True
                else:
                    mark = False
        else:
            print("暂未保存数据信息。")
            return


def show_student(studentList):
    if not studentList:
        print("无数据信息\n")
        return
    # 定义标题显示格式
    format_title = "{:^6}{:^12}\t{:^8}\t{:^10}\t{:^10}\t{:^10}"
    print(format_title.format("ID", "NAME", "英语成绩", "PYTHON成绩", "C", "总成绩"))
    # 定义具体内容输出形式
    format_data = "{:^6}{:^12}\t{:^12}\t{:^12}\t{:^12}\t{:^12}"
    for info in studentList:
        print(format_data.format(info.get("id"),
                                 info.get("name"),
                                 str(info.get("english")),
                                 str(info.get("python")),
                                 str(info.get("c")),
                                 str(info.get("english") + info.get("python") + info.get("c")).center(12)
                                 ))

