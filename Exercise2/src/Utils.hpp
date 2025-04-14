#pragma once
#include <string>

using namespace std;

//Dichiaro la funzione per leggere i file
bool read_data(const string& filename, size_t& n, double& S, double*& w, double*& r);

//Dichiaro la funzione per calcolare il tasso di rendimento
double return_rate(const size_t n, const double* w, const double* r);

//Dichiaro la funzione per calcolare il valore finale del portafoglio
double portfolio_value(const double S, const double total);

//Dichiaro la funzione che converte gli array in stringa
string array_to_string(const size_t n, const double* data);

//Dichiaro la funzione che stampa i risultati su un file
bool print(const string& filename, const double S, const size_t n, const double* w, const double* r, const double rate, const double V);
