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
    string id = "";
    string name = "";
    string department = "";
    int salary = -1;
    string leaderid = "-1";
    string things = "";
    ListNode *next;
};

/*************************************************<global var end>*************************************************/



/*************************************************<fun void begin>*************************************************/
void Create_Menu(ListNode* &pHead);
void Create_Menu_Employee(ListNode* pHead);
void Create_Menu_Things(ListNode* pHead);
void Create_Employee_List(ListNode* &pHead);
void Create_Things_List(ListNode* &pHead);
void Destory_List(ListNode *pHead);
ListNode* Insert_List(ListNode* pHead);
void Delete_List(ListNode* pHead);
ListNode* Search_Employee_List(ListNode* pHead, string id);
void Display_List(ListNode* pHead);
void Delete_List_Employee(ListNode* &pHead, string id);
void Append_List_Employer(ListNode* pHead);
string Eployee_Leaderid(ListNode* pHead, string id);
void Sort_Employee_Salary(ListNode* pHead);
void Change_Employ_List(ListNode* pHead);
void Save_Employee_List(ListNode* pHead);
ListNode* Search_Things_List(ListNode* pHead, string id);
void Delete_List_Things(ListNode* &pHead, string id);
void Append_List_Things(ListNode* pHead);
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
    cout << "       ********************************************************************************************" << endl
         << "       *                                    ��ҵ����ϵͳ                                          *" << endl
         << "       ********************************************************************************************" << endl
         << endl
         << endl
         << endl
         << endl
         << "��������Ҫ�������ļ����:" << endl
         << "1.��ѯԱ����Ϣ" << endl
         << "2.��ѯ������Ϣ" << endl
         << "0.�˳�ϵͳ"
         << endl
         << endl
         << endl;
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
             << "       ****************************************ллʹ�ã�****************************************";
        Sleep(5000);
        return;
    }
    else
    {
        cout << "��������ȷ����ţ�" << endl;
        Sleep(1000);
        Create_Menu(pHead);
        return;
    }
}

