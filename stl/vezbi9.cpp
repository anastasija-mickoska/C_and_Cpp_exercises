#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <exception>
#include <iterator>
using namespace std;

class SpaceException : public exception {
public:
    const char* what() const noexcept override {
        return "Nema prostor za kopiranje!";
    }
};

int main() {
    srand(time(0));
    int n1,n2;
    n1= rand() % 999 + 1;
    n2= rand() % 999 + 1;

    vector<int> vektor1;
    vector<int> vektor2;

    for(int i=0; i<n1; ++i) {
        vektor1.push_back(rand() % 10000);
    }
    for (int i=0; i<n2; ++i) {
        vektor2.push_back(rand() % 10000);
    }
    //se popolnuvaat vektorite

    while(true) {
        try {
            if(vektor1.size() < vektor2.size()) {
                throw SpaceException();
            }
            copy(vektor2.begin(), vektor2.end(), back_inserter(vektor1));
            cout<<"Uspesno kopiranje."<<endl;
            break;
        }
        catch(const SpaceException &e) {
            cout<<e.what()<<endl;
            break;
        }
    }
    cout << "Golemina na prviot vektor po kopiranjeto: " << vektor1.size() << endl;
    return 0;
}
