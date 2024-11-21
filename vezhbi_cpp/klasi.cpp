#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
#define MAX 100

//zadaca 1
class Kvadar {
private:
    int dolzina;
    int sirina;
    int visina;
public:
    float plostina(int a, int b, int c) {
        return 2*(a*b + b*c + a*c);
    }
    float volumen(int a, int b, int c) {
        return a*b*c;
    }
    int getDolzina() {
        return dolzina;
    }
    int getSirina() {
        return sirina;
    }
    int getVisina() {
        return visina;
    }
    void setDolzina() {
        cout<<"dolzina="; cin>>dolzina;
    }
    void setSirina() {
        cout<<"sirina="; cin>>sirina;
    }
    void setVisina() {
        cout<<"visina="; cin>>visina;
    }
};

//zadaca 2

class Stedac {
public:
    void vnesi_podatoci();
    void prikazi_podatoci();
    void uplata(unsigned long i);
    void isplata(unsigned long i);
    long sostojba();
    int getBroj() {
        return broj;
    }

private:
    int broj;
    char imeprezime[30], adresa[50];
    long saldo;
};

void Stedac::vnesi_podatoci() {
    cout<<"Vnesi broj."<<endl;
    cin>>broj;
    cout<<"Vnesi ime i prezime."<<endl;
    cin>>imeprezime;
    cout<<"Vnesi adresa."<<endl;
    cin>>adresa;
    saldo=0;
}

void Stedac::prikazi_podatoci() {
    cout<<"Broj: "<<broj<<":"<<endl;
    cout<<"Ime i prezime: "<<imeprezime<<endl;
    cout<<"Adresa: "<<adresa<<endl;
    cout<<"Saldo: "<<saldo<<endl;
}

void Stedac::uplata(unsigned long br) {
    saldo+=br;
}

void Stedac::isplata(unsigned long br) {
    saldo-=br;
}

long Stedac::sostojba() {
    return saldo;
}

