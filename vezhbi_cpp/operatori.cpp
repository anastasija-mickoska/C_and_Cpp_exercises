#include <iostream>
#include <math.h>
using namespace std;

class Dropki {
private:
    int broitel;
    int imenitel;

public:
    Dropki(int b = 0, int i = 1) {
        if (i == 0) throw invalid_argument("Ne moze da se deli so 0!");
        broitel = b;
        imenitel = i;
    }

    int NZD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    Dropki operator+(Dropki d) {
        Dropki temp;
        temp.broitel=broitel*d.imenitel + d.broitel*imenitel;
        temp.imenitel=imenitel * d.imenitel;
        temp.imenitel/=NZD(temp.broitel, temp.imenitel);
        temp.broitel/=NZD(temp.broitel, temp.imenitel);
        return temp;
    }
    Dropki operator-(Dropki d) {
        Dropki temp;
        temp.broitel=broitel*d.imenitel - d.broitel*imenitel;
        temp.imenitel=imenitel * d.imenitel;
        temp.imenitel/=NZD(temp.broitel, temp.imenitel);
        temp.broitel/=NZD(temp.broitel, temp.imenitel);
        return temp;
    }

    Dropki operator*(Dropki d) {
        Dropki temp;
        temp.broitel=broitel * d.broitel;
        temp.imenitel=imenitel * d.imenitel;
        temp.imenitel/=NZD(temp.broitel, temp.imenitel);
        temp.broitel/=NZD(temp.broitel, temp.imenitel);
        return temp;
    }

    Dropki operator/(Dropki d) {
        if (d.broitel == 0) throw invalid_argument("Ne moze da delime so 0!");
        Dropki temp;
        temp.broitel=broitel * d.imenitel;
        temp.imenitel=imenitel * d.broitel;
        temp.imenitel/=NZD(temp.broitel, temp.imenitel);
        temp.broitel/=NZD(temp.broitel, temp.imenitel);
        return temp;
    }

    Dropki operator+(int b) {
        Dropki temp;
        temp.broitel = broitel + b*imenitel;
        temp.imenitel = imenitel;
        temp.imenitel/=NZD(temp.broitel, temp.imenitel);
        temp.broitel/=NZD(temp.broitel, temp.imenitel);
        return temp;
    }

    Dropki operator-(int b) {
        Dropki temp;
        temp.broitel = broitel - b*imenitel;
        temp.imenitel = imenitel;
        temp.imenitel/=NZD(temp.broitel, temp.imenitel);
        temp.broitel/=NZD(temp.broitel, temp.imenitel);
        return temp;
    }

    Dropki operator*(int b) {
        Dropki temp;
        temp.broitel = broitel * b;
        temp.imenitel = imenitel;
        temp.imenitel/=NZD(temp.broitel, temp.imenitel);
        temp.broitel/=NZD(temp.broitel, temp.imenitel);
        return temp;
    }

    Dropki operator/(int b) {
        Dropki temp;
        temp.broitel = broitel;
        temp.imenitel = imenitel * b;
        temp.imenitel/=NZD(temp.broitel, temp.imenitel);
        temp.broitel/=NZD(temp.broitel, temp.imenitel);
        return temp;
    }

    void pechati() const {
        if(imenitel == 1 ) {
            cout<<broitel<<endl;
        }
        cout << broitel << "/" << imenitel;
    }

    void pechatiRealen() const {
        if(imenitel == 1 ) {
            cout<<broitel<<endl;
        }
        cout << (double)broitel / imenitel;
    }
};

int main() {
    Dropki d1(1, 3);
    Dropki d2(5, 6);
    Dropki d3(3, 2);
    int d4 = 5;

    cout << "Zbir na dropkite ";
    d1.pechati();
    cout << " i ";
    d2.pechati();
    cout << " e ";
    Dropki zbir = (d1+d2);
    zbir.pechati();
    cout << endl;

    cout << "Razlika na dropkite ";
    d1.pechati();
    cout << " i ";
    d2.pechati();
    cout << " e ";
    Dropki razlika = (d1-d2);
    razlika.pechati();
    cout << endl;

    cout << "Proizvod na dropkite ";
    d1.pechati();
    cout << " i ";
    d2.pechati();
    cout << " e ";
    Dropki proizvod = (d1*d2);
    proizvod.pechati();
    cout << endl;

    cout << "Kolicnik na dropkite ";
    d1.pechati();
    cout << " i ";
    d2.pechati();
    cout << " e ";
    Dropki kolicnik = (d1/d2);
    kolicnik.pechati();
    cout << endl;


    cout << "Zbir na dropkata ";
    d3.pechati();
    cout << " i brojot " <<d4<<" e ";
    Dropki zbir1 = (d3+d4);
    zbir1.pechati();
    cout << endl;

    cout << "Razlika na dropkite ";
    d3.pechati();
    cout << " i brojot " <<d4<<" e ";
    Dropki razlika1 = (d3-d4);
    razlika1.pechati();
    cout << endl;

    cout << "Proizvod na dropkite ";
    d3.pechati();
    cout << " i brojot " <<d4<<" e ";
    Dropki proizvod1 = (d3*d4);
    proizvod1.pechati();
    cout << endl;

    cout << "Kolicnik na dropkite ";
    d3.pechati();
    cout << " i brojot " <<d4<<" e ";
    Dropki kolicnik1 = (d3/d4);
    kolicnik1.pechati();
    cout << endl;

    return 0;
}
