#include <iostream>
#include <fstream>
#include <sstream>
#include "Utils.hpp"
#include "iomanip"

using namespace std;


int main()
{
    string inputFileName = "./data.csv";
    double S = 0;
    size_t n = 0;
    double* w = nullptr;
    double* r = nullptr;
    double V = 0;

    if (!ImportVectors(inputFileName, S, n, w, r))
    {
        cerr<< "Something goes wrong with import"<< endl;
        return -1;
    }
    else
        cout << "S = " << fixed << setprecision(2) << S << ", n= " << n << endl;
    cout << "w = " << ArrayToString(n, w) <<endl;
    cout <<"r = " << ArrayToString(n, r) << endl;


    double dotProduct = DotProduct(n, w, r, V, S);
    cout <<fixed << setprecision(4) << "Rate of return of the portfolio: "<< dotProduct << endl;
    cout << "V: " << setprecision(2) << V << endl;

    string outputFileName = "./result.txt";
    if (!ExportResult(outputFileName, n, w, r, dotProduct, S, V))
    {
        cerr<< "Something goes wrong with export"<< endl;
        return -1;
    }
    else
        cout<< "Export successful on file result.txt"<< endl;

    delete[] w;
    delete[] r;

    return 0;
}

