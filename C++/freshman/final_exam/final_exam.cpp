/******************************************************************************************************************   
 *  文件名称: 企业管理系统   
 *  创建日期: 2021.10.28
 *  作者: 陈诺
 *   
 *  修改日期: 
 *  作者: 
 *  说明: 
 *****************************************************************************************************************/

/****************************************************<include>****************************************************/
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

/************************************************<global var start>************************************************/
struct ListNode
{
    string id = "";//员工编号
    string name = "";//员工姓名
    string department = "";//员工部门
    int salary = -1;//员工薪资
    string leaderid = "-1";//员工领导编号
    string things = "";//员工事务
    ListNode *next;
};

/*************************************************<global var end>*************************************************/



/*************************************************<fun void begin>*************************************************/
/*在控制台界面输出总菜单:
    1.查询员工信息
    2.查询事务信息
    0.退出系统*/
void Create_Menu(ListNode* &pHead);

/*在控制台界面输出员工菜单:
    1.查询员工信息
    2.删除员工信息
    3.增加员工信息
    4.修改员工信息
    5.员工排序
    6.管理层级顺序查询
    7.保存员工信息
    0.返回上一页*/
void Create_Menu_Employee(ListNode* pHead);

/*在控制台界面输出事务菜单:
    1.查询事务信息
    2.增加事务信息
    3.保存事务信息
    0.返回上一页*/
void Create_Menu_Things(ListNode* pHead);

//读取并创建员工信息链表
void Create_Employee_List(ListNode* &pHead);

//读取并创建员工信息链表
void Create_Things_List(ListNode* &pHead);

//销毁链表
void Destory_List(ListNode* &pHead);

//删除pHead指向的链表节点
void Delete_List(ListNode* pHead);

/*
根据员工的编号，姓名与部门查询员工信息
变量定义；
    提示用户输入所查询的员工编号，姓名或部门
    如果存在，输出其员工信息
    如果不存在，返回NULL*/
ListNode* Search_Employee_List(ListNode* pHead, string id);

//在控制台上输出当前链表的所有信息
void Display_List(ListNode* pHead);

/*
根据员工编号删除员工信息
变量定义；
    提示用户输入所查询的员工编号
    如果存在，输出并删除其员工信息与事务信息
    如果不存在，输出“查无此人！”*/
void Delete_List_Employee(ListNode* &pHead, string id);

/*
增加员工信息
变量定义：
    提示员工输入需要增加的员工编号，姓名，部门，薪资与领导关系
    若已有相同编号的员工存在，提示“已存在编号为X的员工！”
    若其领导指向自身，提示“领导关系错误！”*/
void Append_List_Employer(ListNode* pHead);

/*
查询领导层级关系
变量定义：
    提示输入需要查询的员工编号，逐个输出其领导编号指向的员工
    若查询的员工不存在领导，提示“该员工没有直系领导！”*/
void Eployee_Leaderid(ListNode* pHead, string id);

/*
按员工薪资排序
变量定义：
    遍历链表获取全部员工薪资并进行由高到低排序，再按照薪资向控制台输出排序结果*/
void Sort_Employee_Salary(ListNode* pHead);

/*
修改员工信息
变量定义；
    提示用户输入所要修改的员工编号，后逐个输入姓名，部门，薪资，直系领导等
    如果存在，修改员工信息
    如果不存在，输出“查无此人！”*/
void Change_Employ_List(ListNode* pHead);

//导出员工信息链表到文件
void Save_Employee_List(ListNode* pHead);

/*
根据员工的编号查询员工事务
变量定义；
    提示用户输入所查询的员工编号
    如果存在，输出其所有员工事务
    如果不存在，返回NULL*/
ListNode* Search_Things_List(ListNode* pHead, string id);

/*
根据员工编号删除员工事务
变量定义；
    提示用户输入所查询的员工编号
    如果存在，删除其事务信息*/
void Delete_List_Things(ListNode* &pHead, string id);

