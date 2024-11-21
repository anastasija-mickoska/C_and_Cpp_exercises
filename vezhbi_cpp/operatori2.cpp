#include <iostream>

using namespace std;
using std::cout;
using std::cin;
using std::endl;

class Complex {
public:
    Complex( double = 0.0, double = 0.0 );
    Complex operator+( const Complex & ) const;
    Complex operator-( const Complex & ) const;
    Complex operator*( int ) const;
    Complex operator*( const Complex & ) const ;
    friend Complex operator*(int, const Complex &);
    const Complex &operator=(const Complex &);
    bool operator==(const Complex &) const;
    bool operator!=(const Complex &) const;
    Complex &operator+=(const Complex &);
    Complex &operator-=(const Complex &);
    Complex &operator*=(const Complex &);
    friend ostream &operator<<(ostream &, const Complex &);
    friend istream &operator>>(istream &, Complex &);

private:
    double real;
    double imaginary;
};

Complex::Complex( double r, double i )
    : real( r ), imaginary( i ) { }


ostream &operator<<( ostream &output, const Complex &num )
{
    output << num.real << " + " << num.imaginary << "i";
    return output;
}

istream &operator>>( istream &input, Complex &num )
{
    input >> num.real >> num.imaginary;
    return input;
}

Complex Complex::operator+( const Complex &operand2 ) const
{
    return Complex( real + operand2.real,
                   imaginary + operand2.imaginary );
}

Complex Complex::operator-( const Complex &operand2 ) const
{
    return Complex( real - operand2.real,
                   imaginary - operand2.imaginary );
}

const Complex& Complex::operator=( const Complex &right )
{
    real = right.real;
    imaginary = right.imaginary;
    return *this;
}

Complex operator*(int b, const Complex &num) {
    return Complex(num.real * b, num.imaginary * b);
}

Complex Complex::operator*( int b ) const {
    Complex temp;
    temp.real = (double) real * b;
    temp.imaginary = (double) imaginary * b;
    return temp;
}

Complex Complex::operator*( const Complex &c ) const {
    Complex temp;
    temp.real = (double) real * c.real - imaginary * c.imaginary;
    temp.imaginary = (double) real * c.imaginary + imaginary * c.real;
    return temp;
}

bool Complex::operator==(const Complex &num) const {
    return ((real == num.real) && (imaginary == num.imaginary));
}

bool Complex::operator!=(const Complex &num) const {
    return !(*this == num);
}

Complex &Complex::operator+=(const Complex &num) {
    this->real += num.real;
    this->imaginary += num.imaginary;
    return *this;
}

Complex &Complex::operator-=(const Complex &num) {
    this->real -= num.real;
    this->imaginary -= num.imaginary;
    return *this;
}

Complex &Complex::operator*=(const Complex &num) {
    this->imaginary = (this->real * num.imaginary) + (this->imaginary * num.real);
    this->real = (this->real * num.real) - (this->imaginary * num.imaginary);;
    return *this;
}


int main()
{
    Complex x, y(4, 8), z(3, 1);

    cout << "Enter a complex number."<<endl;
    cin >> x;

    cout << "x: " << x <<endl;
    cout << "y: " << y <<endl;
    cout << "z: " << z <<endl;

    x = y + z;
    cout << "x = y + z = " << x <<  endl;

    x = y - z;
    cout << "x = y - z = " << x <<  endl;

    x = y * z;
    cout << "x = y * z = " << x <<  endl;

    x += z;
    cout << "x += z  => x = " << x <<  endl;

    x -= y;
    cout << "x -= y  => x = " << x <<  endl;

    x *= z;
    cout << "x *= z  => x = " << x <<  endl;

    x = y * 2;
    cout << y << " * 2 = " << x <<  endl;

    x = 3 * z;
    cout << "3 * " << z << " = " << x <<  endl;

    if (x == z) cout << "x and z are equal.\n";
    else cout << "x and z are not equal.\n";


    return 0;
}


