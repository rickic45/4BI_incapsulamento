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
    EthernetFrame campi1 = CreaFrame();
    string ToTframelvl2 = concatFrameHeader(campi1);
    scritturaMessaggio(ToTframelvl2);
    return 0;
}

 
