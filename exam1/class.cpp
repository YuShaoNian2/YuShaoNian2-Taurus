#include<iostream>
#include<string>
using namespace std;
class Car {
private:
    string color;
    int number;
public:
    Car (string c,int n){
        color = c;
        number = n;
    }
    ~Car(){}
void display(){
        cout <<"颜色："<<color<<endl;
        cout <<"车牌号："<<number<<endl;

    }
};
int main(){
    Car car1("红色",666666);
    Car car2("黑色",888888);
    car1.display();
    car2.display();
    system("pause");
    return 0;
}
