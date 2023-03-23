#pragma once //防止头文件重复
#include<iostream>
#include"worker.h"
#include"Boss.h"
#include"Employee.h"
#include"Manager.h"
#include<fstream>
#define fileName "C:\\Users\\Jason\\Desktop\\c\\EmployeeManagementSystem\\empFile.txt"

using namespace std;

//职员管理类
class workManager
{
    public:
        //构造函数
        workManager();

        //析构函数
        ~workManager();

        //显示菜单
        void showMenu();

        //退出程序
        void exitWorkManager();

        //添加职工
        void addEmp();

        //返回文件中职工数量
        int getNum();

        //从文件中初始化workManager类
        void getEmp();

        //从内存中将数据添加到txt中
        void save();

        //显示员工
        void showEmp();

        //删除员工
        void deleEmp();

        //查找职工的位置
        int searchEmp();

        //查找员工信息
        void checkEmp();

        //修改员工信息
        void changeEmp();

        //对员工按照编号排序
        void sortEmp();

        //清空文档
        void clearEmp();

        int Enum;
        Worker** empArry;
        bool fileIsEmpty;
};