void Create_Menu_Employee(ListNode* pHead)//����Ա������
{
    ListNode* pThings = NULL;
    if (pHead == NULL) Create_Employee_List(pHead);
    while(1)
    {
        system("cls");
        cout << "Ա����Ϣ����:" << endl
            << endl
            << endl
            << "��������������Ҫ�������������:" << endl
            << "1.��ѯԱ����Ϣ" << endl
            << "2.ɾ��Ա����Ϣ" << endl
            << "3.����Ա����Ϣ" << endl
            << "4.�޸�Ա����Ϣ" << endl
            << "5.Ա������" << endl
            << "6.����㼶˳���ѯ" << endl
            << "7.����Ա����Ϣ" << endl
            << "0.������һҳ" << endl
            << endl
            << endl
            << endl;
        int choice, flag = 1;
        string id;
        cin >> choice;
        switch (choice)
        {
            case 1:
                system("cls");
                if (pHead == NULL) 
                {
                    cin.ignore();
                    cout << "��ǰû��Ա����" << endl;
                    getchar();
                    break;
                }
                cout << "��������Ҫ��ѯ��Ա�����,��������(����0��չʾȫ��, ����-1������һ����): ";
                while (cin >> id)
                {
                    if (id == "-1") break;
                    else if (id == "0") Display_List(pHead);
                    else 
                    {
                        if (Search_Employee_List(pHead, id) == NULL) cout << "���޴��ˣ�" << endl;
                    }
                    cout << "\n\n\n��������Ҫ��ѯ��Ա�����,��������(����0��չʾȫ��, ����-1������һ����): ";
                }
                break;
            case 2:
                system("cls");
                Create_Things_List(pThings);
                if (pHead == NULL) 
                {
                    cin.ignore();
                    cout << "��ǰû��Ա����" << endl;
                    getchar();
                    break;
                }
                cout << "��������Ҫɾ����Ա�����(����0��չʾȫ��, ����-1������һ����): ";
                while (cin >> id)
                {
                    if (id == "-1") break;
                    else 
                    {
                        Delete_List_Things(pThings, id);
                        Delete_List_Employee(pHead, id);
                        // Display_List(pThings);
                        flag = 0;
                    }
                    cout << "\n\n\n��������Ҫɾ����Ա�����(����0��չʾȫ��, ����-1������һ����): ";
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
                cout << "��������Ҫ��ѯ��Ա�����(����-1������һ����): ";
                while (cin >> id)
                {
                    if (id == "-1") break;
                    else Eployee_Leaderid(pHead, id);
                    cout << "\n\n\n��������Ҫ��ѯ��Ա�����(����-1�򷵻���һ����): ";
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
                    cout << "�Ƿ���Ҫ���棿(Y/n) ";
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
                cout << "��������ȷ����ţ�" << endl;
                Sleep(1000);
        }
    }
    return;
}

void Create_Menu_Things(ListNode* pHead)//������������
{
    system("cls");
    if (pHead == NULL) Create_Things_List(pHead);
    // cout << pHead << endl;
    cout << "Ա���������:" << endl
         << endl
         << endl
         << "��������������Ҫ�������������:" << endl
         << "1.��ѯ������Ϣ" << endl
         << "2.����������Ϣ" << endl
         << "3.ɾ��������Ϣ" << endl
         << "4.����������Ϣ" << endl
         << "0.������һҳ" << endl
         << endl
         << endl
         << endl;
    int choice, flag = 0;
    string id;
    cin >> choice;
    switch (choice)
    {
    case 1:
        system("cls");
        if (pHead == NULL) 
        {
            cin.ignore();
            cout << "��ǰû������" << endl;
            getchar();
            break;
        }
        cout << "��������Ҫ��ѯ��������(����0��չʾȫ��, ����-1������һ����): ";
        while (cin >> id)
        {
            if (id == "-1") break;
            else if (id == "0") Display_List(pHead);
            else 
            {
                if (Search_Things_List(pHead, id) == NULL) cout << "���޴��£�" << endl;
            }
            cout << "\n\n\n��������Ҫ��ѯ��������(����0��չʾȫ��, ����-1������һ����): ";
        }
        flag = 0;
        break;
    case 2:
        Append_List_Things(pHead);
        flag = 1;
        break;
    case 3:
        system("cls");
        if (pHead == NULL) 
        {
            cin.ignore();
            cout << "��ǰû��Ա����" << endl;
            getchar();
            break;
        }
        cout << "��������Ҫɾ����Ա�����(����0��չʾȫ��, ����-1������һ����): ";
        while (cin >> id)
        {
            if (id == "-1") break;
            else 
            {
                Delete_List_Things(pHead, id);
            }
            cout << "\n\n\n��������Ҫɾ����Ա������(����0��չʾȫ��, ����-1������һ����): ";
        }
        break;
        break;
    case 4:
        Save_Things_List(pHead);
        break;
    case 0:
        if (!flag) 
        {
            cout << "�Ƿ���Ҫ���棿(Y/n) ";
            char tmp;
            cin >> tmp;
            if (tmp == 'Y' || tmp == 'y') Save_Things_List(pHead);
        }
        Create_Menu(pHead);
        return;
    default:
        cout << "��������ȷ����ţ�" << endl;
        Sleep(1000);
        Create_Menu_Things(pHead);
        return;
    }
    Create_Menu_Things(pHead);
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
            // cout << "get" << endl;
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
        // if (!ss.eof()) ss.clear();
        if (!Things_File.eof())
        {
            ListNode* pNewNode = new ListNode;
            pNewNode -> next = NULL;
            p -> next = pNewNode;
            p = pNewNode;
            // cout << "get" << endl;
        }
        else break;
    }
    Things_File.close();
}

void Destory_List(ListNode* pHead)//ɾ������
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

// ListNode* Insert_List(ListNode* pHead)//�����������ز���ĵ�ַ
// {
//     ListNode* pInsert = new ListNode;
//     pInsert -> next = pHead -> next;
//     pHead -> next = pInsert;
//     return pHead -> next;
// }

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
    else
    {
        pHead -> id = -1;
    }
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
            cout << pHead -> id << " " << pHead -> name << " " << pHead -> department;
            if (pHead -> salary != -1) cout << " " << pHead -> salary;
            if (pHead -> leaderid == "-1") cout << endl;
            else cout << " " << pHead -> leaderid << endl;
            break;
        }
        else if(id == pHead -> name)
        {
            cout << pHead -> id << " " << pHead -> name << " " << pHead -> department;
            if (pHead -> salary != -1) cout << " " << pHead -> salary;
            if (pHead -> leaderid == "-1") cout << endl;
            else cout << " " << pHead -> leaderid << endl;
            break;
        }
        else if(id == pHead -> department)
        {
            flag = 0;
            cout << pHead -> id << " " << pHead -> name << " " << pHead -> department;
            if (pHead -> salary != -1) cout << " " << pHead -> salary;
            if (pHead -> leaderid == "-1") cout << endl;
            else cout << " " << pHead -> leaderid << endl;
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
        if (pHead -> id != "-1")
        {
            cout << pHead -> id << " " << pHead -> name << " " << pHead -> department << pHead -> things;
            if (pHead -> salary != -1) cout << " " << pHead -> salary;
            if (pHead -> leaderid == "-1") cout << endl;
            else cout << " " << pHead -> leaderid << endl;
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
        if (ptmp == NULL) cout << "���޴��ˣ�";
        else if (ptmp == pHead) 
        {
            pHead = ptmp -> next;
            delete ptmp;
            cout << "��ɾ����Ա����Ϣ��\n";
        }
        else 
        {
            Delete_List(ptmp);
            cout << "��ɾ����Ա����Ϣ��\n";
        }
        // cout << "\n\n\n��������Ҫɾ����Ա�����(����0��չʾȫ��, ����-1������һ����): ";
    }
}

