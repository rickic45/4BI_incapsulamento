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
};

void Datagram();
string leggiMessaggio();
void scritturaMessaggio(string messaggioBin);
string charToBin(char value);
string stringToBin(string input);
string messaggioToBin(string input);
string calcolaCRC(const string &payload);

#endif
