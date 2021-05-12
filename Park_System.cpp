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
    //打开carData.txt文件
    ifstream carData("carData.txt",ios::in);
    if (! carData)
    {
        //如果！carData 为真则打开失败
        cout << "文件打开失败！" << endl;
        return ;
    }
    else        //文件打开成功
    {
        string carLicense;      //需要查询的车牌号
        time_t _time;       
        time_t t1;          //为了获取当前的时间       然后与文件的时间做减法
        bool flag = true;   //如果查到了车牌号则让flag为false  ture：没有查到车辆 false：查到了

        cout << "请输入要查询的车牌号:  ";
        cin >> carLicense;

        while (carData >> carNum)       //读取车牌号
        {
            carData >> carType >> color >> allTime;     //读取车辆的信息
            t1 = time(&_time);      //获取到当前的时间
            //进入到读取车牌号的循环 需要判断输入的车牌号和读取到的车牌号是否相同
            if (carLicense == carNum)
            {
                flag = false;       //车牌号相同了
                break;
            }
        }
        if (flag)
        {
            cout << "未找到该车辆的信息" << endl;
        }
        else        //找到了 输出车辆信息
        {
            cout << "车牌号: " << carNum << " " << endl;
            cout << "类型: " << carType << " " << endl;
            cout << "颜色: " << color << " " << endl;
            cout << "停车时长: " << allTime << " " << endl;
            cout << "计费: " << (t1 - allTime) * 0.005 << " " << endl;
        }
        carData.close();        //关闭carData.txt文件
    }
}
//修改汽车信息
void Car::modCar()
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
    string name,str;
    bool flag = true;

    cout << "请输入要修改的车牌号：" ;
    cin >> carNum;

    //从carData.txt读取车牌号
    while (carData >> name)
    {
        getline(carData, str);               //carData作为输入流 输入到str里面
        if (carNum == name)                 //输入的数据与文件读取到的一致
        {
            time_t _time;
            cout << "修改后的车牌号：";
            cin >> carNum;
            cout << "已修改为：" << carNum << endl;

            cout << "修改后的车的种类：" ;
            cin >> carType;
            cout << "已修改为：" << carType << endl;

            cout << "修改后的车的颜色：" ;
            cin >> color;
            cout << "已修改为：" << color << endl;
            allTime = time(&_time);         //将当前的系统时间转换格式之后赋值给allTime

            outData << carNum << " " << carType << " " << color << " " << allTime << endl;

            flag = false;                       //查到了  查完了给其标志一下
            break;
        }
        //上面if里面是查到了的  如果不同则写入TempcarData里面
        outData << name << " " << str << endl;
    }
    if (flag)
    {
        cout << "修改车辆数据不存在！" << endl;
    }
    else
    {
        while (getline(carData,str))
        {
            outData << str << endl;     //写入TempcarData里面
        }
    }
    carData.close();            //关闭
    outData.close();

    //读取TempcarData里面的数据写入到carData
    ifstream in("tempcarData.txt", ios::in);
    ofstream out("carData.txt",ios::out);
    if (!in || !out)        //如果两个其中一个都为空
    {
        cout << "文件打开失败" << endl;
        return ;
    }
    else
    {
        while (getline(in, str))        //一行一行读取tempcarData数据到str里
        {
            out << str << endl;     //把str数据写入到carData里面
        }
        
    }
    in.close();
    out.close();

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