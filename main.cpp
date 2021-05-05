#include <iostream>
#include "Lib_System.h"

using namespace std;

//主函数
int main()
{   
   mainDest yourDest;
   if (yourDest.Login())
   {
        cout << setw(15) << " 感谢使用高校图书管理应用系统 " << setw(15) <<endl;
        cout << setw(3) << setw(4) << " 2021-5-5 " << setw(4)<< setw(3) <<endl;
   }
   
     //读取文件出现了问题，让后人来修改吧
    system("pause");
    return 0;
}