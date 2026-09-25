#include <iostream>
using namespace std;
struct student {
    char name [50];
    long long id;
    float score;
};
void input (student* p){//需要的是结构体的指针
    cout <<"请输入学生名字"<<endl;
    cin>>p->name ;
    cout <<"请输入学生id"<<endl;
    cin>>p->id;
    cout <<"请输入学生分数（可以有小数）"<<endl;
    cin>>p->score ;
}
void display (student*p){
    cout <<"该学生的姓名是"<<p->name<<endl;
    cout <<"该学生的学号是"<<p->id<<endl;
    cout <<"该学生的成绩是"<<p->score<<endl;
}
int main (){
    student *p =new student();//动态分布内存，记得回收
    input (p);
    display(p);
    delete p;
    system("pause");
    return 0;
}

