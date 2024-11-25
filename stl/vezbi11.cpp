#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    //zadaca 1
    int m,n;
    cout<<"Vnesi go n."<<endl;
    cin>>n;
    cout<<"Vnesi ja sirinata na kolonite."<<endl;
    cin>>m;
    cout<<endl;
    cout<<"i"<<setw(m)<<"i^2"<<setw(m)<<"i^(1/2)"<<setw(m)<<"i^(1/3)"<<endl;
    cout<<setw(35)<<"------------------------------------"<<endl;
    for(int i=1;i<=n;i++) {
        cout<<i<<setw(m)<<pow(i,2)<<setw(m)<<sqrt(i)<<setw(m)<<cbrt(i)<<endl;
    }
    //zadaca 2
    ifstream input("data.txt");
    ofstream output("output_data.txt");

    if(!input.is_open()) {
        cout<<"Fajlot ne moze da se otvori."<<endl;
    }
    if(!output.is_open()) {
        cout<<"Fajlot ne moze da se otvori."<<endl;
    }
    string line;
    while (getline(input, line)) {
        stringstream ss(line);
        string word;
        while (ss >> word) {
            if (word.length() < 10) {
                output << word << endl;
            }
        }
    }
    input.close();
    output.close();
    return 0;
}
