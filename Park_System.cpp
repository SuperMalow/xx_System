#include <iostream>
#include <string>

using namespace std;


class Car
{
private:
    string carNum;        //车牌号
    string carType;      //汽车类型
    string color;       //汽车颜色
    time_t allTime;    //停车时间
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

//添加汽车信息
void Car::addCar()
{

}
//删除汽车信息
void Car::delCar()
{

}
//查找汽车信息
void Car::findCar()
{

}
//修改汽车信息
void Car::modCar()
{

}
//停车时长统计
void Car::timeAmount()
{

}
//汽车信息保存
void Car::saveInfor()
{

}
//停车场信息显示
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