/******************************************************************************************************************   
 *  �ļ�����: ��ҵ����ϵͳ   
 *  ��������: 2021.10.28
 *  ����: ��ŵ
 *   
 *  �޸�����: 
 *  ����: 
 *  ˵��: 
 *****************************************************************************************************************/

/****************************************************<include>****************************************************/
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

/************************************************<global var start>************************************************/
struct ListNode
{
    string id = "";//Ա�����
    string name = "";//Ա������
    string department = "";//Ա������
    int salary = -1;//Ա��н��
    string leaderid = "-1";//Ա���쵼���
    string things = "";//Ա������
    ListNode *next;
};

/*************************************************<global var end>*************************************************/



/*************************************************<fun void begin>*************************************************/
/*�ڿ���̨��������ܲ˵�:
    1.��ѯԱ����Ϣ
    2.��ѯ������Ϣ
    0.�˳�ϵͳ*/
void Create_Menu(ListNode* &pHead);

/*�ڿ���̨�������Ա���˵�:
    1.��ѯԱ����Ϣ
    2.ɾ��Ա����Ϣ
    3.����Ա����Ϣ
    4.�޸�Ա����Ϣ
    5.Ա������
    6.����㼶˳���ѯ
    7.����Ա����Ϣ
    0.������һҳ*/
void Create_Menu_Employee(ListNode* pHead);

/*�ڿ���̨�����������˵�:
    1.��ѯ������Ϣ
    2.����������Ϣ
    3.����������Ϣ
    0.������һҳ*/
void Create_Menu_Things(ListNode* pHead);

//��ȡ������Ա����Ϣ����
void Create_Employee_List(ListNode* &pHead);

//��ȡ������Ա����Ϣ����
void Create_Things_List(ListNode* &pHead);

//��������
void Destory_List(ListNode* &pHead);

//ɾ��pHeadָ�������ڵ�
void Delete_List(ListNode* pHead);

/*
����Ա���ı�ţ������벿�Ų�ѯԱ����Ϣ
�������壻
    ��ʾ�û���������ѯ��Ա����ţ���������
    ������ڣ������Ա����Ϣ
    ��������ڣ�����NULL*/
ListNode* Search_Employee_List(ListNode* pHead, string id);

//�ڿ���̨�������ǰ�����������Ϣ
void Display_List(ListNode* pHead);

/*
����Ա�����ɾ��Ա����Ϣ
�������壻
    ��ʾ�û���������ѯ��Ա�����
    ������ڣ������ɾ����Ա����Ϣ��������Ϣ
    ��������ڣ���������޴��ˣ���*/
void Delete_List_Employee(ListNode* &pHead, string id);

/*
����Ա����Ϣ
�������壺
    ��ʾԱ��������Ҫ���ӵ�Ա����ţ����������ţ�н�����쵼��ϵ
    ��������ͬ��ŵ�Ա�����ڣ���ʾ���Ѵ��ڱ��ΪX��Ա������
    �����쵼ָ��������ʾ���쵼��ϵ���󣡡�*/
void Append_List_Employer(ListNode* pHead);

/*
��ѯ�쵼�㼶��ϵ
�������壺
    ��ʾ������Ҫ��ѯ��Ա����ţ����������쵼���ָ���Ա��
    ����ѯ��Ա���������쵼����ʾ����Ա��û��ֱϵ�쵼����*/
void Eployee_Leaderid(ListNode* pHead, string id);

/*
��Ա��н������
�������壺
    ���������ȡȫ��Ա��н�ʲ������ɸߵ��������ٰ���н�������̨���������*/
void Sort_Employee_Salary(ListNode* pHead);

/*
�޸�Ա����Ϣ
�������壻
    ��ʾ�û�������Ҫ�޸ĵ�Ա����ţ�������������������ţ�н�ʣ�ֱϵ�쵼��
    ������ڣ��޸�Ա����Ϣ
    ��������ڣ���������޴��ˣ���*/
