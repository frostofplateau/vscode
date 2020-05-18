//
//  work.hpp
//  职工管理系统
//
//  Created by Peng Wang on 2020/5/16.
//  Copyright © 2020 Peng Wang. All rights reserved.
//

#ifndef work_hpp
#define work_hpp
#include <iostream>
#include <string>
using namespace std;
class work
{
public:
    virtual void show_info() = 0;
    virtual string get_dept_name() = 0;
    virtual ~work()
    {
        cout << "~work" << endl;
    }
    
    
    int m_Id;
    string m_Name;
    int m_deptId;
};
#endif /* work_hpp */
