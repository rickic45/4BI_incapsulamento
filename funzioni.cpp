#include "funzioni.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Funzione che inizializza i valori dell'header IP
IpHeader Datagram(){
	IpHeader campi;
	campi.Version = "0100";
	campi.Hlen = "0101";
	campi.TOS = "011001100";
	campi.TOTlenght = "00000000000111100";
	campi.ID = "0011000000111001";
	campi.Flags = "010";
	campi.Fragmentoffset = "0000000000000";
	campi.TTL ="01000000";
	campi.Protocol ="00000110";
	campi.Headerchecksum = "0000000000000000";
	campi.SIA = "11000000101010000000000100001010";
	campi.DIA = "00001000000010000000000000001000";
	campi.Data =  messaggioToBin(leggiMessaggio());
	return campi;
}


string  concatIpHeader(const IpHeader& header){
       return header.Version + header.Hlen + header.TOS + header.TOTlenght +
           header.ID + header.Flags + header.Fragmentoffset + header.TTL +
           header.Protocol + header.Headerchecksum + header.SIA +
           header.DIA + header.Data;
}

void CreaFrame(){
	EthernetFrame campi;
	campi.Preamble = "1010101010101010101010101010101010101010101010101010101010101010";
	campi.Sfd = "11010101";
	campi.Da = "101011111010111110101111101011111010111110101111";
	campi.Sa = "101011001010111110101101101011001010011010101110";
	campi.Type = "10000000000000000";
}

// Funzione per leggere il messaggio da un file
string leggiMessaggio(){
	string risposta;
    ifstream fin("CiaoMondoBacciBelliniCroccolo.txt");
    if (!fin){
        cout << "Errore!!!! non ho letto nulla, riga 10 :((" << endl;
        exit(1); 
    }
    string stampa;
    getline(fin, stampa); 
    risposta = stampa;
    fin.close();
    return risposta;
}

// Funzione per scrivere il messagio su file 
void scritturaMessaggio(string messaggioBin, string ToTframe){
    ofstream fout("frame.txt");
    if (!fout){
        cout << "Errore!!!! non ho scritto nulla, riga 22 :((" << endl;
        exit(1); 
    }
    fout << "il messaggio in binario e': " << messaggioBin << endl;
    fout << "il frame in binario e': " << ToTframe << endl;
    fout.close();
}

// Converte un carattere in una stringa binaria
string charToBin(char value){
    string str = "";
    for (int i = 0; i < 8; i++){
        if (value & 128) {
            str += "1";
        } else {
            str += "0";
        }
        value = value << 1;
    }
    return str;
}

// Converte una stringa in binario
string stringToBin(string input){
    int length = input.length();
    char array[length];  
    string result = ""; 

    for (int i = 0; i < length; i++){
        array[i] = input[i];
    }

    for (int i = 0; i < length; i++){
       result += charToBin(array[i]);  
    }

    return result;
}

// Converte il messaggio da file in binario
string messaggioToBin(string input){
    int length = input.length();
    char array[length];  
    string result = ""; 

    for (int i = 0; i < length; i++){
        array[i] = input[i];
    }

    for (int i = 0; i < length; i++){
       result += charToBin(array[i]);  
    }

    return result;
}



