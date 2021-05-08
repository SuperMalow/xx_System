#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

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
    void addCar();      //添加车辆
    void delCar();      //删除车辆
    void findCar();     //找到车辆
    void modCar();      //修改车辆
    void timeAmount();      //计算停车的时长
    void saveInfor();       //保存车辆信息(写入文件)
    void showInfor();       //显示车辆的信息(读文件)
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
    time_t _time;
    while (true)
    {
       cout << "请输入车牌号码" << endl;
       cin >> carNum;
        //判断文件中是否有相同的车牌号
        ifstream file("carData.txt",ios::in);       //读取文件
        //如果打开成功，执行车牌查询的操作
        if (file)
        {
            char buf[1024];
            string strs[20];
            int index = 0;
            while (!file.eof())         //读取文件，直到文件的末尾
            {
                file.getline(buf,100);       //每次读取一行数据，并储存到buf数组中
                strs[index] = buf[0];       //将第一个字符buf[0](也就是车牌号)保存到strs中
                index++;
            }
            for (auto& num : strs)      //增强型for循环 遍历strs数组
            {
                //判断新输入的车牌号是否跟strs中元素有重复
                if (num == carNum)
                {
                    cout << "车牌号重复" << endl;
                    return ;
                }
            }
        }
        cout << "请输入车的类型:  ";
        cin >> carType;
        cout << "请输入车的颜色:  " ;
        cin >> color;
        allTime = time(&_time);     //记录停车时间
        //调用saceInfor()函数保存新增车辆信息
        saveInfor();
        char ch;
        cout << "  请问是否继续(y/n)? " ;
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
        {
            break;
        }
    }
}
//删除汽车信息
void Car::delCar()
{
    //创建文件读取流，打开carData.txt文件
    ifstream carData("carData.txt",ios::in);
    //创建文件写入流,打开tempcarData.txt文件
    ofstream outData("tempcarData.txt",ios::out);
    if (!carData || !outData)
    {
        //打开两个文件失败
        cout << "打开文件失败！" << endl;
        return ;
    }
    string carlicense;      //存放要删除的车牌号
    string name;
    string str;
    bool flag = true;
    cout << "请输入要删除的车牌号:  " << endl;
    cin >> carlicense;
    //读取文件第一个字段(车牌号)  >>右移遇到空格就结束读取
    while (carData >> name)     //读取到的字段存放到name里面
    {
        cout << "name的字段:" << name << endl;
        getline(carData,str);       //carData作为输入流 输入到str里面getline函数解释
        //如果相等 输出删除车辆的信息
        if (carlicense == name)
        {
            cout << "要删除的车辆信息: " << endl << str << endl;
            flag = false;
            break;
        }
        //如果不相等 车辆信息写入到tempcarData.txt文件中
        outData << name << " " << str << endl;
    }
    if (flag)
    {
        cout << "该车牌号不存在！" << endl;
    }
    else
    {
        while (getline(carData, str))
        {
            outData << str << endl;     //写入到tempcarData文件
        }
        carData.close();        //关闭文件
        outData.close();
    }
    //读取tempcarData.txt文件的数据写入到carData.txt文件中
    ifstream in("tempcarData.txt",ios::in);
    ofstream out("carData.txt",ios::out);
    if (!in || !out)
    {
        cout << "文件打开失败！" << endl;
        return ;
    }
    else
    {
        while (getline(in,str))
        {
            out << str << endl;
        }
        in.close();
        out.close();        //关闭两个文件
    }
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