#include"workerManager.h"

//职员管理类的实现
workManager::workManager()
{   
    ifstream ifs;
    ifs.open(fileName,ios::in);
    if(!ifs.is_open())
    {
        cout<<"文件不存在"<<endl;
        this->fileIsEmpty = true;
        this->Enum = 0; 
        this->empArry = NULL;
        ifs.close();
        return;
    }
    char ch;
    ifs>>ch;
    if(ifs.eof())
    {
        cout<<"文件为空"<<endl;
        this->fileIsEmpty = true;
        this->Enum = 0; 
        this->empArry = NULL;   
        ifs.close();
        return;
    }
    getEmp();
    return;
}

workManager::~workManager(){}

void workManager::showMenu()
{
    cout<<"******************"<<endl;
    cout<<"***职工管理系统****"<<endl;
    cout<<"****0.退出系统*****"<<endl;
    cout<<"****1.增加职工*****"<<endl;
    cout<<"****2.显示职工*****"<<endl;
    cout<<"****3.删除职工*****"<<endl;
    cout<<"****4.修改职工*****"<<endl;
    cout<<"****5.查找职工*****"<<endl;
    cout<<"****6.排序职工*****"<<endl;
    cout<<"****7.清空文档*****"<<endl;
    cout<<"*******************"<<endl;
    cout<<"请输入您的选择："<<endl;
}

void workManager::exitWorkManager()
{
    cout<<"退出程序"<<endl;
    exit(0);
}

//添加职工
void workManager::addEmp()
{
    int addNum = 0;
    cout<<"请输入增加的员工数量"<<endl;
    cin>>addNum;
    if (addNum>0)
    {
        int newNum = this->Enum + addNum;
        Worker** newSpace = new Worker*[newNum];
        if (this->Enum!=0)
        {
            for(int i = 0;i<this->Enum;i++)
            {
                newSpace[i] = this->empArry[i];
            }
        }
        for(int i = 0;i<addNum;i++)
        {
            int id;
            string name;
            int select;
            cout<<"请输入员工ID:"<<endl;
            cin>>id;
            cout<<"请输入员工名字:"<<endl;
            cin>>name;
            cout<<"请输入员工岗位:员工1,经理2,老板3"<<endl;
            cin>>select;

            Worker* worker = NULL;
            switch (select)
            {
            case 1:
                worker = new Employee(id,name,select);
                break;
            case 2:
                worker = new Manager(id,name,select);
                break;
            case 3:
                worker = new Boss(id,name,select);
                break;
            default:
                break;
            }

            newSpace[this->Enum+i] = worker;

        }
        delete[] this->empArry;
        this->empArry = newSpace;
        this->Enum = newNum;
        this->fileIsEmpty = false;
        cout<<"添加成功"<<endl;
        
    }
    else
    {
        cout<<"输入错误"<<endl;
    }
}

void workManager::save()
{
    ofstream ofs;
    ofs.open(fileName,ios::out);
    for(int i = 0;i<this->Enum;i++)
    {
        ofs<<this->empArry[i]->wId<<" "
           <<this->empArry[i]->name<<" "
           <<this->empArry[i]->DeptId<<endl;
    }
    ofs.close();
}

int workManager ::getNum()
{
    int num = 0;
    ifstream ifs;
    ifs.open(fileName,ios::in);
    int Id;
    string name;
    int dId;
    while(ifs>>Id&&ifs>>name&&ifs>>dId)
    {
        num++;
    }
    ifs.close();
    return num;
}

void workManager::getEmp()
{

        int Num = getNum();
        this->empArry = new Worker*[Num];
        ifstream ifs;
        ifs.open(fileName,ios::in);
        int Id;
        string name;
        int dId;
        int i = 0;
        Worker* worker = NULL;
        while(ifs>>Id&&ifs>>name&&ifs>>dId)
        {
            switch (dId)
            {
            case 1:
                worker = new Employee(Id,name,dId);
                break;
            case 2:
                worker = new Manager(Id,name,dId);
                break;
            case 3:
                worker = new Boss(Id,name,dId);
                break;
            default:
                break;
            }
            this->empArry[i] = worker;
            i++;
            //delete worker;//疑问：为啥加上不行
        }
        ifs.close();
        this->Enum = Num;
        this->fileIsEmpty = false;
}

void workManager::showEmp()
{
    if(this->fileIsEmpty)
    {
        cout<<"文件不存在"<<endl;
    }
    else
    {
        for(int i =0;i<this->Enum;i++)
        {
            this->empArry[i]->showInfo();
        }
    }
}

void workManager::deleEmp()
{
    int delet = this->searchEmp();
    if(delet>=0)
    {
        for(int j = delet ;j<(this->Enum-1);j++)
            {
                this->empArry[j]=this->empArry[j+1];
            }
        this->Enum--;
        save();
        cout<<"删除完成"<<endl;
    }
    else
    {
        cout<<"无此人"<<endl;
    }
    
}

int workManager::searchEmp()
{
    cout<<"请输入要操作的的员工序号"<<endl;
    int search;
    cin>>search;
    bool ifEmp = false;
    int i = 0;
    for(i;i<this->Enum;i++)
    {
        if(this->empArry[i]->wId==search)
        {
            ifEmp = true;
            break;
        }
    }
    if(ifEmp)
    {
        return i;
    }
    else
    {
        return -1;
    }
}

void workManager::checkEmp()
{
    int check = this->searchEmp();
    if(check>=0)
    {   
        int de = this->empArry[check]->DeptId;
        cout<<"员工序号:"<<this->empArry[check]->wId<<"\t"
            <<"员工姓名:"<<this->empArry[check]->name<<"\t"
            <<"员工是：";
        switch (de)
        {
        case 1:
            cout<<"职工"<<endl;
            break;
        case 2:
            cout<<"经理"<<endl;
            break;
        case 3:
            cout<<"老板"<<endl;
            break;
        default:
            break;
        }
    }
}

void workManager::changeEmp()
{
    int change = this->searchEmp();
    int id,select;
    string name;
    cout<<"请输入员工ID:"<<endl;
    cin>>id;
    cout<<"请输入员工名字:"<<endl;
    cin>>name;
    cout<<"请输入员工岗位:员工1,经理2,老板3"<<endl;
    cin>>select;
    // delete this->empArry[change];
    switch (select)
    {
    case 1:
        this->empArry[change] = new Employee(id,name,select);
        break;
    case 2:
        this->empArry[change] = new Manager(id,name,select);
        break;
    case 3:
        this->empArry[change] = new Boss(id,name,select);
        break;
    default:
        break;
    }
    this->save();
    cout<<"修改成功"<<endl;
}

void workManager::sortEmp()
{
    Worker* tempWork;
    for(int i = 0;i<(this->Enum-1);i++)
    {
        for(int j = 0;j<(this->Enum-i-1);j++)
        {
            if(this->empArry[j]->wId>this->empArry[j+1]->wId)
            {
                tempWork = this->empArry[j];
                this->empArry[j]=this->empArry[j+1];
                this->empArry[j+1]=tempWork;
            }
        }
    }
    this->save();
    cout<<"排序成功"<<endl;
}

void workManager::clearEmp()
{
    ofstream ofs(fileName,ios::trunc);
    ofs.close();
    if(this->empArry!=NULL)
    {
        for(int i = 0;i<this->Enum;i++)
        {
            if(this->empArry[i]!=NULL)
            {
                delete this->empArry[i];
            }
        }
        this->Enum = 0;
        delete[] this->empArry;
        this->empArry = NULL;
        this->fileIsEmpty = true;
        cout<<"删除成功"<<endl;
    }
}