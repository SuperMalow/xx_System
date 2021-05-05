#include <iostream>
#include <string>
#include <fstream>
#include <iomanip> //�������������ʽ
#include <conio.h>

using namespace std;


const int MaxPeople = 10000; //1w�˿ɽ���
const int MaxBooks = 100000;//���ɴ�10w��
const int MaxBorrow = 6; //ÿ������ܽ�6��

//�鼮��
class Book
{
private:
    int tag; //ɾ���鼮�ı�� 1��ʾɾ�� 0��ʾûɾ��
    int No; //���
    string Name; //����
    string Author; //����
    string Group; //��ķ���
    string Press; //������
    int Press_Time; //����ʱ��
    double Book_Price; //��ļ۸�
    int On_Shelf; //�Ƿ��ڼ�  1�� 0������
public:
    string getBookName();
    string getAuthor();
    string getBookGroup();
    string getBookPress();
    double getBookPrice();
    int getPressTime();
    int getOnShelf();
    int getBookNo();
    int getBookTag();
    void setBookName(string name);
    void setBookAuthor(string author_name);
    void setBookGroup(string Group_name);
    void setBookPress(string Press_name);
    void setBookPrice(double Price_name);
    void setBookTime(int Time_name);
    void setOnSelf(int onself);
    void delBook();
    void addBook(int B_number,string B_name,string B_author,
    string B_press,string B_group,int presstime,double B_price, int B_onself);
    int borrowBook();
    void returnBook();
    void dispBook();

};

//��ȡ�������Ϣ
string Book::getBookName()
{
    return Name; //��ȡ����
}
string Book::getAuthor()
{
    return Author; //��ȡ�������
}
string Book::getBookGroup()
{
    return Group; //��ȡ��ķ���
}
string Book::getBookPress()
{
    return Press; //��ȡ����ʱ��
}
double Book::getBookPrice()
{
    return Book_Price; //��ȡ��ļ۸�
}
int Book::getPressTime()
{
    return Press_Time; //��ȡ����ʱ��
}
int Book::getOnShelf()
{
    return On_Shelf; //��ȡ�Ƿ��ڼ�
}
int Book::getBookNo()
{
    return No; //��ȡ��ı��
}
int Book::getBookTag()
{
    return tag; //��ȡ���ɾ�����
}


//���������Ϣ����
void Book::setBookName(string name)
{
    Name = name; //�������� ��name��Name
}
void Book::setBookAuthor(string author_name)
{
    Author = author_name; //��������
}
void Book::setBookGroup(string Group_name)
{
    Group = Group_name; //������ķ���
}
void Book::setBookPress(string Press_name)
{
    Press= Press_name; //������ĳ�����
}
void Book::setBookPrice(double Price_name)
{
    Book_Price = Price_name; //������ļ۸�
}
void Book::setBookTime(int Time_name)
{
    Press_Time = Time_name; //������ĳ���ʱ��
}
void Book::setOnSelf(int onself)
{
    On_Shelf = onself; //�����Ƿ��ڼ�
}


//��ɾ����
void Book::delBook()
{
    char i;
    cout << "ȷ��ɾ���鼮(y/n)?" << endl;
    cin >> i;
    if (i == 'y' || i == 'Y')
    {
        tag = 1;  //ɾ���鼮
        cout << "ɾ���ɹ�" << endl;
    }
}
void Book::addBook(int B_number,string B_name,string B_author,
string B_press,string B_group,int presstime,double B_price, int B_onself)
{   //���  ����  ������  ���� ���� ����ʱ�� �Ƿ��ڼ�
    tag = 0;
    No = B_number; //���
    Name = B_name; //����
    Author = B_author; //����
    Press = B_press; //������
    Group = B_group; //���� 
    Press_Time = presstime; //����ʱ��
    Book_Price = B_price; //��ļ۸�
    On_Shelf = B_onself; //�Ƿ��ڼ�

}
int Book::borrowBook()  //����
{
    if (On_Shelf > 0)
    {
        On_Shelf --;
        return 1;
    }
    return 0;
}
void Book::returnBook() //����
{
    On_Shelf ++;
}
void Book::dispBook()    //��ӡ�鼮��Ϣ
{   //setw(n) n���ո�
    cout << setw(3) << No << endl;
    cout << setw(3) << Name << endl;
    cout << setw(3) << Group << endl;
    cout << setw(3) << Author << endl;
    cout << setw(3) << Book_Price << endl;
    cout << setw(3) << Press << endl;
    cout << setw(3) << Press_Time << endl;
}