/*
增加事务信息
变量定义：
    提示员工输入需要增加的员工编号与事务信息*/
void Append_List_Things(ListNode* pHead);

//导出事务信息链表到文件
void Save_Things_List(ListNode* pHead);

/***************************************************<fun void end>**************************************************/

/***************************************************<fun def begin>*************************************************/
void Create_Menu(ListNode* &pHead)//建立桌面
{
    system("cls");
    if (pHead != NULL) 
    {
        Destory_List(pHead);
        pHead = NULL;
    }
    cout << "\n\n\n"
         << "              ********************************************************************************************" << endl
         << "              *                                    企业管理系统                                          *" << endl
         << "              ********************************************************************************************" << endl
         << endl
         << endl
         << endl
         << endl
         << "              请输入需要操作的文件序号:\n" << endl
         << "                  1.查询员工信息\n" << endl
         << "                  2.查询事务信息\n" << endl
         << "                  0.退出系统"
         << endl
         << endl
         << endl
         << "                  ";
    int choice;
    cin >> choice;
    if (choice == 1)
        Create_Menu_Employee(pHead);
    else if (choice == 2)
        Create_Menu_Things(pHead);
    else if (choice == 0)
    {
        system("cls");
        cout << endl
             << endl
             << endl
             << endl
             << endl
             << endl
             << endl
             << "       ******************************************************************************************\n"
             << "       ******************************************************************************************\n"
             << "       *************************************** 谢谢使用！****************************************\n"
             << "       ******************************************************************************************\n"
             << "       ******************************************************************************************";
        Sleep(5000);
        return;
    }
    else
    {
        cout << "                  请输入正确的序号！" << endl;
        Sleep(1000);
        Create_Menu(pHead);
        return;
    }
}

void Create_Menu_Employee(ListNode* pHead)//建立员工桌面
{
    ListNode* pThings = NULL;
    if (pHead == NULL) Create_Employee_List(pHead);
    int flag = 1;
    while(1)
    {
        system("cls");
        cout << "\n                  员工信息操作:" << endl
             << endl
             << endl
             << "                  请输入请输入需要操作的任务序号:" << endl
             << "                      1.查询员工信息" << endl
             << "                      2.删除员工信息" << endl
             << "                      3.增加员工信息" << endl
             << "                      4.修改员工信息" << endl
             << "                      5.员工排序" << endl
             << "                      6.管理层级顺序查询" << endl
             << "                      7.保存员工信息" << endl
             << "                      0.返回上一页" << endl
             << endl
             << endl
             << endl
             << "                  ";
        int choice;
        string id;
        cin >> choice;
        switch (choice)
        {
            case 1:
                system("cls");
                if (pHead -> id == "") 
                {
                    cin.ignore();
                    cout << "\n                  当前没有员工！" << endl;
                    getchar();
                    break;
                }
                cout << "\n                  请输入需要查询的员工编号,姓名或部门(输入0以展示全部, 输入-1返回上一界面): ";
                while (cin >> id)
                {
                    if (id == "-1") break;
                    else if (id == "0") Display_List(pHead);
                    else 
                    {
                        if (Search_Employee_List(pHead, id) == NULL) cout << "\n                  查无此人！" << endl;
                    }
                    cout << "\n\n\n                  请输入需要查询的员工编号,姓名或部门(输入0以展示全部, 输入-1返回上一界面): ";
                }
                break;
            case 2:
                system("cls");
                Create_Things_List(pThings);
                if (pHead == NULL) 
                {
                    cin.ignore();
                    cout << "\n                  当前没有员工！" << endl;
                    getchar();
                    break;
                }
                cout << "\n                  请输入需要删除的员工编号(输入0以展示全部, 输入-1返回上一界面): ";
                while (cin >> id)
                {
                    if (id == "-1") break;
                    else 
                    {
                        Delete_List_Things(pThings, id);
                        Delete_List_Employee(pHead, id);
                        flag = 0;
                    }
                    cout << "\n\n\n                  请输入需要删除的员工编号(输入0以展示全部, 输入-1返回上一界面): ";
                }
                break;
            case 3:
                Append_List_Employer(pHead);
                flag = 0;
                break;
            case 4:
                Change_Employ_List(pHead);
                flag = 0;
                break;
            case 5:
                Sort_Employee_Salary(pHead);
                break;
            case 6:
                system("cls");
                cout << "                  请输入需要查询的员工编号(输入-1返回上一界面): ";
                while (cin >> id)
                {
                    if (id == "-1") break;
                    else Eployee_Leaderid(pHead, id);
                    cout << "\n\n\n                  请输入需要查询的员工编号(输入-1或返回上一界面): ";
                }
                break;
            case 7:
                if (pThings != NULL) Save_Things_List(pThings);
                Save_Employee_List(pHead);
                flag = 1;
                break;
            case 0:
                if (!flag) 
                {
                    cout << "                  是否需要保存？(Y/n) ";
                    char tmp;
                    cin >> tmp;
                    if (tmp == 'Y' || tmp == 'y') 
                    {
                        if (pThings != NULL) Save_Things_List(pThings);
                        Save_Employee_List(pHead);
                    }
                }
                Create_Menu(pHead);
                return;
            default:
                cout << "                  请输入正确的序号！" << endl;
                Sleep(1000);
        }
    }
    return;
}

