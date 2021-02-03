/** ***************************************************************************
 * @file    
 *
 * @brief   Where a students test cases will be written for the enqueue,
 *          dequeue, front and copy constructor member functions.
 *       
 *****************************************************************************/
#include "..\catch.hpp"
#include <sstream>
#include "myQueue.h"

using namespace std;

void printQueue( Queue q, ostream &out );

//write your test cases here
 
TEST_CASE("Enqueue")
{
    Queue list;
    ostringstream sout;

    SECTION("Empty list")
    {
        REQUIRE(list.empty() == true);
        REQUIRE(list.enqueue("test") == true);

        list.print(sout);
        REQUIRE(sout.str() == "test");
        sout.str("");
    }

    SECTION("Multiple Lines")
    {
        REQUIRE(list.enqueue("I") == true);
        REQUIRE(list.enqueue("really") == true);
        REQUIRE(list.enqueue("need") == true);
        REQUIRE(list.enqueue("help") == true);

        list.print(sout);
        REQUIRE(sout.str() == "I, really, need, help");
        sout.str("");
    }
}

TEST_CASE("Dequeue")
{
    Queue list;
    ostringstream sout; 
    string word;

    SECTION("Empty list")
    {
        REQUIRE(list.empty() == true);
        REQUIRE(list.dequeue(word) == false);
    }

    SECTION("One item in List")
    {
        REQUIRE(list.enqueue("test") == true);
        list.print(sout);
        REQUIRE(sout.str() == "test");
        sout.str("");

        REQUIRE(list.dequeue(word) == true);
        REQUIRE(word == "test");

        REQUIRE(list.empty() == true);

    }

    SECTION("Multiple Itmes in List")
    {
        REQUIRE(list.enqueue("I") == true);
        REQUIRE(list.enqueue("really") == true);
        REQUIRE(list.enqueue("need") == true);
        REQUIRE(list.enqueue("help") == true);

        list.print(sout);
        REQUIRE(sout.str() == "I, really, need, help");
        sout.str("");

        REQUIRE(list.dequeue(word) == true);
        REQUIRE(word == "I");

        list.print(sout);
        REQUIRE(sout.str() == "really, need, help");
        sout.str("");

        REQUIRE(list.dequeue(word) == true);
        REQUIRE(word == "really");

        list.print(sout);
        REQUIRE(sout.str() == "need, help");
        sout.str("");


    }
}


TEST_CASE("Front")
{
    Queue list;
    ostringstream sout;
    string word;

    SECTION("Empty list")
    {
        REQUIRE(list.empty() == true);
        REQUIRE(list.front(word) == false);
    }

    SECTION("One item in List")
    {
        REQUIRE(list.enqueue("test") == true);
        list.print(sout);
        REQUIRE(sout.str() == "test");
        sout.str("");

        REQUIRE(list.front(word) == true);
        REQUIRE(word == "test");


    }

    SECTION("Multiple Itmes in List")
    {
        REQUIRE(list.enqueue("I") == true);
        REQUIRE(list.enqueue("really") == true);
        REQUIRE(list.enqueue("need") == true);
        REQUIRE(list.enqueue("help") == true);

        list.print(sout);
        REQUIRE(sout.str() == "I, really, need, help");
        sout.str("");

        REQUIRE(list.front(word) == true);
        REQUIRE(word == "I");


    }
}

TEST_CASE("Copy Constructor")
{
    Queue list;
    ostringstream sout, sout1;
    string word;

    SECTION("Empty list")
    {
        REQUIRE(list.empty() == true);
        Queue newList(list);

        REQUIRE(newList.empty() == true);

    }

    SECTION("One item in List")
    {
        REQUIRE(list.enqueue("test") == true);
        list.print(sout);
        REQUIRE(sout.str() == "test");

        Queue newList(list);
        printQueue(newList, sout1);


        REQUIRE(sout.str() == sout1.str());

        sout.str("");
        sout1.str("");

    }

    SECTION("Multiple Itmes in List")
    {
        REQUIRE(list.enqueue("I") == true);
        REQUIRE(list.enqueue("really") == true);
        REQUIRE(list.enqueue("need") == true);
        REQUIRE(list.enqueue("help") == true);

        list.print(sout);
        REQUIRE(sout.str() == "I, really, need, help");

        Queue newList(list);
        printQueue(newList, sout1);

        REQUIRE(sout.str() == sout1.str());

        sout.str("");
        sout1.str("");



    }


}

