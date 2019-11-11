#include <iostream>
#include <cstring>

using namespace std;

string generate_key(string key, string message)
{
    int i=0;

    for(int i=0;i<key.size();i++)
    {
        key[i] = toupper(key[i]);
    }

    while(key.size() < message.size())
    {
        key.push_back(toupper(message[i++]));
    }

    return key;
}

string encrypt(string message, string key)
{
    string cipher;

    for(int i=0;i<message.size();i++)
    {
        if(message[i] == ' ')
            cipher += ' ';

        else if(isupper(message[i]))
            cipher += (message[i] - 'A' + key[i] - 'A' )%26 + 'A';

        else
            cipher += (message[i] - 'a' + key[i] - 'A' )%26 + 'a';
    }

    return cipher;
}

string decrypt(string cipher, string key)
{
    string message;

    for(int i=0;i<cipher.size();i++)
    {
        if(cipher[i] == ' ')
            message += ' ';

        else if(isupper(cipher[i]))
            message += (cipher[i] - 'A' - (key[i] - 'A') + 26 )%26 + 'A';

        else
            message += (cipher[i] - 'a' - (key[i] - 'A') + 26 )%26 + 'a';
    }

    return message;
}

int main()
{
    string message;
    string key;

    cout << "Enter the message : ";
    cin >> message;

    cout << "Enter the key : ";
    cin >> key;

    key = generate_key(key, message);

    string cipher = encrypt(message, key);
    cout << "\nEncrypted Message : " << cipher << endl;

    string plaintext = decrypt(cipher,key);
    cout << "Decrypted Message : " << plaintext << endl;

    return 0;
}