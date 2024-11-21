#include <iostream>
using namespace std;

class Dropki {
private:
    int broitel;
    int imenitel;

public:
    Dropki(int b = 0, int i = 1) {
        broitel = b;
        imenitel = (i == 0) ? 1 : i;
    }

    int NZD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    Dropki sobiranje(const Dropki& d) {
        int sumB = broitel * d.imenitel + d.broitel * imenitel;
        int im = imenitel * d.imenitel;
        int m= NZD(sumB,im);
        sumB/=m;
        im/=m;
        return Dropki(sumB, im);
    }

    Dropki odzemanje(const Dropki& d) {
        int minus = broitel * d.imenitel - d.broitel * imenitel;
        int im = imenitel * d.imenitel;
        int m= NZD(minus,im);
        minus/=m;
        im/=m;
        return Dropki(minus, im);
    }

    Dropki mnozenje(const Dropki& d) {
        int pr = broitel * d.broitel;
        int im = imenitel * d.imenitel;
        int m= NZD(pr,im);
        pr/=m;
        im/=m;
        return Dropki(pr, im);
    }

    Dropki delenje(const Dropki& d) {
        int p = broitel * d.imenitel;
        int im = imenitel * d.broitel;
        int m= NZD(p,im);
        p/=m;
        im/=m;
        return Dropki(p, im);
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
    Dropki d1(2, 4);
    Dropki d2(2, 8);
    Dropki d3(3, 0);
    Dropki d4(1, 6);

    cout << "Zbir na dropkite ";
    d1.pechati();
    cout << " i ";
    d2.pechati();
    cout << " e ";
    Dropki zbir = d1.sobiranje(d2);
    zbir.pechati();
    cout << endl;

    cout << "Razlika na dropkite ";
    d1.pechati();
    cout << " i ";
    d2.pechati();
    cout << " e ";
    Dropki razlika = d1.odzemanje(d2);
    razlika.pechati();
    cout << endl;

    cout << "Proizvod na dropkite ";
    d1.pechati();
    cout << " i ";
    d2.pechati();
    cout << " e ";
    Dropki proizvod = d1.mnozenje(d2);
    proizvod.pechati();
    cout << endl;

    cout << "Kolicnik na dropkite ";
    d1.pechati();
    cout << " i ";
    d2.pechati();
    cout << " e ";
    Dropki kolicnik = d1.delenje(d2);
    kolicnik.pechati();
    cout << endl;


    cout << "Zbir na dropkite ";
    d3.pechati();
    cout << " i ";
    d4.pechati();
    cout << " e ";
    Dropki zbir1 = d3.sobiranje(d4);
    zbir1.pechati();
    cout << endl;

    cout << "Razlika na dropkite ";
    d3.pechati();
    cout << " i ";
    d4.pechati();
    cout << " e ";
    Dropki razlika1 = d3.odzemanje(d4);
    razlika1.pechati();
    cout << endl;

    cout << "Proizvod na dropkite ";
    d3.pechati();
    cout << " i ";
    d4.pechati();
    cout << " e ";
    Dropki proizvod1 = d3.mnozenje(d4);
    proizvod1.pechati();
    cout << endl;

    cout << "Kolicnik na dropkite ";
    d3.pechati();
    cout << " i ";
    d4.pechati();
    cout << " e ";
    Dropki kolicnik1 = d3.delenje(d4);
    kolicnik1.pechati();
    cout << endl;

    return 0;
}