void Change_Employ_List(ListNode* pHead);

//����Ա����Ϣ�����ļ�
void Save_Employee_List(ListNode* pHead);

/*
����Ա���ı�Ų�ѯԱ������
�������壻
    ��ʾ�û���������ѯ��Ա�����
    ������ڣ����������Ա������
    ��������ڣ�����NULL*/
ListNode* Search_Things_List(ListNode* pHead, string id);

/*
����Ա�����ɾ��Ա������
�������壻
    ��ʾ�û���������ѯ��Ա�����
    ������ڣ�ɾ����������Ϣ*/
void Delete_List_Things(ListNode* &pHead, string id);

/*
����������Ϣ
�������壺
    ��ʾԱ��������Ҫ���ӵ�Ա�������������Ϣ*/
void Append_List_Things(ListNode* pHead);

//����������Ϣ�����ļ�
void Save_Things_List(ListNode* pHead);

/***************************************************<fun void end>**************************************************/

/***************************************************<fun def begin>*************************************************/
void Create_Menu(ListNode* &pHead)//��������
{
    system("cls");
    if (pHead != NULL) 
    {
        Destory_List(pHead);
        pHead = NULL;
    }
    cout << "\n\n\n"
         << "              ********************************************************************************************" << endl
         << "              *                                    ��ҵ����ϵͳ                                          *" << endl
         << "              ********************************************************************************************" << endl
         << endl
         << endl
         << endl
         << endl
         << "              ��������Ҫ�������ļ����:\n" << endl
         << "                  1.��ѯԱ����Ϣ\n" << endl
         << "                  2.��ѯ������Ϣ\n" << endl
         << "                  0.�˳�ϵͳ"
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
             << "       *************************************** ллʹ�ã�****************************************\n"
             << "       ******************************************************************************************\n"
             << "       ******************************************************************************************";
        Sleep(5000);
        return;
    }
    else
    {
        cout << "                  ��������ȷ����ţ�" << endl;
        Sleep(1000);
        Create_Menu(pHead);
        return;
    }
}

void Create_Menu_Employee(ListNode* pHead)//����Ա������
{
    ListNode* pThings = NULL;
    if (pHead == NULL) Create_Employee_List(pHead);
    int flag = 1;
    while(1)
    {
        system("cls");
        cout << "\n                  Ա����Ϣ����:" << endl
             << endl
             << endl
             << "                  ��������������Ҫ�������������:" << endl
             << "                      1.��ѯԱ����Ϣ" << endl
             << "                      2.ɾ��Ա����Ϣ" << endl
             << "                      3.����Ա����Ϣ" << endl
             << "                      4.�޸�Ա����Ϣ" << endl
             << "                      5.Ա������" << endl
             << "                      6.����㼶˳���ѯ" << endl
             << "                      7.����Ա����Ϣ" << endl
             << "                      0.������һҳ" << endl
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
                    cout << "\n                  ��ǰû��Ա����" << endl;
                    getchar();
                    break;
                }
                cout << "\n                  ��������Ҫ��ѯ��Ա�����,��������(����0��չʾȫ��, ����-1������һ����): ";
                while (cin >> id)
                {
                    if (id == "-1") break;
                    else if (id == "0") Display_List(pHead);
                    else 
                    {
                        if (Search_Employee_List(pHead, id) == NULL) cout << "\n                  ���޴��ˣ�" << endl;
                    }
                    cout << "\n\n\n                  ��������Ҫ��ѯ��Ա�����,��������(����0��չʾȫ��, ����-1������һ����): ";
                }
                break;
            case 2:
                system("cls");
                Create_Things_List(pThings);
                if (pHead == NULL) 
                {
                    cin.ignore();
                    cout << "\n                  ��ǰû��Ա����" << endl;
                    getchar();
                    break;
                }
                cout << "\n                  ��������Ҫɾ����Ա�����(����0��չʾȫ��, ����-1������һ����): ";
                while (cin >> id)
                {
                    if (id == "-1") break;
                    else 
                    {
                        Delete_List_Things(pThings, id);
                        Delete_List_Employee(pHead, id);
                        flag = 0;
                    }
                    cout << "\n\n\n                  ��������Ҫɾ����Ա�����(����0��չʾȫ��, ����-1������һ����): ";
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
                cout << "                  ��������Ҫ��ѯ��Ա�����(����-1������һ����): ";
                while (cin >> id)
                {
                    if (id == "-1") break;
                    else Eployee_Leaderid(pHead, id);
                    cout << "\n\n\n                  ��������Ҫ��ѯ��Ա�����(����-1�򷵻���һ����): ";
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
                    cout << "                  �Ƿ���Ҫ���棿(Y/n) ";
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
                cout << "                  ��������ȷ����ţ�" << endl;
                Sleep(1000);
        }
    }
    return;
}

