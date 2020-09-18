//
//  workmanager.cpp
//  职工管理系统
//
//  Created by Peng Wang on 2020/5/15.
//  Copyright © 2020 Peng Wang. All rights reserved.
//
#include <iostream>

#include "workmanager.hpp"
#import "work.hpp"
#include "employee.hpp"
#include "manager.hpp"
#include "boss.hpp"

using namespace std;

workmanager::workmanager()
{
    //cout << "sd" << endl;
    /*
    this->m_empNum = 0;
    this->m_empArray = NULL;
     */
    ifstream isf;
    isf.open(FILENAME, ios::in);
    //文件不存在的情况
    if(!isf.is_open())
    {
        cout << "文件不存在" << endl;
        this->m_empNum = 0;
        this->m_empArray = NULL;
        this->m_file_is_empty = true;
//        isf.close();
        return;
    }
    //文件存在的情况
    char ch;
    isf >> ch;
    if(isf.eof())
    {
        cout << "文件为空！" << endl;
        this->m_empNum = 0;
        this->m_empArray = NULL;
        this->m_file_is_empty = true;
        isf.close();
        return;
    }
    
    /*
    this->m_empArray = new work*[this->m_empNum];
    this->init_emp();
     */
}

workmanager::~workmanager()
{
    if(this->m_empArray != NULL)
    {
        delete[] this->m_empArray;
        this->m_empArray = NULL;
    }
}

void workmanager::show_menu()
{
    cout << "*************************************************" << endl;
    cout << "**************  欢迎使用职工管理系统 ***************" << endl;
    cout << "************** 1、增加职工信息 ********************" << endl;
    cout << "************** 2、显示职工信息 *********************" << endl;
    cout << "************** 3、删除离职职工 *********************" << endl;
    cout << "************** 4、修改职工信息 *********************" << endl;
    cout << "************** 5、查找职工信息 *********************" << endl;
    cout << "************** 6、按照编号排序 *********************" << endl;
    cout << "************** 7、清空所有文档 *********************" << endl;
    cout << "**************************************************" << endl;
}

void workmanager::exitSystem()
{
    cout << "欢迎下次使用！" << endl;
    //system("pause");
    exit(0);
}

void workmanager::add_emp()
{
    cout << "请输入新增加的员工人数：" << endl;
    int numbers;
    cin >>numbers;
    if(numbers > 0)
    {
        int all_emp = this->m_empNum + numbers;
        work** new_space = new work*[all_emp];
        if(this->m_empNum > 0)//if(this->empArray != NULL)
        {
            for(int i = 0; i < this->m_empNum; i++)
            {
                new_space[i] = this->m_empArray[i];
            }
        }
        //输入新数据
        for(int i = 0; i < numbers; ++i)
        {
            int id;
            string name;
            int dSelect;
            cout << "请输入第" << i+1 << "个员工编号：" << endl;
            cin >> id;
            
            cout << "请输入第" << i+1 << "个员工姓名：" << endl;
            cin >> name;
            
            cout << "请选择该员工的岗位：" << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> dSelect;
            work* work = NULL;
            switch (dSelect) {
                case 1:
                    work = new employee(id,name,1);
                    break;
                case 2:
                    work = new manager(id,name,2);
                    break;
                case 3:
                    work = new boss(id,name,3);
                    break;
                default:
                    break;
            }
            delete[] this->m_empArray;
            this->m_empArray = new_space;
            this->m_empNum = all_emp;
            this->m_file_is_empty = false;
            cout << "成功添加" << numbers << "名新员工！" << endl;
            this->save();
        }
    }
    else{
        cout << "输入有误！" << endl;
    }
}

void workmanager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);
    for(int i = 0; i < this->m_empNum; ++i)
    {
        ofs << this->m_empArray[i]->m_Id << " "
            << this->m_empArray[i]->m_Name << " "
        << this->m_empArray[i]->m_deptId << endl;
    }
    ofs.close();
}

int workmanager::getNums()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    
    int id;
    string name;
    int dId;
    
    int num = 0;
    while (ifs >> id && ifs >> name && ifs >> dId) {
        num++;
    }
    ifs.close();
    return num;
}

void workmanager::init_emp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    
    int id;
    string name;
    int dId;
    
    int index = 0;
    
    while (ifs >> id && ifs >> name && ifs >> dId) {
        work* work = NULL;
        if(dId == 1)
            work = new employee(id, name, dId);
        else if(dId == 2)
            work = new manager(id, name, dId);
        else
            work = new boss(id, name, dId);
        this->m_empArray[index] = work;
        index++;
    }
    ifs.close();
}

