//
//  employee.cpp
//  职工管理系统
//
//  Created by Peng Wang on 2020/5/16.
//  Copyright © 2020 Peng Wang. All rights reserved.
//

#include "employee.hpp"

employee::employee(int id,string name, int dId)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_deptId = dId;
}


void employee::show_info()
{
    cout << "职工编号：" << this->m_Id
         << "\t职工姓名：" << this->m_Name
         << "\t岗位：" << this->get_dept_name()
         << "\t职位职责：完成经理交给的任务！"
    << endl;
}

string employee::get_dept_name()
{
    return "员工";
}
