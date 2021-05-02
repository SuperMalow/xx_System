#include <iostream>
#include <string>
#include <fstream>
#include <iomanip> //控制数据输出格式

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



};





