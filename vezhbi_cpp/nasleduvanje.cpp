#include <iostream>
#include <string.h>

#define MAX 100

using std::cout;
using std::cin;
using std::endl;

class Vraboten {
    char* ime;
    char* prezime;
    int godina_vrabotuvanje;
public:
    Vraboten() {
        ime = nullptr;
        prezime = nullptr;
        godina_vrabotuvanje = 0;
    }
    Vraboten(char *i, char *p, int g) {
        ime=new char[strlen(i)+1];
        strcpy(ime,i);
        prezime=new char[strlen(p) + 1];
        strcpy(prezime,p);
        godina_vrabotuvanje=g;
    }
    void postavi(char *i, char *p, int g) {
        strcpy(ime,i);
        strcpy(prezime,p);
        godina_vrabotuvanje=g;
    }
    void prikazi_podatoci() {
        cout<<"Ime: "<<ime<<", prezime: "<<prezime<<", godina na vrabotuvanje: "<<godina_vrabotuvanje<<endl;
    }
    ~Vraboten() {
        delete[] ime;
        delete[] prezime;
    }
};

class Profesor : Vraboten {
private:
    char *zvanje;
    char *oblast;
    int br_predmeti;
public:
    Profesor() : Vraboten() {
        zvanje=nullptr;
        oblast=nullptr;
        br_predmeti=0;
    }
    Profesor(char *i, char *p, int g, char *z, char *o, int b) : Vraboten (i,p,g) {
        zvanje=new char[strlen(z)+1];
        strcpy(zvanje,z);
        oblast=new char[strlen(o) + 1];
        strcpy(oblast,o);
        br_predmeti=b;
    }
    void postaviP(char *i, char *p, int g,char *z, char *o, int b ) {
        postavi(i,p,g);
        strcpy(zvanje,z);
        strcpy(oblast,o);
        br_predmeti=b;
    }
    void prikazi_podatociP() {
        prikazi_podatoci();
        cout<<"Zvanje: "<<zvanje<<", oblast: "<<oblast<<", broj na predmeti:  "<<br_predmeti<<endl;
    }
    ~Profesor() {
        delete[] zvanje;
        delete[] oblast;
    }
};

class Asistent : Vraboten {
private:
    char *zvanje;
    char *mentor;
    int br_predmeti;
public:
    Asistent() : Vraboten() {
        zvanje=nullptr;
        mentor=nullptr;
        br_predmeti=0;
    }
    Asistent(char *i, char *p, int g, char *z, char *m, int b) : Vraboten (i,p,g) {
        zvanje=new char[strlen(z)+1];
        strcpy(zvanje,z);
        mentor=new char[strlen(m) + 1];
        strcpy(mentor,m);
        br_predmeti=b;
    }
    void postaviA(char *i, char *p, int g,char *z, char *m, int b ) {
        postavi(i,p,g);
        strcpy(zvanje,z);
        strcpy(mentor,m);
        br_predmeti=b;
    }
    void prikazi_podatociA() {
        prikazi_podatoci();
        cout<<"Zvanje: "<<zvanje<<", mentor: "<<mentor<<", broj na predmeti:  "<<br_predmeti<<endl;
    }
    ~Asistent() {
        delete[] zvanje;
        delete[] mentor;
    }
};

class Demonstrator : Vraboten {
private:
    int vremeOd;
    int vremeDo;
public:
    Demonstrator() : Vraboten() {
        vremeOd=0;
        vremeDo=0;
    }
    Demonstrator(char *i, char *p, int g, int o, int d) : Vraboten (i,p,g) {
        vremeOd = o;
        vremeDo = d;
    }
    void postaviD(char *i, char *p, int g, int o, int d ) {
        postavi(i,p,g);
        vremeOd = o;
        vremeDo = d;
    }
    void prikazi_podatociD() {
        prikazi_podatoci();
        cout<<"Rabotno vreme od "<<vremeOd<<" do "<<vremeDo<<" casot."<<endl;
    }
};

int main() {
    Vraboten V[MAX];
    Asistent vA[MAX];
    Profesor vP[MAX];
    Demonstrator vD[MAX];

    int izbor=0;
    char v;
    int i=0,i1=0,i2=0,i3=0;
    int god, vrOd, vrDo, br;
    char ime[30], prezime[30], zv[30], ob[30], mentor[30];

    while(izbor!=3) {
        cout<<"Izberi opcija od korisnickoto meni."<<endl;
        cout<<"1) Dodavanje na nov vraboten vo listata"<<endl;
        cout<<"2) Prikazuvanje na listata"<<endl;
        cout<<"3) Kraj"<<endl;
        cin>>izbor;

        switch(izbor) {
        case 1: {
            cout<<"Dali kje se vnesuva profesor, asistent ili demonstrator?"<<endl;
            cin>>v;
            if(v == 'p') {
                cout<<"Vnesi ime: "<<endl;
                cin>>ime;
                cout<<"Vnesi prezime."<<endl;
                cin>>prezime;
                cout<<"Vnesi godina na vrabotuvanje."<<endl;
                cin>>god;
                cout<<"Vnesi zvanje."<<endl;
                cin>>zv;
                cout<<"Vnesi oblast."<<endl;
                cin>>ob;
                cout<<"Vnesi broj na predmeti."<<endl;
                cin>>br;
                vP[i1++]=Profesor(ime, prezime, god, zv, ob, br);
            }
            else if(v == 'a') {
                cout<<"Vnesi ime: "<<endl;
                cin>>ime;
                cout<<"Vnesi prezime."<<endl;
                cin>>prezime;
                cout<<"Vnesi godina na vrabotuvanje."<<endl;
                cin>>god;
                cout<<"Vnesi zvanje."<<endl;
                cin>>zv;
                cout<<"Vnesi mentor."<<endl;
                cin>>mentor;
                cout<<"Vnesi broj na predmeti."<<endl;
                cin>>br;
                vA[i2++]=Asistent(ime, prezime, god, zv, mentor, br);
            }
            else if(v == 'd') {
                cout<<"Vnesi ime: "<<endl;
                cin>>ime;
                cout<<"Vnesi prezime."<<endl;
                cin>>prezime;
                cout<<"Vnesi godina na vrabotuvanje."<<endl;
                cin>>god;
                cout<<"Vnesi rabotno vreme od."<<endl;
                cin>>vrOd;
                cout<<"Vnesi raboteno vreme do."<<endl;
                cin>>vrDo;
                vD[i3++]=Demonstrator(ime, prezime, god, vrOd, vrDo);
            }
            break;
        }
        case 2: {
            cout<<"Prikaz na site vraboteni:"<<endl;
            for (int j = 0; j < i1; j++) {
                vP[j].prikazi_podatociP();
            }
            for (int j = 0; j < i2; j++) {
                vA[j].prikazi_podatociA();
            }
            for (int j = 0; j < i3; j++) {
                vD[j].prikazi_podatociD();
            }
            break;
        }
        case 3: {
            cout<<"Kraj"<<endl;
            break;
        }
        default: {
            cout<<"Greshka! Obidete se povtorno."<<endl;
        }

        }
    }


}
