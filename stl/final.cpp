#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <fstream>
#include <sstream>
#include <exception>

using namespace std;

//zadaca 1

template<typename T>
class Pole {
private:
    vector<T> array;
    int size;
public:
    Pole() {}
    Pole(T arr[], int s) {
        size=s;
        for(int i=0;i<s;i++) {
            array.push_back(arr[i]);
        }
    }
    int getSize() {
        return size;
    }
    void addElement(T value) {
        array.push_back(value);
    }
    T getElementAtIndex(int index) const {
        return array.at(index);
    }
    T& operator[](int index) {
        return array[index];
    }
    const T& operator[](int index) const {
        return array[index];
    }
    friend ostream& operator<<(ostream& os, const Pole<T>& pole) {
        for (const auto& element : pole.array) {
            os << element << " ";
        }
        return os;
    }
};

//zadaca 2
class Inventar {
private:
    int id;
    int kolicestvo;
    double cena;
public:
    Inventar() {}
    Inventar(int i,int k, double c) {
        id=i;
        kolicestvo=k;
        cena=c;
    }
    int getKolicestvo() const {
        return kolicestvo;
    }
    double getCena() const {
        return cena;
    }
    int getID() const {
        return id;
    }
    void prikaziArtikl() {
        cout<<"ID: "<<id<<", kolicestvo: "<<kolicestvo<<", cena: "<<cena<<endl;
    }
};

template<typename T>
T max(Pole<T>& arr, int n) {
    T maximum=arr[0];
    for(int i=1;i<n;i++) {
        if(arr[i] > maximum) {
            maximum=arr[i];
        }
    }
    return maximum;
}

int main() {
    Pole<int> niza1;
    Pole<char> niza2;
    Pole<string> niza3;

    cout<<"Popolni ja nizata so integeri."<<endl;
    for(int i=0;i<5;i++) {
        int temp;
        cin >> temp;
        niza1.addElement(temp);
    }
    cout<<"Najgolem element: "<<max(niza1,5);

    cout<<"Popolni ja nizata so karakteri."<<endl;
    for(int i=0;i<5;i++) {
        char temp;
        cin >> temp;
        niza2.addElement(temp);
    }
    cout<<"Najgolem element: "<<max(niza2,5);

    cout<<"Popolni ja nizata so stringovi."<<endl;
    for(int i=0;i<5;i++) {
        string temp;
        cin >> temp;
        niza3.addElement(temp);
    }
    cout<<"Najgolem element: "<<max(niza3,5);

    //zadaca 2

    ifstream input_file("inventar.txt");
    if (!input_file) {
        throw runtime_error("Ne mozhe da se otvori datotekata inventar.txt!");
        return 1;
    }

    vector<Inventar> artikli;
    int id,k;
    double c;

    while (input_file >> id >> k >> c) {
        artikli.emplace_back(id, k, c);
    }
    input_file.close();

    double suma = accumulate(artikli.begin(), artikli.end(), 0.0, [](double vkupno, const Inventar& artikl) {
        return vkupno + artikl.getKolicestvo() * artikl.getCena();
    });
    cout<<"Vkupna vrednost: "<<suma<<endl;
    for(auto &a:artikli) {
        if(a.getKolicestvo() < 10 ) {
            a.prikaziArtikl();
        }
    }

    return 0;
}