void workmanager::show_emp()
{
    if(this->m_empArray)
    {
        cout << "文件不存在或文件为空" << endl;
    }
    else
    {
        for(int i = 0; i < this->m_empNum; ++i)
        {
            //利用多态调用接口
            this->m_empArray[i]->show_info();
        }
    }
}

int workmanager::isExit(int id)
{
    int index = -1;
    for(int i = 0; i < this->m_empNum; ++i)
    {
        if(this->m_empArray[i]->m_Id == id)
        {
            index = id;
            break;
        }
        
    }
    return index;
}

void workmanager::del_emp()
{
    if(this->m_file_is_empty)
        cout << "文件为空或不存在！" << endl;
    else
        cout << "输入想要删除的职工编号：" << endl;
    int id = 0;
    cin >> id;
    int index = this->isExit(id);
    if(index != -1)
    {
        for(int i = index; i < this->m_empNum-1; i++)
        {
            this->m_empArray[i] = this->m_empArray[i+1];
        }
        this->m_empNum--;
    }
    else
    {
        cout << "输入有误！" << endl;
    }
    this->save();
    cout << "删除成功！" << endl;
}

void workmanager::mod_emp()
{
    if(this->m_file_is_empty)
        cout << "文件不存在或记录为空！" << endl;
    else
    {
        cout << "输入删除职工的ID：" << endl;
        int id;
        cin >> id;
        int index = this->isExit(id);
        if(index != 1)
        {
            delete this->m_empArray[index];
            int id = 0;
            string name = "";
            int dSelect;
            cout << "查到：" << index << "号职工,请输入新职工号：" << endl;
            cin >> id;
            cout << "请输入姓名" << endl;
            cin >> name;
            
            cout << "请选择该员工的岗位：" << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> dSelect;
            work* work = NULL;
            switch (dSelect) {
                case 1:
                    work = new employee(id,name,1);
                    break;
                case 2:
                    work = new manager(id,name,2);
                    break;
                case 3:
                    work = new boss(id,name,3);
                    break;
                default:
                    break;
            }
            //更改数据到数组中
            this->m_empArray[index] = work;
            cout << "修改成功" << this->m_empArray[index]->m_deptId << endl;
            this->save();
        }
        else{
            cout << "修改失败，查无此人！" << endl;
        }
    }
}

void workmanager::find_emp()
{
    if(this->m_file_is_empty)
        cout << "文件不存在或记录为空！" << endl;
    else
    {
        cout << "请输入查找的方式：" << endl;
        cout << "1、按职工编号查找"  << endl;
        cout << "2、按姓名查找" << endl;
        int select;
        cin >> select;
        if(select == 1)
        {
            int id;
            cout << "请输入需要查找的职工编号：" << endl;
            cin >> id;
            int ret= this->isExit(id);
            if(ret != -1)
            {
                cout << "查找成功，该职工信息如下：" << endl;
                this->m_empArray[ret]->show_info();
            }
            else
                cout << "查无此人！" << endl;
        }
        else if(select == 2)
        {
            string name = "";
            cout << "请输入查找的姓名：" << endl;
            cin >> name;
            bool flag = false;
            for(int i = 0;i < this->m_empNum; ++i)
            {
                if(this->m_empArray[i]->m_Name == name)
                {
                    cout << "查找成功！，职工编号为："
                    << this->m_empArray[i]->m_Id
                    << "信息如下：" << endl;
                    flag = true;
                    this->m_empArray[i]->show_info();
                    
                }
            }
            if (flag == false) {
                cout << "查无此人！" << endl;
            }
            else
                cout << "输入选项有误！" << endl;
        }
    }
}

void workmanager::clean_file()
{
    cout << "确认清空？" << endl;
    cout << "1、确认" << endl;
    cout << "2、返回" << endl;
    int select = 0;
    if(select == 1)
    {
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();
        if(this->m_empArray != NULL)
        {
            for(int i = 0; i < this->m_empNum; ++i)
            {
                if(this->m_empArray[i] != NULL)
                {
                    delete this->m_empArray[i];
                }
            }
            this->m_empNum = 0;
            delete [] this->m_empArray;
            this->m_empArray = NULL;
            this->m_file_is_empty = true;
            
        }
        cout << "文件清空！" << endl;
    }
}