void Append_List_Employer(ListNode* pHead)
{
    system("cls");
    cout << "����������Ա������Ϣ: (��� ���� ���� нˮ ֱ���쵼��ţ���ѡ��)" << endl;
    string str;
    cin.ignore();
    while (getline(cin, str))
    {
        system("cls");
        stringstream ss(str); 
        int flag = 0, tmp_salary = -1;
        string tmp_id, tmp_name = "", tmp_department = "", tmp_leaderid = "";
        ss >> tmp_id;
        if (tmp_id == "-1" || (tmp_id >= "a" && tmp_id <= "z") || (tmp_id >= "A" && tmp_id <= "Z")) return;
        ListNode* ptmp = pHead;
        while (ptmp -> next != NULL) 
        {
            if (ptmp -> id == tmp_id)
            {
                cout << "�Ѵ��ڱ��Ϊ" << tmp_id << "��Ա�������������룡\n";
                Sleep(2000);
                system("cls");
                cout << "����������Ա������Ϣ: (��� ���� ���� нˮ ֱ���쵼��ţ���ѡ��)" << endl;
                flag = 1;
                break;
            }
            ptmp = ptmp -> next;
        }
        if (flag) continue;
        if (!ss.eof()) ss >> tmp_name;
        if (!ss.eof()) ss >> tmp_department;
        if (!ss.eof()) ss >> tmp_salary;
        if (!ss.eof()) ss >> tmp_leaderid;
        else tmp_leaderid = "-1";
        if (tmp_leaderid == tmp_id) 
        {
            cout << "�쵼��ϵ�������������룡" << endl;
            Sleep(2000);
            system("cls");
            cout << "����������Ա������Ϣ: (��� ���� ���� нˮ ֱ���쵼��ţ���ѡ��)" << endl;
            continue;
        }
        // ListNode* ptmp2 = pHead;
        // if (tmp_leaderid == tmp_id || tmp_id != Eployee_Leaderid(pHead, tmp_leaderid))
        // {
        //     system("cls");
        //     cout << "�쵼��ϵ�������������룡" << endl;
        //     Sleep(2000);
        //     system("cls");
        //     cout << "����������Ա������Ϣ: (��� ���� ���� нˮ ֱ���쵼��ţ���ѡ��)" << endl;
        //     continue;
        // }
        ListNode* pNew = new ListNode;
        pNew -> next = NULL;
        ptmp -> next = pNew;
        ptmp = pHead;
        pNew -> id = tmp_id;
        pNew -> name = tmp_name;
        pNew -> department = tmp_department;
        pNew -> salary = tmp_salary;
        pNew -> leaderid = tmp_leaderid;
        if (pNew -> id != "") cout << pNew -> id;
        if (pNew -> name != "") cout << " " << pNew -> name;
        if (pNew -> department != "") cout << " " << pNew -> department;
        if (pNew -> salary != -1) cout << " " << pNew -> salary;
        if (pNew -> leaderid != "") cout << " " << pNew -> leaderid;
        cout << "\n\n\n������ϣ�\n����-1������һ��������¼��Ա����Ϣ(��� ���� ���� нˮ ֱ���쵼��ţ���ѡ��)..." << endl;
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
        // ptmp = pHead;
        while (ptmp != NULL)
        {
            if (salary[i] == ptmp -> salary)
            {
                if (ptmp-> id != "") cout << ptmp -> id;
                if (ptmp -> name != "") cout << " " << ptmp -> name;
                if (ptmp -> department != "") cout << " " << ptmp -> department;
                if (ptmp -> salary != -1) cout << " " << ptmp -> salary;
                if (ptmp -> leaderid != "-1") cout << " " << ptmp -> leaderid;
                cout << endl;
                ptmp = pHead;
                break;
            }
            ptmp = ptmp -> next;
        }
    }
    cout << "\n\n\n���������������һ����...";
    getchar();
    return;    
}

