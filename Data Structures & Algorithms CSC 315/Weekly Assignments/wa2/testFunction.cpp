#include"/home/teapot/csc315/catch/catch.hpp"
#include"maxStack.h"
#include<sstream>
#include<iostream>

using namespace std;
using std::ostringstream;


TEST_CASE("Constructor")
{
    MaxStack list;

    REQUIRE(list.empty() == true);
    REQUIRE(list.size() == 0);
}

TEST_CASE("Empty")
{
    MaxStack list;

    REQUIRE(list.empty() == true);

    list.push(100);
    
    REQUIRE(list.empty() == false);

    list. push (-100);

    REQUIRE(list.empty() == false);
}

TEST_CASE("Size and push")
{
    MaxStack list;

    REQUIRE(list.size() == 0);

    list.push(100);
    list.push(250);

    REQUIRE(list.size() == 2);

    list. push(50);
    REQUIRE(list.size()==3);

    list. push(100);
    REQUIRE(list.size()==4);
}

TEST_CASE("Top")
{
    MaxStack list;

    REQUIRE(list.empty() == true);
    list.push (100);

    REQUIRE(list.size() == 1);
    REQUIRE (list.top() == 100);

    list.push(250);

    REQUIRE(list.size() == 2);
    REQUIRE(list.top() == 250);

    list. push(50);
    REQUIRE(list.size()==3);
    REQUIRE(list.top() == 50);

    list. push(100);
    REQUIRE(list.size()==4);
    REQUIRE(list.top() == 100);
}

TEST_CASE("Pop")
{
    MaxStack list;

    REQUIRE(list.size() == 0);

    list.push(100);
    list.push(250);

    REQUIRE(list.size() == 2);

    list. push(50);
    REQUIRE(list.size()==3);

    list. push(100);
    REQUIRE(list.size()==4);

    list.pop();
    REQUIRE(list.size()==3);
    REQUIRE(list.top() == 50);

    list.pop();
    REQUIRE(list.size()==2);
    REQUIRE(list.top() == 250);
}

TEST_CASE("Max")
{
    MaxStack list;

    REQUIRE(list.empty() == true);

    list.push(100);

    REQUIRE(list.max() == 100);

    list.push(50);

    REQUIRE(list.max() == 100);

    list.push(250);

    REQUIRE(list.max() == 250);

    list.push(25);

    REQUIRE(list.max() == 250);

    list.push(100);

    REQUIRE(list.max() == 250);

    list.push(1000);

    REQUIRE(list.max() == 1000);
}

TEST_CASE("Overload")
{
    MaxStack list;
    ostringstream sout;

    list.push(100);
    sout << list;

    REQUIRE(sout.str() == "MaxStack:\n100 [100]\n");
    sout.str("");

    list.push(50);
    sout << list;

    REQUIRE(sout.str() == "MaxStack:\n50 [100]\n100 [100]\n");

}