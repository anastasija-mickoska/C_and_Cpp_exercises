#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <random>
#include <map>
using namespace std;

//zadaca 2

vector<pair<string, int>> kreirajSpil() {
    vector<pair<string, int>> spil;
    vector<string> boi = {"Srce", "Karo", "List", "Detelina"};
    for (const auto& boja : boi) {
        for (int vrednost = 1; vrednost <= 13; ++vrednost) {
            spil.emplace_back(boja, vrednost);
        }
    }
    return spil;
}

void mesajSpil(vector<pair<string, int>>& spil) {
    random_shuffle(spil.begin(), spil.end());
}

int presmetajZbir(const vector<pair<string, int>>& karti, bool dvojnaVrednostZaSrce) {
    int zbir = 0;
    for (const auto& karta : karti) {
        int vrednost = karta.second;
        if (karta.first == "Srce" && dvojnaVrednostZaSrce) {
            vrednost *= 2;
        }
        zbir += vrednost;
    }
    return zbir;
}

int main() {
    //zadaca 1
    vector<int> numbers(10000);

    srand(static_cast<unsigned>(time(0)));

    for (int& num : numbers) {
        num = rand() % 10000;
    }

    int parni = count_if(numbers.begin(), numbers.end(), [](int n) { return n % 2 == 0; });
    int pomaliOd2000 = count_if(numbers.begin(), numbers.end(), [](int n) { return n < 2000; });
    int od2000do4000 = count_if(numbers.begin(), numbers.end(), [](int n) { return n >= 2000 && n < 4000; });
    int od4000do6000 = count_if(numbers.begin(), numbers.end(), [](int n) { return n >= 4000 && n < 6000; });
    int od6000do8000 = count_if(numbers.begin(), numbers.end(), [](int n) { return n >= 6000 && n < 8000; });
    int od8000do10000 = count_if(numbers.begin(), numbers.end(), [](int n) { return n >= 8000 && n < 10000; });

    double average = accumulate(numbers.begin(), numbers.end(), 0.0) / 10000;

    cout<<"Broj na parni elementi: "<<parni<<endl;
    cout<<"Pomali od 2000: "<<pomaliOd2000<<endl;
    cout<<"Pomegju 2000 i 4000: "<<od2000do4000<<endl;
    cout<<"Pomegju 4000 i 6000: "<<od4000do6000<<endl;
    cout<<"Pomegju 6000 i 8000: "<<od6000do8000<<endl;
    cout<<"Pomegju 8000 i 10000: "<<od8000do10000<<endl;
    cout<<"Sredna vrednost: "<<average<<endl;

    //zadaca 2

    int brojIgraci;
    cout << "Vnesi broj na igraci: ";
    cin >> brojIgraci;

    if (brojIgraci <= 0 || brojIgraci > 52) {
        cout << "Brojot na igraci mora da bide pomal od 52 i pogolem od 0." << endl;
        return 1;
    }

    auto spil = kreirajSpil();
    mesajSpil(spil);

    map<int, vector<pair<string, int>>> igraci;
    for (int i = 0; i < spil.size(); ++i) {
        igraci[i % brojIgraci].push_back(spil[i]);
    }

    map<int, int> zbirIgrac;
    bool dvojnaVrednostZaSrce = true;
    for (int igrac = 0; igrac < brojIgraci; ++igrac) {
        cout << "Igrac " << igrac + 1 << " gi ima slednite karti:" << endl;
        for (const auto& karta : igraci[igrac]) {
            cout << karta.first << " " << karta.second << ", ";
        }
        cout << endl;
        int zbir = presmetajZbir(igraci[igrac], dvojnaVrednostZaSrce);
        zbirIgrac[igrac] = zbir;
        cout << "Zbir: " << zbir << endl;
        cout<<endl;
    }
    auto pobednik = max_element(zbirIgrac.begin(), zbirIgrac.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });
    cout << "Pobednik e Igrac " << pobednik->first + 1 << " so zbir: " << pobednik->second << endl;


    return 0;
}

