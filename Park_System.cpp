#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;


class Car
{
private:
    string carNum;        //���ƺ�
    string carType;      //��������
    string color;       //������ɫ
    time_t allTime;    //ͣ��ʱ��
public:
    Car(string num,string type,string color,time_t time);
    ~Car();
    void addCar();      //��ӳ���
    void delCar();      //ɾ������
    void findCar();     //�ҵ�����
    void modCar();      //�޸ĳ���
    void timeAmount();      //����ͣ����ʱ��
    void saveInfor();       //���泵����Ϣ(д���ļ�)
    void showInfor();       //��ʾ��������Ϣ(���ļ�)
};

Car::Car(string num,string type,string color,time_t time):carNum(num),carType(type),color(color),allTime(time)
{
}

Car::~Car()
{
}

//���������Ϣ
void Car::addCar()
{
    time_t _time;
    while (true)
    {
       cout << "�����복�ƺ���" << endl;
       cin >> carNum;
        //�ж��ļ����Ƿ�����ͬ�ĳ��ƺ�
        ifstream file("carData.txt",ios::in);       //��ȡ�ļ�
        //����򿪳ɹ���ִ�г��Ʋ�ѯ�Ĳ���
        if (file)
        {
            char buf[1024];
            string strs[20];
            int index = 0;
            while (!file.eof())         //��ȡ�ļ���ֱ���ļ���ĩβ
            {
                file.getline(buf,100);       //ÿ�ζ�ȡһ�����ݣ������浽buf������
                strs[index] = buf[0];       //����һ���ַ�buf[0](Ҳ���ǳ��ƺ�)���浽strs��
                index++;
            }
            for (auto& num : strs)      //��ǿ��forѭ�� ����strs����
            {
                //�ж�������ĳ��ƺ��Ƿ��strs��Ԫ�����ظ�
                if (num == carNum)
                {
                    cout << "���ƺ��ظ�" << endl;
                    return ;
                }
            }
        }
        cout << "�����복������:  ";
        cin >> carType;
        cout << "�����복����ɫ:  " ;
        cin >> color;
        allTime = time(&_time);     //��¼ͣ��ʱ��
        //����saceInfor()������������������Ϣ
        saveInfor();
        char ch;
        cout << "  �����Ƿ����(y/n)? " ;
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
        {
            break;
        }
    }
}
//ɾ��������Ϣ
void Car::delCar()
{
    //�����ļ���ȡ������carData.txt�ļ�
    ifstream carData("carData.txt",ios::in);
    //�����ļ�д����,��tempcarData.txt�ļ�
    ofstream outData("tempcarData.txt",ios::out);
    if (!carData || !outData)
    {
        //�������ļ�ʧ��
        cout << "���ļ�ʧ�ܣ�" << endl;
        return ;
    }
    string carlicense;      //���Ҫɾ���ĳ��ƺ�
    string name;
    string str;
    bool flag = true;
    cout << "������Ҫɾ���ĳ��ƺ�:  " << endl;
    cin >> carlicense;
    //��ȡ�ļ���һ���ֶ�(���ƺ�)  >>���������ո�ͽ�����ȡ
    while (carData >> name)     //��ȡ�����ֶδ�ŵ�name����
    {
        cout << "name���ֶ�:" << name << endl;
        getline(carData,str);       //carData��Ϊ������ ���뵽str����getline��������
        //������ ���ɾ����������Ϣ
        if (carlicense == name)
        {
            cout << "Ҫɾ���ĳ�����Ϣ: " << endl << str << endl;
            flag = false;
            break;
        }
        //�������� ������Ϣд�뵽tempcarData.txt�ļ���
        outData << name << " " << str << endl;
    }
    if (flag)
    {
        cout << "�ó��ƺŲ����ڣ�" << endl;
    }
    else
    {
        while (getline(carData, str))
        {
            outData << str << endl;     //д�뵽tempcarData�ļ�
        }
        carData.close();        //�ر��ļ�
        outData.close();
    }
    //��ȡtempcarData.txt�ļ�������д�뵽carData.txt�ļ���
    ifstream in("tempcarData.txt",ios::in);
    ofstream out("carData.txt",ios::out);
    if (!in || !out)
    {
        cout << "�ļ���ʧ�ܣ�" << endl;
        return ;
    }
    else
    {
        while (getline(in,str))
        {
            out << str << endl;
        }
        in.close();
        out.close();        //�ر������ļ�
    }
}
//����������Ϣ
void Car::findCar()
{

}
//�޸�������Ϣ
void Car::modCar()
{

}
//ͣ��ʱ��ͳ��
void Car::timeAmount()
{

}
//������Ϣ����
void Car::saveInfor()
{

}
//ͣ������Ϣ��ʾ
void Car::showInfor()
{

}


class User
{
private:
    /* data */
public:
    User();
    ~User();
    void checkCar();
};

User::User()
{
}

User::~User()
{
}

void User::checkCar()
{

}


class Admin
{
private:
    /* data */
public:
    Admin();
    ~Admin();
    void manager();
};

Admin::Admin()
{
}

Admin::~Admin()
{
}

void Admin::manager()
{

}


int main()
{


    system("pause");
    return 0;
}