#include "Park_System.cpp"



int main()
{
    User user;
    Admin admin;
    
    char ch;
    while (true)
    {
        system("cls");              //清屏操作
        cout << "1.普通用户登录" << endl;
        cout << "2.管理员登录" << endl;
        cout << "3.退出系统" << endl;

        char ch;
        cout << "请输入要执行的操作: " ;
        cin >> ch;
        switch (ch)
        {
        case '1':
            user.checkCar();                         //普通用户
            break;
        case '2':
            admin.manager();                        //管理员
            break;
        case '3':
            break;
        default:
            cout << "请输入正确的操作" << endl;
        }
    }
    return 0;
}