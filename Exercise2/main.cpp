#include <iostream>
#include <string>
#include "Utils.hpp"

using namespace std;

int main()
{
    string filename = "data.txt";
    size_t n;
    double S;
    double* w = nullptr;
    double* r = nullptr;

    read_data(filename, n, S, w, r);
    double rate = return_rate(n, w, r);
    double V = portfolio_value(S, rate);
    print("result.txt", S, n, w, r, rate, V);

    // Deallocazione memoria
    delete[] w;
    delete[] r;
    
    return 0;
}

