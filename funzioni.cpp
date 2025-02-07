#include "funzioni.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Funzione che inizializza i valori dell'header IP
void Datagram(){
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
void scritturaMessaggio(string messaggioBin){
    ofstream fout("frame.txt");
    if (!fout){
        cout << "Errore!!!! non ho scritto nulla, riga 22 :((" << endl;
        exit(1); 
    }
    fout << messaggioBin << endl;
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

string calcolaCRC(const string &payload){
    unsigned short crc = 0xFFFF;
    const unsigned short POLY = 0x1021;
    for (unsigned char c : payload){
        crc ^= (c << 8);
        for (int i = 0; i < 8; i++){
            if (crc & 0x8000) crc = (crc << 1) ^ POLY;
            else crc <<= 1;
        }
    }
    return crc;
}
