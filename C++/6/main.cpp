using namespace std;

#include <iostream>
#include "Utils.h"

int main() {
    char st[100];

    puts("Enter string: ");
    gets(st);

    auto *utils = new Utils();
    utils->shortestWord(st);

    return 0;
}

