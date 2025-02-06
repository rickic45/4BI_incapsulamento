#include "funzioni.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Funzione che inizializza i valori dell'header IP
void Datagram(){
	IpHeader campi;
	campi.Version = 4;
	campi.Hlen = 7;
	campi.TOS = 0;
	campi.TOTlenght = 60;
	campi.ID = 7238;
	campi.Flags = 010;
	campi.Fragmentoffset = 0;
	campi.TTL = 64;
	campi.Protocol = 6;
	campi.Headerchecksum = 45542;
	campi.SIA = 0xC0A80101; //basati a 32 bit (sorgente)
	campi.DIA = 0x5DB8D822; //basati a 32 bit (destinatario)
	campi.Options = 148;
	campi.Padding = 0;
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
void scritturaMessaggio(string carattere, string stringa, string messaggioBin){
    ofstream fout("frame.txt");
    if (!fout){
        cout << "Errore!!!! non ho scritto nulla, riga 22 :((" << endl;
        exit(1); 
    }
    fout << carattere << endl;
    fout << stringa << endl;
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
