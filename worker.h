#pragma once
#include<iostream>
#include<string>
using namespace std;

//职员类
class Worker
{
    public:
        //岗位信息描述
        virtual void showInfo()=0;
        //获取岗位名称
        virtual string getDeptName()=0;

        //职员ID
        int wId;
        //职员姓名
        string name;
        //部门ID
        int DeptId;
};