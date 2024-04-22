#include "Utils.hpp"
#include "iostream"
#include "fstream"
#include "sstream"
#include "iomanip"

using namespace std;

bool ImportVectors(const string& FileInput, double& S, size_t& n, double*& w, double*& r){

    ifstream file;
    file.open(FileInput);
    if (file.fail())
    {
        cerr<< "File not opened correctly: "<< endl;
        return false;
    }


    string line;
    string useless;
    getline(file, useless, ';');
    getline(file, line);
    istringstream ConvertS;
    ConvertS.str(line);
    ConvertS >> S;

    getline(file, useless, ';');
    getline(file, line);
    istringstream ConvertN;
    ConvertN.str(line);
    ConvertN >> n;

    string header;
    getline(file, header);

    string fraction;
    string revenue;
    w = new double[n];
    r = new double[n];
    for (unsigned int i = 0; i < n; i++)
    {
        getline(file, fraction, ';');
        getline(file, revenue);

        istringstream convertW;
        istringstream convertR;

        convertW.str(fraction);
        convertR.str(revenue);

        convertW >> w[i];
        convertR >> r[i];
    }

    file.close();
    return true;
}

string ArrayToString(const size_t& n,  const double* const& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (unsigned int i = 0; i < n; i++)
        toString<< v[i]<< " "; toString << "]";

    return toString.str();
}

double DotProduct(const size_t& n,const double* const& v1,
                  const double* const& v2, double& V, const double& S)
{
    double dotProduct = 0;
    for (unsigned int i = 0; i < n; i++)
        dotProduct += v1[i] * v2[i];
    V = (1 + dotProduct) * S;
    return dotProduct;
}

bool ExportResult(const string& outputFilePath,const size_t& n,const double* const& w,
                  const double* const& r,const double& dotProduct,const double& S,
                  const double& V)
{

    ofstream file;
    file.open(outputFilePath);

    if (file.fail())
    {
        cerr<< "File not opened correctly: "<< endl;
        return false;
    }

    file<< fixed << setprecision(2) << "S = "<< S << ", n = " << n<< endl;

    file<< "w = "<< ArrayToString(n, w) << endl;

    file<< "r = "<< ArrayToString(n, r) << endl;

    file<< setprecision(4) << "Rate of return of the portfolio: "<< dotProduct << endl;

    file << fixed << setprecision(2) << "V: " << V << endl;

    file.close();

    return true;
}
