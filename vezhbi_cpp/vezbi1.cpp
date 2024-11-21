#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;
using namespace std;

//zadaca 1
inline float circleArea(int radius) {
    return radius*radius*3.14;
}

//zadaca 2
int tripleCallByValue(int count) {
    count *= 3;
    return count;
}

void tripleCallByReference(int &count) {
    count *= 3;
}

//zadaca 1 - vezbi 2

template <typename C>
C min(C a, C b, C c) {
    C minimum=a;
    if(b<minimum) {
        minimum = b;
    }
    if(c<minimum) {
        minimum=c;
    }
    return minimum;
}

int main()
{
    //zadaca 1
    int r;
    cout<<"Vnesi radius.\n"<<endl;
    cin>>r;
    cout<<"Povrsinata na krugot e :"<<circleArea(r)<<endl;

    //zadaca 2
    int count=10;
    int count1=tripleCallByValue(count);
    cout<<"count="<<count<<endl;
    cout<<"Call by value : "<<count1<<endl;
    tripleCallByReference(count);
    cout<<"Call by reference : "<<count<<endl;

    //zadaca 1 - vezbi 2
    int a,b,c;
    cout<<"Vnesi tri celobrojni vrednosti."<<endl;
    cin>>a>>b>>c;
    cout<<"Minimumot e: "<<min(a,b,c)<<endl;
    double a1,b1,c1;
    cout<<"Vnesi tri double vrednosti."<<endl;
    cin>>a1>>b1>>c1;
    cout<<"Minimumot e: "<<min(a1,b1,c1)<<endl;
    char a2,b2,c2;
    cout<<"Vnesi tri karakteri."<<endl;
    cin>>a2>>b2>>c2;
    cout<<"Minimumot e: "<<min(a2,b2,c2)<<endl;

    return 0;
}