void Create_Menu_Things(ListNode* pHead)//建立事务桌面
{
    if (pHead == NULL) Create_Things_List(pHead);
    int flag = 1;
    while(1)
    {
        system("cls");
        cout << "\n                  员工事务操作:" << endl
            << endl
            << endl
            << "\n                  请输入请输入需要操作的任务序号:" << endl
            << "\n                      1.查询事务信息" << endl
            << "\n                      2.增加事务信息" << endl
            << "\n                      3.保存事务信息" << endl
            << "\n                      0.返回上一页" << endl
            << endl
            << endl
            << endl << "                  ";
        int choice;
        string id;
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("cls");
            if (pHead -> id == "") 
            {
                cin.ignore();
                cout << "\n                  当前没有事务！" << endl;
                getchar();
                break;
            }
            cout << "\n                  请输入需要查询的事务编号(输入0以展示全部, 输入-1返回上一界面): ";
            while (cin >> id)
            {
                if (id == "-1") break;
                else if (id == "0") Display_List(pHead);
                else 
                {
                    if (Search_Things_List(pHead, id) == NULL) cout << "\n                  查无此事！" << endl;
                }
                cout << "\n\n\n                  请输入需要查询的事务编号(输入0以展示全部, 输入-1返回上一界面): ";
            }
            break;
        case 2:
            Append_List_Things(pHead);
            flag = 0;
            break;
        case 3:
            Save_Things_List(pHead);
            flag = 1;
            Sleep(2000);
            break;
        case 0:
            if (!flag) 
            {
                cout << "                  是否需要保存？(Y/n) ";
                char tmp;
                cin >> tmp;
                if (tmp == 'Y' || tmp == 'y') 
                {
                    Save_Things_List(pHead);
                    Sleep(2000);
                    flag = 1;
                }
            }
            Create_Menu(pHead);
            return;
        default:
            cout << "                  请输入正确的序号！" << endl;
            Sleep(1000);
            Create_Menu_Things(pHead);
            return;
        }
    }
    return;
}

void Create_Employee_List(ListNode* &pHead)//创立链表
{
    ifstream Employee_File("employee.txt", ios::binary);
    pHead = new ListNode;
    pHead -> next = NULL;
    ListNode* p = pHead;
    while (1)
    {
        string tmp;
        getline(Employee_File, tmp);
        stringstream ss(tmp);
        ss >> p -> id;
        ss >> p -> name;
        ss >> p -> department;
        ss >> p -> salary;
        if (!ss.eof()) ss >> p -> leaderid;
        if (!Employee_File.eof())
        {
            ListNode* pNewNode = new ListNode;
            pNewNode -> next = NULL;
            p -> next = pNewNode;
            p = pNewNode;
        }
        else break;
    }
    Employee_File.close();
}

