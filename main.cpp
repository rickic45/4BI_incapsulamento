#include <iostream>
#include <fstream>
#include <string>
#include "funzioni.h"
using namespace std;

int main(){
    string messaggio = leggiMessaggio();
    string messaggioBin = messaggioToBin(messaggio);
    IpHeader campi = Datagram(); 
    string ToTframe = concatIpHeader(campi);
    scritturaMessaggio(messaggioBin, ToTframe);
    return 0;
}

 
