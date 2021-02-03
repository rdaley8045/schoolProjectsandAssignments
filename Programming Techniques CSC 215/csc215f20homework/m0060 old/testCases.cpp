#include "newton.h"
#include "..\catch.hpp"

double f( double x )
{
    return pow( x, 3 ) + 2;
}

double fP( double x )
{
    return 3 * pow( x, 2 );
}

TEST_CASE( "newtonApprox - x^3 + 2" )
{
    double epsilon = .001;
    double n = 2;
    double ans;
    
    // note, you pass the name of your functions
    ans = newtonApprox( n, f, fP, epsilon ); 

    REQUIRE( fabs( f( ans ) ) <= epsilon );
}