void Create_Things_List(ListNode* &pHead)//创立事务链表
{
    ifstream Things_File("things.txt", ios::binary);
    pHead = new ListNode;
    pHead -> next = NULL;
    ListNode* p = pHead;
    while (1)
    {
        string tmp;
        getline(Things_File, tmp);
        stringstream ss(tmp);
        ss >> p -> id;
        if (!ss.eof()) ss >> p -> things;
        if (!Things_File.eof())
        {
            ListNode* pNewNode = new ListNode;
            pNewNode -> next = NULL;
            p -> next = pNewNode;
            p = pNewNode;
        }
        else break;
    }
    Things_File.close();
}

void Destory_List(ListNode* &pHead)//删除链表
{
    assert(pHead != NULL);
    ListNode *pNext = pHead->next;
    while (pNext != NULL)
    {
        delete pHead;
        pHead = pNext;
        pNext = pHead->next;
    }
    delete pHead;
    pHead = NULL;
    return;
}

void Delete_List(ListNode* pHead)//删除pHead
{
    if (pHead -> next != NULL)
    {
        ListNode* pNext = pHead -> next;
        pHead -> id = pNext -> id;
        pHead -> name = pNext -> name;
        pHead -> department = pNext -> department;
        pHead -> salary = pNext -> salary;
        pHead -> leaderid = pNext -> leaderid;
        pHead -> next = pNext -> next;
        delete pNext;
    }
    else pHead -> id = "-1";
    return;
}

ListNode* Search_Employee_List(ListNode* pHead, string id)//搜索员工序号
{
    system("cls");
    int flag = 1;
    ListNode* re = pHead;
    while (pHead != NULL)
    {
        if (id == pHead -> id) 
        {
            cout << "\n                  员工序号： " << pHead -> id << "\n                  员工姓名：" << pHead -> name << "\n                  员工部门：" << pHead -> department;
            if (pHead -> salary != -1) cout << "\n                  员工薪资：" << pHead -> salary;
            if (pHead -> leaderid == "-1") cout << endl;
            else cout << "\n                  员工领导编号：" << pHead -> leaderid << endl;
            break;
        }
        else if(id == pHead -> name)
        {
            cout << "\n                  员工序号： " << pHead -> id << "\n                  员工姓名：" << pHead -> name << "\n                  员工部门：" << pHead -> department;
            if (pHead -> salary != -1) cout << "\n                  员工薪资：" << pHead -> salary;
            if (pHead -> leaderid == "-1") cout << endl;
            else cout << "\n                  员工领导编号：" << pHead -> leaderid << endl;
            break;
        }
        else if(id == pHead -> department)
        {
            flag = 0;
            cout << "\n                  员工序号： " << pHead -> id << "\n                  员工姓名：" << pHead -> name << "\n                  员工部门：" << pHead -> department;
            if (pHead -> salary != -1) cout << "\n                  员工薪资：" << pHead -> salary;
            if (pHead -> leaderid == "-1") cout << endl;
            else cout << "\n                  员工领导编号：" << pHead -> leaderid << endl;
            cout << "                  -----------------------------------------------------" << endl;
        }
        pHead = pHead -> next;
    }
    if (flag) return pHead;
    else return re;
}

void Display_List(ListNode* pHead)
{
    system("cls");
    while(pHead != NULL)
    {
        if (pHead -> id != "-1" && pHead -> leaderid != "\r")
        {
            cout << "\n                  员工编号：" << pHead -> id;
            if (pHead -> name != "") cout << "\n                  员工姓名：" << pHead -> name;
            if (pHead -> department != "") cout << "\n                  员工部门：" << pHead -> department;
            if (pHead -> things != "") cout << "\n                  员工事务：" << pHead -> things; 
            if (pHead -> salary != -1) cout << "\n                  员工薪资：" << pHead -> salary;
            if (pHead -> leaderid == "-1") cout << endl;
            else cout << "\n                  员工领导序号：" << pHead -> leaderid << endl;
            cout << "                  -----------------------------------------------------" << endl;
        }
        pHead = pHead -> next;
    }
    return;
}

