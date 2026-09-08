#include<iostream>
#include<string>
using namespace std;
#define MAX 1000
//联系人结构体
struct person{ 
    string m_name;
    int m_sex;
    int m_age;
    string m_phone;
    string m_address;
};
//通讯录结构体
struct addressbooks{
    struct person per_arr[MAX];
    int m_size;
};
//菜单界面
void showMenu()
{
    cout<<"***********************"<<endl;
    cout<<"***** 1.添加联系人 *****"<<endl;
    cout<<"***** 2.显示联系人 *****"<<endl;
    cout<<"***** 3.删除联系人 *****"<<endl;
    cout<<"***** 4.查找联系人 *****"<<endl;
    cout<<"***** 5.修改联系人 *****"<<endl;
    cout<<"***** 6.清空联系人 *****`"<<endl;
    cout<<"***** 0.退出通讯录 *****"<<endl;
    cout<<"***********************"<<endl;
}
//1.添加联系人
void addperson(addressbooks *abs){
    if(abs->m_size==MAX){
        cout<<"通讯录已满，无法添加"<<endl;
        return;
    }
    else{
        //姓名
        string name;
        cout<<"请输入姓名"<<endl;
        cin>>name;
        abs->per_arr[abs->m_size].m_name=name;
        //性别
        int sex;
        cout<<"请输入性别"<<endl;
        cout<<"1--男"<<endl;
        cout<<"2--女"<<endl;
        while(true){
            cin>>sex;
            if(sex==1 || sex==2){
                abs->per_arr[abs->m_size].m_sex=sex;
                break;
            }
            else cout<<"输入有误，重新输入"<<endl;
        }
        //年龄
        int age=0;
        cout<<"请输入年龄"<<endl;
        cin>>age;
        abs->per_arr[abs->m_size].m_age=age;
        //电话
        string phone;
        cout<<"请输入联系电话"<<endl;
        while(true){
            cin>>phone;
            if(phone.length()==11){
                abs->per_arr[abs->m_size].m_phone=phone;
                break;
            }
            else cout<<"输入有误，请重新输入"<<endl;
        }
        //地址
        string address;
        cout<<"请输入家庭住址"<<endl;
        cin>>address;
        abs->per_arr[abs->m_size].m_address=address;
        //更新人数
        abs->m_size++;
        cout<<"添加成功"<<endl;
        system("pause");
        system("cls");
    }
}
//2.显示联系人
void showperson(addressbooks *abs){
    if(abs->m_size==0){
        cout<<"当前记录为空"<<endl;
    }
    else{
        for(int i=0;i<abs->m_size;i++){
            cout<<"姓名："<<abs->per_arr[i].m_name<<"\t";
            cout<<"姓别："<<(abs->per_arr[i].m_sex==1?"男":"女")<<"\t";
            cout<<"年龄："<<abs->per_arr[i].m_age<<"\t";
            cout<<"电话："<<abs->per_arr[i].m_phone<<"\t";
            cout<<"住址："<<abs->per_arr[i].m_address<<endl;
        }
    }
    system("pause");
    system("cls");
}
//3.1检测联系人是否存在,存在返回数组中具体位置，不存在返回-1
int isExist(addressbooks *abs,string name){
    for(int i=0;i<abs->m_size;i++){
        if(abs->per_arr[i].m_name==name){
            return i;
        }
    }
    return -1;
}
//3.2删除指定联系人
void deleteperson(addressbooks *abs){
    cout<<"输入你要删除的联系人"<<endl;
    string name;
    cin>>name;
    int ret=isExist(abs,name);
    if(ret!=-1){
        for(int i=ret;i<abs->m_size;i++){
            abs->per_arr[i]=abs->per_arr[i+1];
            abs->m_size--;
            cout<<"删除成功"<<endl;
        }
    }
    else  cout<<"查无此人"<<endl;
    system("pause");
    system("cls");
}
//4.查找联系人
void findperson(addressbooks *abs){
    cout<<"请输入您要查找的联系人"<<endl;
    string name;
    cin>>name;
    int ret=isExist(abs,name);
    if(!ret!=-1){
        cout<<"姓名："<<abs->per_arr[ret].m_name<<"\t";
        cout<<"姓别："<<(abs->per_arr[ret].m_sex==1?"男":"女")<<"\t";
        cout<<"年龄："<<abs->per_arr[ret].m_age<<"\t";
        cout<<"电话："<<abs->per_arr[ret].m_phone<<"\t";
        cout<<"住址："<<abs->per_arr[ret].m_address<<endl;
    }
    else cout<<"查无此人"<<endl;
    system("pause");
    system("cls");
}
//修改联系人
void modifyperson(addressbooks *abs){
    cout<<"请输入要修改的联系人"<<endl;
    string name;
    cin>>name;
    int ret=isExist(abs,name);
    if(ret==-1)  cout<<"查无此人"<<endl;
    else{
        //姓名
        string name;
        cout<<"请输入姓名："<<endl;
        cin>>name;
        abs->per_arr[ret].m_name=name;
        //性别
        int sex;
        cout<<"请输入性别"<<endl;
        cout<<"1--男"<<endl;
        cout<<"2--女"<<endl;
        while(true){
            cin>>sex;
            if(sex==1 || sex==2){
                abs->per_arr[ret].m_sex=sex;
                break;
            }
            else cout<<"输入有误，重新输入"<<endl;
        }
        //年龄
        int age;
        cout<<"请输入年龄："<<endl;
        cin>>age;
        abs->per_arr[ret].m_age=age;
        //手机号
        int phone;
        cout<<"请输入联系电话："<<endl;
        cin>>name;
        abs->per_arr[ret].m_phone=phone;
        //地址
        string address;
        cout<<"请输入家庭地址："<<endl;
        cin>>name;
        abs->per_arr[ret].m_address=address;
        cout<<"修改成功"<<endl;
    }
    system("pause");
    system("cls");
}
//清空联系人
void cleanperson(addressbooks *abs){
    abs->m_size=0;
    cout<<"通讯录已清空"<<endl;
    cout<<"无法查找"<<endl;
    system("pause");
    system("cls");
}
int main()
{
    addressbooks abs;
    abs.m_size=0;
    int select=0;
    while(true){
        showMenu();
        cin>>select;
        if(select==1){  //添加联系人
            addperson(&abs);           
        }
        else if(select==2){  //显示联系人
            showperson(&abs);     
        }
        else if(select==3){  //删除联系人
            deleteperson(&abs);
        }
        else if(select==4){  //查找联系人
            findperson(&abs);
        }
        else if(select==5){  //修改联系人
            modifyperson(&abs);
        }
        else if(select==6){  //清空联系人
            cleanperson(&abs);
        }
        else if(select==0){  //退出通讯录
           cout<<"欢迎下次使用"<<endl;
           system("pause");
           return 0;
           break;      
        }
        else break;
    }
    return 0;
}