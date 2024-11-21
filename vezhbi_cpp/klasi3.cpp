#include <iostream>
#include <ctime>
#include <cstring>
using namespace std;

#define MAX 100

class Datum {
private:
    int den;
    int mesec;
    int godina;

    int checkDay(int testDay) {
        static const int daysPerMonth[13] =
            {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (testDay > 0 && testDay <= daysPerMonth[mesec])
            return testDay;

        if (mesec == 2 && testDay == 29 &&
            (godina % 400 == 0 || (godina % 4 == 0 && godina % 100 != 0)))
            return testDay;

        cout << "Denot " << testDay << " e greshen. Postavi vrednost za den na 1.\n";
        return 1;
    }

public:
    Datum(int d = 1, int m = 1, int g = 2002) {
        mesec = (m > 0 && m <= 12) ? m : 1;
        den = checkDay(d);
        godina = g;
    }

    void print() const {
        cout << den << "/" << mesec << "/" << godina;
    }

    time_t toTimeT() const {
        tm timeStruct = {};
        timeStruct.tm_mday = den;
        timeStruct.tm_mon = mesec - 1;
        timeStruct.tm_year = godina - 1900;
        return mktime(&timeStruct);
    }
    int getMesec() {
        return mesec;
    }
    int getGodina() {
        return godina;
    }
    int getDen() {
        return den;
    }
};

class Zivotno {
private:
    Datum* datum_na_ragjanje;
    Datum* donesuvanje_vo_zoo;
    char tip;
    char pol;
    char ime[30];
    Datum* posledna_vakcinacija;

public:
    Zivotno(int ddr, int ddm, int ddg,
            int ddz, int mdz, int gdz,
            char t, char p, const char* name,
            int ddv, int mdv, int gdv)
        : datum_na_ragjanje(new Datum(ddr, ddm, ddg)),
        donesuvanje_vo_zoo(new Datum(ddz, mdz, gdz)),
        posledna_vakcinacija(new Datum(ddv, mdv, gdv)) {
        tip = t;
        pol = p;
        strncpy(ime, name, sizeof(ime) - 1);
        ime[sizeof(ime) - 1] = '\0';
    }

    void print() const {
        cout << "Ime: " << ime
             << ", Tip: " << tip
             << ", Pol: " << pol
             << ", Datum na ragjanje: ";
        datum_na_ragjanje->print();
        cout << ", Datum na donesuvanje vo zoo: ";
        donesuvanje_vo_zoo->print();
        cout << ", Posledna vakcinacija: ";
        posledna_vakcinacija->print();
        cout << endl;
    }

    char getTip() const { return tip; }

    time_t getVakcinacijaTime() const { return posledna_vakcinacija->toTimeT(); }

    Datum slednaVakcinacija() const {
        int meseci = 0;

        if (tip == 'c') {
            meseci = 12;
        } else if (tip == 'p') {
            meseci = 6;
        } else if (tip == 'v') {
            meseci = 8;
        }

        int nov = posledna_vakcinacija->getMesec() + meseci;
        int nov1 = posledna_vakcinacija->getGodina() + (meseci - 1) / 12;
        meseci = (meseci - 1) % 12 + 1;

        return Datum(posledna_vakcinacija->getDen(), nov, nov1);
    }

    ~Zivotno() {
        delete datum_na_ragjanje;
        delete donesuvanje_vo_zoo;
        delete posledna_vakcinacija;
    }
};

int main() {
    Zivotno* zivotni[MAX];
    int count = 0, izbor = 0;

    while (izbor != 6) {
        cout << "\nIzberete opcija od korisnickoto meni:\n"
             << "1) Dodavanje na zivotno vo zoo\n"
             << "2) Prikazuvanje na brojna sostojba\n"
             << "3) Prikazuvanje na zivotni od daden tip\n"
             << "4) Prikazuvanje na cela lista\n"
             << "5) Prikazuvanje na zivotni koi treba da se vakciniraat vo rok od edna nedela\n"
             << "6) Izlez\n";
        cin >> izbor;

        switch (izbor) {
        case 1: {
            if (count >= MAX) {
                cout << "Zivotnite ne mozhe da se dodadat. Maksimalniot broj e dostignat." << endl;
                break;
            }

            char ime[30], tip, pol;
            int d1, m1, g1, d2, m2, g2, d3, m3, g3;

            cout << "Vnesi ime na zivotnoto: ";
            cin >> ime;
            cout << "Vnesi tip na zivotnoto: ";
            cin >> tip;
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

            zivotni[count++] = new Zivotno(d1, m1, g1, d2, m2, g2, tip, pol, ime, d3, m3, g3);
            break;
        }
        case 2:
            cout << "Brojna sostojba: " << count << endl;
            break;

        case 3: {
            char tip;
            cout << "Vnesi tip (c, v, p): ";
            cin >> tip;

            bool found = false;
            for (int i = 0; i < count; ++i) {
                if (zivotni[i]->getTip() == tip) {
                    zivotni[i]->print();
                    found = true;
                }
            }

            if (!found)
                cout << "Nema zivotni od toj tip." << endl;
            break;
        }
        case 4:
            cout << "Lista na site zivotni:" << endl;
            for (int i = 0; i < count; ++i) {
                zivotni[i]->print();
            }
            break;

        case 5: {
            time_t today = time(nullptr);
            cout << "Slednive zivotni treba da se vakciniraat vo rok od 1 nedela:" << endl;

            for (int j = 0; j < count; j++) {
                Datum sledna = zivotni[j]->slednaVakcinacija();
                time_t vremeSlednaVakcinacija = sledna.toTimeT();

                double denovi = difftime(vremeSlednaVakcinacija, today) / (60 * 60 * 24);

                if (denovi >= 0 && denovi <= 7) {
                    zivotni[j]->print();
                }
            }
            break;
        }
        case 6:
            cout << "Izlez od programata." << endl;
            for (int i = 0; i < count; ++i) {
                delete zivotni[i];
            }
            break;

        default:
            cout << "Greshka! Obidete se povtorno." << endl;
        }
    }

    return 0;
}
