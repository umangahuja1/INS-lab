#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char pt[30], c[27], ct[30];
    int i, j, index;
    cout << "\nEnter Plain Text : ";
    cin >> pt;
    cout << "\nEnter Key From a to z : \n";
    for (i = 0; i < 26; i++)
    {
        cout << (char)(i + 97) << "-";
        cin >> c[i];
    }

    for (i = 0; i < strlen(pt); i++)
    {
        index = pt[i] - 97;
        ct[i] = c[index];
    }

    cout << "\n\nCipher Text is : ";
    for (i = 0; i < strlen(pt); i++)
    {
        cout << ct[i];
    }
}