#ifndef FUNZIONI_H
#define FUNZIONI_H
#include <string>  
using namespace std;  

struct IpHeader {
    string Version;
    string Hlen;
    string TOS;
    string TOTlenght;
    string ID;
    string Flags;
    string Fragmentoffset;
    string TTL;
    string Protocol;
    string Headerchecksum;
    string SIA;
    string DIA;
    string Data;
};

struct EthernetFrame {
    string Preamble;
    string Sfd;
    string Da;
    string Sa;
    string Type;
    IpHeader ipHeader;
};

IpHeader Datagram();
string leggiMessaggio();
void scritturaMessaggio(string Totframelvl2);
string charToBin(char value);
string stringToBin(string input);
string messaggioToBin(string input);
string concatIpHeader(const IpHeader& header);
string concatFrameHeader(const EthernetFrame& header);
EthernetFrame CreaFrame();
string ipChecksum(const string& bits);

#endif
