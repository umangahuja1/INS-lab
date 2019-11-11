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
    long long p,q;
    
    long long message;

    cout << "Enter two prime numbers : ";
    cin >> p >> q;

    cout << "Enter the value of message : ";
    cin >> message;

    long long n = p * q;
    long long phi = (p-1) * (q-1);

    long long e = 2;
    while(e < phi)
    {
        if(gcd(e,phi)==1)
            break;

        else 
            e++;
    } 

    long long k = 1;
    long long d = (1 + k*phi)/e;

    while(d < phi)
    {
        if( (1+k*phi)%e == 0)
        {
            d = (1+k*phi)/e;
            break;
        }

        else
            k++;
    }

    long long c = power(message, e, n);

    cout << "\nOriginal Message : " << message << endl;

    cout << "\nPublic key (e,n) : (" << e << ", " << n << ")" << endl;

    cout << "Private key (d,n) : (" << d << ", " << n << ")" << endl;

    cout << "\nEncrypted Message : " << c << endl;

    long long m = power(c, d, n);

    cout << "Decrypted Message : " << m << endl;

    return 0;
}