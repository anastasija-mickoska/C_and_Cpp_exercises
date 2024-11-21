#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

class Oblik {
protected:
    static int brojNaObjekti;
public:
    Oblik() {
        brojNaObjekti++;
    }
    static int getBrojNaObjekti() {
        return brojNaObjekti;
    }
    void prikazhi() {
        cout<<"Oblik:";
    }
};
int Oblik::brojNaObjekti = 0;

class DvoDimenzionalni : public Oblik {
protected:
    static int brojNaObjekti2D;

public:
    DvoDimenzionalni() : Oblik() {
        brojNaObjekti2D++;
    }
    static int getBrojNaObjekti2D() {
        return brojNaObjekti2D;
    }
    void prikazhi2D() {
        prikazhi();
        cout<<"Dvodimenzionalen - ";
    }
};
int DvoDimenzionalni::brojNaObjekti2D = 0;

class Krug : public DvoDimenzionalni {
    double radius;

public:
    Krug(double r) : radius(r) {}
    void prikazhiKrug() {
        prikazhi2D();
        cout << "Krug so radius " << radius << " i plostina " << 3.14 * radius * radius << endl;
    }
};

class Kvadrat : public DvoDimenzionalni {
    double strana;
public:
    Kvadrat(double s) : strana(s) {}
    void prikazhiKvadrat() {
        prikazhi2D();
        cout << "Kvadrat so strana " << strana << " i plostina " << strana * strana << endl;
    }
};

class TroDimenzionalni : public Oblik {
protected:
    static int brojNaObjekti3D;
public:
    TroDimenzionalni() : Oblik() {
        brojNaObjekti3D++;
    }
    static int getBrojNaObjekti3D() {
        return brojNaObjekti3D;
    }
    void prikazhi3D() {
        prikazhi();
        cout<<"Trodimenzionalen - ";
    }
};
int TroDimenzionalni::brojNaObjekti3D = 0;

class Topka : public TroDimenzionalni {
    double radius;

public:
    Topka(double r) : radius(r) {}
    void prikazhiTopka() {
        prikazhi3D();
        cout << "Topka so radius " << radius << " i volumen " << (4.0 / 3) * 3.14 * pow(radius, 3) << endl;
    }
};

class Kocka : public TroDimenzionalni {
    double strana;
public:
    Kocka(double s) : strana(s) {}
    void prikazhiKocka() {
        prikazhi3D();
        cout << "Kocka so strana " << strana << " i volumen " << pow(strana, 3) << endl;
    }
};

int main() {
    int izbor=-1;
    Krug k1(5);
    Kvadrat kv(4);
    Topka t(3);
    Kocka k2(2);

    cout << "Direktno kreirani objekti:" << endl;
    k1.prikazhiKrug();
    kv.prikazhiKvadrat();
    t.prikazhiTopka();
    k2.prikazhiKocka();

    while(izbor != 0) {
        cout << "Vnesi objekt:" << endl;
        cout << "Izbor (1 - Krug, 2 - Kvadrat, 3 - Topka, 4 - Kocka): ";
        cout<<"Vnesi 0 za kraj."<<endl;
        cin >> izbor;
        switch(izbor) {
        case 1: {
            double r;
            cout << "Vnesi radius na krugot: ";
            cin >> r;
            Krug K(r);
            K.prikazhiKrug();
            break;
        }
        case 2: {
            double s;
            cout << "Vnesi strana na kvadratot: ";
            cin >> s;
            Kvadrat Kv(s);
            Kv.prikazhiKvadrat();
            break;
        }
        case 3: {
            double r;
            cout << "Vnesi radius na topkata: ";
            cin >> r;
            Topka T(r);
            T.prikazhiTopka();
            break;
        }
        case 4: {
            double s;
            cout << "Vnesi strana na kockata: ";
            cin >> s;
            Kocka K2(s);
            K2.prikazhiKocka();
            break;
        }
        default: {
            cout<<"Greshka! Obidete se povtorno."<<endl;
            break;
        }
        cout << "Broj na instancirani objekti:" << endl;
        cout << "Oblik: " << Oblik::getBrojNaObjekti() << endl;
        cout << "DvoDimenzionalni: " << DvoDimenzionalni::getBrojNaObjekti2D() << endl;
        cout << "TroDimenzionalni: " << TroDimenzionalni::getBrojNaObjekti3D() << endl;
    }

    }

    return 0;
}
