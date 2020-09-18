//
//  main.cpp
//  职工管理系统
//
//  Created by Peng Wang on 2020/5/15.
//  Copyright © 2020 Peng Wang. All rights reserved.
//

#include <iostream>
#include "work.hpp"
#include "workmanager.hpp"
#include "employee.hpp"
#include "manager.hpp"
#include "boss.hpp"
int main(int argc, const char * argv[]) {
    workmanager wm;
    int choice = 1;
    while(true)
    {
        wm.show_menu();
        cout << "please input your choice:" << endl;
        
        cin >> choice;
        
        switch(choice){
            case 0:
                wm.exitSystem();
                break;
            case 1:
                wm.add_emp();
                break;
            case 2:
                wm.show_emp();
                break;
            case 3:
                wm.del_emp();
                break;
            case 4:
                wm.mod_emp();
                break;
            case 5:
                wm.find_emp();
                break;
            case 6:
                cout << "as" << endl;
                break;
            case 7:
                wm.clean_file();
                break;
            default:
                system("clear");
            break;
        }
    }
    return 0;
}

