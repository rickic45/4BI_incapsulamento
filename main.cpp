#include <iostream>
#include <fstream>
#include <string>
#include "funzioni.h"
using namespace std;

int main(){
    string messaggio = leggiMessaggio();
    string messaggioBin = messaggioToBin(messaggio);
    string carattere = charToBin('A');
    string stringa = stringToBin("ciao");
    scritturaMessaggio(carattere, stringa, messaggioBin);
    return 0;
}
