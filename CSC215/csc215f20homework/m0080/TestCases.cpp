#include "sortedSingle.h"
#include "..\catch.hpp"
#include <sstream>
#include <iostream>

using namespace std;
 
TEST_CASE("Constructor")
{
    sortedSingle list1;

    REQUIRE(list1.size() == 0);
    REQUIRE(list1.empty() == true);
    
}

TEST_CASE("Destructor")
{
    sortedSingle list1;

    list1.insert(50);
    list1.insert(20);
    list1.insert(30);

    list1.~sortedSingle();

    REQUIRE(list1.empty() == true);


}


TEST_CASE("Find")
{
    sortedSingle list1;

    list1.insert(40);
    list1.insert(50);
    list1.insert(60);
    list1.insert(75);
    list1.insert(80);

    REQUIRE(list1.empty() == false);
    CHECK(list1.find(40) == true);
    CHECK(list1.find(80) == true);
    CHECK(list1.find(60) == true);
    CHECK(list1.find(5) == false);
    CHECK(list1.find(45) == false);
    CHECK(list1.find(74) == false);
    

}

TEST_CASE("SIZE")
{
    sortedSingle list1;
    sortedSingle list2;
    sortedSingle list3;

    list1.insert(10);

    list2.insert(20);
    list2.insert(30);
    list2.insert(40);

    list3.insert(50);
    list3.insert(60);
    list3.insert(70);
    list3.insert(80);

    REQUIRE(list1.empty() == false);
    REQUIRE(list2.empty() == false);
    REQUIRE(list3.empty() == false);
    CHECK(list1.size() == 1);
    CHECK(list2.size() == 3);
    CHECK(list3.size() == 4);
}

TEST_CASE("Retrieve Position")
{
    sortedSingle list1;

    list1.insert(10);
    list1.insert(20);
    list1.insert(30);
    list1.insert(40);
    list1.insert(50);
    list1.insert(60);
    list1.insert(70);
    list1.insert(80);

    REQUIRE(list1.empty() == false);
    CHECK(list1.retrievePosition(10) == 1);
    CHECK(list1.retrievePosition(30) == 3);
    CHECK(list1.retrievePosition(80) == 8);
    CHECK(list1.retrievePosition(100) == 0);
    CHECK(list1.retrievePosition(11) == 0);
    CHECK(list1.retrievePosition(41) == 0);
}

TEST_CASE("Insert")

{
    sortedSingle list1, list2;
    ostringstream sout;

    REQUIRE(list1.insert(10) == true);
    CHECK(list1.insert(15) == true);
    CHECK(list1.size() == 2);
    list1.print(sout);
    CHECK(sout.str() == "10, 15");
    sout.str("");

    REQUIRE(list1.insert(10) == true);
    list1.print(sout);
    REQUIRE(sout.str() == "10, 10, 15");
    sout.str("");

    REQUIRE(list2.insert(5) == true);
    REQUIRE(list2.insert(10) == true);
    REQUIRE(list2.insert(15) == true);
    REQUIRE(list2.insert(20) == true);
    REQUIRE(list2.insert(25) == true);
    list2.print(sout);
    REQUIRE(sout.str() == "5, 10, 15, 20, 25");
    sout.str("");

    REQUIRE(list2.insert(1) == true);
    list2.print(sout);
    REQUIRE(sout.str() == "1, 5, 10, 15, 20, 25");
    sout.str("");

    REQUIRE(list2.insert(15) == true);
    REQUIRE(list2.insert(17) == true);
    list2.print(sout);
    REQUIRE(sout.str() == "1, 5, 10, 15, 15, 17, 20, 25");
    sout.str("");



    REQUIRE(list1.empty() == false);
    REQUIRE(list2.empty() == false);

    CHECK(list1.size() == 3);
    CHECK(list2.size() == 8);

}

TEST_CASE("Print")
{
    sortedSingle list1;
    sortedSingle list2;
    ostringstream sout1, sout2;

    list1.insert(10);
    list1.insert(15);

    list2.insert(5);
    list2.insert(10);
    list2.insert(15);
    list2.insert(20);
    list2.insert(25);

    REQUIRE(list1.empty() == false);
    REQUIRE(list2.empty() == false);

    list1.print(sout1);
    
    REQUIRE(sout1.str() == "10, 15");

    list2.print(sout2);
    
    REQUIRE(sout2.str() == "5, 10, 15, 20, 25");

}

TEST_CASE("Remove")
{
    sortedSingle list1, list2;
    ostringstream sout;

    REQUIRE(list1.size() == 0);
    REQUIRE(list1.remove(0) == false);

    REQUIRE(list1.insert(10) == true);
    CHECK(list1.insert(15) == true);
    CHECK(list1.size() == 2);
    list1.print(sout);
    CHECK(sout.str() == "10, 15");
    sout.str("");

    REQUIRE(list1.insert(10) == true);
    list1.print(sout);
    REQUIRE(sout.str() == "10, 10, 15");
    sout.str("");
    CHECK(list1.size() == 3);

    REQUIRE(list1.remove(10) == true);
    list1.print(sout);
    REQUIRE(sout.str() == "10, 15");
    sout.str("");
    CHECK(list1.size() == 2);

    REQUIRE(list2.insert(5) == true);
    REQUIRE(list2.insert(10) == true);
    REQUIRE(list2.insert(15) == true);
    REQUIRE(list2.insert(20) == true);
    REQUIRE(list2.insert(25) == true);
    list2.print(sout);
    REQUIRE(sout.str() == "5, 10, 15, 20, 25");
    sout.str("");

    REQUIRE(list2.insert(1) == true);
    list2.print(sout);
    REQUIRE(sout.str() == "1, 5, 10, 15, 20, 25");
    sout.str("");

    REQUIRE(list2.insert(15) == true);
    REQUIRE(list2.insert(17) == true);
    list2.print(sout);
    REQUIRE(sout.str() == "1, 5, 10, 15, 15, 17, 20, 25");
    sout.str("");

    CHECK(list2.size() == 8);

    REQUIRE(list2.remove(10) == true);

    list2.print(sout);
    REQUIRE(sout.str() == "1, 5, 15, 15, 17, 20, 25");
    sout.str("");

    CHECK(list2.size() == 7);

    REQUIRE(list2.remove(25) == true);
    list2.print(sout);
    REQUIRE(sout.str() == "1, 5, 15, 15, 17, 20");
    sout.str("");

    CHECK(list2.size() == 6);

    REQUIRE(list2.remove(100) == false);

    REQUIRE(list1.empty() == false);
    REQUIRE(list2.empty() == false);

    
}

TEST_CASE("Clear")
{
    sortedSingle list1, list2;

    REQUIRE(list1.empty() == true);
    list1.clear();
    REQUIRE(list1.empty() == true);

    REQUIRE(list2.insert(5) == true);
    REQUIRE(list2.insert(10) == true);
    REQUIRE(list2.insert(15) == true);
    REQUIRE(list2.insert(20) == true);
    REQUIRE(list2.insert(25) == true);

    REQUIRE(list2.empty() == false);
    list2.clear();
    REQUIRE(list2.empty() == true);
}