void Delete_List_Employee(ListNode* &pHead, string id)//删除员工序号
{
    system("cls");
    ListNode* ptmp = pHead;
    if (id == "0") Display_List(ptmp);
    else 
    {
        ptmp = Search_Employee_List(ptmp, id);
        if (ptmp == NULL) cout << "\n                  查无此人！";
        else if (ptmp == pHead) 
        {
            pHead = ptmp -> next;
            delete ptmp;
            cout << "\n                  已删除该员工信息！\n";
        }
        else 
        {
            Delete_List(ptmp);
            cout << "\n                  已删除该员工信息！\n";
        }
    }
}

void Append_List_Employer(ListNode* pHead)
{
    system("cls");
    cout << "\n                  请输入新增员工的信息: (编号 姓名 部门 薪水 直属领导编号（可选）)" << endl << "                  ";
    string str;
    cin.ignore();
    while (getline(cin, str))
    {
        system("cls");
        stringstream ss(str); 
        int flag = 0, tmp_salary = -1;
        string tmp_id, tmp_name = "", tmp_department = "", tmp_leaderid = "-1";
        ss >> tmp_id;
        if (tmp_id == "-1" || (tmp_id >= "a" && tmp_id <= "z") || (tmp_id >= "A" && tmp_id <= "Z") || tmp_id == "") return;
        ListNode* ptmp = pHead, *p_end;
        while (ptmp != NULL) 
        {
            if (ptmp -> id == tmp_id)
            {
                cout << "\n                  已存在编号为" << tmp_id << "的员工，请重新输入！\n";
                Sleep(1500);
                system("cls");
                cout << "\n                  请输入新增员工的信息: (编号 姓名 部门 薪水 直属领导编号（可选）)" << endl << "                  ";
                flag = 1;
                break;
            }
            p_end = ptmp;
            ptmp = ptmp -> next;
        }
        if (flag) continue;
        ptmp = p_end;
        if (!ss.eof()) ss >> tmp_name;
        if (!ss.eof()) ss >> tmp_department;
        if (!ss.eof()) ss >> tmp_salary;
        if (!ss.eof()) ss >> tmp_leaderid;
        if (tmp_leaderid == tmp_id) 
        {
            cout << "                  领导关系错误！请重新输入！" << endl;
            Sleep(2000);
            system("cls");
            cout << "                  请输入新增员工的信息: (编号 姓名 部门 薪水 直属领导编号（可选）)" << endl << "                  ";
            continue;
        }
        ListNode* pNew = new ListNode;
        pNew -> next = NULL;
        ptmp -> next = pNew;
        ptmp = pHead;
        pNew -> id = tmp_id;
        pNew -> name = tmp_name;
        pNew -> department = tmp_department;
        pNew -> salary = tmp_salary;
        pNew -> leaderid = tmp_leaderid;
        if (pNew -> id != "") cout << "\n                  员工序号： " << pNew -> id;
        if (pNew -> name != "") cout << "\n                  员工姓名：" << pNew -> name;
        if (pNew -> department != "") cout << "\n                  员工部门：" << pNew -> department;
        if (pNew -> salary != -1) cout << "\n                  员工薪资：" << pNew -> salary;
        if (pNew -> leaderid != "-1") cout << "\n                  员工领导序号" << pNew -> leaderid;
        cout << "\n\n\n                  增加完毕！\n                  输入-1返回上一界面或继续录入员工信息(编号 姓名 部门 薪水 直属领导编号（可选）)..." << endl << "                  ";
    }
}

