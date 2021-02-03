#include "newton.h"


// write the function named newtonApprox here

double newtonApprox(double n, double f(double x), double fp(double x),
    double espilon)
{
    double ans;
    double ans2=0;

    ans = fabs(f(n));

    if (ans <= espilon)   //base case
        return n;

    else {
        ans = n - (f(n) / fp(n));

        ans2 = newtonApprox(ans, f, fp, espilon);
        return ans2;

    }
}
