#include <iostream>
#include <string>
#include <fstream>

using namespace std;


const int MaxPeople = 10000; //1w人可借书
const int MaxBooks = 100000;//最多可存10w书
const int MaxBorrow = 6; //每人最多能借6本


class Book
{
private:
    int tag; ///图书是否存在 1表示存在 2表示不存在
    int No; //编号
    string Name; //书名
    string Author; //作者
    string Group; //书的分类
    string Press; //出版社
    int Press_Time; //出版时间
    double Book_Price; //书的价格
    int On_Shelf; //是否在架  1在 2不存在
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
};

Book::Book(/* args */)
{
}

Book::~Book()
{
}

