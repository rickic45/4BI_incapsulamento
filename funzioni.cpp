#include "funzioni.h"
#include <iostream>
#include <fstream>
#include <string>
#include <bitset>

using namespace std;

// Funzione che inizializza i valori dell'header IP
IpHeader Datagram() {
    IpHeader campi;
    campi.Version = "0100";
    campi.Hlen = "0101";
    campi.TOS = "11001100";
    campi.TOTlenght = "0000000000111100";
    campi.ID = "0011000000111001";
    campi.Flags = "010";
    campi.Fragmentoffset = "0000000000000";
    campi.TTL = "01000000";
    campi.Protocol = "00000110";
    campi.Headerchecksum = "0000000000000000";
    campi.SIA = "11000000101010000000000100001010";
    campi.DIA = "00001000000010000000000000001000";
    campi.Data = messaggioToBin(leggiMessaggio());
    campi.Headerchecksum = ipChecksum(concatIpHeader(campi));
    return campi;
}

string concatIpHeader(const IpHeader& header) {
    return header.Version + header.Hlen + header.TOS + header.TOTlenght +
           header.ID + header.Flags + header.Fragmentoffset + header.TTL +
           header.Protocol + header.Headerchecksum + header.SIA +
           header.DIA + header.Data;
}

EthernetFrame CreaFrame() {
    EthernetFrame campi;
    campi.Preamble = "101010101010101010101010101010";
    campi.Sfd = "11010101";
    campi.Da = "101011111010111110101111101011111010111110101111";
    campi.Sa = "101011001010111110101101101011001010011010101110";
    campi.Type = "10000000000000000";
    campi.ipHeader = Datagram();
    return campi;
}

string concatFrameHeader(const EthernetFrame& header) {
    return header.Preamble + header.Sfd + header.Da + header.Sa + header.Type + 
           concatIpHeader(header.ipHeader);
}

// Funzione per leggere il messaggio da un file
string leggiMessaggio() {
    ifstream fin("CiaoMondoBacciBelliniCroccolo.txt");
    if (!fin) {
        cerr << "Errore: Impossibile leggere il file." << endl;
        exit(1);
    }
    string stampa;
    getline(fin, stampa);
    fin.close();
    return stampa;
}

// Funzione per scrivere il messaggio su file 
void scritturaMessaggio(string ToTframelvl2) {
    ofstream fout("frame.txt");
    if (!fout) {
        cerr << "Errore: Impossibile scrivere il file." << endl;
        exit(1);
    }
    fout << "Il frame in binario è: " << ToTframelvl2 << endl;
    fout.close();
}

// Converte un carattere in una stringa binaria
string charToBin(char value) {
    string str = "";
    for (int i = 0; i < 8; i++) {
        str += (value & 128) ? "1" : "0";
        value <<= 1;
    }
    return str;
}

// Converte una stringa in binario
string stringToBin(string input) {
    string result = "";
    for (char c : input) {
        result += charToBin(c);
    }
    return result;
}

// Converte il messaggio in binario
string messaggioToBin(string input) {
    string result = "";
    for (char c : input) {
        result += charToBin(c);
    }
    return result;
}


// Calcola il checksum IP
string ipChecksum(const string& bits) {
    if (bits.size() % 8 != 0) {
        cerr << "Errore: La stringa di input non è un multiplo di 16 bit." << endl;
        exit(1);
    }

    unsigned int sum = 0;
    for (size_t i = 0; i < bits.size(); i += 16) {
        unsigned short block = 0;
        for (int j = 0; j < 16 && (i + j) < bits.size(); j++) {
            if (bits[i + j] != '0' && bits[i + j] != '1') {
                cerr << "Errore: La stringa contiene caratteri non validi." << endl;
                exit(1);
            }
            block = (block << 1) | (bits[i + j] - '0');
        }
        sum += block;

        if (sum > 0xFFFF) {
            sum = (sum & 0xFFFF) + 1;
        }
    }

    sum = ~sum & 0xFFFF;
    return bitset<16>(sum).to_string();  // Converti in binario
}
