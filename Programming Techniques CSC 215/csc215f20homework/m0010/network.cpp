#include"network.h"


//compressOctets function takes in 4 octet and converts it into an IP address

ip compressOctets(octet oct1, octet oct2, octet oct3, octet oct4)
{
    ip address = 0;

    //takes in first octet 
    address = oct1;
    //moves address by 8 bits
    address = address << 8;
    //takes in second octet
    address = address | oct2;
    //moves address by 8 bits
    address = address << 8;
    //takes in thrid octet
    address = address | oct3;
    //moves address by 8 bits
    address = address << 8;
    //takes in the fourth octet
    address = address | oct4;

    //returns the address to the calling function
    return address;
}

//extractOctets extracts the four octets from a valid ip address
void extractOctets(ip address, octet& oct1, octet& oct2, octet& oct3,
    octet& oct4)
{
    //creates a masking id of 1111 1111 to obtain the value of the 4 octets
    ip mask = 255;

    //takes out the last 8 bits and converts it to dec
    oct4 = address & mask;
    //moves over 8 spaces and removed the next 8 bits and converts to dec
    oct3 = (address >> 8) & mask;
    //moves over 16 spaces and removed the next 8 bits and converts to dec
    oct2 = (address >> 16) & mask;
    //moves over 24 spaces and removed the next 8 bits and converts to dec
    oct1 = (address >> 24) & mask;
}


networkType getNetworkType(ip address)
{
    networkType type;
    octet oct1, oct2, oct3, oct4;

    extractOctets(address, oct1, oct2, oct3, oct4);

    if (oct1 >= 1 && oct1 <= 127)
    {
        if (oct1 == 10)
            type = APRIVATE;
        else if (oct1 == 127)
            type = LOCALHOST;
        else
            type = CLASSA;
    }

    else if (oct1 >= 128 && oct1 <= 191)
    {
        if (oct1 == 172 && (oct2 >= 16 && oct2 <= 31))
            type = BPRIVATE;
        else
            type = CLASSB;
    }

    else if (oct1 >= 192 && oct1 <= 223)
    {
        if (oct1 == 192 && oct2 == 168)
            type = CPRIVATE;
        else
            type = CLASSC;
    }

    else if (oct1 >= 224 && oct1 <= 239)
        type = CLASSD;

    else if (oct1 >= 240 && oct1 <= 255)
        type = CLASSE;

    else
        type = INVALID;

    return type;
}
