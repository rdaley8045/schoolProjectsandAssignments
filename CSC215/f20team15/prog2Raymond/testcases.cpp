#define CATCH_CONFIG_MAIN
#include "..\catch.hpp"
#include "..\prog2\wordFreq.h"

TEST_CASE("constructors")
{
    wordFreq list;

    REQUIRE(list.empty() == true);
    REQUIRE(list.sizeList() == 0);                                   
}

TEST_CASE("Destructor")
{
    wordFreq list;


    CHECK(list.insert("blade") == true);
    REQUIRE(list.insert("bad") == true);
    CHECK(list.insert("can") == true);

    list.printWord(cout);
    

    REQUIRE(list.sizeList() == 3);
    REQUIRE(list.empty() == false);

    list.~wordFreq();

    REQUIRE(list.sizeList() == 0);
    REQUIRE(list.empty() == true);

}


TEST_CASE("Insert")
{
    wordFreq list;


    REQUIRE(list.insert("apple") == true);
    REQUIRE(list.insert("bacon") == true);
    REQUIRE(list.insert("chips") == true);
    REQUIRE(list.insert("dog") == true);
    REQUIRE(list.insert("eat") == true);
    REQUIRE(list.insert("face") == true);


    SECTION("Front")
    {
        REQUIRE(list.insert("alpha") == true);
        REQUIRE(list.insert("appay") == true);
        REQUIRE(list.insert("appel") == true);

    }
    SECTION("Middle")
    {
        REQUIRE(list.insert("cat") == true);
        REQUIRE(list.insert("chaps") == true);


    }
    SECTION("End")
    {
        REQUIRE(list.insert("fade") == true);
        REQUIRE(list.insert("fate") == true);

    }

}


TEST_CASE("Find")
{
    wordFreq list;

    REQUIRE(list.insert("apple") == true);
    REQUIRE(list.insert("bacon") == true);
    REQUIRE(list.insert("chips") == true);
    REQUIRE(list.insert("dog") == true);
    REQUIRE(list.insert("eat") == true);
    REQUIRE(list.insert("face") == true);

    REQUIRE(list.find("apple") == true);
    REQUIRE(list.find("dog") == true);
    REQUIRE(list.find("face") == true);

    REQUIRE(list.find("people") == false);
    REQUIRE(list.find("a") == false);
}


TEST_CASE("REMOVE")
{
    wordFreq list;

    REQUIRE(list.insert("apple") == true);
    REQUIRE(list.insert("bacon") == true);
    REQUIRE(list.insert("chips") == true);
    REQUIRE(list.insert("dog") == true);
    REQUIRE(list.insert("eat") == true);
    REQUIRE(list.insert("face") == true);

    REQUIRE(list.empty() == false);

    REQUIRE(list.remove("apple") == true);
    REQUIRE(list.remove("bacon") == true);
    REQUIRE(list.remove("chips") == true);
    REQUIRE(list.remove("dog") == true);
    REQUIRE(list.remove("eat") == true);
    REQUIRE(list.remove("face") == true);

    REQUIRE(list.empty() == true);
}

TEST_CASE("Freq Increase")
{
    wordFreq list;

    REQUIRE(list.insert("apple") == true);
    REQUIRE(list.insert("bacon") == true);
    REQUIRE(list.insert("chips") == true);
    REQUIRE(list.insert("dog") == true);
    REQUIRE(list.insert("eat") == true);
    REQUIRE(list.insert("face") == true);

    REQUIRE(list.maxFreq() == 1);

    list.printFreq(cout, list.maxFreq());

    REQUIRE(list.frequencyInc("apple") == true);
    
    REQUIRE(list.maxFreq() == 2);

    list.printFreq(cout, list.maxFreq());

    REQUIRE(list.frequencyInc("apple") == true);
    REQUIRE(list.frequencyInc("apple") == true);

    REQUIRE(list.maxFreq() == 4);

    list.printFreq(cout, list.maxFreq());
}



TEST_CASE("Freq Decrease")
{
    wordFreq list;

    REQUIRE(list.insert("apple") == true);
    REQUIRE(list.insert("bacon") == true);
    REQUIRE(list.insert("chips") == true);
    REQUIRE(list.insert("dog") == true);
    REQUIRE(list.insert("eat") == true);
    REQUIRE(list.insert("face") == true);
    REQUIRE(list.frequencyInc("apple") == true);
    REQUIRE(list.frequencyInc("apple") == true);
    REQUIRE(list.frequencyInc("apple") == true);



}