void Sort_Employee_Salary(ListNode* pHead)
{
    system("cls");
    cin.ignore();
    int salary[500], len = 0;
    ListNode* ptmp = pHead;
    while (ptmp != NULL)
    {
        salary[len++] = ptmp -> salary;
        ptmp = ptmp -> next;
    }
    sort(salary, salary + len);
    ptmp = pHead;
    for (int i = len - 1; i >= 0; --i)
    {
        while (ptmp != NULL)
        {
            if (salary[i] == ptmp -> salary)
            {
                if (ptmp-> id != "-1") cout << "\n                  员工序号： " << ptmp -> id;
                else 
                {
                    ptmp = ptmp -> next;
                    continue;
                }
                if (ptmp -> name != "") cout << "\n                  员工姓名：" << ptmp -> name;
                if (ptmp -> department != "") cout << "\n                  员工部门：" << ptmp -> department;
                if (ptmp -> salary != -1) cout << "\n                  员工薪资：" << ptmp -> salary;
                if (ptmp -> leaderid != "-1") cout << "\n                  员工领导序号：" << ptmp -> leaderid;
                cout << "\n                  -----------------------------------------------------\n";
                ptmp = pHead;
                break;
            }
            ptmp = ptmp -> next;
        }
    }
    cout << "\n\n\n                  输入任意键返回上一界面...";
    getchar();
    return;    
}

void Eployee_Leaderid(ListNode* pHead, string id)
{
    system("cls");
    ListNode* ptmp = pHead;
    ListNode* pNewList_forward = NULL,* pNLHead = NULL;
    int flag = 1;
    while (ptmp != NULL)
    {
        if (id == ptmp -> id) 
        {
            if (id == "-1") break;
            ListNode* pNewList = NULL;
            pNewList = new ListNode;
            pNewList -> next = NULL;
            if (flag)
            {
                flag = 0;
                pNLHead = pNewList;
            }
            if (pNewList_forward != NULL) pNewList_forward -> next = pNewList;
            pNewList -> id = ptmp -> id;
            pNewList -> name = ptmp -> name;
            pNewList -> department = ptmp -> department;
            pNewList -> salary = ptmp -> salary;
            pNewList -> leaderid = ptmp -> leaderid;
            id = ptmp -> leaderid;
            ptmp = pHead;
            pNewList_forward = pNewList;
        }
        else ptmp = ptmp -> next;
    }
    if (pNLHead == NULL) 
    {
        cout << "\n                  查无此人！" << endl;
        Sleep(1000);
    }
    else if (pNLHead -> next == NULL)
    {
        cout << "\n                  员工序号：" << pNLHead -> id << "\n                  员工姓名：" << pNLHead -> name << "\n                  员工部门：" << pNLHead -> department << "\n                  员工薪资：" << pNLHead -> salary;
        cout << "\n                  该员工没有直属领导！" << endl;
    }
    else
    {
        Display_List(pNLHead);
        Destory_List(pNLHead);
    }
    return;
}

void Change_Employ_List(ListNode* pHead)
{
    system("cls");
    cin.ignore();
    cout << "\n                  请输入需要修改的员工序号(输入-1退出): ";
    string str;
    while (getline(cin, str))
    {
        stringstream ss(str);
        ss >> str;
        if (str == "-1") break;
        cout <<"\n\n";
        ListNode* pChange = Search_Employee_List(pHead, str);
        if (pChange == NULL)
        {
            cout << "\n                  查无此人！";
            Sleep(1000);
            system("cls");
            cout << "\n                  请输入需要修改的员工序号(输入-1退出): ";
            continue;
        }
        cout << "\n                  请输入修改后的员工名字: ";
        cin >> pChange -> name;
        cout << "\n                  请输入修改后的员工部门: ";
        cin >> pChange -> department;
        cout << "\n                  请输入修改后的员工薪水: ";
        cin >> pChange -> salary;
        cout << "\n                  请输入修改后的员工直系领导: ";
        cin >> pChange -> leaderid;
        Sleep(500);
        cout << "\n\n                  修改完毕！";
        cin.ignore();
        Sleep(2000);
        system("cls");
        cout << "\n                  请输入需要修改的员工序号(输入-1退出): ";
    }
    return;
}