int main() {

    //zadaca 1

    Kvadar* obj[MAX];
    int i=0,izbor=-1;
    int indeks;

    cout<<"Izberete od korisnickoto meni."<<endl;
    while(izbor!=0) {
        cout<<"0)Kraj"<<endl;
        cout<<"1)Kreiraj nov objekt."<<endl;
        cout<<"2)Postavi dimenzii."<<endl;
        cout<<"3)Pechati dimenzii na site objekti."<<endl;
        cout<<"4)Pechati dimenzii za odreden objekt."<<endl;
        cout<<"5)Pechati gi objektite sto go zadovoluvaat uslovot."<<endl;
        cin>>izbor;
        switch(izbor) {
        case 1:{
            obj[i] = new Kvadar();
            i++;
            break;
        }
        case 2: {
            cout << "Vnesi indeks na objekt za postavuvanje dimenzii: ";
            cin >> indeks;
            if (indeks >= i || indeks < 0) {
                cout << "Nevaliden indeks!" << endl;
            } else {
                cout<<"Postavi dolzina:"<<endl;
                obj[indeks]->setDolzina();
                cout<<"Postavi sirina:"<<endl;
                obj[indeks]->setSirina();
                cout<<"Postavi visina:"<<endl;
                obj[indeks]->setVisina();
            }
            break;
        }
        case 3: {
            for(int j=0;j<i;j++) {
                cout<<"Objekt "<<j<<":"<<endl;
                cout<<"Dolzina:"<<obj[j]->getDolzina()<<endl;
                cout<<"Sirina:"<<obj[j]->getSirina()<<endl;
                cout<<"Visina:"<<obj[j]->getVisina()<<endl;
            }
            break;
        }
        case 4: {
            cout<<"Vnesi indeks na objekt:"<<endl;
            cin>>indeks;
            if(indeks > i) {
                cout<<"Nema objekt so toj indeks."<<endl;
            }
            else {
                cout<<"Dolzina:"<<obj[indeks]->getDolzina()<<endl;
                cout<<"Sirina:"<<obj[indeks]->getSirina()<<endl;
                cout<<"Visina:"<<obj[indeks]->getVisina()<<endl;
            }
            break;
        }
        case 5: {
            if (i == 0) {
                cout << "Nema kreirani objekti!" << endl;
                break;
            }
            float pl=obj[0]->plostina(obj[0]->getDolzina(), obj[0]->getSirina(), obj[0]->getVisina());
            int k;
            for(int j=1;j<i;j++) {
                if(obj[j]->plostina(obj[j]->getDolzina(), obj[j]->getSirina(), obj[j]->getVisina()) < pl && ((obj[j]->getDolzina() != obj[j]->getSirina()) || (obj[j]->getSirina() != obj[j]->getVisina()) )) {
                    pl=obj[j]->plostina(obj[j]->getDolzina(), obj[j]->getSirina(), obj[j]->getVisina());
                    k=j;
                }
            }
            cout<<"Elementot so najmala plostina koj ne e kocka e:"<<endl;
            cout<<"Dolzina: "<<obj[k]->getDolzina()<<endl;
            cout<<"Sirina: "<<obj[k]->getSirina()<<endl;
            cout<<"Visina: "<<obj[k]->getVisina()<<endl;
            break;
        }
        default: {
            cout<<"Greshka! Obidete se povtorno."<<endl;
        }
        }
    }
    for (int j = 0; j < i; j++) {
        delete obj[j];
    }

    //zadaca 2

    Stedac* st[MAX];
    int i1=0, suma, broj;
    int izbor1;

    cout<<"Izberete od korisnickoto meni."<<endl;
    while(izbor1!=0) {
        cout<<"0)Kraj"<<endl;
        cout<<"1)Vnesuvanje na nov stedac."<<endl;
        cout<<"2)Prikaz na podatoci."<<endl;
        cout<<"3)Uplata na sredstva."<<endl;
        cout<<"4)Isplata na sredstva."<<endl;
        cout<<"5)Prikaz na saldo za stedac."<<endl;
        cin>>izbor1;
        switch(izbor1) {
        case 1: {
            st[i1]=new Stedac();
            st[i1]->vnesi_podatoci();
            cout<<"Uspesno kreiran stedac."<<endl;
            i1++;
            break;
        }
        case 2: {
            if(i1==0) {
                cout<<"Nema vneseni stedaci."<<endl;
            }
            else {
                for(int j=0;j<i1;j++) {
                    st[j]->prikazi_podatoci();
                }
            }
            break;
        }
        case 3: {
            cout<<"Vnesi broj na stedac."<<endl;
            cin>>broj;
            int t=0;
            for(int j=0;j<i1;j++) {
                if(st[j]->getBroj() == broj) {
                    cout<<"Vnesi ja sumata."<<endl;
                    cin>>suma;
                        st[j]->uplata(suma);
                        cout<<"Uplatata e uspesno izvrsena. Novoto saldo e "<<st[j]->sostojba()<<endl;
                        t=1;
                        break;
                }
            }
            if(!t) {
                cout<<"Ne e pronajden stedac so toj broj."<<endl;
            }
            break;        }
        case 4: {
            cout<<"Vnesi broj na stedac."<<endl;
            cin>>broj;
            int t=0;
            for(int j=0;j<i1;j++) {
                if(st[j]->getBroj() == broj) {
                    cout<<"Vnesi ja sumata."<<endl;
                    cin>>suma;
                    if(st[j]->sostojba() > suma) {
                        st[j]->isplata(suma);
                        cout<<"Isplatata e uspesno izvrsena. Novoto saldo e "<<st[j]->sostojba()<<endl;
                    }
                    else {
                        cout<<"Nemate dovolno sredstva za isplata."<<endl;
                    }
                    t=1;
                    break;
                }
            }
            if(!t) {
                cout<<"Ne e pronajden stedac so toj broj."<<endl;
            }
            break;
        }
        case 5: {
            cout<<"Vnesi broj na stedac."<<endl;
            cin>>broj;
            int t=0;
            for(int j=0;j<i1;j++) {
                if(st[j]->getBroj() == broj) {
                    cout<<"Saldoto za stedac so broj "<<broj<<" e "<<st[j]->sostojba()<<endl;
                    t=1;
                    break;
                }
            }
            if(!t) {
                cout<<"Ne e pronajden stedac so toj broj."<<endl;
            }
            break;
        }
        default: {
            cout<<"Greshka! Obidete se povtorno."<<endl;
        }
    }
    }
    for(int j=0; j<i1; j++) {
        delete st[j];
    }


    return 0;
}
