//
//  manager.hpp
//  职工管理系统
//
//  Created by Peng Wang on 2020/5/16.
//  Copyright © 2020 Peng Wang. All rights reserved.
//

#ifndef manager_hpp
#define manager_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "work.hpp"
using namespace std;

class manager : public work
{
public:
    manager(int id,string name, int dId);
    virtual void show_info();
    virtual string get_dept_name();
};
#endif /* manager_hpp */
