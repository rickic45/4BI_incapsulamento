def leggiDaFile():
    with open("frame.txt","r") as f:
        print("Messaggio letto correttamente")
        return f.readline()

frame = leggiDaFile()

def decapsulaEthernet(frame):
    preamble = frame[:56]
    SFD = frame[56:64]
    destinationAddress = frame[64:112]
    sourceAddress = frame[112:160]
    tipo = frame[160:176]
    ipHeader = frame[176:len(frame)-32]
    FCS = frame[len(frame)-32:]
    return ipHeader

headerIP = decapsulaEthernet(frame)

def decapsulaIP(headerIP):
    version = headerIP[:4]
    HLEN = headerIP[4:8]
    TOS = headerIP[8:16]
    totalLength = headerIP[16:32]
    identification = headerIP[32:48]
    flag = headerIP[48:51]
    fragmentOffset = headerIP[51:64]
    TTL = headerIP[64:72]
    protocol = headerIP[72:80]
    headerChecksum = headerIP[80:96]
    sourceAddress = headerIP[96:128]
    destinationAddress = headerIP[128:160]
    data = headerIP[160:]
    return data

messaggio = decapsulaIP(headerIP)
messaggio =''.join(chr(int(messaggio[i:i+8], 2)) for i in range(0, len(messaggio), 8))
print("Messaggio finale:", messaggio)


