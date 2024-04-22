#pragma once
#include "iostream"
using namespace std;

bool ImportVectors(const string& FileInput, double& S, size_t& n, double*& w, double*& r);
string ArrayToString(const size_t& n,const double* const& v);
double DotProduct(const size_t& n,const double* const& v1,const double* const& v2, double& V, const double& S);
bool ExportResult(const string& outputFilePath,const size_t& n,const double* const& w,const double* const& r,const double& dotProduct,
                  const double& S,const double& V);
