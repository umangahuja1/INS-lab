#include <iostream>
#include "sha1.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "sha1('The'):" << sha1("the") << endl;
    return 0;
}