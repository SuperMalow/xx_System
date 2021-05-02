#include <iostream>
#include <string>
#include <fstream>
#include <iomanip> //控制数据输出格式
#include <conio.h>

using namespace std;


const int MaxPeople = 10000; //1w人可借书
const int MaxBooks = 100000;//最多可存10w书
const int MaxBorrow = 6; //每人最多能借6本

//书籍类
class Book
{
private:
    int tag; //删除书籍的标记 1表示删除 0表示没删除
    int No; //编号
    string Name; //书名
    string Author; //作者
    string Group; //书的分类
    string Press; //出版社
    int Press_Time; //出版时间
    double Book_Price; //书的价格
    int On_Shelf; //是否在架  1在 0不存在
public:
    Book(/* args */);
    ~Book();

    string getBookName()
    {
        return Name; //获取书名
    }
    string getAuthor()
    {
        return Author; //获取书的作者
    }
    string getBookGroup()
    {
        return Group; //获取书的分类
    }
    string getBookPress()
    {
        return Press; //获取出版时间
    }
    double getBookPrice()
    {
        return Book_Price; //获取书的价格
    }
    int getPressTime()
    {
        return Press_Time; //获取出版时间
    }
    int getOnShelf()
    {
        return On_Shelf; //获取是否在架
    }
    int getBookNo()
    {
        return No; //获取书的编号
    }
    int getBookTag()
    {
        return tag; //获取书的删除标记
    }
    void setBookName(string name)
    {
        Name = name; //设置书名 从name到Name
    }
    void setBookAuthor(string author_name)
    {
        Author = author_name; //设置作者
    }
    void setBookGroup(string Group_name)
    {
        Group = Group_name; //设置书的分类
    }
    void setBookPress(string Press_name)
    {
        Press= Press_name; //设置书的出版社
    }
    void setBookPrice(double Price_name)
    {
        Book_Price = Price_name; //设置书的价格
    }
    void setBookTime(int Time_name)
    {
        Press_Time = Time_name; //设置书的出版时间
    }
    void setOnSelf(int onself)
    {
        On_Shelf = onself; //设置是否在架
    }

    //增删功能
    void delBook()
    {
        char i;
        cout << "确认删除书籍(y/n)?" << endl;
        cin >> i;
        if (i == 'y' || i == 'Y')
        {
            tag = 1;  //删除书籍
            cout << "删除成功" << endl;
        }
    }
    //参数:  编号  书名  出版社  分类 作者 出版时间 是否在架
    void addBook(int B_number,string B_name,string B_author,
    string B_press,string B_group,int presstime,double B_price, int B_onself)
    {
        tag = 0;
        No = B_number; //编号
        Name = B_name; //书名
        Author = B_author; //作者
        Press = B_press; //出版社
        Group = B_group; //分类 
        Press_Time = presstime; //出版时间
        Book_Price = B_price; //书的价格
        On_Shelf = B_onself; //是否在架

    }
    int borrowBook()
    {
        if (On_Shelf > 0)
        {
            /* 借书 */
            On_Shelf --;
            return 1;
        }
        return 0;
    }
    void returnBook()
    {
        On_Shelf ++;
    }
    void dispBook()    //打印书籍信息
    {
        
        cout << setw(3) << No << endl;
        cout << setw(3) << Name << endl;
        cout << setw(3) << Group << endl;
        cout << setw(3) << Author << endl;
        cout << setw(3) << Book_Price << endl;
        cout << setw(3) << Press << endl;
        cout << setw(3) << Press_Time << endl;
        //setw(n) n个空格

    }

};

Book::Book(/* args */)
{
}

Book::~Book()
{
}