void Create_Menu_Things(ListNode* pHead)//������������
{
    if (pHead == NULL) Create_Things_List(pHead);
    int flag = 1;
    while(1)
    {
        system("cls");
        cout << "\n                  Ա���������:" << endl
            << endl
            << endl
            << "\n                  ��������������Ҫ�������������:" << endl
            << "\n                      1.��ѯ������Ϣ" << endl
            << "\n                      2.����������Ϣ" << endl
            << "\n                      3.����������Ϣ" << endl
            << "\n                      0.������һҳ" << endl
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
                cout << "\n                  ��ǰû������" << endl;
                getchar();
                break;
            }
            cout << "\n                  ��������Ҫ��ѯ��������(����0��չʾȫ��, ����-1������һ����): ";
            while (cin >> id)
            {
                if (id == "-1") break;
                else if (id == "0") Display_List(pHead);
                else 
                {
                    if (Search_Things_List(pHead, id) == NULL) cout << "\n                  ���޴��£�" << endl;
                }
                cout << "\n\n\n                  ��������Ҫ��ѯ��������(����0��չʾȫ��, ����-1������һ����): ";
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
                cout << "                  �Ƿ���Ҫ���棿(Y/n) ";
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
            cout << "                  ��������ȷ����ţ�" << endl;
            Sleep(1000);
            Create_Menu_Things(pHead);
            return;
        }
    }
    return;
}

void Create_Employee_List(ListNode* &pHead)//��������
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

void Create_Things_List(ListNode* &pHead)//������������
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

void Destory_List(ListNode* &pHead)//ɾ������
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

void Delete_List(ListNode* pHead)//ɾ��pHead
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

