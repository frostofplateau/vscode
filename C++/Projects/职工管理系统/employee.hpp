//
//  employee.hpp
//  职工管理系统
//
//  Created by Peng Wang on 2020/5/16.
//  Copyright © 2020 Peng Wang. All rights reserved.
//

#ifndef employee_hpp
#define employee_hpp
#include <iostream>
#include <string>
#include "work.hpp"
using namespace std;

class employee : public work
{
public:
    employee(int id,string name, int dId);
    virtual void show_info();
    virtual string get_dept_name();
};
#endif /* employee_hpp */