//����ϵͳά�� ��ɾ��
class LibSystem
{
private:
    int top; //ͼ���¼��index�±�
    Book Bookm[MaxBooks]; //���洢�������
public:
    LibSystem()             //���캯��  ��bookdata.txt ��ȡ��Bookm[]����
    {
        Book book;
        top = -1;
        fstream file("bookdata.txt",ios::in); //��ȡ����
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
    ~LibSystem()            //�������� ��Bookm[]д��bookdata.txt�ļ���
    {
        fstream file("bookdata.txt",ios::out); //д
        for (int i = 0; i <= top; i++)
        {
            if (Bookm[i].getBookTag() == 0)  //û��ɾ��������� д������
            {
                /* code */
                file.write((char*)&Bookm[i],sizeof(Bookm[i]));
            }
            
        }
        file.close();
    }

    void clearBook()            //ȫ��ɾ���鼮
    {
        char i;
        cout << "�Ƿ�ȷ��ȫ��ɾ���鼮(y/n)?" << endl;
        cin >> i;
        if (i == 'y' || i == 'Y')
        {
            /* code */
            top = -1; //ɾ���鼮
        }  
    }            
    int addBook(int n,string na,string an,string gp,
    string pr,int time,double price,int oself)  //���ͼ����Ϣ
    {
        //���ж��Ƿ����Ȿ�� Ҳ�����Ȳ�һ�� û�в�¼��
        Book * p = Cheak1(n);
        if (p == NULL)
        {
            top ++;
            Bookm[top].addBook(n,na,an,gp,pr,time,price,oself); //��ʼ¼���鼮����Ϣ
            return 1;
        }
        
    }

    Book * Cheak1(int book_number)  //������ı�Ų����鼮
    {
        for (int i = 0; i <= top; i++)
        {
            if (Bookm[i].getBookNo() == book_number && Bookm[i].getBookTag() == 0)
            {
                /* ������ı�� ���Ҹ����Ƿ�ɾ�� */
                return &Bookm[i];
            }
        }
    }
    Book * Cheak2(string book_name)  //����������ֲ����鼮
    {
        int r = 0;
        Book *e;
        for (int i = 0; i <= top; i++)
        {
            if (Bookm[i].getBookName() == book_name && Bookm[i].getBookTag() == 0)
            {
                if (r == 0)
                {
                    //��ӡ�鼮��Ϣ
                    cout << setw(3) << "���" << setw(5);
                    cout << setw(3) << "����" << setw(5);
                    cout << setw(3) << "����" << setw(5);
                    cout << setw(3) << "����" << setw(5);
                    cout << setw(3) << "�۸�" << setw(5);
                    cout << setw(3) << "������" << setw(5);
                    cout << setw(3) << "����ʱ��" << endl;
                }
                e = &Bookm[i];
                e->dispBook();
                r++;
            }
            if (r == 0)
            {
                cout << "�Ҳ����������Ϣ" << endl;
            }
        }
        return NULL;   
        /*for���� ����ҵ����鼮����e->��ʾ�鼮����ϢȻ�󷵻�NULL
        ���û�ҵ�������ʾ�鼮��ϢȻ�󷵻�NULL*/
    }
    Book * Cheak3(string book_author)  //����������߲����鼮
    {
        Book *e;
        int r = 0;
        for (int i = 0; i <= top; i++)
        {
            if (Bookm[i].getAuthor() == book_author && Bookm[i].getBookTag() == 0)
            {
                if (r == 0)
                {
                    //��ӡ�鼮��Ϣ
                    cout << setw(3) << "���" << setw(5);
                    cout << setw(3) << "����" << setw(5);
                    cout << setw(3) << "����" << setw(5);
                    cout << setw(3) << "����" << setw(5);
                    cout << setw(3) << "�۸�" << setw(5);
                    cout << setw(3) << "������" << setw(5);
                    cout << setw(3) << "����ʱ��" << endl;
                }
                e = &Bookm[i];
                e->dispBook();
                r++;
            }
            if (r == 0)
            {
                cout << "�Ҳ����������Ϣ" << endl;
            }
        }
        return NULL;
    }
    Book * Cheak4(string book_press)  //������ĳ���������鼮
    {
        Book *e;
        int r = 0;
        for (int i = 0; i <= top; i++)
        {
            if (Bookm[i].getBookPress() == book_press && Bookm[i].getBookTag() == 0)
            {
                if (r == 0)
                {
                    //��ӡ�鼮��Ϣ
                    cout << setw(3) << "���" << setw(5);
                    cout << setw(3) << "����" << setw(5);
                    cout << setw(3) << "����" << setw(5);
                    cout << setw(3) << "����" << setw(5);
                    cout << setw(3) << "�۸�" << setw(5);
                    cout << setw(3) << "������" << setw(5);
                    cout << setw(3) << "����ʱ��" << endl;
                }
                e = &Bookm[i];
                e->dispBook();
                r++;
            }
            if (r == 0)
            {
                cout << "�Ҳ����������Ϣ" << endl;
            }
        }
        return NULL;
    }
    Book * Cheak5(int book_presstime)  //������ĳ���ʱ������鼮
    {
        Book *e;
        int r = 0;
        for (int i = 0; i <= top; i++)
        {
            if (Bookm[i].getPressTime() == book_presstime && Bookm[i].getBookTag() == 0)
            {
                if (r == 0)
                {
                    //��ӡ�鼮��Ϣ
                    cout << setw(3) << "���" << setw(5);
                    cout << setw(3) << "����" << setw(5);
                    cout << setw(3) << "����" << setw(5);
                    cout << setw(3) << "����" << setw(5);
                    cout << setw(3) << "�۸�" << setw(5);
                    cout << setw(3) << "������" << setw(5);
                    cout << setw(3) << "����ʱ��" << endl;
                }
                e = &Bookm[i];
                e->dispBook();
                r++;
            }
            if (r == 0)
            {
                cout << "�Ҳ����������Ϣ" << endl;
            }
        }
        return NULL;
    }
    Book * Cheak6(int book_price)  //������ļ۸�����鼮
    {
        Book *e;
        int r = 0;
        for (int i = 0; i <= top; i++)
        {
            if (Bookm[i].getBookPrice() == book_price && Bookm[i].getBookTag() == 0)
            {
                if (r == 0)
                {
                    //��ӡ�鼮��Ϣ
                    cout << setw(3) << "���" << setw(5);
                    cout << setw(3) << "����" << setw(5);
                    cout << setw(3) << "����" << setw(5);
                    cout << setw(3) << "����" << setw(5);
                    cout << setw(3) << "�۸�" << setw(5);
                    cout << setw(3) << "������" << setw(5);
                    cout << setw(3) << "����ʱ��" << endl;
                }
                e = &Bookm[i];
                e->dispBook();
                r++;
            }
            if (r == 0)
            {
                cout << "�Ҳ����������Ϣ" << endl;
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
                /* �ж�ûɾ�����鼮����ʾ���� */
                Bookm[i].dispBook();
            }
        }
        
    }
    
    //������Ϣ�ı���
    void bookData();
};

void LibSystem::bookData()
{
    char choise = 0;
    string b_name;
    string b_aname;
    string b_group;
    string b_press;
    int b_number;//�鼮������ �Ƿ��ڼ� 
    int b_presstime;
    double b_price;
    char ch;
    char choise2;
    int b_id;
    Book *b;


    while (choise != '0')
    {
        /* code */
        cout << setw(15) << " ������Ϣϵͳ:ͼ��˵�ģ�� " << setw(15) <<endl;
        cout << setw(3) << " 1 -> ����ͼ�� " << setw(4) << " 2 -> ����ͼ�� " << setw(4)
        << " 3 -> ɾ��ͼ�� " << setw(3) <<endl;
        cout << setw(3) << " 4 -> ��ѯͼ�� " << setw(4) << " 5 -> ��ʾͼ�� " << setw(4)
        << " 6 -> ���ͼ�� " << setw(3) <<endl;
        cout << setw(3) << " 0 -> �����ϼ�Ŀ¼ " << endl;

        cout << "��ѡ�������: " ;
        cin >> choise2;
        switch (choise2)    
        {
            case '1':  //����ͼ��
                cout << setw(15) << " **���ͼ��** " << setw(15) <<endl;
                cout << "�������鼮���: " ;
                cin >> b_id;
                b = Cheak1(b_id);
                if (b != NULL)
                {
                    cout << "�ñ���Ѿ������ˣ��޷��������" << endl;
                    break;
                }
                cout << "�������鼮����: ";
                cin >>b_name;
                cout << "�������鼮��������: ";
                cin >>b_aname;
                cout << "�������鼮�ķ���: ";
                cin >>b_group;
                cout << "�������鼮�ĳ���������: ";
                cin >>b_press;
                cout << "�������鼮�ĳ���ʱ��: ";
                cin >>b_presstime;
                cout << "�������鼮�ļ۸�: ";
                cin >>b_price;
                cout << "�������鼮����: ";
                cin >>b_number;
                
                //���û��Ӽ������������Ϣ��ͨ���������ͼ�麯����Ϊʵ�δ����β�
                addBook(b_id,b_name,b_aname,b_group,b_press,b_presstime,b_price,b_number);
                char choise3;
                //��������һ������
                {
                    cout << setw(15) << " �Ƿ񱣴�¼����鼮��Ϣ���浽�����ļ� " << setw(15) <<endl;
                    cout << setw(5) << " 1 -> ���� " << setw(4) << " 2 -> ȡ�� " << setw(5) <<endl;
                    cout << "��ѡ�������: " ;
                    cin >> choise3;   //�����鼮������
                    switch (choise3)
                    {
                    case '1':
                        cout << "����ɹ���" << endl;
                        break;
                    case '2':
                        break;
                    }
                }
                _getch();  //��ͣһ��


            case '2':  //����ͼ��
                cout << setw(15) << " **����ͼ��** " << setw(15) <<endl;
                cout << "������ͼ����Ϣ�ı�ţ�";
                cin >> b_id;
                b = Cheak1(b_id);
                if (b == NULL)
                {
                    cout << "���鲻���ڣ������¼��" << endl;
                    break;
                }
                //���ҵ�����Ϣ
                cout << "������Ϣ���£�" << endl;
                cout << setw(3) << "���" << setw(5);
                cout << setw(3) << "����" << setw(5);
                cout << setw(3) << "����" << setw(5);
                cout << setw(3) << "����" << setw(5);
                cout << setw(3) << "�۸�" << setw(5);
                cout << setw(3) << "������" << setw(5);
                cout << setw(3) << "����ʱ��" << endl;
                b->dispBook();  //��ӡ�����Ϣ
                cout << "�����Ƿ����ͼ����Ϣ(y/n)?" << endl;
                cin >> ch;  //ȷ��ͼ����Ϣ�޸�
                if (ch == 'y' || ch == 'Y')
                {
                    cout << setw(15) << " ������Ϣϵͳ:ͼ��˵�ģ�� " << setw(15) <<endl;
                    cout << setw(3) << " 1 -> �޸����� " << setw(4) << " 2 -> �޸����� " << setw(4)
                    << " 3 -> �޸ķ��� " << setw(3) <<endl;
                    cout << setw(3) << " 4 -> �޸ĳ������� " << setw(2) << " 5 -> �޸ĳ���ʱ�� " << setw(2)
                    << " 6 -> �޸�ͼ��۸� " << setw(3) <<endl;
                    cout << setw(3) << setw(4) << " 7 -> �޸�ͼ���� " << " 0 -> �����ϼ�Ŀ¼ "<< endl;
                    char c_choise;   //ȷ���޸�ͼ����Ϣ
                    cout << "��ѡ�������: " ;
                    cin >> c_choise;
                    switch (c_choise)
                    {
                    case '1':
                        cout << "�������޸ĵ�����: ";
                        cin >> b_name;
                        b->setBookName(b_name);
                        break;
                    case '2':
                        cout << "�������޸ĵ�����: ";
                        cin >> b_aname;
                        b->setBookAuthor(b_aname);
                        break;
                    case '3':
                        cout << "�������޸ĵķ���: ";
                        cin >> b_group;
                        b->setBookGroup(b_group);
                        break;
                    case '4':
                        cout << "�������޸ĵĳ�������: ";
                        cin >> b_press;
                        b->setBookPress(b_press);
                        break;
                    case '5':
                        cout << "�������޸ĵĳ���ʱ��: ";
                        cin >> b_presstime;
                        b->setBookTime(b_presstime);
                        break;
                    case '6':
                        cout << "�������޸ĵļ۸�: ";
                        cin >> b_price;
                        b->setBookPrice(b_price);
                        break;
                    case '7':
                        cout << "�������޸ĵ�ͼ����: ";
                        cin >> b_number;
                        b->setOnSelf(b_number);
                        break;
                    case '0':
                        break;
                    }
                
                }
                cout << "�޸ĳɹ���" << endl;
                _getch();  //��ͣһ��
                break;


            case '3':  //ɾ��ͼ��
                cout << setw(15) << " **ɾ��ͼ��** " << setw(15) <<endl;
                cout << "������ͼ����Ϣ�ı�ţ�";
                cin >> b_id;
                b = Cheak1(b_id);
                if (b == NULL)
                {
                    cout << "���鲻���ڣ������¼��" << endl;
                    break;
                }               
                b->delBook();
                cout << "ɾ���ɹ���" << endl;
                _getch();  //��ͣһ��
                break;
            case '4':  //��ѯͼ��
                cout << setw(15) << " **��ѯͼ��** " << setw(15) <<endl;
                cout << setw(3) << " 1 -> ���ݱ�� " << setw(4) << " 2 -> �������� " << setw(4)
                << " 3 -> �������� " << setw(3) <<endl;
                cout << setw(3) << " 4 -> ���ݳ������� " << setw(4) << " 0 -> �����ϼ�Ŀ¼ "  << setw(3) <<endl;
                char f_choise;   //ȷ�ϲ�ѯͼ��
                cout << "��ѡ�������: " ;
                cin >> f_choise;
                switch (f_choise)
                {
                case '1':   //���ݱ�Ų�ѯͼ��
                    cout << "������ͼ���ţ�" << endl;
                    cin >> b_id;
                    b = Cheak1(b_id);
                    if (b == NULL)
                    {
                        cout << "��ͼ����Ϣ������" << endl;
                        break;
                    }
                    cout << "���鼮��Ϣ���£�" << endl;
                    cout << setw(3) << "���" << setw(5);
                    cout << setw(3) << "����" << setw(5);
                    cout << setw(3) << "����" << setw(5);
                    cout << setw(3) << "����" << setw(5);
                    cout << setw(3) << "�۸�" << setw(5);
                    cout << setw(3) << "������" << setw(5);
                    cout << setw(3) << "����ʱ��" << endl;
                    b->dispBook();  //��ӡ�����Ϣ
                    break;

                case '2':   //�������Ʋ�ѯͼ��
                    cout << "������ͼ�����ƣ�" << endl;
                    cin >> b_name;
                    b = Cheak2(b_name);
                    if (b == NULL)
                    {
                        cout << "��ͼ����Ϣ������" << endl;
                        break;
                    }
                    cout << "���鼮��Ϣ���£�" << endl;
                    cout << setw(3) << "���" << setw(5);
                    cout << setw(3) << "����" << setw(5);
                    cout << setw(3) << "����" << setw(5);
                    cout << setw(3) << "����" << setw(5);
                    cout << setw(3) << "�۸�" << setw(5);
                    cout << setw(3) << "������" << setw(5);
                    cout << setw(3) << "����ʱ��" << endl;
                    b->dispBook();  //��ӡ�����Ϣ
                    break;
                case '3':   //��������
                    cout << "������ͼ�����ߣ�" << endl;
                    cin >> b_aname;
                    b = Cheak3(b_aname);
                    if (b == NULL)
                    {
                        cout << "��ͼ����Ϣ������" << endl;
                        break;
                    }
                    cout << "���鼮��Ϣ���£�" << endl;
                    cout << setw(3) << "���" << setw(5);
                    cout << setw(3) << "����" << setw(5);
                    cout << setw(3) << "����" << setw(5);
                    cout << setw(3) << "����" << setw(5);
                    cout << setw(3) << "�۸�" << setw(5);
                    cout << setw(3) << "������" << setw(5);
                    cout << setw(3) << "����ʱ��" << endl;
                    b->dispBook();  //��ӡ�����Ϣ
                    break;
                case '4':     //���ݳ�������
                    cout << "������ͼ������磺" << endl;
                    cin >> b_aname;
                    b = Cheak4(b_aname);
                    if (b == NULL)
                    {
                        cout << "��ͼ����Ϣ������" << endl;
                        break;
                    }
                    cout << "���鼮��Ϣ���£�" << endl;
                    cout << setw(3) << "���" << setw(5);
                    cout << setw(3) << "����" << setw(5);
                    cout << setw(3) << "����" << setw(5);
                    cout << setw(3) << "����" << setw(5);
                    cout << setw(3) << "�۸�" << setw(5);
                    cout << setw(3) << "������" << setw(5);
                    cout << setw(3) << "����ʱ��" << endl;
                    b->dispBook();  //��ӡ�����Ϣ
                    break;
                case '5':     //���ݳ���ʱ��
                    cout << "������ͼ�����ʱ�䣺" << endl;
                    cin >> b_presstime;
                    b = Cheak5(b_presstime);
                    if (b == NULL)
                    {
                        cout << "��ͼ����Ϣ������" << endl;
                        break;
                    }
                    cout << "���鼮��Ϣ���£�" << endl;
                    cout << setw(3) << "���" << setw(5);
                    cout << setw(3) << "����" << setw(5);
                    cout << setw(3) << "����" << setw(5);
                    cout << setw(3) << "����" << setw(5);
                    cout << setw(3) << "�۸�" << setw(5);
                    cout << setw(3) << "������" << setw(5);
                    cout << setw(3) << "����ʱ��" << endl;
                    b->dispBook();  //��ӡ�����Ϣ
                    break;

                case '6':     //������ļ۸�
                    cout << "������ͼ��ļ۸�" << endl;
                    cin >> b_price;
                    b = Cheak6(b_price);
                    if (b == NULL)
                    {
                        cout << "��ͼ����Ϣ������" << endl;
                        break;
                    }
                    cout << "���鼮��Ϣ���£�" << endl;
                    cout << setw(3) << "���" << setw(5);
                    cout << setw(3) << "����" << setw(5);
                    cout << setw(3) << "����" << setw(5);
                    cout << setw(3) << "����" << setw(5);
                    cout << setw(3) << "�۸�" << setw(5);
                    cout << setw(3) << "������" << setw(5);
                    cout << setw(3) << "����ʱ��" << endl;
                    b->dispBook();  //��ӡ�����Ϣ
                    break;

                case '0':
                    break;

                }
            case '5':    //��ʾͼ��
                cout << "�����鼮��Ϣ���£�" << endl;
                cout << setw(3) << "���" << setw(5);
                cout << setw(3) << "����" << setw(5);
                cout << setw(3) << "����" << setw(5);
                cout << setw(3) << "����" << setw(5);
                cout << setw(3) << "�۸�" << setw(5);
                cout << setw(3) << "������" << setw(5);
                cout << setw(3) << "����ʱ��" << endl;
                b->dispBook();  //��ӡ�����Ϣ
                _getch();  //��ͣһ��
                break;
            case '6':    //ɾ��ͼ��
                clearBook();
                break;
            case '0':
                break;
        }
    }
}

// �������
class Rearder
{
private:
    int R_tag;                  //ɾ���ı��
    int R_no;                   //���߱��
    string R_name;              //��������    
    int R_borBook[MaxBorrow];   //�����鼮                

public:
    Rearder(/* args */);

