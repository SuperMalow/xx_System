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
    Car();
    ~Car();
    void addCar();      //��ӳ���
    void delCar();      //ɾ������
    void findCar();     //�ҵ�����
    void modCar();      //�޸ĳ���
    void timeAmount();      //����ͣ����ʱ��
    void saveInfor();       //���泵����Ϣ(д���ļ�)
    void showInfor();       //��ʾ��������Ϣ(���ļ�)
};

Car::Car()
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
    //��carData.txt�ļ�
    ifstream carData("carData.txt",ios::in);
    if (! carData)
    {
        //�����carData Ϊ�����ʧ��
        cout << "�ļ���ʧ�ܣ�" << endl;
        return ;
    }
    else        //�ļ��򿪳ɹ�
    {
        string carLicense;      //��Ҫ��ѯ�ĳ��ƺ�
        time_t _time;       
        time_t t1;          //Ϊ�˻�ȡ��ǰ��ʱ��       Ȼ�����ļ���ʱ��������
        bool flag = true;   //����鵽�˳��ƺ�����flagΪfalse  ture��û�в鵽���� false���鵽��

        cout << "������Ҫ��ѯ�ĳ��ƺ�:  ";
        cin >> carLicense;

        while (carData >> carNum)       //��ȡ���ƺ�
        {
            carData >> carType >> color >> allTime;     //��ȡ��������Ϣ
            t1 = time(&_time);      //��ȡ����ǰ��ʱ��
            //���뵽��ȡ���ƺŵ�ѭ�� ��Ҫ�ж�����ĳ��ƺźͶ�ȡ���ĳ��ƺ��Ƿ���ͬ
            if (carLicense == carNum)
            {
                flag = false;       //���ƺ���ͬ��
                break;
            }
        }
        if (flag)
        {
            cout << "δ�ҵ��ó�������Ϣ" << endl;
        }
        else        //�ҵ��� ���������Ϣ
        {
            cout << "���ƺ�: " << carNum << " " << endl;
            cout << "����: " << carType << " " << endl;
            cout << "��ɫ: " << color << " " << endl;
            cout << "ͣ��ʱ��: " << allTime << " " << endl;
            cout << "�Ʒ�: " << (t1 - allTime) * 0.005 << " " << endl;
        }
        carData.close();        //�ر�carData.txt�ļ�
    }
}
//�޸�������Ϣ
void Car::modCar()
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
    string name,str;
    bool flag = true;

    cout << "������Ҫ�޸ĵĳ��ƺţ�" ;
    cin >> carNum;

    //��carData.txt��ȡ���ƺ�
    while (carData >> name)
    {
        getline(carData, str);               //carData��Ϊ������ ���뵽str����
        if (carNum == name)                 //������������ļ���ȡ����һ��
        {
            time_t _time;
            cout << "�޸ĺ�ĳ��ƺţ�";
            cin >> carNum;
            cout << "���޸�Ϊ��" << carNum << endl;

            cout << "�޸ĺ�ĳ������ࣺ" ;
            cin >> carType;
            cout << "���޸�Ϊ��" << carType << endl;

            cout << "�޸ĺ�ĳ�����ɫ��" ;
            cin >> color;
            cout << "���޸�Ϊ��" << color << endl;
            allTime = time(&_time);         //����ǰ��ϵͳʱ��ת����ʽ֮��ֵ��allTime

            outData << carNum << " " << carType << " " << color << " " << allTime << endl;

            flag = false;                       //�鵽��  �����˸����־һ��
            break;
        }
        //����if�����ǲ鵽�˵�  �����ͬ��д��TempcarData����
        outData << name << " " << str << endl;
    }
    if (flag)
    {
        cout << "�޸ĳ������ݲ����ڣ�" << endl;
    }
    else
    {
        while (getline(carData,str))
        {
            outData << str << endl;     //д��TempcarData����
        }
    }
    carData.close();            //�ر�
    outData.close();

    //��ȡTempcarData���������д�뵽carData
    ifstream in("tempcarData.txt", ios::in);
    ofstream out("carData.txt",ios::out);
    if (!in || !out)        //�����������һ����Ϊ��
    {
        cout << "�ļ���ʧ��" << endl;
        return ;
    }
    else
    {
        while (getline(in, str))        //һ��һ�ж�ȡtempcarData���ݵ�str��
        {
            out << str << endl;     //��str����д�뵽carData����
        }
        
    }
    in.close();
    out.close();

}
//ͣ��ʱ��ͳ��
void Car::timeAmount()
{
    ifstream carData("carData.txt",ios::in);
    if (!carData)
    {
        cout << "���ļ�ʧ��" << endl;
        return ;
    }
    else
    {
        //c1 ��ʾ�ܳ���   c2��ʾͣ��������һ��ĳ���
        int c1 = 0,c2 = 0;
        time_t _time,t1;
        while (carData >> carNum)
        {
            c1++;
            t1 = time(&_time);
            
            //��ȡ����
            carData >> carType >> color >> allTime;

            //����ʱ�� ������һ�������
            if ((t1 - allTime) * 0.0001 < long(8.64))   
            {
                c2++;
            }
        }
        //ѭ�������˾���ʾ������ͣ��ʱ����Ϣ
        cout << "����������" << c1 << endl;
        cout << "ͣ��ʱ�䲻����һ�죺" << c2 << endl;
        cout << "ͣ��ʱ�䳬��һ��" << c1 - c2 << endl;
    }
    carData.close();    

}
//������Ϣ����
void Car::saveInfor()
{
    //�ļ������ ��carData�ļ�
    ofstream outData("carData.txt",ios::app);
    if (!outData)
    {
        cout << "���ļ�ʧ��" << endl;
    }
    else
    {
        //����Ϣ���浽�ļ���
        outData << carNum << " " << carType << " " << color << " " << allTime << endl;
    }
    outData.close();
}
//ͣ������Ϣ��ʾ ��ʾ���г���
void Car::showInfor()
{
    ifstream carData("carData.txt",ios::in);
    if (!carData)
    {
        cout << "���ļ�ʧ�ܣ�" << endl;
        return ;
    }
    else
    {
        bool flag = true;
        time_t _time,t;

        while (carData >> carNum)
        {
            //��ȡ����
            carData >> carType >> color >> allTime;
            t = time(&_time);       //��ȡ��ǰʱ��

            //���
            cout << "���ƺţ�" << carNum << " " << "�������ͣ�" << carType << " "
            << "��ɫ��" << color << " " << "ͣ��ʱ����" << (t - allTime) << "��"
            << " " << "�Ʒѣ�" << (t - allTime) * 0.05 << "Ԫ" << endl;
            flag = false;
        }
        if (flag)
        {
            cout << "\n�޳�����Ϣ" << endl;
        }
        else
        {
            cout << "\n��������ʾ" << endl;
        }        
        carData.close();
    }
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
    Car car;
    while (true)
    {
        system("cls");              //����
        cout << "1.��ʾ����״��" << endl;
        cout << "2.��ѯ������Ϣ" << endl;
        cout << "3.ͳ�Ƴ���" << endl;
        cout << "4.�˳���ͨ�û�" << endl;
        char ch;
        cout << "������Ҫִ�еĲ���: " ;
        cin >> ch;
        switch (ch)
        {
        case '1':
            car.showInfor();                    //��ʾ������Ϣ
            break;
        case '2':
            car.findCar();                      //��ѯ����
            break;
        case '3':
            car.timeAmount();                    //ͳ�Ƴ��� 
            break;
        case '4':
            return;   
        default:
            cout << "��������ȷ�Ĳ���" << endl;
        }
        system("pause");
    }
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
    Car car;
    while (true)
    {
        system("cls");              //��������
        cout << "1.���ӳ���" << endl;
        cout << "2.��ʾ���г�����Ϣ" << endl;
        cout << "3.��ѯ" << endl;
        cout << "4.�޸�" << endl;
        cout << "5.ɾ��" << endl;
        cout << "6.ͳ��" << endl;
        cout << "7.�˳������û�" << endl;

        char ch;
        cout << "������Ҫִ�еĲ���: " ;
        cin >> ch;
        switch (ch)
        {
        case '1':
            car.addCar();                       //���ӳ���
            break;
        case '2':
            car.showInfor();                    //��ʾ���г�����Ϣ
            break;
        case '3':
            car.findCar();                      //��ѯ 
            break;
        case '4':
            car.modCar();                       //�޸�
            break;   
        case '5':
            car.delCar();                       //ɾ��
        case '6':
            car.timeAmount();                   //ͳ��
        case '7':
            return;                              //�˳�
        default:
            cout << "��������ȷ�Ĳ���" << endl;
        }
        system("pause");
    }
}
