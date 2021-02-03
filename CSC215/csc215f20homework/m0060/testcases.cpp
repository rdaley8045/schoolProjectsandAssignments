#include "newton.h"
#include "..\catch.hpp"

double f(double x)
{
    return pow(x, 3) + 2;
}

double fP(double x)
{
    return 3 * pow(x, 2);
}

TEST_CASE("newtonApprox - x^3 + 2")
{
    double epsilon = .001;
    double n = 2;
    double ans;

    // note, you pass the name of your functions
    ans = newtonApprox(n, f, fP, epsilon);

    REQUIRE(fabs(f(ans)) <= epsilon);
}




double alpha(double x)
{
    return log(pow(x,2))/(1+log(x));
}

double bravo(double x)
{
    return 2/pow((1+log(x)),2);
}

TEST_CASE("newtonApprox - ln x^2 / (1+ln x)")
{
    double epsilon = .001;
    double n = 5;
    double ans;

    // note, you pass the name of your functions
    ans = newtonApprox(n, alpha, bravo, epsilon);

    REQUIRE(fabs(alpha(ans)) <= epsilon);
}


double charlie(double x)
{
    return log((3*x-2)/(x*sqrt(x+1)));
}

double delta(double x)
{
    return (3/(3*x-2)) - (1/x) + (1/(2*x+2));
}

TEST_CASE("newtonApprox - ln((3x-2)/xSqrt(x+1) , 3/3x-2-1/x+1/2x+2")
{
    double epsilon = .001;
    double n = 4;
    double ans;

    // note, you pass the name of your functions
    ans = newtonApprox(n, charlie, delta, epsilon);

    REQUIRE(fabs(charlie(ans)) <= epsilon);
}

double echo(double x)
{
    return 6*pow(x,2)-10*x-5*pow(x,-2);
}

double foxtrot(double x)
{
    return 12*x-10+10*pow(x,-3);
}

TEST_CASE("newtonApprox - 6x^2-10x-5x^2 , 12x-10+10x^-3")
{
    double epsilon = .001;
    double n = -2;
    double ans;

    // note, you pass the name of your functions
    ans = newtonApprox(n, echo, foxtrot, epsilon);

    REQUIRE(fabs(echo(ans)) <= epsilon);
}


double golf(double x)
{
    return 3*pow(x,7)-7*pow(x,3)+21*pow(x,3);
}

double hotel(double x)
{
    return 21*pow(x,6)+42*pow(x,2);
}

TEST_CASE("newtonApprox - 3x^7-7x^3+21x^3 , 21x^6+42x^2")
{
    double epsilon = .001;
    double n = 1;
    double ans;

    // note, you pass the name of your functions
    ans = newtonApprox(n, golf, hotel, epsilon);

    REQUIRE(fabs(golf(ans)) <= epsilon);
}