#include "trim.h"
#include "..\\catch.hpp"


TEST_CASE("cTrim - Testing C strings with no ws on either end")
{
    // These variable will be initialized and any REQUIRE/CHECK 
    // executed before each section below.
    char theString[100] = "Catch with Sections!";
    char theAnswer[100] = "Catch with Sections!";
    CHECK(strcmp(theString, theAnswer) == 0);

    // variables reinitialize and checked
    SECTION("Front -  Just a phrase")
    {
        cTrim(theString, FRONT);
        CHECK(strcmp(theAnswer, theString) == 0);
    }
    // variables reinitialize and checked
    SECTION("End -  Just a phrase")
    {
        cTrim(theString, END);
        CHECK(strcmp(theAnswer, theString) == 0);
    }
    // variables reinitialize and checked
    SECTION("BOTH - Just a phrase")
    {
        cTrim(theString, BOTH);
        CHECK(strcmp(theAnswer, theString) == 0);
    }
}


TEST_CASE("sTrim - Testing strings with no ws on either end")
{
    // These variable will be initialized and any REQUIRE/CHECK 
    // executed before each section below.
    string theString = "Catch with Sections!";
    string theAnswer = "Catch with Sections!";
    CHECK(theString == theAnswer);

    // variables reinitialize and checked
    SECTION("Front -  Just a phrase")
    {
        sTrim(theString, FRONT);
        CHECK(theAnswer == theString);
    }
    // variables reinitialize and checked
    SECTION("End - Just a phrase")
    {
        sTrim(theString, END);
        CHECK(theAnswer == theString);
    }
    // variables reinitialize and checked
    SECTION("BOTH - Just a phrase")
    {
        sTrim(theString, BOTH);
        CHECK(theAnswer == theString);
    }
}

TEST_CASE("cTrim - Testing C strings with ws to the front")
{
    // These variable will be initialized and any REQUIRE/CHECK 
    // executed before each section below.
    char theString[100] = "    Help I can do this no more!";
    char theAnswer[100] = "Help I can do this no more!";
    CHECK(strcmp(theString, theAnswer) <= 0);

    // variables reinitialize and checked
    SECTION("Front -  Just a phrase")
    {
        cTrim(theString, FRONT);
        CHECK(strcmp(theAnswer, theString) == 0);
    }
    // variables reinitialize and checked
    SECTION("End -  Just a phrase")
    {
        cTrim(theString, END);
        CHECK(strcmp(theAnswer, theString) > 0);
    }
    // variables reinitialize and checked
    SECTION("BOTH - Just a phrase")
    {
        cTrim(theString, BOTH);
        CHECK(strcmp(theAnswer, theString) == 0);
    }
}


TEST_CASE("cTrim - Testing C strings with ws on back end")
{
    // These variable will be initialized and any REQUIRE/CHECK 
    // executed before each section below.
    char theString[100] = "When will the pain stop!    ";
    char theAnswer[100] = "When will the pain stop!";
    CHECK(strcmp(theString, theAnswer) >= 0);
    

    // variables reinitialize and checked
    SECTION("Front -  Just a phrase")
    {
        cTrim(theString, FRONT);
        CHECK(strcmp(theAnswer, theString) < 0);
    }
    // variables reinitialize and checked
    SECTION("End -  Just a phrase")
    {
        cTrim(theString, END);
        CHECK(strcmp(theAnswer, theString) == 0);
    }
    // variables reinitialize and checked
    SECTION("BOTH - Just a phrase")
    {
        cTrim(theString, BOTH);
        CHECK(strcmp(theAnswer, theString) == 0);
    }
}

TEST_CASE("cTrim - Testing C strings with ws on either end")
{
    // These variable will be initialized and any REQUIRE/CHECK 
    // executed before each section below.
    char theString[100] = "    When will life get better!    ";
    char theAnswer[100] = "When will life get better!";
    CHECK(strcmp(theString, theAnswer)<= 0);

    // variables reinitialize and checked
    SECTION("Front -  Just a phrase")
    {
        cTrim(theString, FRONT);
        CHECK(strcmp(theAnswer, theString) < 0);
    }
    // variables reinitialize and checked
    SECTION("End -  Just a phrase")
    {
        cTrim(theString, END);
        CHECK(strcmp(theAnswer, theString) > 0);
    }
    // variables reinitialize and checked
    SECTION("BOTH - Just a phrase")
    {
        cTrim(theString, BOTH);
        CHECK(strcmp(theAnswer, theString) == 0);
    }
}

