#ifndef __NETWORK__H__
#define __NETWORK__H__

//Write prototypes, typdefs, and enumerated type here



//created enum class called networkType
enum networkType { INVALID, CLASSA, APRIVATE, LOCALHOST, CLASSB, BPRIVATE, 
    CLASSC, CPRIVATE, CLASSD, CLASSE };

//created typedef called octet
typedef unsigned short int octet;

//created typedef called ip
typedef unsigned int ip;

//prototypes
ip compressOctets(octet oct1, octet oct2, octet oct3, octet oct4);
void extractOctets(ip address, octet& oct1, octet& oct2, octet& oct3,
    octet& oct4);
networkType getNetworkType(ip address);


#endif // !__NETWORK__H__

