#define CATCH_CONFIG_MAIN
#include "..\catch.hpp"
#include"..\prog2\wordFreq.h"
#include<iostream>


TEST_CASE("clear")
{
    wordFreq list1;
    wordFreq list2;

    list1.insert("twelve");
    list1.insert("twentyfour");
    list1.insert("thirtyseven");
    list1.insert("fortyfive");
    list1.insert("fiftythree");
    //twelve, twentyfour, thirtyseven, fortyfive, fiftythree
    // 12,24,37,45,53

    REQUIRE(list1.empty() == false);
    list1.clear();
    REQUIRE(list1.empty() == true);

}

TEST_CASE("find")
{
    wordFreq list1;

    list1.insert("ten");
    list1.insert("fifteen");
    list1.insert("twentyfive");
    list1.insert("fortyfive");


    CHECK(list1.find("ten") == true);
    CHECK(list1.find("fifteen") == true);

    CHECK(list1.find("three") == false);
    CHECK(list1.find("eleven") == false);
}

TEST_CASE("insert")
{
    wordFreq list1;
    wordFreq list2;
    ostringstream sout;

    SECTION("empty")
    {
        REQUIRE(list1.insert("ten") == true);
        REQUIRE(list1.empty() == false);
        sout.str("");
        list1.printFreq(sout);
        REQUIRE(sout.str() == "ten");

        REQUIRE(list2.insert("twenty") == true);
        REQUIRE(list2.empty() == false);
        sout.str("");
        list2.printFreq(sout);
        REQUIRE(sout.str() == "twenty");

    }

    list1.insert("fifty");
    list1.insert("twenty");
    list1.insert("forty");
    SECTION("front")
    {
        REQUIRE(list1.insert("ten") == true);
        list1.print(sout);
        REQUIRE(sout.str() == "ten, twenty, forty, fifty");

    }
    SECTION("middle")
    {
        REQUIRE(list1.insert(30) == true);
        list1.print(sout);
        REQUIRE(sout.str() == "20, 30, 40, 50");
    }
    SECTION("end")
    {
        REQUIRE(list1.insert(80) == true);
        list1.print(sout);
        REQUIRE(sout.str() == "20, 40, 50, 80");
    }

}