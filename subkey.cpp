#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std; 

string permute(string k, int* arr, int n){ 
	string per=""; 
	for(int i=0; i<n ; i++){ 
		per+= k[arr[i]-1]; 
	} 
	return per; 
} 

string shift_left(string k, int shifts){ 
	string s=""; 
	for(int i=0; i<shifts; i++){ 
		for(int j=1; j<28; j++){ 
			s+= k[j]; 
		} 
		s+= k[0]; 
		k= s; 
		s=""; 
	} 
	return k; 
} 

void print_key(string key, int width)
{
    for(int i=1;i<=key.size();i++)
    {
        cout << key[i-1];
        if(i%width==0) cout << ' ';
    }

    cout << endl;
}


int main(){ 
	string key; 
	cout<<"Enter key(in binary): "; 
	cin>>key;
	
    cout << "\nOriginal Key      : ";
	print_key(key, 8);

	int keyp[56]= 
	{ 57,49,41,33,25,17,9, 
		1,58,50,42,34,26,18, 
		10,2,59,51,43,35,27, 
		19,11,3,60,52,44,36,		 
		63,55,47,39,31,23,15, 
		7,62,54,46,38,30,22, 
		14,6,61,53,45,37,29, 
		21,13,5,28,20,12,4 
	}; 
	
	key= permute(key, keyp, 56); 
    cout << "Permuted Choice 1 : ";
	print_key(key, 7);

	int shift_table[16]= 
	{ 1, 1, 2, 2, 
		2, 2, 2, 2, 
		1, 2, 2, 2, 
		2, 2, 2, 1 
	}; 
	
	int key_comp[48]= 
	{ 14,17,11,24,1,5, 
		3,28,15,6,21,10, 
		23,19,12,4,26,8, 
		16,7,27,20,13,2, 
		41,52,31,37,47,55, 
		30,40,51,45,33,48, 
		44,49,39,56,34,53, 
		46,42,50,36,29,32 
	}; 
	
	string left= key.substr(0, 28); 
	string right= key.substr(28, 28); 
	
	for(int i=0; i<16; i++){ 

		left= shift_left(left, shift_table[i]); 
		right= shift_left(right, shift_table[i]); 
		
		string combine= left + right; 
		
		string RoundKey= permute(combine, key_comp, 48); 
        cout << "Round " << setw(2) << i+1 << " Key      : ";
        print_key(RoundKey, 6);
	} 

    return 0;
} 
