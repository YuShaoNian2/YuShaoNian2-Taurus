#include <iostream>
using namespace std;
struct Student {
    char name [50];
    int id;
    float score;
};
void input (Student *p){
    cout<<"请输入姓名"<<endl;
    cin>>p->name;
    cout<<"请输入学号"<<endl;
    cin>>p->id;
    cout<<"请输入分数"<<endl;
    cin>>p->score;
}
void display(Student *p){
    cout <<"姓名:"<<endl;
    cout <<p->name<<endl;
    cout <<"学号:"<<endl;
    cout <<p->id<<endl;
    cout <<"分数:"<<endl;
    cout <<p->score<<endl;
}
int main (){
    Student *s=new Student();
    input (s);
    display (s);
    delete s;
    system ("pause");
    return 0;
}
