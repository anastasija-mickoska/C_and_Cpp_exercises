#include <iostream>
#include <string.h>
#include <chrono>
#include <ctime>

#define MAX 100

using namespace std;
using std::cin;
using std::cout;
using std::endl;

class Datum {
    int den;
    int mesec;
    int godina;

public:
    Datum() {
        den=0;
        mesec=0;
        godina=0;
    }
    Datum(int d, int m, int g) {
        den=d;
        mesec=m;
        godina=g;
    }
    void prikazhiDatum() {
        cout<<den<<"/"<<mesec<<"/"<<godina<<endl;
    }
    int toDays() const {
        int denovi = den;

        static const int denoviMesec[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        for (int i = 0; i < mesec - 1; ++i) {
            denovi += denoviMesec[i];
        }

        denovi += (godina - 1) * 365;
        denovi += (godina - 1) / 4;
        denovi -= (godina - 1) / 100;
        denovi += (godina - 1) / 400;

        if (prestapnaGodina(godina) && mesec > 2) {
            denovi += 1;
        }

        return denovi;
    }
    bool prestapnaGodina(int god) const {
        return (god % 4 == 0 && god % 100 != 0) || (god % 400 == 0);
    }

    static Datum denes() {
        auto t = std::time(nullptr);
        auto tm = *std::localtime(&t);
        return Datum(tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    }
};

class Zivotno {
protected:
    Datum datum_na_ragjanje;
    Datum donesuvanje_vo_zoo;
    char pol;
    char ime[30];
    Datum posledna_vakcinacija;
public:
    Zivotno() {}
    Zivotno(int dr, int mr, int gr, int dd, int md, int gd, char p, char* i, int dv, int mv, int gv) : datum_na_ragjanje(dr,mr,gr),
        donesuvanje_vo_zoo(dd,md,gd), posledna_vakcinacija(dv,mv,gv) {
        pol=p;
        strncpy(ime,i,sizeof(i)+1);
        ime[sizeof(i)-1]='\0';
    }
    virtual void Prikazi_Podatoci() {
        cout<<"Ime: "<<ime<<", pol: "<<pol<<", datum na ragjanje: ";
        datum_na_ragjanje.prikazhiDatum();
        cout<<"Datum na donesuvanje vo zoo: ";
        donesuvanje_vo_zoo.prikazhiDatum();
        cout<<"Datum na posledna vakcinacija: ";
        posledna_vakcinacija.prikazhiDatum();
    }
    virtual void Presmetaj_vakcinacija() {
        cout << "Presmetaj vakcinacija za zivotno: " << ime << endl;
    }
    virtual bool treba_vakcinacija() const = 0;

    virtual ~Zivotno() {}
};

class Vlekaci : public Zivotno {
protected:
    Datum sledna_vakcinacija;

public:
    Vlekaci() : Zivotno() {}
    Vlekaci(int dr, int mr, int gr, int dd, int md, int gd, char p, char* i, int dv, int mv, int gv, int ds, int ms, int gs)
        : Zivotno(dr, mr, gr, dd, md, gd, p, i, dv,mv,gv), sledna_vakcinacija(ds,ms,gs) {}

    void Presmetaj_vakcinacija()  {
        cout << "Presmetaj vakcinacija za vlekac: " << ime << endl;
    }
    void Prikazi_Podatoci()  {
        Zivotno::Prikazi_Podatoci();
        cout<<"Datum na sledna vakcinacija: ";
        sledna_vakcinacija.prikazhiDatum();
    }
    bool treba_vakcinacija() const override {
        return (sledna_vakcinacija.toDays() - Datum::denes().toDays()) <= 7;
    }
};

class Ptici : public Zivotno {
protected:
    bool letac;  //(d/n)
public:
    Ptici() : Zivotno() {}
    Ptici(int dr, int mr, int gr, int dd, int md, int gd, char p, char* i, int dv, int mv, int gv, bool l)
        : Zivotno(dr, mr, gr, dd, md, gd, p, i, dv,mv,gv) {
        letac=l;
    }

    void Presmetaj_vakcinacija() {
        cout << "Presmetaj vakcinacija za ptica: " << ime << endl;
    }

    void Prikazi_Podatoci()  {
        Zivotno::Prikazi_Podatoci();
        cout << "Letac: " << (letac ? "Da" : "Ne") << endl;
    }
    bool treba_vakcinacija() const override {
        return (posledna_vakcinacija.toDays() - Datum::denes().toDays()) > 180;
    }
};

class Cicaci : public Zivotno {
protected:
    bool prezivar; //(d/n)

public:
    Cicaci() : Zivotno() {}
    Cicaci(int dr, int mr, int gr, int dd, int md, int gd, char p, char* i, int dv, int mv, int gv, bool pr)
        : Zivotno(dr, mr, gr, dd, md, gd, p, i, dv,mv,gv) {
        prezivar=pr;
    }

    void Presmetaj_vakcinacija() {
        cout << "Presmetaj vakcinacija za cicaci: " << ime << endl;
    }

    void Prikazi_Podatoci() {
        Zivotno::Prikazi_Podatoci();
        cout << "Prezivar: " << (prezivar ? "Da" : "Ne") << endl;
    }
    bool treba_vakcinacija() const override {
        return (posledna_vakcinacija.toDays() - Datum::denes().toDays()) > 365;
    }
};

int main() {
    Vlekaci vlekaci[MAX];
    Ptici ptici[MAX];
    Cicaci cicaci[MAX];
    int countZ = 0, countV=0, countP=0, countC=0, izbor = 0;
    char z;
    while (izbor != 6) {
        cout << "\nIzberete opcija od korisnickoto meni:\n"
             << "1) Dodavanje na zivotno vo listata\n"
             << "2) Prikazuvanje na brojna sostojba\n"
             << "3) Prikazuvanje na zivotni od dadena grupa\n"
             << "4) Prikazuvanje na cela lista\n"
             << "5) Prikazuvanje na zivotni koi treba da se vakciniraat vo rok od edna nedela\n"
             << "6) Izlez\n";
        cin >> izbor;

        switch (izbor) {
        case 1: {
            char ime[30], pol;
            int d1, m1, g1, d2, m2, g2, d3, m3, g3;
            cout<<"Vo koja kategorija kje se vnesuva zivotno? (v/p/c)"<<endl;
            cin>>z;
            cout << "Vnesi ime na zivotnoto: ";
            cin >> ime;
            do {
                cout << "Vnesi pol (m/z): ";
                cin >> pol;
            } while (pol != 'm' && pol != 'z');
            cout << "Vnesi datum na ragjanje (den mesec godina): ";
            cin >> d1 >> m1 >> g1;
            cout << "Vnesi datum na donesuvanje vo zoo (den mesec godina): ";
            cin >> d2 >> m2 >> g2;
            cout << "Vnesi datum na posledna vakcinacija (den mesec godina): ";
            cin >> d3 >> m3 >> g3;
            if (z == 'v') {
                int d, m, g;
                cout << "Vnesi datum na sledna vakcinacija. (den, mesec, godina)" << endl;
                cin >> d >> m >> g;
                vlekaci[countV++] = Vlekaci(d1, m1, g1, d2, m2, g2, pol, ime, d3, m3, g3, d, m, g);
                countZ++;
            } else if (z == 'p') {
                bool l;
                cout << "Dali pticata e letac? (d/n)" << endl;
                cin >> l;
                ptici[countP++] = Ptici(d1, m1, g1, d2, m2, g2, pol, ime, d3, m3, g3, l);
                countZ++;
            } else if (z == 'c') {
                bool p;
                cout << "Dali cicacot e prezivar? (d/n)" << endl;
                cin >> p;
                cicaci[countC++] = Cicaci(d1, m1, g1, d2, m2, g2, pol, ime, d3, m3, g3, p);
                countZ++;
            }
            break;
        }
        case 2: {
            cout<<"Brojna sostojba: "<<endl;
            cout<<"Vkupen broj na zivotni: "<<countZ<<endl;
            cout<<"Vlekaci: "<<countV<<", ptici: "<<countP<<", cicaci: "<<countC<<endl;
            break;
        }
        case 3: {
            char grupa;
            cout << "Vnesi grupa (v, p, c): ";
            cin >> grupa;

            if(grupa == 'v') {
                for(int i=0;i<countV;i++) {
                    vlekaci[i].Prikazi_Podatoci();
                }
                break;
            }
            if(grupa == 'p') {
                for(int i=0;i<countP;i++) {
                    ptici[i].Prikazi_Podatoci();
                }
                break;
            }
            if(grupa == 'c') {
                for(int i=0;i<countC;i++) {
                    cicaci[i].Prikazi_Podatoci();
                }
                break;
            }
            break;
        }
        case 4: {
            cout << "Lista na site zivotni:" << endl;
            for(int i=0;i<countV;i++) {
                vlekaci[i].Prikazi_Podatoci();
            }
            for(int i=0;i<countP;i++) {
                ptici[i].Prikazi_Podatoci();
            }
            for(int i=0;i<countC;i++) {
                cicaci[i].Prikazi_Podatoci();
            }
            break;
        }
        case 5: {
            cout << "Slednive zivotni treba da se vakciniraat vo rok od 1 nedela:" << endl;

            for (int j = 0; j < countV; j++) {
                if(vlekaci[j].treba_vakcinacija()) {
                    vlekaci[j].Prikazi_Podatoci();
                }
            }
            for (int j = 0; j < countP; j++) {
                if(ptici[j].treba_vakcinacija()) {
                    ptici[j].Prikazi_Podatoci();
                }
            }
            for (int j = 0; j < countC; j++) {
                if(cicaci[j].treba_vakcinacija()) {
                    cicaci[j].Prikazi_Podatoci();
                }
            }
            break;
        }
        case 6: {
            cout << "Izlez od programata." << endl;
            break;
        }
        default:
            cout << "Greshka! Obidete se povtorno." << endl;
        }
    }
    return 0;
}
