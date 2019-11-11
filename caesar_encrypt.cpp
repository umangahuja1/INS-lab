#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream cin("input.txt");
    string message;
    char ch;
    int i, key;

    cout << "Enter a message to encrypt : ";
    cin >> message;
    cout << message << endl;
    ;
    cout << "Enter key: ";
    cin >> key;
    cout << message << endl;

    for (i = 0; message[i] != '\0'; ++i)
    {
        ch = message[i];
        if (ch == ' ')
        {
            ch = '#';
            message[i] = ch;
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            ch = char((ch + key - 'a') % 26 + 'a');
            message[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            ch = char((ch + key - 'a') % 26 + 'a');
            message[i] = ch;
        }
    }
    cout << "Encrypted message: " << message;
    return 0;
}