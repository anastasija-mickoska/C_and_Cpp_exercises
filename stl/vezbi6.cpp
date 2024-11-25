#include <iostream>
#include <set>
#include <map>
#include <queue>
using namespace std;

//zadaca 1
class Uplata {
private:
    string ime;
    int uplata;
public:
    Uplata() {}
    Uplata(string i, int u) {
        ime=i;
        uplata=u;
    }
    const string getIme() {
        return ime;
    }
    int getUplata() {
        return uplata;
    }
    void setIme(string i) {
        ime = i;
    }
    void setUplata(int p) {
        uplata = p;
    }
};

void dodadiUplata(multimap<string, double>& uplati) {
    Uplata stedac;
    int suma;
    string i;

    cout<<"Vnesi ime: ";
    cin.ignore();
    getline(cin,i);
    stedac.setIme(i);

    cout<<"Vnesi iznos na uplata: ";
    cin>>suma;
    stedac.setUplata(suma);

    uplati.insert({stedac.getIme(), stedac.getUplata()});
    cout<<"Uspesno dodadena uplata."<<endl;
}

void prikaziUplatiZaStedac(const  multimap< string, double>& uplati) {
    Uplata stedac;
    int suma;
    string i;

    cout<<"Vnesi ime: ";
    cin.ignore();
    getline(cin,i);
    stedac.setIme(i);

    auto range = uplati.equal_range(stedac.getIme());
    if (range.first == range.second) {
         cout << "Nema uplati za ovoj stedac.\n";
        return;
    }

    cout << "Uplati za stedacot "<<stedac.getIme()<<endl;
    int vkupno = 0;
    for (auto it = range.first; it != range.second; ++it) {
         cout << "-" << it->second << " denari\n";
        vkupno += it->second;
    }
     cout << "Vkupno uplati: " << vkupno << " denari"<<endl;
}

//zadaca 2
class Proces {
private:
    int id;
    double priority;
public:
    Proces() {
    }
    Proces(int i, double p){
        id=i;
        priority=p;
    }
    int getId(){
        return id;
    }
    double getPriority() {
        return priority;
    }
    bool operator<(const Proces& other) const {
        return priority < other.priority;
    }
};

int main() {
    //zadaca 1
    multimap< string, double> uplati;
    int izbor;

    do {
        cout << "Izberi opcija od korisnickoto meni: "<<endl;
        cout << "1) Dodaj uplata"<<endl;
        cout << "2) Prikazi uplati za daden stedac"<<endl;
        cout << "3) Kraj"<<endl;
        cin >> izbor;

        switch (izbor) {
        case 1:
            dodadiUplata(uplati);
            break;
        case 2:
            prikaziUplatiZaStedac(uplati);
            break;
        case 3:
             cout << "Kraj."<<endl;
            break;
        default:
             cout << "Greshka! Obidete se povtorno."<<endl;
        }
    } while (izbor != 3);

    //zadaca 2
    priority_queue<Proces> procesi;
    char c;
    int ID;
    double p;
    while(c!='n') {
        cout<<"Dali kje se vnesuvaat uste podatoci?"<<endl;
        cin>>c;
        cout<<"Vnesi id."<<endl;
        cin>>ID;
        cout<<"Vnesi prioritet na procesot."<<endl;
        cin>>p;
        procesi.push({ID, p});

    }
    cout << "Procesite kje bidat opsluzeni po sledniot redosled:"<<endl;
    while (!procesi.empty()) {
        Proces p = procesi.top();
        procesi.pop();

        cout << "Proces ID: " << p.getId() << ", Prioritet: " << p.getPriority() << endl;
    }
    return 0;
}
