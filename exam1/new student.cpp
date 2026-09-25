#include <iostream>
using namespace std;
struct student {
    char name [50];
    long long id;
    float score;
};
void input (student *p){
    cout <<"1.请输入学生姓名"<<endl;
    cin>>p->name;
    cout <<"2.请输入学生学号"<<endl;
    cin >>p->id;
    cout <<"3.请输入学生分数"<<endl;
    cin>>p->score;
}
void display(student*p){
    cout <<"1\t姓名:"<<p->name<<endl;
    cout <<"2\t学号:"<<p->id<<endl;
    cout <<"3\t分数:"<<p->score<<endl;
}
int main(){
    student *p=new student ();
    input(p);
    display(p);
    delete p;
    system ("pause");
    return 0;
}