#include "Park_System.cpp"



int main()
{
    User user;
    Admin admin;
    
    char ch;
    while (true)
    {
        system("cls");              //��������
        cout << "1.��ͨ�û���¼" << endl;
        cout << "2.����Ա��¼" << endl;
        cout << "3.�˳�ϵͳ" << endl;

        char ch;
        cout << "������Ҫִ�еĲ���: " ;
        cin >> ch;
        switch (ch)
        {
        case '1':
            user.checkCar();                         //��ͨ�û�
            break;
        case '2':
            admin.manager();                        //����Ա
            break;
        case '3':
            break;
        default:
            cout << "��������ȷ�Ĳ���" << endl;
        }
    }
    return 0;
}