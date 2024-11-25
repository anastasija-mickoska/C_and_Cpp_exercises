#include <iostream>
#include <vector>
#include <cstring>
#include <list>
#include<algorithm>
#include <deque>
using namespace std;

//zadaca 1
template <typename T>
bool palindrom(const vector<T>& element) {
    auto iteratorNapred = element.begin();
    auto iteratorNazad = element.end() - 1;
    while (iteratorNapred < iteratorNazad) {
        if (*iteratorNapred != *iteratorNazad) {
            return false;
        }
        ++iteratorNapred;
        --iteratorNazad;
    }
    return true;
}


int main() {
    //zadaca 1
    string zbor;
    vector<char> zbor1;

    cout << "Vnesi zbor." << endl;
    cin >> zbor;
    for (char c : zbor) {
        zbor1.push_back(c);
    }
    if (palindrom(zbor1)) {
        cout << "Vektorot e palindrom." << endl;
    } else {
        cout << "Vektorot ne e palindrom." << endl;
    }

    //zadaca 2
    list<char*> email1List;
    list<char*> email2List;
    list<char*> email3List;
    vector<char*>::iterator it;
    email1List.push_back("email1@gmail.com");
    email1List.push_back("email2@gmail.com");
    email1List.push_back("email3@gmail.com");
    email2List.push_back("email4@gmail.com");
    email2List.push_back("email2@gmail.com");
    email3List.push_back("email5@gmail.com");
    email3List.push_back("email1@gmail.com");

    email1List.sort();
    email2List.sort();
    email3List.sort();

    email1List.merge(email2List);
    email1List.merge(email3List);
    cout<<"Posle spojuvanje, so duplikati:"<<endl;
    for(const auto& email : email1List) {
        cout<<email<<endl;
    }
    cout<<"Bez duplikati:"<<endl;
    email1List.unique();
    for(const auto& email : email1List) {
        cout<<email<<endl;
    }

    //zadaca 3
    deque<int> d;
    vector<int> v1;
    vector<int> v;
    vector<int>::reverse_iterator it1;
    vector<int>::iterator it2;
    d.push_back(15);
    d.push_back(54);
    d.push_back(45);
    d.push_back(20);
    d.push_back(27);
    d.push_back(18);

    for(const auto& br : d) {
        v1.push_back(br);
    }
    for(it1=v1.rbegin(); it1!=v1.rend();++it1) {
        v.push_back(*it1);
    }

    cout<<"Vektorot vo obraten redosled:"<<endl;
    for(it2=v.begin(); it2!=v.end();++it2) {
        cout<<*it2<<endl;
    }

    return 0;
}
