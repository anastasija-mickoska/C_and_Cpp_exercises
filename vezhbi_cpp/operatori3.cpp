#include <iostream>
#include <cassert>
using namespace std;

class Matrica {
    friend istream &operator>>(istream &, Matrica &);
    friend ostream &operator<<(ostream &, const Matrica &);

private:
    int m, n;
    int *ptr;
    static int matrixCount;

public:
    Matrica(int rows = 4, int columns = 5);
    Matrica(const Matrica &);
    ~Matrica();

    Matrica &operator=(const Matrica &);
    Matrica operator+(const Matrica &) const;
    Matrica operator-(const Matrica &) const;
    Matrica operator*(const Matrica &) const;
    Matrica operator+(int) const;
    Matrica operator-(int) const;
    Matrica operator*(int) const;

    int &operator[](int index);
    const int &operator[](int index) const;

    static int getMatrixCount();

    int getRows() const { return m; }
    int getCols() const { return n; }
};

int Matrica::matrixCount = 0;

Matrica::Matrica(int rows, int cols) : m(rows), n(cols) {
    ptr = new int[m * n]{0};
    assert(ptr != nullptr);
    ++matrixCount;
}

Matrica::Matrica(const Matrica &matrix) : m(matrix.getRows()), n(  matrix.getCols()) {
    ptr = new int[m * n];
    assert(ptr != nullptr);
    ++matrixCount;
    for (int i = 0; i < m * n; ++i) {
        ptr[i] =   matrix.ptr[i];
    }
}

Matrica::~Matrica() {
    delete[] ptr;
    --matrixCount;
}

Matrica::Matrica(const int* arr) { //konverziski konstruktor za prefrlanje od matrica vo niza
    ptr = new int[m * n];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            ptr[i * n + j] = arr[i * n + j];
        }
    }
}

Matrica &Matrica::operator=(const Matrica &matrix) {
    if (this != &matrix) {
        if (m * n !=  (matrix.getRows() * matrix.getCols())) {
            delete[] ptr;
            ptr = new int[matrix.getRows() * matrix.getCols()];
            assert(ptr != nullptr);
        }
        m = matrix.getRows();
        n = matrix.getCols();
        for (int i = 0; i < m * n; ++i) {
            ptr[i] = matrix.ptr[i];
        }
    }
    return *this;
}

Matrica Matrica::operator+(const Matrica &matrix) const {
    assert(m == matrix.getRows() && n == matrix.getCols());
    Matrica result(m, n);
    for (int i = 0; i < m * n; ++i) {
        result.ptr[i] = ptr[i] + matrix.ptr[i];
    }
    return result;
}

Matrica Matrica::operator-(const Matrica &matrix) const {
    assert(m ==   matrix.getRows() && n ==   matrix.getCols());
    Matrica result(m, n);
    for (int i = 0; i < m * n; ++i) {
        result.ptr[i] = ptr[i] - matrix.ptr[i];
    }
    return result;
}

Matrica Matrica::operator*(const Matrica &matrix) const {
    assert(n == matrix.getRows());
    Matrica result(m, matrix.getCols());
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < matrix.getCols(); ++j) {
            result.ptr[i * matrix.getCols() + j] = 0;
            for (int k = 0; k < n; ++k) {
                result.ptr[i * matrix.getCols() + j] += ptr[i * n + k] * matrix.ptr[k * matrix.getCols() + j];
            }
        }
    }
    return result;
}

Matrica Matrica::operator+(int b) const {
    Matrica result(m, n);
    for (int i = 0; i < m * n; ++i) {
        result.ptr[i] = ptr[i] + b;
    }
    return result;
}

Matrica Matrica::operator-(int b) const {
    Matrica result(m, n);
    for (int i = 0; i < m * n; ++i) {
        result.ptr[i] = ptr[i] - b;
    }
    return result;
}

Matrica Matrica::operator*(int b) const {
    Matrica result(m, n);
    for (int i = 0; i < m * n; ++i) {
        result.ptr[i] = ptr[i] * b;
    }
    return result;
}

int &Matrica::operator[](int index) {
    assert(index >= 0 && index < m * n);
    return ptr[index];
}

const int &Matrica::operator[](int index) const {
    assert(index >= 0 && index < m * n);
    return ptr[index];
}

int Matrica::getMatrixCount() {
    return matrixCount;
}

istream &operator>>(istream &input, Matrica &matrix) {
    for (int i = 0; i < matrix.getRows() * matrix.getCols(); ++i) {
        input >> matrix.ptr[i];
    }
    return input;
}

ostream &operator<<(ostream &output, const Matrica &matrix) {
    for (int i = 0; i < matrix.getRows(); ++i) {
        for (int j = 0; j < matrix.getCols(); ++j) {
            output << matrix.ptr[i * matrix.getCols() + j] << " ";
        }
        output << endl;
    }
    return output;
}

Matrica operator+(int b, const Matrica &matrix) {
    Matrica result(matrix.getRows(), matrix.getCols());
    for (int i = 0; i < matrix.getRows(); ++i) {
        for (int j = 0; j < matrix.getRows(); ++j) {
            result.ptr[i * matrix.getCols() + j] = b + matrix.ptr[i * matrix.getCols() + j];
        }
    }
    return result;
}

Matrica operator-(int b, const Matrica &matrix) {
    Matrica result(matrix.getRows(), matrix.getCols());
    for (int i = 0; i < matrix.getRows(); ++i) {
        for (int j = 0; j < matrix.getCols(); ++j) {
            result.ptr[i * matrix.getCols() + j] = b - matrix.ptr[i * matrix.getCols() + j];
        }
    }
    return result;
}

Matrica operator*(int b, const Matrica &matrix) {
    Matrica result(matrix.getRows(), matrix.getCols());
    for (int i = 0; i < matrix.getRows(); ++i) {
        for (int j = 0; j < matrix.getCols(); ++j) {
            result.ptr[i * matrix.getCols() + j] = b * matrix.ptr[i * matrix.getCols() + j];
        }
    }
    return result;
}

int main() {
    int izbor;
    Matrica m(3,4);
    Matrica n(4,2);
    Matrica p(3,4);

    while(izbor!=11) {
        cout<<"Izberi opcija od korisnickoto meni."<<endl;
        cout<<"1) Sobiranje na dve matrici"<<endl;
        cout<<"2) Odzemanje na dve matrici"<<endl;
        cout<<"3) Mnozenje na dve matrici"<<endl;
        cout<<"4) Sobiranje na matrica i cel broj"<<endl;
        cout<<"5) Odzemanje na matrica i cel broj"<<endl;
        cout<<"6) Mnozenje na matrica i cel broj"<<endl;
        cout<<"7) Sobiranje na cel broj i matrica"<<endl;
        cout<<"8) Odzemanje na cel broj i matrica"<<endl;
        cout<<"9) Mnozenje na cel broj i matrica"<<endl;
        cout<<"10) Ednakvost na nizi"<<endl;
        cout<<"11) Izlez"<<endl;

        switch(izbor) {
        case 1: {

        }
        }
    }


    return 0;
}