//管理系统维护 查删
class LibSystem
{
private:
    int top; //图书记录指针？
    Book Bookm[MaxBooks]; //最大存储书的数量
    


public:
    LibSystem()             //构造函数  将bookdata.txt 读取到Bookm[]里面
    {
        Book book;
        top = -1;
        fstream file("bookdata.txt",ios::in); //读取数据
        while (1)
        {
            file.read((char *)&book,sizeof(book));
            if (!file)
            {
                break;
            }
            top++;
            Bookm[top] = book;
            
        }
        file.close();
    }
    ~LibSystem()            //析构函数 将Bookm[]写到bookdata.txt文件中
    {
        fstream file("bookdata.txt",ios::out); //写
        for (int i = 0; i <= top; i++)
        {
            if (Bookm[i].getBookTag() == 0)  //没有删除的情况下 写入数据
            {
                /* code */
                file.write((char*)&Bookm[i],sizeof(Bookm[i]));
            }
            
        }
        file.close();
    }

    void clearBook()            //全部删除书籍
    {
        char i;
        cout << "是否确认全部删除书籍(y/n)?" << endl;
        cin >> i;
        if (i == 'y' || i == 'Y')
        {
            /* code */
            top = -1; //删除书籍
        }
        
    }            
    int addBook(int n,string na,string an,string gp,
    string pr,int time,double price,int oself)  //添加图书信息
    {
        //先判断是否有这本书 也就是先查一遍 没有才录入
        Book * p = Cheak1(n);
        if (p == NULL)
        {
            top ++;
            Bookm[top].addBook(n,na,an,gp,pr,time,price,oself); //开始录入书籍的信息
            return 1;
        }
        
    }

    Book * Cheak1(int book_number)  //根据书的编号查找书籍
    {
        for (int i = 0; i <= top; i++)
        {
            if (Bookm[i].getBookNo() == book_number && Bookm[i].getBookTag() == 0)
            {
                /* 遍历书的编号 并且该书是否被删除 */
                return &Bookm[i];
            }
            
        }
        
    }
    Book * Cheak2(string book_name)  //根据书的名字查找书籍
    {
        int r = 0;
        Book *e;
        for (int i = 0; i <= top; i++)
        {
            if (Bookm[i].getBookName() == book_name && Bookm[i].getBookTag() == 0)
            {
                if (r == 0)
                {
                    //打印书籍信息
                    cout << setw(3) << "编号" << setw(5);
                    cout << setw(3) << "书名" << setw(5);
                    cout << setw(3) << "分类" << setw(5);
                    cout << setw(3) << "作者" << setw(5);
                    cout << setw(3) << "价格" << setw(5);
                    cout << setw(3) << "出版社" << setw(5);
                    cout << setw(3) << "出版时间" << endl;
                }
                e = &Bookm[i];
                e->dispBook();
                r++;
            }
            if (r == 0)
            {
                cout << "找不到该书的信息" << endl;
            }
        }
        return NULL;   
        /*for遍历 如果找到了书籍会在e->显示书籍的信息然后返回NULL
        如果没找到不会显示书籍信息然后返回NULL*/
    }
    Book * Cheak3(string book_author)  //根据书的作者查找书籍
    {
        Book *e;
        int r = 0;
        for (int i = 0; i <= top; i++)
        {
            if (Bookm[i].getAuthor() == book_author && Bookm[i].getBookTag() == 0)
            {
                if (r == 0)
                {
                    //打印书籍信息
                    cout << setw(3) << "编号" << setw(5);
                    cout << setw(3) << "书名" << setw(5);
                    cout << setw(3) << "分类" << setw(5);
                    cout << setw(3) << "作者" << setw(5);
                    cout << setw(3) << "价格" << setw(5);
                    cout << setw(3) << "出版社" << setw(5);
                    cout << setw(3) << "出版时间" << endl;
                }
                e = &Bookm[i];
                e->dispBook();
                r++;
            }
            if (r == 0)
            {
                cout << "找不到该书的信息" << endl;
            }
        }
        return NULL;
    }
    Book * Cheak4(string book_press)  //根据书的出版社查找书籍
    {
        Book *e;
        int r = 0;
        for (int i = 0; i <= top; i++)
        {
            if (Bookm[i].getBookPress() == book_press && Bookm[i].getBookTag() == 0)
            {
                if (r == 0)
                {
                    //打印书籍信息
                    cout << setw(3) << "编号" << setw(5);
                    cout << setw(3) << "书名" << setw(5);
                    cout << setw(3) << "分类" << setw(5);
                    cout << setw(3) << "作者" << setw(5);
                    cout << setw(3) << "价格" << setw(5);
                    cout << setw(3) << "出版社" << setw(5);
                    cout << setw(3) << "出版时间" << endl;
                }
                e = &Bookm[i];
                e->dispBook();
                r++;
            }
            if (r == 0)
            {
                cout << "找不到该书的信息" << endl;
            }
        }
        return NULL;
    }
    Book * Cheak5(int book_presstime)  //根据书的出版时间查找书籍
    {
        Book *e;
        int r = 0;
        for (int i = 0; i <= top; i++)
        {
            if (Bookm[i].getPressTime() == book_presstime && Bookm[i].getBookTag() == 0)
            {
                if (r == 0)
                {
                    //打印书籍信息
                    cout << setw(3) << "编号" << setw(5);
                    cout << setw(3) << "书名" << setw(5);
                    cout << setw(3) << "分类" << setw(5);
                    cout << setw(3) << "作者" << setw(5);
                    cout << setw(3) << "价格" << setw(5);
                    cout << setw(3) << "出版社" << setw(5);
                    cout << setw(3) << "出版时间" << endl;
                }
                e = &Bookm[i];
                e->dispBook();
                r++;
            }
            if (r == 0)
            {
                cout << "找不到该书的信息" << endl;
            }
        }
        return NULL;
    }
    Book * Cheak6(int book_price)  //根据书的出版时间查找书籍
    {
        Book *e;
        int r = 0;
        for (int i = 0; i <= top; i++)
        {
            if (Bookm[i].getBookPrice() == book_price && Bookm[i].getBookTag() == 0)
            {
                if (r == 0)
                {
                    //打印书籍信息
                    cout << setw(3) << "编号" << setw(5);
                    cout << setw(3) << "书名" << setw(5);
                    cout << setw(3) << "分类" << setw(5);
                    cout << setw(3) << "作者" << setw(5);
                    cout << setw(3) << "价格" << setw(5);
                    cout << setw(3) << "出版社" << setw(5);
                    cout << setw(3) << "出版时间" << endl;
                }
                e = &Bookm[i];
                e->dispBook();
                r++;
            }
            if (r == 0)
            {
                cout << "找不到该书的信息" << endl;
            }
        }
        return NULL;
    }

