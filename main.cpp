#include <iostream>
#include <fstream>
#include <string>
#include "funzioni.h"
using namespace std;

int main(){
    string messaggio = leggiMessaggio();
    string messaggioBin = messaggioToBin(messaggio);
    scritturaMessaggio(messaggioBin);
    return 0;
}