ListNode* Search_Employee_List(ListNode* pHead, string id)//����Ա�����
{
    system("cls");
    int flag = 1;
    ListNode* re = pHead;
    while (pHead != NULL)
    {
        if (id == pHead -> id) 
        {
            cout << "\n                  Ա����ţ� " << pHead -> id << "\n                  Ա��������" << pHead -> name << "\n                  Ա�����ţ�" << pHead -> department;
            if (pHead -> salary != -1) cout << "\n                  Ա��н�ʣ�" << pHead -> salary;
            if (pHead -> leaderid == "-1") cout << endl;
            else cout << "\n                  Ա���쵼��ţ�" << pHead -> leaderid << endl;
            break;
        }
        else if(id == pHead -> name)
        {
            cout << "\n                  Ա����ţ� " << pHead -> id << "\n                  Ա��������" << pHead -> name << "\n                  Ա�����ţ�" << pHead -> department;
            if (pHead -> salary != -1) cout << "\n                  Ա��н�ʣ�" << pHead -> salary;
            if (pHead -> leaderid == "-1") cout << endl;
            else cout << "\n                  Ա���쵼��ţ�" << pHead -> leaderid << endl;
            break;
        }
        else if(id == pHead -> department)
        {
            flag = 0;
            cout << "\n                  Ա����ţ� " << pHead -> id << "\n                  Ա��������" << pHead -> name << "\n                  Ա�����ţ�" << pHead -> department;
            if (pHead -> salary != -1) cout << "\n                  Ա��н�ʣ�" << pHead -> salary;
            if (pHead -> leaderid == "-1") cout << endl;
            else cout << "\n                  Ա���쵼��ţ�" << pHead -> leaderid << endl;
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
            cout << "\n                  Ա����ţ�" << pHead -> id;
            if (pHead -> name != "") cout << "\n                  Ա��������" << pHead -> name;
            if (pHead -> department != "") cout << "\n                  Ա�����ţ�" << pHead -> department;
            if (pHead -> things != "") cout << "\n                  Ա������" << pHead -> things; 
            if (pHead -> salary != -1) cout << "\n                  Ա��н�ʣ�" << pHead -> salary;
            if (pHead -> leaderid == "-1") cout << endl;
            else cout << "\n                  Ա���쵼��ţ�" << pHead -> leaderid << endl;
            cout << "                  -----------------------------------------------------" << endl;
        }
        pHead = pHead -> next;
    }
    return;
}

void Delete_List_Employee(ListNode* &pHead, string id)//ɾ��Ա�����
{
    system("cls");
    ListNode* ptmp = pHead;
    if (id == "0") Display_List(ptmp);
    else 
    {
        ptmp = Search_Employee_List(ptmp, id);
        if (ptmp == NULL) cout << "\n                  ���޴��ˣ�";
        else if (ptmp == pHead) 
        {
            pHead = ptmp -> next;
            delete ptmp;
            cout << "\n                  ��ɾ����Ա����Ϣ��\n";
        }
        else 
        {
            Delete_List(ptmp);
            cout << "\n                  ��ɾ����Ա����Ϣ��\n";
        }
    }
}

