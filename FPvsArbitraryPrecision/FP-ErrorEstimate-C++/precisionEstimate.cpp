#include <cmath>
#include <iostream>
#include <iomanip>
#include <functional>

#include "cleveMoler.h"

using namespace std;

/**
 * Run an arbitrary function a predefined number of times.
 *
 * @param f function to run
 * @param numExecs number of function executions
 *
 * @return total execution time
 */
template<typename T>
long performExecs(T (*f)(), long numExecs)
{
    T p;

    long start = time(NULL);

    for (long i = 0; i < numExecs; i++) {
        p = f();
    }

    long stop = time(NULL);

    return stop - start;
}

//------------------------------------------------------------------------------
int main(int argc, char** argv)
{
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " numExecs" << "\n";
        return 1;
    }

    long numExecs = std::stol(argv[1]);

    float    sp = estimatePrecision<float>();
    double   dp = estimatePrecision<double>();
    float128 qp = estimatePrecision<float128>();

    long totalTime = performExecs(estimatePrecision<float>, numExecs);
    cout << right << setw(4) <<  totalTime << " secs | " << sp << "\n";

    totalTime = performExecs(estimatePrecision<double>, numExecs);
    cout << right << setw(4) <<  totalTime << " secs | " << dp << "\n";

    totalTime = performExecs(estimatePrecision<float128>, numExecs);
    cout << right << setw(4) <<  totalTime << " secs | " << qp << "\n";

    return 0;
}
