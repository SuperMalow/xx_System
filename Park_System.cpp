#include <iostream>
#include <string>

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
    void addCar();
    void delCar();
    void findCar();
    void modCar();
    void timeAmount();
    void saveInfor();
    void showInfor();
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

}
//ɾ��������Ϣ
void Car::delCar()
{

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