    friend ostream &operator<<(ostream& output,Rearder &rd)
    {
        output << rd.R_no;
        output << "";
        output << endl;
        return output;
    }
    string getReadname()
    {
        return this->R_name;
    }
    int getReadno()
    {
        return this->R_no;
    }
    int getReadtag()
    {
        return this->R_tag;
    }
    string setReadname(string n)
    {
        this->R_name = n;
        return this->R_name;
    }
    int setReadno(int No)
    {
        this->R_no = No;
        return this->R_no;
    }
    int setReadtag(int Tag)
    {
        this->R_tag = Tag;
        return this->R_tag;
    }

    void setdelbook()           //����ɾ����־
    {
        char delbook_choise;
        cout << "ȷ��Ҫɾ����(y/n)?" << endl;
        cin >> delbook_choise;
        if (delbook_choise == 'y' || delbook_choise == 'Y')
        {
            this->R_tag = 1;
        }
        
    }

    void addrReader(int n,string na)       //���Ӷ��ߵļ�¼
    {
        this->R_tag = 0;
        this->R_no = n;
        this->R_name = na;
        for (int i = 0; i < MaxBorrow; i++)
        {
            this->R_borBook[i] = 0;
        }
        

    }
    void borrowBook(int bookid)             //����Ĳ���
    {
        for (int i = 0; i < MaxBorrow; i++)
        {
            if (this->R_borBook[i] == 0)
            {
                this->R_borBook[i] = bookid;
            }
        }
    }

    int returnBook(int bookid)             //����Ĳ���
    {
        for (int i = 0; i < MaxBorrow; i++)
        {
            if (this->R_borBook[i] == bookid)
            {
                this->R_borBook[i] = 0;
                cout << "����ɹ�" << endl;
                return 1;
            }
        }
        cout << "������δ���������ʧ��" << endl;
        return 0;
    }

    void showReaderInfo()                   //��ʾ���ߵ���Ϣ
    {
        int hava = 0;
        int bz = 0;

        cout << setw(3) << this->R_no << setw(5) << this->R_name << setw(10);
        for (int i = 0; i < MaxBorrow; i++)
        {
            if (this->R_borBook[i] != 0)
            {
                if (bz == 0)
                {
                    hava = 1;
                    cout << "��" << this->R_borBook[i] << "��\t" << endl;
                    bz++;
                }
            }
            else
            {
                cout << "��" << this->R_borBook << "��\t" << endl;
            }
            if (hava == 0)
            {
                cout << " ����δ�� " << endl;

            }
        }
    }
};



// ���߿���
class ReaderData
{
private:
    /* data */
public:
    ReaderData();
    ~ReaderData();
};