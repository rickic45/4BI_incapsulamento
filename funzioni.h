#ifndef FUNZIONI_H
#define FUNZIONI_H
#include <string>  
using namespace std;  

struct IpHeader{
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
	string Options;
	string Padding;
	string Data;
};

struct EthernetFrame{
	string Preamble;
	string Sfd;
	string Da;
	string Sa;
	string Type;
	IpHeader ipHeader;
};

IpHeader Datagram();
string leggiMessaggio();
void scritturaMessaggio(string messaggioBin, string ToTframe);
string charToBin(char value);
string stringToBin(string input);
string messaggioToBin(string input);
string concatIpHeader(const IpHeader& header);

#endif

