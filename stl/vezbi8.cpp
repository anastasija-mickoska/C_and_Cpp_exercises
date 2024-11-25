#include <iostream>
#include <algorithm>
#include <numeric>
#include <list>
#include <string>

using namespace std;

class Vraboten {
private:
    string ime;
    int bodovi;
public:
    Vraboten() {
        ime="";
        bodovi=0;
    }
    Vraboten(string i, int b) {
        ime=i;
        bodovi=b;
    }
    string getIme() const {
        return ime;
    }
    int getBodovi() const {
        return bodovi;
    }
    bool operator<(const Vraboten& other) const {
        return bodovi < other.bodovi;
    }
};

int main() {
    list<Vraboten> vraboteni;
    int br, bod, vr;
    string ime;
    int suma;

    cout << "Vnesi broj na vraboteni." << endl;
    cin >> br;
    cout << "Vnesi ja vrednosta na bodot." << endl;
    cin >> vr;

    for (int i = 0; i < br; i++) {
        cout << "Vnesi ime." << endl;
        cin >> ime;
        cout << "Vnesi bodovi." << endl;
        cin >> bod;
        vraboteni.emplace_back(ime, bod);
    }
    vraboteni.sort();
    cout << "Vraboteni sortirani po bodovi: " << endl;
    for (const auto& v : vraboteni) {
        cout << v.getIme() << " - " << v.getBodovi() << " bodovi" << endl;
    }
    suma = accumulate(vraboteni.begin(), vraboteni.end(), 0, [](int total, const Vraboten& v) {
        return total + v.getBodovi();
    });
    suma *= vr;
    cout << "Vkupnata mesecna plata sto treba da se isplati e " << suma << endl;

    return 0;
}