void Save_Employee_List(ListNode* pHead)
{
    ofstream Employee_File("employee.txt", ios::binary);
    Display_List(pHead);
    while(pHead != NULL)
    {
        if (pHead -> id != "-1")
        {
            Employee_File << pHead -> id << " " << pHead -> name << " " << pHead -> department;
            if (pHead -> salary != -1) Employee_File << " " << pHead -> salary;
            if (pHead -> leaderid != "-1") Employee_File << " " << pHead -> leaderid;
            if (pHead -> next != NULL && pHead -> next -> id != "-1") Employee_File << endl;
        }
        pHead = pHead -> next;
    }
    cout << "\n\n\n                  保存完毕！" << endl;
    Sleep(2000);
    return;
}

ListNode* Search_Things_List(ListNode* pHead, string id)//搜索事务序号
{
    system("cls");
    int flag = 0;
    ListNode* re = NULL, *pRe;
    while (pHead != NULL)
    {
        if (id == pHead -> id) 
        {
            cout << "\n                  员工序号：" << pHead -> id 
                 << "\n                  员工事务：" << pHead -> things 
                 << "\n                  -----------------------------------------------------";
            pRe = pHead;
            flag = 1;
        }
        pHead = pHead -> next;
    }
    if (flag) return pRe;
    else return re;
}

void Delete_List_Things(ListNode* &pHead, string id)//删除事务序号
{
    ListNode* ptmp = pHead;
    while (ptmp != NULL)
    {
        if (ptmp -> id == id && ptmp == pHead) 
        {
            pHead = ptmp -> next;
            delete ptmp;
        }
        else if (ptmp -> id == id) Delete_List(ptmp);
        ptmp = ptmp -> next;
    }
}

void Append_List_Things(ListNode* pHead)
{
    system("cls");
    cout << "\n                  请输入新增事务的信息: (编号 事务)" << endl << "                  ";
    string str;
    cin.ignore();
    while (getline(cin, str))
    {
        system("cls");
        ListNode* ptmp = pHead;
        stringstream ss(str); 
        string tmp_id, tmp_things;
        ss >> tmp_id;
        if (tmp_id == "-1" || (tmp_id >= "a" && tmp_id <= "z") || (tmp_id >= "A" && tmp_id <= "Z")) return;
        if (!ss.eof()) ss >> tmp_things;
        else 
        {
            cout << "\n                  请输入正确的员工事务！" << endl;
            Sleep(1000);
            system("cls");
            cout << "\n                  请输入新增事务的信息: (编号 事务)" << endl;
            continue;
        }
        while (ptmp -> next != NULL) ptmp = ptmp -> next;
        ListNode* pNew = new ListNode;
        pNew -> next = NULL;
        ptmp -> next = pNew;
        ptmp = pHead;
        pNew -> id = tmp_id;
        pNew -> things = tmp_things;
        cout << "\n                  员工序号：" << tmp_id 
             << "\n                  员工事务：" << tmp_things 
             << "\n                  -----------------------------------------------------";
        cout << "\n\n\n                  增加完毕!"
             << endl << "                  输入-1返回上一界面或继续录入员工事务(编号 事务)..." 
             << endl << "                  ";
    }
}

void Save_Things_List(ListNode* pHead)
{
    ofstream Things_File("things.txt", ios::binary);
    Display_List(pHead);
    while(pHead != NULL)
    {
        if (pHead -> id != "-1")
        {
            Things_File << pHead -> id << " " << pHead -> things;
            if (pHead -> next != NULL && pHead -> next -> id != "-1") Things_File << endl;
        }
        pHead = pHead -> next;
    }
    cout << "\n\n\n                  保存完毕！" << endl;
    return;
}

/****************************************************<fun def end>***************************************************/

int main()
{
    ListNode* pHead = NULL;
    Create_Menu(pHead);
    return 0;
}