TEST_CASE("Assignment")
{
    Queue q1, q2;
    ostringstream sout, sout1;

    SECTION("Empty List")
    {
        REQUIRE(q1.empty() == true);
        q2 = q1;
        REQUIRE(q2.empty() == true);

        REQUIRE(q2.enqueue("this") == true);
        q2 = q1;
        REQUIRE(q2.empty() == true);

        q1 = q1;
        REQUIRE(q1.empty() == true);
    }

    SECTION("One item in List")
    {
        REQUIRE(q1.enqueue("test") == true);
        q1.print(sout);
        REQUIRE(sout.str() == "test");

        q2 = q1;

        REQUIRE(q2.empty() == false);

        q2.print(sout1);
        REQUIRE(sout.str() == sout1.str());

        sout1.str("");

        q2.enqueue("Help");
        q2.print(sout1);
        REQUIRE(sout1.str() == "test, Help");
        sout1.str("");
        q2 = q1;

        q2.print(sout1);
        REQUIRE(sout.str() == sout1.str());

        sout1.str("");
        sout.str("");
    }

    SECTION("Many items in List")
    {
        REQUIRE(q1.enqueue("I") == true);
        REQUIRE(q1.enqueue("really") == true);
        REQUIRE(q1.enqueue("need") == true);
        REQUIRE(q1.enqueue("help") == true);

        q1.print(sout);
        REQUIRE(sout.str() == "I, really, need, help");

        q2 = q1;

        q2.print(sout1);

        REQUIRE(sout.str() == sout1.str());

        sout1.str("");

        REQUIRE(q2.enqueue("I") == true);
        REQUIRE(q2.enqueue("hope") == true);

        q2 = q1;

        q2.print(sout1);

        REQUIRE(sout.str() == sout1.str());

        sout1.str("");
        sout.str("");
    }

}


TEST_CASE("equal")
{
    Queue q1, q2;
    ostringstream sout, sout1;

    SECTION("Empty List")
    {
        REQUIRE(q1.empty() == true);
        q2 = q1;
        REQUIRE((q2 == q1) == true);

        REQUIRE(q2.enqueue("this") == true);
        q2 = q1;
        REQUIRE((q2 == q1) == true);
    }

    SECTION("One item in List")
    {
        REQUIRE(q1.enqueue("test") == true);
        q1.print(sout);
        REQUIRE(sout.str() == "test");

        q2 = q1;

        REQUIRE((q2 == q1) == true);

        q2.print(sout1);
        REQUIRE(sout.str() == sout1.str());

        sout1.str("");

        q2.enqueue("Help");
        q2.print(sout1);
        REQUIRE(sout1.str() == "test, Help");
        sout1.str("");

        REQUIRE((q2 == q1) == false);

        q2 = q1;

        REQUIRE((q2 == q1) == true);
        q2.print(sout1);
        REQUIRE(sout.str() == sout1.str());

        sout1.str("");
        sout.str("");
    }

    SECTION("Many items in List")
    {
        REQUIRE(q1.enqueue("I") == true);
        REQUIRE(q1.enqueue("really") == true);
        REQUIRE(q1.enqueue("need") == true);
        REQUIRE(q1.enqueue("help") == true);

        q1.print(sout);
        REQUIRE(sout.str() == "I, really, need, help");

        q2 = q1;
        
        REQUIRE((q2 == q1) == true);

        q2.print(sout1);

        REQUIRE(sout.str() == sout1.str());

        sout1.str("");

        REQUIRE(q2.enqueue("I") == true);
        REQUIRE(q2.enqueue("hope") == true);

        REQUIRE((q2 == q1) == false);

        q2 = q1;

        q2.print(sout1);

        REQUIRE((q2 == q1) == true);
        REQUIRE(sout.str() == sout1.str());

        sout1.str("");
        sout.str("");
    }
}


TEST_CASE("not equal")
{
    Queue q1, q2;
    ostringstream sout, sout1;

    SECTION("Empty List")
    {
        REQUIRE(q1.empty() == true);
        q2 = q1;
        REQUIRE((q2 != q1) == false);

        REQUIRE(q2.enqueue("this") == true);
        REQUIRE((q2 != q1) == true);
        q2 = q1;
    }

    SECTION("One item in List")
    {
        REQUIRE(q1.enqueue("test") == true);
        q1.print(sout);
        REQUIRE(sout.str() == "test");

        q2 = q1;

        REQUIRE((q2 != q1) == false);

        q2.print(sout1);
        REQUIRE(sout.str() == sout1.str());

        sout1.str("");

        q2.enqueue("Help");
        q2.print(sout1);
        REQUIRE(sout1.str() == "test, Help");
        sout1.str("");

        REQUIRE((q2 != q1) == true);

        q2 = q1;

        REQUIRE((q2 != q1) == false);
        q2.print(sout1);
        REQUIRE(sout.str() == sout1.str());

        sout1.str("");
        sout.str("");
    }

    SECTION("Many items in List")
    {
        REQUIRE(q1.enqueue("I") == true);
        REQUIRE(q1.enqueue("really") == true);
        REQUIRE(q1.enqueue("need") == true);
        REQUIRE(q1.enqueue("help") == true);

        q1.print(sout);
        REQUIRE(sout.str() == "I, really, need, help");

        q2 = q1;

        REQUIRE((q2 != q1) == false);

        q2.print(sout1);

        REQUIRE(sout.str() == sout1.str());

        sout1.str("");

        REQUIRE(q2.enqueue("I") == true);
        REQUIRE(q2.enqueue("hope") == true);

        REQUIRE((q2 != q1) == true);

        q2 = q1;

        q2.print(sout1);

        REQUIRE((q2 != q1) == false);
        REQUIRE(sout.str() == sout1.str());

        sout1.str("");
        sout.str("");
    }
}


void printQueue( Queue q, ostream &out )
{
    // write the code to print a queue to the screen destroying the
    // contents of the queue when done. It is pass by value.
    string word;

    while (q.empty()== false)
    {
        q.dequeue(word);
        out << word;
        if (q.front(word) == true)
            out << ", ";
    }
    
     
}

