#ifndef FUNZIONI_H
#define FUNZIONI_H
#include <string>  
using namespace std;  

struct IpHeader{
	string Version;
	string Hlen;
	int TOS;
	string TOTlenght;
	int ID;
	string Flags;
	int Fragmentoffset;
	string TTL;
	string Protocol;
	int Headerchecksum;
	long SIA;
	long DIA;
	string Options;
	int Padding;
};

void Datagram();
string leggiMessaggio();
void scritturaMessaggio(string messaggioBin);
string charToBin(char value);
string stringToBin(string input);
string messaggioToBin(string input);
string calcolaCRC(const string &payload);

#endif
