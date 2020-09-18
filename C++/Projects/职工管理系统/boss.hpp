//
//  boss.hpp
//  职工管理系统
//
//  Created by Peng Wang on 2020/5/16.
//  Copyright © 2020 Peng Wang. All rights reserved.
//

#ifndef boss_hpp
#define boss_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "workmanager.hpp"
#include "work.hpp"
using namespace std;

class boss : public work
{
public:
    boss(int id,string name, int dId);
    virtual void show_info();
    virtual string get_dept_name();
};
#endif /* boss_hpp */
