//
//  workmanager.hpp
//  职工管理系统
//
//  Created by Peng Wang on 2020/5/15.
//  Copyright © 2020 Peng Wang. All rights reserved.
//

#ifndef workmanager_hpp
#define workmanager_hpp

#include <iostream>
#include <fstream>
#include "work.hpp"
#define FILENAME "empFile.txt"
using namespace std;

class workmanager
{
public:
    workmanager();
    ~workmanager();
    void show_menu();
    void exitSystem();
    void add_emp();
    void save();
    int getNums();
    void init_emp();
    void show_emp();
    void del_emp();
    int isExit(int id);
    void mod_emp();
    void find_emp();
//    void sort_emp();
    void clean_file();
    
private:
    int m_empNum;
    // 员工数组指针
    work **m_empArray;
    bool m_file_is_empty;
};
#endif /* workmanager_hpp */
