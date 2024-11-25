#include <iostream>

using namespace std;

template<typename T>
class Pravoagolnik {
private:
    T sirina;
    T dolzina;
public:
    Pravoagolnik() {
        sirina=0;
        dolzina=0;
    }
    Pravoagolnik(T a, T b) {
        sirina = a;
        dolzina = b;
    }
    T getSirina() {
        return sirina;
    }
    T getDolzina(){
        return dolzina;
    }
    T povrsina() const {
        return sirina*dolzina;
    }
    void prikazi() const {
        cout << "Pravoagolnik: Sirina = " << sirina << ", Dolzina = " << dolzina << endl;
    }
    bool operator==(const Pravoagolnik& p) const {
        return sirina == p.sirina && dolzina == p.dolzina;
    }
};

template<typename T>
class Kvadrat {
private:
    T strana;
public:
    Kvadrat() {
        strana=0;
    }
    Kvadrat(T a) {
        strana = a;
    }
    T getStrana() {
        return strana;
    }
    T povrsina() const {
        return strana*strana;
    }
    void prikazi() const {
        cout << "Kvadrat: Strana = " << strana << endl;
    }
    bool operator==(const Kvadrat& k) const {
        return strana == k.strana;
    }
};

template<typename T>
class Krug {
private:
    T radius;
public:
    Krug() {
        radius=0;
    }
    Krug(T r) {
        radius = r;
    }
    T getRadius() {
        return radius;
    }
    T povrsina() const {
        return radius*radius*3.14;
    }
    void prikazi() const {
        cout << "Krug: Radius = " << radius << endl;
    }
    bool operator==(const Krug& k) const {
        return radius == k.radius;
    }
};

template<typename T>
class Mnozestvo{
private:
    T elements[100];
    int count;
public:
    Mnozestvo() {
        count=0;
    }
     void dodadi(const T& element) {
        for (int i = 0; i < count; i++) {
            if (elements[i] == element) {
                cout<<"Elementot vekje postoi."<<endl;
                return;
            }
        }
        if (count < 100) {
            elements[count++] = element;
        }
    }
    void prikazi() const {
        cout << "{ ";
        for (int i = 0; i < count; i++) {
            elements[i].prikazi();
        }
        cout << "}" << endl;
    }
    T najgolem() const {
        if (count == 0) {
            cout<<"Mnozestvoto e prazno!"<<endl;
        }
        T maxElement = elements[0];
        for (int i = 1; i < count; i++) {
            if (elements[i].povrsina() > maxElement.povrsina()) {
                maxElement = elements[i];
            }
        }
        return maxElement;
    }

    int getBrojElementi() {
        return count;
    }
};

template<typename T>
void pechati(Mnozestvo<T> m) {
    for(int i=0;i<m.getBrojElementi();i++) {
        m[i].prikazi();
    }
}

int main() {
    Mnozestvo<Pravoagolnik<int>> pravoagolnici;
    Mnozestvo<Kvadrat<int>> kvadrati;
    Mnozestvo<Krug<float>> krugovi;
    int izbor=0;
    int d1,d2;
    float r;

    while(izbor!=9) {
        cout<<"Izberi opcija od korisnickoto meni."<<endl;
        cout<<"1)Dodaj pravoagolnik"<<endl;
        cout<<"2)Dodaj kvadrat"<<endl;
        cout<<"3)Dodaj krug"<<endl;
        cout<<"4)Prikazi go mnozestvoto pravoagolnici"<<endl;
        cout<<"5)Prikazi go mnozestvoto kvadrati"<<endl;
        cout<<"6)Prikazi go mnozestvoto krugovi"<<endl;
        cout<<"7)Prikazi najgolemi elementi"<<endl;
        cout<<"8)Prikazi broj na elementi vo mnozestvata"<<endl;
        cout<<"9)Kraj"<<endl;
        cin>>izbor;

        switch(izbor) {
        case 1: {
            cout<<"Vnesi dimenzii na pravoagolnikot."<<endl;
            cin>>d1>>d2;
            pravoagolnici.dodadi(Pravoagolnik<int>(d1,d2));
            break;
        }
        case 2: {
            cout<<"Vnesi dimenzii na kvadratot."<<endl;
            cin>>d1;
            kvadrati.dodadi(Kvadrat<int>(d1));
            break;
        }
        case 3: {
            cout<<"Vnesi radius na krugot."<<endl;
            cin>>r;
            krugovi.dodadi(Krug<float>(r));
            break;
        }
        case 4: {
            pravoagolnici.prikazi();
            break;
        }
        case 5: {
            kvadrati.prikazi();
            break;
        }
        case 6: {
            krugovi.prikazi();
            break;
        }
        case 7: {
            cout<<"Najgolem element vo mnozestvo pravoagolnici e "<<endl;
            pravoagolnici.najgolem().prikazi();
            cout<<"Najgolem element vo mnozestvo kvadrati e "<<endl;
            kvadrati.najgolem().prikazi();
            cout<<"Najgolem element vo mnozestvo krugovi e "<<endl;
            krugovi.najgolem().prikazi();
            break;
        }
        case 8: {
            cout<<"Broj na elementi vo mnozestvo pravoagolnici: "<<pravoagolnici.getBrojElementi()<<endl;
            cout<<"Broj na elementi vo mnozestvo kvadrati: "<<kvadrati.getBrojElementi()<<endl;
            cout<<"Broj na elementi vo mnozestvo krugovi: "<<krugovi.getBrojElementi()<<endl;
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