TEST_CASE("cTrim - Testing C strings with ws on either end 2")
{
    // These variable will be initialized and any REQUIRE/CHECK 
    // executed before each section below.
    char theString[100] = "    Why must the pain continue on!    ";
    char theAnswer[100] = "Why must the pain continue on!";
    CHECK(strcmp(theString, theAnswer) <= 0);

    // variables reinitialize and checked
    SECTION("Front -  Just a phrase")
    {
        cTrim(theString, FRONT);
        CHECK(strcmp(theAnswer, theString) < 0);
    }
    // variables reinitialize and checked
    SECTION("End -  Just a phrase")
    {
        cTrim(theString, END);
        CHECK(strcmp(theAnswer, theString) > 0);
    }
    // variables reinitialize and checked
    SECTION("BOTH - Just a phrase")
    {
        cTrim(theString, BOTH);
        CHECK(strcmp(theAnswer, theString) == 0);
    }
}
/*****************************************************************************/


TEST_CASE("sTrim - Testing strings with ws on either end")
{
    // These variable will be initialized and any REQUIRE/CHECK 
    // executed before each section below.
    string theString = "    I saw mom with Santa Claus!    ";
    string theAnswer = "I saw mom with Santa Claus!";
    CHECK(theString <= theAnswer);

    //Issue
    // variables reinitialize and checked
    SECTION("Front -  Just a phrase")
    {
        sTrim(theString, FRONT);
        CHECK(theAnswer < theString);
    }
    // variables reinitialize and checked
    SECTION("End - Just a phrase")
    {
        sTrim(theString, END);
        CHECK(theAnswer > theString);
    }
    //Issue
    // variables reinitialize and checked
    SECTION("BOTH - Just a phrase")
    {
        sTrim(theString, BOTH);
        CHECK(theAnswer == theString);
    }
}

TEST_CASE("sTrim - Testing strings with ws on front end")
{
    // These variable will be initialized and any REQUIRE/CHECK 
    // executed before each section below.
    string theString = "    Peace is for wimps. War is the answer!";
    string theAnswer = "Peace is for wimps. War is the answer!";
    CHECK(theString <= theAnswer);

    //Issue
    // variables reinitialize and checked
    SECTION("Front -  Just a phrase")
    {
        sTrim(theString, FRONT);
        CHECK(theAnswer == theString);
    }
    // variables reinitialize and checked
    SECTION("End - Just a phrase")
    {
        sTrim(theString, END);
        CHECK(theAnswer >= theString);
    }
    //Issue
    // variables reinitialize and checked
    SECTION("BOTH - Just a phrase")
    {
        sTrim(theString, BOTH);
        CHECK(theAnswer == theString);
    }
}

TEST_CASE("sTrim - Testing strings with ws on back end")
{
    // These variable will be initialized and any REQUIRE/CHECK 
    // executed before each section below.
    string theString = "Why do they all take their lives!    ";
    string theAnswer = "Why do they all take their lives!";
    CHECK(theString >= theAnswer);
    

    // variables reinitialize and checked
    SECTION("Front -  Just a phrase")
    {
        sTrim(theString, FRONT);
        CHECK(theAnswer < theString);
    }
    //Issue
    // variables reinitialize and checked
    SECTION("End - Just a phrase")
    {
        sTrim(theString, END);
        CHECK(theAnswer == theString);
    }
    //Issue
    // variables reinitialize and checked
    SECTION("BOTH - Just a phrase")
    {
        sTrim(theString, BOTH);
        CHECK(theAnswer == theString);
    }
}

TEST_CASE("sTrim - Testing strings with no ws on either end 2")
{
    // These variable will be initialized and any REQUIRE/CHECK 
    // executed before each section below.
    string theString = "       ";
    string theAnswer = "";
    CHECK(theString >= theAnswer);

    // variables reinitialize and checked
    SECTION("Front -  Just a phrase")
    {
        sTrim(theString, FRONT);
        CHECK(theAnswer == theString);
    }
    // variables reinitialize and checked
    SECTION("End - Just a phrase")
    {
        sTrim(theString, END);
        CHECK(theAnswer == theString);
    }
    // variables reinitialize and checked
    SECTION("BOTH - Just a phrase")
    {
        sTrim(theString, BOTH);
        CHECK(theAnswer == theString);
    }
}
