ip = "10.3.9.12"
sIP = ip.split(".")
binstr = ""
s = ""
for i in range(0,4):
    if len(bin(int(sIP[i]))[2:]) < 8:
        if len(bin(int(sIP[i]))[2:]) == 3:
            s = "00000" + bin(int(sIP[i]))[2:]
        elif len(bin(int(sIP[i]))[2:]) == 2:
            s = "000000" + bin(int(sIP[i]))[2:]
        else:
            s = "0000000" + bin(int(sIP[i]))[2:]
        sIP[i] = s
    else:
        sIP[i] = bin(int(sIP[i]))[2:]
for i in range(4):
    binstr += sIP[i]
print(binstr)
