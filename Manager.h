#pragma once
#include"worker.h"
#include<iostream>
#include<string>
using namespace std;

//员工类
class Manager:public Worker
{
    public:
        //构造函数
        Manager(int wId,string name,int DeptId);
        //岗位信息描述
        void showInfo();
        //获取岗位名称
        string getDeptName();
};