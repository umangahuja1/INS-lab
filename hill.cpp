#include<iostream>
#include<cmath>
using namespace std;

float message[3][1], encrypt[3][1], decrypt[3][1], a[3][3], inv[3][3], c[3][3];

void getKeyMessage() {
	int i, j;
	char msg[3];
    char key_char;
	cout<<"Enter 3x3 invertible matrix for key (uppercase) : ";
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++) {

			cin>>key_char;
            a[i][j] = key_char-65;
			c[i][j] = a[i][j];
		}
	cout<<"\nEnter a 3 lowercase letter string : ";
	cin>>msg;
	for(i = 0; i < 3; i++)
		message[i][0] = msg[i] - 97;
} 
 
void inverse() {
	int i, j, k;
	float p, q;
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++) {
			if(i == j)
				inv[i][j]=1;
			else
				inv[i][j]=0;
		}
	for(k = 0; k < 3; k++) {
		for(i = 0; i < 3; i++) {
			p = c[i][k];
			q = c[k][k];		
			for(j = 0; j < 3; j++) {
				if(i != k) {
					c[i][j] = c[i][j]*q - p*c[k][j];
					inv[i][j] = inv[i][j]*q - p*inv[k][j];
				}
			}
		}
	}
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			inv[i][j] = inv[i][j] / c[i][i];
	
    cout<<"\n\nInverse Matrix is:\n";
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++)
			cout<<inv[i][j]<<" ";
		cout<<"\n";
	}
}

void encryption() {
	int i, j, k;
	for(i = 0; i < 3; i++)
		for(j = 0; j < 1; j++)
			for(k = 0; k < 3; k++)
				encrypt[i][j] = encrypt[i][j] + a[i][k] * message[k][j];
	cout<<"\nEncrypted string is: ";
	for(i = 0; i < 3; i++)
		cout<<(char)(fmod(encrypt[i][0], 26) + 97);
}
 
void decryption() {
	int i, j, k;
	inverse();
	for(i = 0; i < 3; i++)
		for(j = 0; j < 1; j++)
			for(k = 0; k < 3; k++)
				decrypt[i][j] = decrypt[i][j] + inv[i][k] * encrypt[k][j];
	cout<<"\nDecrypted string is: ";
	for(i = 0; i < 3; i++)
		cout<<(char)(fmod(decrypt[i][0], 26) + 97);
	cout<<"\n";
}
 
int main() {
	getKeyMessage();
	encryption();
	decryption();
}