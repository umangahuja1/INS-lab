#include <iostream>
#include "sha1.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "sha1('The'):" << sha1("The") << endl;
    return 0;
}