#include <iostream>
#include <string>
using namespace std;

string msg; 
char n[5][5];

char getChar( int a, int b ) 
{ 
    return n[ (a + 5) % 5 ][ (b + 5) % 5 ];
}

bool getPos( char l, int &c, int &d ) 
{ 
    for( int x = 0; x < 5; x++ )
    for( int y = 0; y < 5; y++ )
    if( n[x][y] == l ) {
        c = x;
        d = y;
        return true;
    }
    return false;
}

void print()
{
    cout << "\n\nSolution:" << endl;
    string::iterator it = msg.begin();
    while( it != msg.end() ) {
        cout << *it;
        it++;
        cout << *it << " ";
        it++;
    }
}


void getText( string t, bool m, bool e ) { 
    for( string::iterator it = t.begin(); it != t.end(); it++ ) {
        *it = toupper( *it );
        if( *it < 65 || *it > 90 )
        continue;
        if( *it == 'J' && m )
        *it = 'I';
        else if( *it == 'Q' && !m )
        continue;
        msg += *it;
    }  
    if( e ) {
        string nmsg = ""; size_t len = msg.length();
        for( size_t x = 0; x < len; x += 2 ) {
        nmsg += msg[x];
        if( x + 1 < len ) {
            if( msg[x] == msg[x + 1] ) nmsg += 'X';
            nmsg += msg[x + 1];
        }
        }
        msg = nmsg;
    }
    if( msg.length() & 1 )
    msg += 'X';
}
void createEncoder( string key, bool m ) 
{  
    key += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string s= "";
    for(int i = 0 ; i < key.size(); i++) 
    {
        key[i] = toupper(key[i]);
        if( key[i] < 65 || key[i] > 90 )
        continue;
        if( ( key[i] == 'J' && m ) || ( key[i] == 'Q' && !m ) )
        continue;
        if( s.find( key[i] ) == -1 )
        s += key[i];
    }
    copy( s.begin(), s.end(), &n[0][0] );

    cout << "\nKey table \n";
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
            cout << n[i][j] << ' '; 
        cout << endl;
    }
}


void play( int dir ) {
    int j,k,p,q;
    string nmsg;
    for( string::const_iterator it = msg.begin(); it != msg.end(); it++ ) {
        if( getPos( *it++, j, k ) )
        if( getPos( *it, p, q)) {
        //for same row
        if( j == p ) {
            nmsg += getChar( j, k + dir );
            nmsg += getChar( p, q + dir );
        }
        //for same column
        else if( k == q ) {
            nmsg += getChar( j + dir, k );
            nmsg += getChar( p + dir, q );
        } 
        else {
            nmsg += getChar( j, q );
            nmsg += getChar( p, k );
        }
        }
    }
    msg = nmsg;
}

void play( string k, string t, bool m, bool e ) 
{
    createEncoder( k, m );
    getText( t, m, e );
    if( e )
        play( 1 );
    else
        play( -1 );
    print();
}
    

int main( ) 
{
    string k, i, msg;
    bool m, c;

    cout << "Encrpty or Decypt? ";
    getline( cin, i );

    c = ( i[0] == 'e' || i[0] == 'E' );

    cout << "Enter a key: ";
    getline( cin, k);

    cout << "I <-> J (Y/N): ";
    getline( cin, i );

    m = ( i[0] == 'y' || i[0] == 'Y' );

    cout << "Enter the message: ";
    getline( cin, msg );

    play( k, msg,m, c );
    return 0;
}