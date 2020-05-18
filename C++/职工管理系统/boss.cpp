//
//  boss.cpp
//  职工管理系统
//
//  Created by Peng Wang on 2020/5/16.
//  Copyright © 2020 Peng Wang. All rights reserved.
//

#include "boss.hpp"
boss::boss(int id,string name, int dId)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_deptId = dId;
}


void boss::show_info()
{
    cout << "职工编号：" << this->m_Id
         << "\t职工姓名：" << this->m_Name
         << "\t岗位：" << this->get_dept_name()
         << "\t职位职责：manager all thing!"
    << endl;
}

string boss::get_dept_name()
{
    return "BOSS";
}
