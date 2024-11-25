#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;

//zadaca 1
template<typename T>
class Zapis {
private:
    T x;
    T y;
    T z;
public:
    Zapis(T a, T b, T c) {
        x=a;
        y=b;
        z=c;
    }
    void pechati() {
        cout<<"X: "<<x<<", y :"<<y<<", z: "<<z<<endl;
    }
    T getX() {
        return x;
    }
    T getY() {
        return y;
    }
    T getZ() {
        return z;
    }
};

template<typename T>
void kontrolor(Zapis<T> z) {
    if(z.getX() + z.getY() + z.getZ() > 10000) {
        cout<<"Zbirot nadminuva 10000."<<endl;
    }
    else cout<<"Zbirot ne nadminuva 10000"<<endl;
}

//zadaca 2

template<typename T>
class Mnozestvo {
private:
    T elements[100];
    static int count;
public:
    Mnozestvo() {
        count = 0;
    }

    void dodadi(const T& element) {
        for (int i = 0; i < count; i++) {
            if (elements[i] == element) {
                cout<<"Elementot vekje postoi."<<endl;
            }
        }
        if (count < 100) {
            elements[count++] = element;
        }
    }

    void prikazi() const {
        cout << "{ ";
        for (int i = 0; i < count; i++) {
            cout << elements[i] << " ";
        }
        cout << "}" << endl;
    }

    T najgolem() const {
        if (count == 0) {
            cout<<"Mnozestvo e prazno!"<<endl;
        }
        T maxElement = elements[0];
        for (int i = 1; i < count; i++) {
            if (elements[i] > maxElement) {
                maxElement = elements[i];
            }
        }
        return maxElement;
    }

    static int getBrojElementi() {
        return count;
    }
};

template<typename T>
int Mnozestvo<T>::count = 0;

template<>
class Mnozestvo<char*> {
private:
    char* elements[100];
    static int count;
public:
    Mnozestvo() {
        count = 0;
    }

    ~Mnozestvo() {
        for (int i = 0; i < count; i++) {
            delete[] elements[i];
        }
    }

    void dodadi(const char* element) {
        for (int i = 0; i < count; i++) {
            if (strcmp(elements[i], element) == 0) {
                cout<<"Elementot vekje postoi."<<endl;
            }
        }
        if (count < 100) {
            elements[count] = new char[strlen(element) + 1];
            strcpy(elements[count], element);
            count++;
        }
    }

    void prikazi() const {
        cout << "{ ";
        for (int i = 0; i < count; i++) {
            cout << elements[i] << " ";
        }
        cout << "}" << endl;
    }

    const char* najgolem() const {
        if (count == 0) {
            cout<<"Mnozestvoto e prazno!"<<endl;
        }
        const char* maxElement = elements[0];
        for (int i = 1; i < count; i++) {
            if (strcmp(elements[i], maxElement) > 0) {
                maxElement = elements[i];
            }
        }
        return maxElement;
    }

    static int getBrojElementi() {
        return count;
    }
};

int Mnozestvo<char*>::count = 0;

int main() {
    //zadaca 1
    Zapis<int> z1(2345, 2514, 7541);
    Zapis<int> z3(235, 254, 751);
    Zapis<double> z2(120.25, 2541.03, 745.215);

    kontrolor(z1);
    kontrolor(z2);
    kontrolor(z3);

    //zadaca 2

    Mnozestvo<int> A;
    Mnozestvo<double> B;
    Mnozestvo<char*> C;
    int izbor=0;
    int countA=0, countB=0, countC=0;
    int element;
    double element1;
    char* element2;
    while(izbor!=9) {
        cout<<"Izberi opcija od korisnickoto meni."<<endl;
        cout<<"1)Dodaj element vo A"<<endl;
        cout<<"2)Dodaj element vo B"<<endl;
        cout<<"3)Dodaj element vo C"<<endl;
        cout<<"4)Prikazi go A"<<endl;
        cout<<"5)Prikazi go B"<<endl;
        cout<<"6)Prikazi go C"<<endl;
        cout<<"7)Prikazi najgolemi elementi"<<endl;
        cout<<"8)Prikazi broj na elementi vo mnozestvata"<<endl;
        cout<<"9)Kraj"<<endl;
        cin>>izbor;

        switch(izbor) {
        case 1: {
            cout<<"Vnesi go elementot sto sakas da go dodades."<<endl;
            cin>>element;
            A.dodadi(element);
            break;
        }
        case 2: {
            cout<<"Vnesi go elementot sto sakas da go dodades."<<endl;
            cin>>element1;
            B.dodadi(element1);
            break;
        }
        case 3: {
            char buffer[100];
            cout<<"Vnesi go elementot sto sakas da go dodades."<<endl;
            cin.ignore();
            cin.getline(buffer, sizeof(buffer));
            element2= new char[strlen(buffer)+1];
            strcpy(element2, buffer);
            C.dodadi(element2);
            break;
        }
        case 4: {
            A.prikazi();
            break;
        }
        case 5: {
            B.prikazi();
            break;
        }
        case 6: {
            C.prikazi();
            break;
        }
        case 7: {
            cout<<"Najgolem element vo mnozestvo A e "<<A.najgolem()<<endl;
            cout<<"Najgolem element vo mnozestvo B e "<<B.najgolem()<<endl;
            cout<<"Najgolem element vo mnozestvo C e "<<C.najgolem()<<endl;
            break;
        }
        case 8: {
            cout<<"Broj na elementi vo mnozestvo A: "<<A.getBrojElementi()<<endl;
            cout<<"Broj na elementi vo mnozestvo B: "<<B.getBrojElementi()<<endl;
            cout<<"Broj na elementi vo mnozestvo C: "<<C.getBrojElementi()<<endl;
            break;
        }
        case 9: {
            cout<<"Kraj."<<endl;
            break;
        }
        default: {
            cout<<"Greshka! Obidete se povtorno!"<<endl;
        }
    }
    }
    return 0;
}
