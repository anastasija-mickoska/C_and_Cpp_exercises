#include <iostream>
#include <string.h>

using namespace std;
using std::cout;
using std::cin;
using std::endl;

class Covek {
private:
    char ime[20];
    char prezime[20];
    char adresa[20];
    char telefon[10];
public:
    Covek(char* i, char *p, char *a, char *t) {
        int length=strlen(i);
        strncpy(ime,i, length);
        ime[length] = '\0';
        length=strlen(p);
        strncpy(prezime,p, length);
        prezime[length] = '\0';
        length=strlen(a);
        strncpy(adresa,a, length);
        adresa[length] = '\0';
        length=strlen(t);
        strncpy(telefon,t, length);
        telefon[length] = '\0';
        cout << "Konstruktor za nov stedac " << ime<< ' ' << prezime << " povikan." << endl;
    }
    ~Covek() {
        cout<<"Destruktor za objekt od klasa Covek povikan."<<endl;
    }
};

class Stedac {
private:
    static int kamata;
    static int brojStedaci;
    Covek lice;
    int bilans;
    int kredit;
public:
    Stedac(char* i, char* p, char* a, char *t, int b, int k) : lice(i, p, a, t){
        bilans=b;
        kredit=k;
        cout<<"Konstruktor za stedac "<<i<<" "<<p<<" povikan."<<endl;
        ++brojStedaci;
    }
    static int getBrojStedaci() {
        return brojStedaci;
    }
    ~Stedac() {
        --brojStedaci;
    }
};

int Stedac::brojStedaci = 0;

int main() {
    cout << "Broj na stedaci pred instanciranje e "
         << Stedac::getBrojStedaci() << endl;

    Stedac *s1 = new Stedac( "ime1", "prez1", "adresa1", "123456", 12000, 2000 );
    Stedac *s2 = new Stedac(  "ime2", "prez2", "adresa2", "12345", 10000, 1000  );

    cout << "Broj na stedaci po instanciranje e "
         << s1->getBrojStedaci() << " "<< s2->getBrojStedaci();

    delete s1;
    delete s2;

    cout << "Broj na stedaci po brishenje e "
         << Stedac::getBrojStedaci() << endl;

}
