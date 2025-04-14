#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include "Utils.hpp"

using namespace std;

// Importo i dati dal file e alloco memoria per w e r
bool read_data(const string& filename, size_t& n, double& S, double*& w, double*& r)
{
    ifstream file(filename);
    if (file.fail()) 
    {
        cerr << "File not found" << endl;
        return false;
    }

    // La stringa vuota tmp serve per leggere temporaneamente una parte della riga del file
    string tmp;
    // Lettura del file fino al carattere ;
    getline(file, tmp, ';');
    // Assegno ad S la parte dopo il ;
    file >> S;
    // Ignoro il carattere di newline (\n)
    file.ignore();

    // Ripeto il procedimento per la seconda riga
    getline(file, tmp, ';');
    file >> n;
    file.ignore();

    // Ignoro la terza riga
    getline(file, tmp);

    // Uso array dinamici perchè non conosco la lunghezza del file
    w = new double[n];
    r = new double[n];

    // Lettura righe successive
    for(unsigned int i = 0; i < n; ++i)
    {
        getline(file, tmp);
        // Cerco la posizione di ; all'interno della riga
        size_t f = tmp.find(';');
        // Estraggo con substr() la parte prima del ; e poi lo converto in double usando stod()
        w[i] = stod(tmp.substr(0, f));
        // Stesso procedimento precendente, ma stavolta l'estrazione avviene dopo il ;
        r[i] = stod(tmp.substr(f+1));
    }

    file.close();
    return true;
}

// Calcolo il tasso di rendimento
double return_rate(const size_t n, const double* w, const double* r)
{
    // Calcolo il tasso di rendimento finale
    double total = 0.0;
    for(size_t i = 0; i < n; ++i)
    {
        total += w[i] * r[i];
    }
    return total;
}

// Calcolo il valore finale del portafoglio usando la formula presente nel readme
double portfolio_value(const double S, const double total)
{
    return ( 1.0 + total )* S;
}

// Converto un array in stringa
string array_to_string(const size_t n, const double* data)
{
    ostringstream ostr;
    ostr << "[ ";
    for (size_t i = 0; i < n; ++i)
    {
        ostr << data[i] << " ";
    
    }
    ostr << "]";
    return ostr.str();
}

// Stampo i risultati
bool print(const string& filename, const double S, const size_t n, const double* w, const double* r, const double rate, const double V)
{
    // Controllo se c'è un errore nell'apertura del file
    ofstream file(filename);
    if (file.fail())
    {
        cerr << "Opening file failed" << endl;
        return false;
    }

    // Scrivo sul file, richiamando la funzione array_to_string per convertire gli array in stringa
    file << fixed << setprecision(2);
    file << "S = " << S << ", n = " << n << endl;
    file << "w = " << array_to_string(n, w) << endl;
    file << "r = " << array_to_string(n, r) << endl;
    file << setprecision(4) << "Rate of return of the portfolio: "  << rate << endl;
    file << setprecision(2) << "V: " << V << endl;

    // Output sul terminale
    cout << fixed << setprecision(2);
    cout << "S = " << S << ", n = " << n << endl;
    cout << "w = " << array_to_string(n, w) << endl;
    cout << "r = " << array_to_string(n, r) << endl;
    cout << setprecision(4) << "Rate of return of the portfolio: "  << rate << endl;
    cout << setprecision(2) << "V: " << V << endl;

    return true;

}