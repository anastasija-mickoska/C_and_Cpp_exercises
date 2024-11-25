#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

//zadaca 1
template<class T>
void sort(T arr[], int n) {
    T temp;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(arr[j] < arr[i]) {
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }
}

//zadaca 2
template<class T>
int printArray(T arr, int n, int lowSubscript, int highSubscript) {
    if(lowSubscript < 0 || highSubscript > n) {
        return 0;
    }
    else {
        for(int i=lowSubscript;i<highSubscript;i++) {
            cout<<arr[i]<<",";
        }
    }
    return highSubscript-lowSubscript;
}

//zadaca 4
void printArray(int arr[], int n) {
    for (int i=0;i<n;i++) {
        std::cout << std::setw(5) << arr[i];
        if ((i + 1) % 4 == 0) {
            cout<<endl;
        }
    }
}

//zadaca 5
template<class T>
class Array {
private:
    T* niza;
    int n;
public:
    Array(int size) : n(size){
        niza = new T[n];
    }
    ~Array() {
        delete[] niza;
    }
    void setElement(int index, const T& value) {
        if (index >= n) {
            cout<<"Out of range!"<<endl;
        }
        niza[index] = value;
    }
    T getElement(int index) const {
        if (index >= n) {
            cout<<"Out of range!"<<endl;
        }
        return niza[index];
    }
    int getSize() const {
        return n;
    }
};


int main() {
    //zadaca 1
    int array1[5];
    double array2[5];

    for(int i=0;i<5;i++) {
        cin>>array1[i];
    }
    for(int i=0;i<5;i++) {
        cin>>array2[i];
    }

    sort(array1, 5);
    sort(array2, 5);

    for(int i=0;i<5;i++) {
        cout<<array1[i]<<",";
    }
    cout<<endl;
    for(int i=0;i<5;i++) {
        cout<<array2[i]<<",";
    }
    cout<<endl;

    //zadaca 2
    int a=2, b=4;
    int c=printArray(array1, 5, a,b);
    int d=printArray(array2, 5,a,b);
    cout<<c<<" "<<d<<endl;

    //zadaca 4
    printArray(array1, 5);

    //zadaca 5
    Array<int> niza1(5);
    Array<double> niza2(4);
    for(int i=0;i<5;i++) {
        niza1.setElement(i, rand() % 10);
    }
    for(int i=0;i<4;i++) {
        niza2.setElement(i, rand() % 10);
    }
    int p=2;
    cout<<"Element na pozicija "<<p<<" vo niza1 e "<<niza1.getElement(p)<<endl;
    cout<<"Element na pozicija "<<p<<" vo niza2 e "<<niza2.getElement(p)<<endl;

    return 0;
}
