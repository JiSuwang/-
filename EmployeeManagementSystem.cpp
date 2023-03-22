#include<iostream>
#include"workerManager.h"
#include"Manager.h"
#include"Boss.h"
#include"Employee.h"
#include"worker.h"
using namespace std;

//void test();

//职员管理系统
int main()
{   

    workManager wm;
    int choose = 0;
    wm.showMenu();
    while (true)
    {   
        cin>>choose;
        switch(choose)
        {
            case 0://退出系统
                wm.exitWorkManager();
                break;
            case 1://增加职工
            {
                wm.addEmp();
                wm.save();
            }
                break;
            case 2://显示职工
                wm.showEmp();
                break;
            case 3://删除职工
                wm.deleEmp();
                break;
            case 4://修改职工
                wm.changeEmp();
                break;
            case 5://查找职工
                wm.checkEmp();
                break;
            case 6://排序职工
                
                break;
            case 7://清空文档
                break;
        }

    }
    
    return 0;
} 

/*void test()
{
    Worker* worker = NULL;
    worker = new Employee(1,"wang",1);
    worker->showInfo();
    worker->getDeptName();
    delete worker;
    
    worker = new Manager(2,"Li",2);
    worker->showInfo();
    worker->getDeptName();
    delete worker;
    
    worker = new Boss(3,"zhang",3);
    worker->showInfo();
    worker->getDeptName();
    delete worker;
}*/