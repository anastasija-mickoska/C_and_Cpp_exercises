#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

/*Да се направи хиерархија за класата Oblik, така да оваа класа е апстрактна основна класа која содржи интерфејс
 *  за целата хиерархија. Од неа директно наследуваат DvoDimenzionalni и TroDimenzionalni кои исто така треба да
 *  се апстрактни. Од секоја од овие две  класи да се изведат најмалку по 3 облици. Да се користи виртуелна print функција
 *  за да се испечати типот и димензиите на секоја класа. Да се направат и виртуелни функции ploshtina и volumen
 *  кои ќе ги пресметуваат ове вредности за секој од облиците.
 * Да се напише тест програма која ги прикажува манипулациите со оваа хиерархија.*/
class Oblik {
public:
    virtual double plostina() const {
        return 0.0;
    }
    virtual double volumen() const {
        return 0.0;
    }
    virtual string getIme() const = 0;
    virtual void print() const = 0;
};

class DvoDimenzionalni : public Oblik {
private:
    int dolzina;
    int sirina;
public:
    DvoDimenzionalni(int x, int y) {
        dolzina = x;
        sirina = y;
    }
    void setDolzina(int x) {
        dolzina = x;
    }
    void setSirina(int y) {
        sirina = y;
    }
    int getDolzina() const {
        return dolzina;
    }
    int getSirina() const {
        return sirina;
    }
    string getIme() const {
        return "Dvodimenzionalen oblik - ";
    }
    void print() const {
        cout<<DvoDimenzionalni::getIme();
        cout<<"Dimenzii: ("<<getDolzina()<<", "<<getSirina()<<")"<<endl;
    }
};

class TroDimenzionalni : public Oblik {
private:
    int dolzina;
    int sirina;
    int visina;
public:
    TroDimenzionalni(int x, int y, int z) {
        dolzina = x;
        sirina = y;
        visina = z;
    }
    void setDolzina(int x) {
        dolzina = x;
    }
    void setSirina(int y) {
        sirina = y;
    }
    void setVisina(int z) {
        visina = z;
    }
    int getDolzina() const {
        return dolzina;
    }
    int getSirina() const {
        return sirina;
    }
    int getVisina() const {
        return visina;
    }
    string getIme() const {
        return "Trodimenzionalen oblik - ";
    }
    void print() const {
        cout<<TroDimenzionalni::getIme();
        cout<<"Dimenzii: ("<<getDolzina()<<", "<<getSirina()<<", "<<getVisina()<<")"<<endl;
    }
};

class Krug : public DvoDimenzionalni {
private:
    double radius;
public:
    Krug(int x, int y, double r) : DvoDimenzionalni( x,y) {
        radius = r;
    }
    void setRadius(double r) {
        radius = r;
    }
    double getRadius() const {
        return radius;
    }
    double plostina() const {
        return 3.14 * radius * radius;
    }
    string getIme() const {
        return " Krug -";
    }
    void print() const {
        cout<<Krug::getIme();
        DvoDimenzionalni::print();
        cout<<"Radius: "<<getRadius()<<endl;
    }
};

class Kvadrat : public DvoDimenzionalni {
public:
    Kvadrat(int x, int y) : DvoDimenzionalni(x,y) {
    }
    double plostina() const {
        return getDolzina() * getDolzina();
    }
    string getIme() const {
        return " Kvadrat -";
    }
    void print() const {
        cout<<Kvadrat::getIme();
        DvoDimenzionalni::print();
    }
};

class Pravoagolnik : public DvoDimenzionalni {
public:
    Pravoagolnik(int x, int y) : DvoDimenzionalni( x,y) {
    }
    double plostina() const {
        return getDolzina() * getSirina();
    }
    string getIme() const {
        return " Pravoagolnik -";
    }
    void print() const {
        cout<<Pravoagolnik::getIme();
        DvoDimenzionalni::print();
    }
};

class Topka : public TroDimenzionalni {
private:
    double radius;
public:
    Topka(int x, int y, int z, double r) : TroDimenzionalni(x,y,z) {
        radius = r;
    }
    void setRadius(double s) {
        radius = s;
    }
    double getRadius() const {
        return radius;
    }
    double plostina() const {
        return 4 * 3.14 * radius * radius;
    }
    double volumen() const {
        return (4 / 3) * 3.14 * radius * radius * radius;
    }
    string getIme() const {
        return " Topka -";
    }
    void print() const {
        cout<<Topka::getIme();
        TroDimenzionalni::print();
        cout<<"Radius: "<<getRadius()<<endl;
    }
};

class Kocka : public TroDimenzionalni {
public:
    Kocka(int x, int y, int z) : TroDimenzionalni(x,y,z) {
    }
    double plostina() const {
        return 6 * getDolzina() * getDolzina();
    }
    double volumen() const {
        return getDolzina() * getDolzina() * getDolzina();
    }
    string getIme() const {
        return " Kocka -";
    }
    void print() const {
        cout<<Kocka::getIme();
        TroDimenzionalni::print();
    }
};

class Kvadar : public TroDimenzionalni {
public:
    Kvadar(int x, int y, int z) : TroDimenzionalni(x,y,z) {
    }
    double plostina() const {
        return 2* ((getDolzina()*getSirina()) + (getDolzina()*getVisina()) + (getSirina()*getVisina()));
    }
    double volumen() const {
        return getDolzina() * getSirina() * getVisina();
    }
    string getIme() const {
        return " Kvadar -";
    }
    void print() const {
        cout<<Kvadar::getIme();
        TroDimenzionalni::print();
    }
};

int main() {
    Oblik* shapes[10];
    shapes[0] = new Krug(0, 0, 5.0);
    shapes[0]->print();
    cout<<"Plostina: "<<shapes[0]->plostina()<<endl;
    cout<<endl;
    shapes[1] = new Kvadrat(4,4);
    shapes[1]->print();
    cout<<"Plostina: "<<shapes[1]->plostina()<<endl;
    cout<<endl;
    shapes[2] = new Pravoagolnik(3,4);
    shapes[2]->print();
    cout<<"Plostina: "<<shapes[2]->plostina()<<endl;
    cout<<endl;
    shapes[3] = new Topka(0, 0, 0, 5.0);
    shapes[3]->print();
    cout<<"Plostina: "<<shapes[3]->plostina()<<endl;
    cout<<"Volumen: "<<shapes[3]->volumen()<<endl;
    cout<<endl;
    shapes[4] = new Kocka(4,4,4);
    shapes[4]->print();
    cout<<"Plostina: "<<shapes[4]->plostina()<<endl;
    cout<<"Volumen: "<<shapes[4]->volumen()<<endl;
    cout<<endl;
    shapes[5] = new Kvadar(4,5,6);
    shapes[5]->print();
    cout<<"Plostina: "<<shapes[5]->plostina()<<endl;
    cout<<"Volumen: "<<shapes[5]->volumen()<<endl;

    for(int i=0;i<5;i++) {
        delete shapes[i];
    }

    return 0;
}
