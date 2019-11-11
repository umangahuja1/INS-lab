#include <iostream>
#include <cmath>

using namespace std;


long long gcd(long long a, long long b)
{
    if(b==0) return a;

    return gcd(b, a%b);
}

long long power(long long x, long long p, long long n)
{
    if(p==1) return x;

    long long temp = power(x,p/2,n);

    if(p&1)
        return (temp%n * temp%n * x)%n;
    else
        return (temp%n * temp%n)%n;
}

int main()
{
    long long p,g;
    
    cout << "Enter prime number p : ";
    cin >> p;

    cout << "Enter the value of primitive root (g) of p : ";
    cin >> g;

    long long a,b,A,B;

    cout << "\nEnter private key of A : ";
    cin >> a;

    cout << "Enter private key of B : ";
    cin >> b;

    A = power(g,a,p);

    cout << "\nPublic key of A : " << A << endl;

    B = power(g,b,p);

    cout << "Public key of B : " << B << endl;

    long long ka, kb;

    ka = power(B,a,p);
    kb = power(A,b,p);

    cout << "\nSecret key of A : " << ka << endl;
    cout << "Secret key of B : " << kb << endl;

    return 0;
}