    void dispLib()
    {
        for (int i = 0; i <= top; i++)
        {
            if (Bookm[i].getBookTag() == 0) 
            {
                /* 判断没删除的书籍并显示出来 */
                Bookm[i].dispBook();
            }
        }
        
    }
    
    //对于信息的保管
    void bookData();
};

void LibSystem::bookData()
{
    char choise = 0;
    string b_name;
    string b_aname;
    string b_group;
    string b_press;
    int b_number;//书籍的数量 是否在架 
    int b_presstime;
    double b_price;
    char ch;
    int choise2;
    int b_id;
    Book *b;


    while (choise != '0')
    {
        /* code */
        cout << setw(15) << " 管理信息系统:图书菜单模块 " << setw(15) <<endl;
        cout << setw(3) << " 1 -> 增加图书 " << setw(4) << " 2 -> 更改图书 " << setw(4)
        << " 3 -> 删除图书 " << setw(3) <<endl;
        cout << setw(3) << " 4 -> 查询图书 " << setw(4) << " 5 -> 显示图书 " << setw(4)
        << " 6 -> 清空图书 " << setw(3) <<endl;
        cout << setw(3) << " 0 -> 返回上级目录 " << endl;

        cout << "请选择操作项: " ;
        cin >> choise2;
        switch (choise2)    
        {
            case 1:  //增加图书
                cout << "请输入书籍编号: " ;
                cin >> b_id;
                b = Cheak1(b_id);
                if (b != NULL)
                {
                    cout << "该编号已经存在了，无法进行添加" << endl;
                    break;
                }
                cout << "请输入书籍名称: ";
                cin >>b_name;
                cout << "请输入书籍作者名称: ";
                cin >>b_aname;
                cout << "请输入书籍的分类: ";
                cin >>b_group;
                cout << "请输入书籍的出版社名称: ";
                cin >>b_press;
                cout << "请输入书籍的出版时间: ";
                cin >>b_presstime;
                cout << "请输入书籍的价格: ";
                cin >>b_price;
                cout << "请输入书籍数量: ";
                cin >>b_number;
                
                //将用户从键盘上输入的信息，通过调用添加图书函数作为实参传给形参
                addBook(b_id,b_name,b_aname,b_group,b_press,b_presstime,b_price,b_number);
                char choise3;
                //给数据做一个保存
                {
                    cout << setw(15) << " 是否保存录入的书籍信息保存到本地文件 " << setw(15) <<endl;
                    cout << setw(5) << " 1 -> 保存 " << setw(4) << " 2 -> 取消 " << setw(5) <<endl;
                    cout << "请选择操作项: " ;
                    cin >> choise3;
                    switch (choise3)
                    {
                    case '1':
                        cout << "保存成功！" << endl;
                        break;
                    case '2':
                        break;
                    }
                }
                _getch();  //暂停一下


            case 2:  //更改图书
                cout << "请输入图书信息的编号：";
                cin >> b_id;
                b = Cheak1(b_id);
                if (b == NULL)
                {
                    cout << "此书不存在，请重新检查" << endl;
                    break;
                }
                cout << "该书信息如下：" << endl;
                cout << setw(3) << "编号" << setw(5);
                cout << setw(3) << "书名" << setw(5);
                cout << setw(3) << "分类" << setw(5);
                cout << setw(3) << "作者" << setw(5);
                cout << setw(3) << "价格" << setw(5);
                cout << setw(3) << "出版社" << setw(5);
                cout << setw(3) << "出版时间" << endl;
                b->dispBook();  //打印书的信息
                cout << "请问是否更改图书信息(y/n)?" << endl;
                cin >> ch;
                if (ch == 'y' || ch == 'Y')
                {
                    cout << setw(15) << " 管理信息系统:图书菜单模块 " << setw(15) <<endl;
                    cout << setw(3) << " 1 -> 修改书名 " << setw(4) << " 2 -> 修改作者 " << setw(4)
                    << " 3 -> 修改分类 " << setw(3) <<endl;
                    cout << setw(3) << " 4 -> 修改出版社名 " << setw(2) << " 5 -> 修改出版时间 " << setw(2)
                    << " 6 -> 修改图书价格 " << setw(3) <<endl;
                    cout << setw(3) << setw(4) << " 7 -> 修改图书库存 " << " 0 -> 返回上级目录 "<< endl;
                    int c_choise;
                    cout << "请选择操作项: " ;
                    cin >> c_choise;
                    switch (c_choise)
                    {
                    case 1:
                        cout << "请输入修改的书名: ";
                        cin >> b_name;
                        b->setBookName(b_name);
                        break;
                    case 2:
                        cout << "请输入修改的作者: ";
                        cin >> b_aname;
                        b->setBookAuthor(b_aname);
                        break;
                    case 3:
                        cout << "请输入修改的分类: ";
                        cin >> b_group;
                        b->setBookGroup(b_group);
                        break;
                    case 4:
                        cout << "请输入修改的出版社名: ";
                        cin >> b_press;
                        b->setBookPress(b_press);
                        break;
                    case 5:
                        cout << "请输入修改的出版时间: ";
                        cin >> b_presstime;
                        b->setBookTime(b_presstime);
                        break;
                    case 6:
                        cout << "请输入修改的价格: ";
                        cin >> b_price;
                        b->setBookPrice(b_price);
                        break;
                    case 7:
                        cout << "请输入修改的图书库存: ";
                        cin >> b_number;
                        b->setOnSelf(b_number);
                        break;
                    case 0:
                        break;
                    }
                
                }
                cout << "修改成功！" << endl;
                _getch();  //暂停一下
                break;


            case 3:  //删除图书
        }

    }
    
}



