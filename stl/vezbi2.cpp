#include <iostream>
#include <string.h>
using std::cout;
using std::endl;
using std::cin;
using std::ostream;

//zadaca 1
template<class T>
T sum(T arr[], int a, int b, T start = T()) {
    T sum = start;
    for(int i=a; i<b;i++) {
        sum+=arr[i];
    }
    return sum;
}

//zadaca 2
template<class T>
class Kvadrat {
private:
    T strana;
public:
    Kvadrat(T s) {
        strana=s;
    }
    T plostina() const {
        return strana * strana;
    }
    friend std::ostream& operator<<(std::ostream& os, const Kvadrat& k) {
        return os<<"Kvadrat(strana="<<k.strana<<", plostina="<< k.plostina()<< ")";
    }
};

template<class T>
class Pravoagolnik {
private:
    T sirina;
    T dolzina;
public:
    Pravoagolnik(T s, T d) {
        sirina=s;
        dolzina=d;
    }
    T plostina() const {
        return sirina * dolzina;
    }
    friend std::ostream& operator<<(std::ostream& os, const Pravoagolnik& p) {
        return os<<"Pravoagolnik(sirina="<<p.sirina<<", dolzina="<< p.dolzina<<", plostina="<<p.plostina()<< ")";
    }
};

template <typename T>
void sortirajPole(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j].plostina() < arr[i].plostina()) {
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

template<typename T>
void pecatiPole(T arr[], int n) {
    for (int i=0; i<n; i++) {
        cout<<arr[i];
        cout<<",";
    }
    cout<<endl;
}

//zadaca 3
template<typename T>
class Lica {
private:
    char* imeIprezime;
    int mat_br;
    int vozrast;
    char *adresa;
    T kod;
public:
    Lica() : imeIprezime(nullptr), adresa(nullptr) {}
    ~Lica() {
        delete[] imeIprezime;
        delete[] adresa;
    }
    void vnesi_podatoci() {
        char buffer[100];
        cout << "Vnesi ime i prezime: ";
        cin.getline(buffer, 100);
        imeIprezime = new char[strlen(buffer) + 1];
        strcpy(imeIprezime, buffer);

        cout << "Vnesi maticen broj: ";
        cin >> mat_br;

        cout << "Vnesi vozrast: ";
        cin >> vozrast;

        cout << "Vnesi adresa: ";
        cin.getline(buffer, 100);
        adresa = new char[strlen(buffer) + 1];
        strcpy(adresa, buffer);

        cout << "Vnesi kod (niza od znaci): ";
        cin>>kod;
    }
    void pecati_podatoci() const {
        cout << "Ime i prezime: " << imeIprezime << endl;
        cout << "Maticen broj: " << mat_br << endl;
        cout << "Vozrast: " << vozrast << endl;
        cout << "Adresa: " << adresa << endl;
        cout << "Kod: " << kod << endl;
    }
    friend ostream& operator<<(ostream& os, const Lica<T>& l) {
        os << "Ime i prezime: " << l.imeIprezime << ", "
           << "Maticen broj: " << l.mat_br << ", "
           << "Vozrast: " << l.vozrast << ", "
           << "Adresa: " << l.adresa << ", "
           << "Kod: " << l.kod;
        return os;
    }
};

template <>
class Lica<char*> {
private:
    char* imeIprezime;
    int mat_br;
    int vozrast;
    char* adresa;
    char* kod;

public:
    Lica() : imeIprezime(nullptr), adresa(nullptr), kod(nullptr) {}
    ~Lica() {
        delete[] imeIprezime;
        delete[] adresa;
        delete[] kod;
    }
    void vnesi_podatoci() {
        char buffer[100];
        cout << "Vnesi ime i prezime: ";
        cin.getline(buffer, 100);
        imeIprezime = new char[strlen(buffer) + 1];
        strcpy(imeIprezime, buffer);

        cout << "Vnesi maticen broj: ";
        cin >> mat_br;

        cout << "Vnesi vozrast: ";
        cin >> vozrast;

        cout << "Vnesi adresa: ";
        cin.getline(buffer, 100);
        adresa = new char[strlen(buffer) + 1];
        strcpy(adresa, buffer);

        cout << "Vnesi kod (niza od znaci): ";
        cin.getline(buffer, 100);
        kod = new char[strlen(buffer) + 1];
        strcpy(kod, buffer);
    }
    void pecati_podatoci() const {
        cout << "Ime i prezime: " << imeIprezime << endl;
        cout << "Maticen broj: " << mat_br << endl;
        cout << "Vozrast: " << vozrast << endl;
        cout << "Adresa: " << adresa << endl;
        cout << "Kod: " << kod << endl;
    }
    friend ostream& operator<<(ostream& os, const Lica<char*>& l) {
        os << "Ime i prezime: " << l.imeIprezime << ", "
           << "Maticen broj: " << l.mat_br << ", "
           << "Vozrast: " << l.vozrast << ", "
           << "Adresa: " << l.adresa << ", "
           << "Kod: " << l.kod;
        return os;
    }
};
int main() {
    //zadaca 1
    int niza[10];
    for(int i=0;i<10;i++) {
        niza[i] = rand() % 20;
    }
    for(int i=0;i<10;i++) {
        cout<<niza[i]<<",";
    }
    cout<<"Sumata e: "<<sum(niza, 3,7, 0);

    //zadaca 2
    Kvadrat<double> kvadrati[3] = {Kvadrat<double>(3), Kvadrat<double>(1.5), Kvadrat<double>(2)};
    Pravoagolnik<double> pravoagolnici[3] = {Pravoagolnik<double>(3, 4), Pravoagolnik<double>(2, 5), Pravoagolnik<double>(1, 1)};

    cout << "Pred sortiranje:" << endl;
    pecatiPole(kvadrati, 3);
    pecatiPole(pravoagolnici, 3);

    sortirajPole(kvadrati, 3);
    sortirajPole(pravoagolnici, 3);

    cout << "Posle sortiranje:" << endl;
    pecatiPole(kvadrati, 3);
    pecatiPole(pravoagolnici, 3);

    //zadaca 3
    Lica<int> Vraboteni[3];
    Lica<char*> Klienti[3];
    int izbor=0, countV=0, countK=0;
    while(izbor!=5) {
        cout<<"Izberi opcija od korisnickoto meni."<<endl;
        cout<<"1) Vnesuvanje na podatoci za vraboten."<<endl;
        cout<<"2) Vnesuvanje na podatoci za klient."<<endl;
        cout<<"3) Pecatenje na lista na vraboteni."<<endl;
        cout<<"4) Pecatenje na lista na klienti."<<endl;
        cout<<"5) Kraj"<<endl;
        cin>>izbor;

        switch (izbor) {
        case 1:
            if(countV < 3) {
                Vraboteni[countV++].vnesi_podatoci();
            }
            else {
                cout<<"Maksimalen broj na vraboteni."<<endl;
            }
            break;
        case 2:
            if (countK < 3) {
                Klienti[countK++].vnesi_podatoci();
            } else {
                cout << "Maksimalen broj na klienti." << endl;
            }
            break;
        case 3:
            cout << "Lista na vraboteni:\n";
            pecatiPole(Vraboteni, countV);
            break;
        case 4:
            cout << "Lista na klienti:\n";
            pecatiPole(Klienti, countK);
            break;
        case 5:
            cout << "Kraj na programata.\n";
            break;
        default:
            cout << "Greshka! Obidete se povtorno.\n";
            break;
        }
    }
    return 0;
}
