#ifndef JACOBI_H
#define	JACOBI_H

#include <iostream>
#include<fstream>
#include<math.h>
#include<iomanip>
#include <armadillo>
#include<time.h>
#include<vector>
#include<string>

using namespace std;
using namespace arma;

void print_vals(mat,mat,int,double);
void initialize(int,double,mat&,vec&,mat&,int,double);
void init(int, double, mat&, mat&); 
int jacobi(int,int,double,double,mat&,vec&,mat&);
void find_max(mat,int&,int&,double&,int);
vector<double> get_eigenvals(mat,int);
mat get_eigenvecs(mat,mat,int);
void write_eig_to_file(mat, int, int, string);
void find_lowest_eigenvalue(mat, int, int&); 

#endif /* JACOBI_H */