void Append_List_Employer(ListNode* pHead)
{
    system("cls");
    cout << "\n                  ����������Ա������Ϣ: (��� ���� ���� нˮ ֱ���쵼��ţ���ѡ��)" << endl << "                  ";
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
                cout << "\n                  �Ѵ��ڱ��Ϊ" << tmp_id << "��Ա�������������룡\n";
                Sleep(1500);
                system("cls");
                cout << "\n                  ����������Ա������Ϣ: (��� ���� ���� нˮ ֱ���쵼��ţ���ѡ��)" << endl << "                  ";
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
            cout << "                  �쵼��ϵ�������������룡" << endl;
            Sleep(2000);
            system("cls");
            cout << "                  ����������Ա������Ϣ: (��� ���� ���� нˮ ֱ���쵼��ţ���ѡ��)" << endl << "                  ";
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
        if (pNew -> id != "") cout << "\n                  Ա����ţ� " << pNew -> id;
        if (pNew -> name != "") cout << "\n                  Ա��������" << pNew -> name;
        if (pNew -> department != "") cout << "\n                  Ա�����ţ�" << pNew -> department;
        if (pNew -> salary != -1) cout << "\n                  Ա��н�ʣ�" << pNew -> salary;
        if (pNew -> leaderid != "-1") cout << "\n                  Ա���쵼���" << pNew -> leaderid;
        cout << "\n\n\n                  ������ϣ�\n                  ����-1������һ��������¼��Ա����Ϣ(��� ���� ���� нˮ ֱ���쵼��ţ���ѡ��)..." << endl << "                  ";
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
                if (ptmp-> id != "-1") cout << "\n                  Ա����ţ� " << ptmp -> id;
                else 
                {
                    ptmp = ptmp -> next;
                    continue;
                }
                if (ptmp -> name != "") cout << "\n                  Ա��������" << ptmp -> name;
                if (ptmp -> department != "") cout << "\n                  Ա�����ţ�" << ptmp -> department;
                if (ptmp -> salary != -1) cout << "\n                  Ա��н�ʣ�" << ptmp -> salary;
                if (ptmp -> leaderid != "-1") cout << "\n                  Ա���쵼��ţ�" << ptmp -> leaderid;
                cout << "\n                  -----------------------------------------------------\n";
                ptmp = pHead;
                break;
            }
            ptmp = ptmp -> next;
        }
    }
    cout << "\n\n\n                  ���������������һ����...";
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
        cout << "\n                  ���޴��ˣ�" << endl;
        Sleep(1000);
    }
    else if (pNLHead -> next == NULL)
    {
        cout << "\n                  Ա����ţ�" << pNLHead -> id << "\n                  Ա��������" << pNLHead -> name << "\n                  Ա�����ţ�" << pNLHead -> department << "\n                  Ա��н�ʣ�" << pNLHead -> salary;
        cout << "\n                  ��Ա��û��ֱ���쵼��" << endl;
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
    cout << "\n                  ��������Ҫ�޸ĵ�Ա�����(����-1�˳�): ";
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
            cout << "\n                  ���޴��ˣ�";
            Sleep(1000);
            system("cls");
            cout << "\n                  ��������Ҫ�޸ĵ�Ա�����(����-1�˳�): ";
            continue;
        }
        cout << "\n                  �������޸ĺ��Ա������: ";
        cin >> pChange -> name;
        cout << "\n                  �������޸ĺ��Ա������: ";
        cin >> pChange -> department;
        cout << "\n                  �������޸ĺ��Ա��нˮ: ";
        cin >> pChange -> salary;
        cout << "\n                  �������޸ĺ��Ա��ֱϵ�쵼: ";
        cin >> pChange -> leaderid;
        Sleep(500);
        cout << "\n\n                  �޸���ϣ�";
        cin.ignore();
        Sleep(2000);
        system("cls");
        cout << "\n                  ��������Ҫ�޸ĵ�Ա�����(����-1�˳�): ";
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
    cout << "\n\n\n                  ������ϣ�" << endl;
    Sleep(2000);
    return;
}

ListNode* Search_Things_List(ListNode* pHead, string id)//�����������
{
    system("cls");
    int flag = 0;
    ListNode* re = NULL, *pRe;
    while (pHead != NULL)
    {
        if (id == pHead -> id) 
        {
            cout << "\n                  Ա����ţ�" << pHead -> id 
                 << "\n                  Ա������" << pHead -> things 
                 << "\n                  -----------------------------------------------------";
            pRe = pHead;
            flag = 1;
        }
        pHead = pHead -> next;
    }
    if (flag) return pRe;
    else return re;
}

void Delete_List_Things(ListNode* &pHead, string id)//ɾ���������
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
    cout << "\n                  �����������������Ϣ: (��� ����)" << endl << "                  ";
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
            cout << "\n                  ��������ȷ��Ա������" << endl;
            Sleep(1000);
            system("cls");
            cout << "\n                  �����������������Ϣ: (��� ����)" << endl;
            continue;
        }
        while (ptmp -> next != NULL) ptmp = ptmp -> next;
        ListNode* pNew = new ListNode;
        pNew -> next = NULL;
        ptmp -> next = pNew;
        ptmp = pHead;
        pNew -> id = tmp_id;
        pNew -> things = tmp_things;
        cout << "\n                  Ա����ţ�" << tmp_id 
             << "\n                  Ա������" << tmp_things 
             << "\n                  -----------------------------------------------------";
        cout << "\n\n\n                  �������!"
             << endl << "                  ����-1������һ��������¼��Ա������(��� ����)..." 
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
    cout << "\n\n\n                  ������ϣ�" << endl;
    return;
}

/****************************************************<fun def end>***************************************************/

int main()
{
    ListNode* pHead = NULL;
    Create_Menu(pHead);
    return 0;
}