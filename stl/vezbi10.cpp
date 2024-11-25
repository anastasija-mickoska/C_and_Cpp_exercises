#include <iostream>
using namespace std;

//zadaca 1
class Klasa {
public:
    Klasa() {
        cout<<"Se kreira objekt."<<endl;
    }

    ~Klasa() {
        cout<<"Objektot e unisten."<<endl;
    }
};

//zadaca 2

class Motor {
public:
    Motor() {
        bool problemi = true; //motorot ima problemi
        if (problemi) {
            throw runtime_error("Problem so motorot.");
        }
        cout<<"Se kreira objekt od klasa Motor."<<endl;
    }
    ~Motor() {
        cout<<"Se unisti objekt od klasa Motor."<<endl;
    }
};
class Avtomobil {
private:
    Motor m;
public:
    Avtomobil() {
        m = Motor();
        cout<<"Se kreira objekt od klasa Avtomobil."<<endl;
    }
    ~Avtomobil() {
        cout<<"Se unisti objekt od klasa Avtomobil."<<endl;
    }
};

class Garaza {
private:
    Avtomobil a;
public:
    Garaza() {
        try {
            a = Avtomobil();
            cout<<"Se kreira objekt od klasa Garaza."<<endl;
        }
        catch(const runtime_error& e) {
            throw runtime_error("Problem pri kreiranjeto na Avtomobil vo Garaza: " + string(e.what()));
        }    }
    ~Garaza() {
        cout<<"Se unisti objekt od klasa Garaza."<<endl;
    }
};

int main() {
    //zadaca 1
    Klasa* obj = new Klasa();
    Klasa* obj2 = new Klasa();
    obj = nullptr; //objektot nema da se unisti, bidejki pokazuvacot seuste kje postoi, no nema da pokazuva na tocna lokacija (memory leak)
    delete obj2; //so ova kje se unisti objektot, i kje se aktivira destruktorot
    cout << "Kraj na programata."<<endl;

    //zadaca 2
    try {
        Garaza garaza;
    }
    catch (const runtime_error& e) {
        cout << "Fati iskluchok: " << e.what() << endl;
    }
    cout<<"Kraj."<<endl;
    return 0;
}
