#include"Employee.h"

////员工类的实现
Employee::Employee(int wId,string name,int DeptId)
{
    this->wId = wId;
    this->name = name;
    this->DeptId = DeptId;
}

void Employee::showInfo()
{
    cout<<"职员编号:"<<this->wId<<"\t"
        <<"职员姓名:"<<this->name<<"\t"
        <<"职员部门:"<<this->DeptId<<"\t"
        <<"职员职责:上班摸鱼"<<endl;
}

string Employee::getDeptName()
{
    return string("员工");
}