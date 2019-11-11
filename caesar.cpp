#include <iostream>
#include <cstring>

using namespace std;

string encrypt(string message, int key)
{
    string cipher;

    for(int i=0;i<message.size();i++)
    {
        if(message[i] == ' ')
            cipher += ' ';

        else if(isupper(message[i]))
            cipher += (message[i] - 'A' + key )%26 + 'A';

        else
            cipher += (message[i] - 'a' + key )%26 + 'a';
    }

    return cipher;
}

string decrypt(string cipher, int key)
{
    string message;

    for(int i=0;i<cipher.size();i++)
    {
        if(cipher[i] == ' ')
            message += ' ';

        else if(isupper(cipher[i]))
            message += ( (cipher[i] - 'A') - key + 26)%26 + 'A';

        else
            message += ( (cipher[i]- 'a') - key + 26)%26 + 'a';
    }

    return message;
}

int main()
{
    string message;
    int key;

    cout << "Enter the message : ";
    getline(cin, message);

    cout << "Enter the key : ";
    cin >> key;

    string cipher = encrypt(message, key);
    cout << "\nEncrypted Message : " << cipher << endl;

    string plaintext = decrypt(cipher,key);
    cout << "Decrypted Message : " << plaintext << endl;

}