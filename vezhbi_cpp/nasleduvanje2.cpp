#include <iostream>
#include <string.h>

#define MAX 100

using namespace std;
using std::cout;
using std::cin;
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
    int toDays() const {  //funkcija za pretvoranje na datumite vo denovi
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
};

class Artikl {
protected:
    char ime[30];
    int golemina;
    int cena;
    Datum donesen_vo_prodavnica;
public:
    Artikl() : donesen_vo_prodavnica() {
        ime[0] = '\0';
        golemina = 0;
        cena = 0;
    }
    Artikl(const char *i, int g, int c, int d, int m, int god) : donesen_vo_prodavnica(d,m,god) {
        strncpy(ime,i,sizeof(i)+1);
        ime[sizeof(i)-1]='\0';
        golemina = g;
        cena = c;
    }
    void prikazhi_podatoci() {
        cout<<"Ime na artikl: "<<ime<<", golemina: "<<golemina<<", cena: "<<cena<<endl;
        cout<<"Donesen vo prodavnica: ";
        donesen_vo_prodavnica.prikazhiDatum();
    }
    Datum presmetaj_nabavka() {
        return donesen_vo_prodavnica;
    }
    int getCena() {
        return cena;
    }
};

class Pantoloni : public Artikl {
protected:
    Datum sledna_nabavka;
public:
    Pantoloni() : Artikl(), sledna_nabavka() {
    }
    Pantoloni(char *i, int g, int c, int d, int m, int god, int d1, int m1, int god1) : Artikl(i,g,c,d,m,god), sledna_nabavka(d1,m1,god1){
    }
    void prikazhi_podatociP() {
        prikazhi_podatoci();
        cout<<"Sledna nabavka: ";
        sledna_nabavka.prikazhiDatum();
    }
    Datum presmetaj_nabavkaP() {
        return donesen_vo_prodavnica;
    }
    Datum presmetaj_slednaNabavkaP() {
        return sledna_nabavka;
    }
};

class Kosuli : public Artikl {
public:
    Kosuli() : Artikl() {
    }
    Kosuli(const char *i, int g, int c, int d, int m, int god) : Artikl(i,g,c,d,m,god) {
    }
    void prikazhi_podatociK() {
        prikazhi_podatoci();
    }
    Datum presmetaj_nabavkaK() {
        return donesen_vo_prodavnica;
    }
};


int main() {
    Artikl a[MAX];
    Pantoloni p[MAX];
    Kosuli k[MAX];

    int izbor=0;
    int i1=0,i2=0,i3=0;
    int golemina, cena, den, mesec,godina;
    int d1,m1,g1;
    char ime[30],v;

    while(izbor!=5) {
        cout<<"Izberi opcija od korisnickoto meni."<<endl;
        cout<<"1) Dodavanje na artikl vo listata"<<endl;
        cout<<"2) Prikazuvanje na artikli od dadena grupa"<<endl;
        cout<<"3) Prikazuvanje na celata lista (so vkupna cena)"<<endl;
        cout<<"4) Prikazuvanje na site artikli koi treba da se nabavat vo rok od 1 nedela i pari koi treba da se potrosat za potrebnite artikli"<<endl;
        cout<<"5) Izlez"<<endl;

        cin>>izbor;

        switch(izbor) {
        case 1: {
                cout<<"Kakov artikl kje se vnesuva (pantoloni ili kosula)?"<<endl;
                cin>>v;
                cout<<"Vnesi ime: "<<endl;
                cin>>ime;
                cout<<"Vnesi golemina."<<endl;
                cin>>golemina;
                cout<<"Vnesi cena."<<endl;
                cin>>cena;
                cout<<"Vnesi datum (den,mesec,godina)"<<endl;
                cin>>den>>mesec>>godina;
                a[i1++] = Artikl(ime, golemina, cena, den,mesec,godina);
                if(v=='p') {
                    cout<<"Vnesi datum na sledna nabavka (den,mesec,godina)."<<endl;
                    cin>>d1>>m1>>g1;
                    p[i2++] = Pantoloni(ime,golemina,cena,den,mesec,godina, d1,m1,g1);
                }
                if(v=='k') {
                    k[i3++] = Kosuli(ime,golemina,cena,den,mesec,godina);
                }
                break;
        }
        case 2: {
            cout<<"Prikaz na artikli od dadena grupa:"<<endl;
            cout<<"Koj artikl (pantoloni ili kosula)?"<<endl;
            cin>>v;
            if(v=='p') {
                for (int j = 0; j < i2; j++) {
                    p[j].prikazhi_podatociP();
                }
            }
            else if(v=='k') {
                for (int j = 0; j < i3; j++) {
                    k[j].prikazhi_podatociK();
                }
            }
            break;
        }
        case 3: {
            cout<<"Prikaz na celata lista:"<<endl;
            int sum=0;
            for (int j = 0; j < i2; j++) {
                p[j].prikazhi_podatociP();
                sum+=p[j].getCena();
            }
            for (int j = 0; j < i3; j++) {
                k[j].prikazhi_podatociK();
                sum+=k[j].getCena();
            }
            cout<<"Vkupna cena: "<<sum<<endl;
            break;
        }
        case 4: {
            int pari;
            for(int j=0;j<i2;j++) {
                int donesen = p[j].presmetaj_nabavkaP().toDays();
                int sledna = p[j].presmetaj_slednaNabavkaP().toDays();

                if(abs(donesen-sledna) <= 7) {
                    p[j].prikazhi_podatociP();
                    pari+=p[j].getCena();
                }
            }
            cout<<"Vkupno pari: "<<pari<<endl;
            break;
        }
        case 5: {
            cout<<"Izlez"<<endl;
            break;
        }
        default: {
            cout<<"Greshka! Obidete se povtorno."<<endl;
        }
        }
    }
    return 0;
}
