#include"..\\catch.hpp"
#include"network.h"

//Test case proved by Roger Schrader
TEST_CASE("CompressOctets - testing a class b ip address")
{
    octet oct1 = 151,
          oct2 = 159,
          oct3 = 15,
          oct4 = 20;

    ip resultIP = compressOctets(oct1, oct2, oct3, oct4);

    REQUIRE(2543783700 == resultIP);
}

//Test a class A ip address Compression
TEST_CASE("CompressOctets - test a class A ip address")
{
    octet oct1 = 127, oct2 = 186, oct3 = 255, oct4 = 15;

    ip resultIP = compressOctets(oct1, oct2, oct3, oct4);

    REQUIRE(2142961423 == resultIP);
}

//Test a class B ip address Compression
TEST_CASE("CompressOctets - test a class B ip address")
{
    octet oct1 = 187, oct2 = 142, oct3 = 31, oct4 = 25;

    ip resultIP = compressOctets(oct1, oct2, oct3, oct4);

    REQUIRE(3146653465 == resultIP);
}

//Test a class C ip address Compression
TEST_CASE("CompressOctets - test a class C ip address")
{
    octet oct1 = 221, oct2 = 142, oct3 = 28, oct4 = 10;

    ip resultIP = compressOctets(oct1, oct2, oct3, oct4);

    REQUIRE(3717078026 == resultIP);
}

//Test a class D ip address Compression
TEST_CASE("CompressOctets - test a class D ip address")
{
    octet oct1 = 225, oct2 = 230, oct3 = 225, oct4 = 15;

    ip resultIP = compressOctets(oct1, oct2, oct3, oct4);

    REQUIRE(3790004495 == resultIP);
}

//Test a class E ip address Compression
TEST_CASE("CompressOctets - test a class E ip address")
{
    octet oct1 = 250, oct2 = 240, oct3 = 230, oct4 = 10;
   
    ip resultIP = compressOctets(oct1, oct2, oct3, oct4);

    REQUIRE(4210091530 == resultIP);
}

//Test case proved by the Roger Schrader 
TEST_CASE("extractOctets - testing a class b ip to octect version 1")
{
    ip theIP = 2543783700; 
    
    octet oct1, oct2, oct3, oct4;

    extractOctets(theIP, oct1, oct2, oct3, oct4);
    CHECK(151 == oct1);
    CHECK(159 == oct2);
    CHECK(15 == oct3);
    CHECK(20 == oct4);
}

//Test case proved by Roger Schrader
TEST_CASE("extractOctets - testing a class b ip to octect version 2")
{
    ip theIP = compressOctets(151, 159, 15, 20);

    octet oct1, oct2, oct3, oct4;

    extractOctets(theIP, oct1, oct2, oct3, oct4);
    CHECK(151 == oct1);
    CHECK(159 == oct2);
    CHECK(15 == oct3);
    CHECK(20 == oct4);
}

//Test Case 1  class A
TEST_CASE("extractOctets - testing a class A ip to octect version 1")
{
    ip theIP = 2142961423;

    octet oct1, oct2, oct3, oct4;

    extractOctets(theIP, oct1, oct2, oct3, oct4);
    CHECK(127 == oct1);
    CHECK(186 == oct2);
    CHECK(255 == oct3);
    CHECK(15 == oct4);
}

//Test Case 2 class b
TEST_CASE("extractOctets - testing a class B ip to octect version 1")
{
    ip theIP = 3146653465;

    octet oct1, oct2, oct3, oct4;

    extractOctets(theIP, oct1, oct2, oct3, oct4);
    CHECK(187 == oct1);
    CHECK(142 == oct2);
    CHECK(31 == oct3);
    CHECK(25 == oct4);

}

//Test Case 3 class C
TEST_CASE("extractOctets - testing a class C ip to octect version 1")
{
    ip theIP = 3717078026;

    octet oct1, oct2, oct3, oct4;

    extractOctets(theIP, oct1, oct2, oct3, oct4);
    CHECK(221 == oct1);
    CHECK(142 == oct2);
    CHECK(28 == oct3);
    CHECK(10 == oct4);

}

//Test Case 4 class D
TEST_CASE("extractOctets - testing a class D ip to octect version 1")
{
    ip theIP = 3790004495;

    octet oct1, oct2, oct3, oct4;

    extractOctets(theIP, oct1, oct2, oct3, oct4);
    CHECK(225 == oct1);
    CHECK(230 == oct2);
    CHECK(225 == oct3);
    CHECK(15 == oct4);
}

//Test Case 5 class E
TEST_CASE("extractOctets - testing a class E ip to octect version 1")
{
    ip theIP = 4210091530;

    octet oct1, oct2, oct3, oct4;

    extractOctets(theIP, oct1, oct2, oct3, oct4);
    CHECK(250 == oct1);
    CHECK(240 == oct2);
    CHECK(230 == oct3);
    CHECK(10 == oct4);

}

