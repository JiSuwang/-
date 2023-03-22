#include"Boss.h"

////员工类的实现
Boss::Boss(int wId,string name,int DeptId)
{
    this->wId = wId;
    this->name = name;
    this->DeptId = DeptId;
}

void Boss::showInfo()
{
    cout<<"职员编号:"<<this->wId<<"\t"
        <<"职员姓名:"<<this->name<<"\t"
        <<"职员部门:"<<this->DeptId<<"\t"
        <<"职员职责:亏钱"<<endl;
}

string Boss::getDeptName()
{
    return string("老板");
}