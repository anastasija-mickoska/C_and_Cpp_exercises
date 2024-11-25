#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

//zadaca 1
class Imenik {
private:
    char *ime;
    char *telefon;

public:
    Imenik() : ime(nullptr), telefon(nullptr) {}

    Imenik(const char *i, const char *t) {
        ime = new char[strlen(i) + 1];
        strcpy(ime, i);
        ime[strlen(i)] = '\0'; // Correctly null-terminate
        telefon = new char[strlen(t) + 1];
        strcpy(telefon, t);
        telefon[strlen(t)] = '\0'; // Correctly null-terminate
    }
    bool operator<(const Imenik& other) const {
        return strcmp(ime, other.ime) < 0;
    }

    friend ostream& operator<<(ostream& os, const Imenik& im) {
        os<<"Name: "<<im.ime<<", Phone: "<<im.telefon;
        return os;
    }
};

//zadaca 2
bool anagram(const string& z1, const string& z2) {
    if (z1.size() != z2.size()) {
        return false;
    }
    if (z1.empty() || z2.empty()) {
        return false;
    }
    vector<char> zbor1(zbor1.begin(), zbor1.end());
    vector<char> zbor2(zbor2.begin(), zbor2.end());

    transform(zbor1.begin(), zbor1.end(), zbor1.begin(), [](unsigned char c) { return tolower(c); });
    transform(zbor2.begin(), zbor2.end(), zbor2.begin(), [](unsigned char c) { return tolower(c); });

    sort(zbor1.begin(), zbor1.end());
    sort(zbor2.begin(), zbor2.end());

    return equal(zbor1.begin(), zbor1.end(), zbor2.begin());
}

int main() {
    //zadaca 1
    vector<Imenik> imenik;
    imenik.push_back(Imenik("Ana", "123-456"));
    imenik.push_back(Imenik("Maya", "123-4567-8"));
    imenik.push_back(Imenik("John", "12-345/67"));

    sort(imenik.begin(), imenik.end());

    cout<<"Sorted by alphabetical order:"<<endl;
    for(const Imenik& im : imenik) {
        cout<<im<<endl;
    }

    //zadaca 2
    string zbor1, zbor2;
    cout<<"Vnesi dva zbora."<<endl;
    cin>>zbor1;
    cin>>zbor2;
    if(anagram(zbor1,zbor2)) {
        cout<<"Zborovite se anagrami."<<endl;
    }
    else cout<<"Zborovite ne se anagrami."<<endl;

    //zadaca 3
    string tekst;
    cout << "Vnesi tekst: ";
    getline(cin, tekst);

    vector<string> zborovi;
    string zbor;

    for (char c : tekst) {
        if (c == ' ') {
            if (!zbor.empty()) {
                zborovi.push_back(zbor);
                zbor.clear();
            }
        } else {
            zbor += c;
        }
    }

    if (!zbor.empty()) {
        zborovi.push_back(zbor);
    }
    sort(zborovi.begin(), zborovi.end());
    vector<string>::iterator it = unique(zborovi.begin(), zborovi.end());
    zborovi.resize(distance(zborovi.begin(), it));
    cout<<"Zborovi vo abeceden redosled:\n";
    for (const string& z : zborovi) {
        cout<<z<<endl;
    }

    return 0;
}