string Eployee_Leaderid(ListNode* pHead, string id)
{
    system("cls");
    ListNode* ptmp = pHead;
    ListNode* pNewList_forward = NULL,* pNLHead = NULL;
    int flag = 1;
    while (ptmp != NULL)
    {
        if (id == ptmp -> id) 
        {
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
        cout << "���޴��ˣ�" << endl;
        Sleep(1000);
    }
    else if (pNLHead -> next == NULL)
    {
        cout << pNLHead -> id << " " << pNLHead -> name << " " << pNLHead -> department << " " << pNLHead -> salary;
        cout << "\n��Ա��û��ֱ���쵼��" << endl;
    }
    else
    {
        Display_List(pNLHead);
        Destory_List(pNLHead);
    }
    return id;
}

void Change_Employ_List(ListNode* pHead)
{
    system("cls");
    cin.ignore();
    cout << "��������Ҫ�޸ĵ�Ա�����(����-1�˳�): ";
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
            cout << "���޴��ˣ�";
            Sleep(1000);
            system("cls");
            cout << "��������Ҫ�޸ĵ�Ա�����(����-1�˳�): ";
            continue;
        }
        cout << "�������޸ĺ��Ա������: ";
        cin >> pChange -> name;
        cout << "�������޸ĺ��Ա������: ";
        cin >> pChange -> department;
        cout << "�������޸ĺ��Ա��нˮ: ";
        cin >> pChange -> salary;
        cout << "�������޸ĺ��Ա��ֱϵ�쵼: ";
        cin >> pChange -> leaderid;
        Sleep(500);
        cout << "\n\n�޸���ϣ�";
        cin.ignore();
        Sleep(2000);
        system("cls");
        cout << "��������Ҫ�޸ĵ�Ա�����(����-1�˳�): ";
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
            if (pHead -> next != NULL) Employee_File << endl;
        }
        pHead = pHead -> next;
    }
    cout << "������ϣ�" << endl;
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
            cout << pHead -> id << " " << pHead -> things << endl;
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
    system("cls");
    ListNode* ptmp = pHead;
    if (id == "-1") return;
    else if (id == "0") Display_List(ptmp);
    else 
    {
        ptmp = Search_Employee_List(ptmp, id);
        if (ptmp == NULL) cout << "���޴��£�";
        else if (ptmp == pHead) 
        {
            pHead = ptmp -> next;
            delete ptmp;
            cout << "��ɾ����Ա������\n";
        }
        else 
        {
            Delete_List(ptmp);
            cout << "��ɾ����Ա������\n";
        }
    }
}

void Append_List_Things(ListNode* pHead)
{
    system("cls");
    cout << "�����������������Ϣ: (��� ����)" << endl;
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
            cout << "��������ȷ��Ա������" << endl;
            Sleep(1000);
            system("cls");
            cout << "�����������������Ϣ: (��� ����)" << endl;
            continue;
        }
        while (ptmp -> next != NULL) ptmp = ptmp -> next;
        ListNode* pNew = new ListNode;
        pNew -> next = NULL;
        ptmp -> next = pNew;
        ptmp = pHead;
        pNew -> id = tmp_id;
        pNew -> things = tmp_things;
        cout << pNew -> id << " " << pNew -> things;
        cout << "\n\n\n������ϣ�\n����-1������һ��������¼��Ա������(��� ����)..." << endl;
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
            if (pHead -> next != NULL) Things_File << endl;
        }
        pHead = pHead -> next;
    }
    cout << "������ϣ�" << endl;
    Sleep(2000);
    return;
}

/****************************************************<fun def end>***************************************************/

int main()
{
    ListNode* pHead = NULL;
    Create_Menu(pHead);
    return 0;
}