//Test Case provided by Roger Schrader
TEST_CASE("getNetworkType - classifying a Class B networks including private")
{
    ip theIP = compressOctets(151, 159, 15, 20);
    networkType classified = getNetworkType(theIP);
    REQUIRE(CLASSB == classified);

    theIP = compressOctets(172, 18, 4, 20);
    classified = getNetworkType(theIP);
    REQUIRE(BPRIVATE == classified);
}

//Test Case for INVALID
TEST_CASE("getNetworkType - classifying a INVALID network address")
{
    ip theIP = compressOctets(0, 0, 255, 34);
    networkType classified = getNetworkType(theIP);
    REQUIRE(INVALID == classified);

    theIP = compressOctets(0, 240, 215, 212);
    classified = getNetworkType(theIP);
    REQUIRE(INVALID == classified);
}

//Test Case for CLASSA
TEST_CASE("getNetworkType - classifying a CLASSA network address")
{
    ip theIP = compressOctets(1, 0, 255, 34);
    networkType classified = getNetworkType(theIP);
    REQUIRE(CLASSA == classified);

    theIP = compressOctets(123, 240, 215, 212);
    classified = getNetworkType(theIP);
    REQUIRE(CLASSA == classified);
}

//Test Case for APRIVATE
TEST_CASE("getNetworkType - classifying an APRIVATE network address")
{
    ip theIP = compressOctets(10, 0, 255, 34);
    networkType classified = getNetworkType(theIP);
    REQUIRE(APRIVATE == classified);

    theIP = compressOctets(10, 240, 215, 212);
    classified = getNetworkType(theIP);
    REQUIRE(APRIVATE == classified);
}

//Test Case for LOCALHOST
TEST_CASE("getNetworkType - classifying an LOCALHOST network address")
{
    ip theIP = compressOctets(127, 0, 255, 34);
    networkType classified = getNetworkType(theIP);
    REQUIRE(LOCALHOST == classified);

    theIP = compressOctets(127, 240, 215, 212);
    classified = getNetworkType(theIP);
    REQUIRE(LOCALHOST == classified);
}

//Test Case for CLASSB
TEST_CASE("getNetworkType - classifying a CLASSB network address")
{
    ip theIP = compressOctets(147, 0, 255, 34);
    networkType classified = getNetworkType(theIP);
    REQUIRE(CLASSB == classified);

    theIP = compressOctets(172, 240, 215, 212);
    classified = getNetworkType(theIP);
    REQUIRE(CLASSB == classified);
}

//Test Case for BPRIVATE
TEST_CASE("getNetworkType - classifying an BPRIVATE network address")
{
    ip theIP = compressOctets(172, 18, 255, 34);
    networkType classified = getNetworkType(theIP);
    REQUIRE(BPRIVATE == classified);

    theIP = compressOctets(172, 30, 215, 212);
    classified = getNetworkType(theIP);
    REQUIRE(BPRIVATE == classified);
}

//Test Case for CLASSC
TEST_CASE("getNetworkType - classifying an CLASSC network address")
{
    ip theIP = compressOctets(192, 167, 255, 34);
    networkType classified = getNetworkType(theIP);
    REQUIRE(CLASSC == classified);

    theIP = compressOctets(220, 240, 215, 212);
    classified = getNetworkType(theIP);
    REQUIRE(CLASSC == classified);
}

//Test Case for CPRIVATE
TEST_CASE("getNetworkType - classifying an CPRIVATE network address")
{
    ip theIP = compressOctets(192, 168, 255, 34);
    networkType classified = getNetworkType(theIP);
    REQUIRE(CPRIVATE == classified);

    theIP = compressOctets(192, 168, 215, 212);
    classified = getNetworkType(theIP);
    REQUIRE(CPRIVATE == classified);
}

//Test Case for CLASSD
TEST_CASE("getNetworkType - classifying an CLASSD network address")
{
    ip theIP = compressOctets(225, 168, 255, 34);
    networkType classified = getNetworkType(theIP);
    REQUIRE(CLASSD == classified);

    theIP = compressOctets(238, 168, 215, 212);
    classified = getNetworkType(theIP);
    REQUIRE(CLASSD == classified);
}

//Test Case for CLASSE
TEST_CASE("getNetworkType - classifying an CLASSE network address")
{
    ip theIP = compressOctets(241, 168, 255, 34);
    networkType classified = getNetworkType(theIP);
    REQUIRE(CLASSE == classified);

    theIP = compressOctets(253, 168, 215, 212);
    classified = getNetworkType(theIP);
    REQUIRE(CLASSE == classified);
}