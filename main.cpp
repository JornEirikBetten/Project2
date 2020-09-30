#include "jacobi.h"
#include "armadillo"
#include <vector>
#include <string>
#include <fstream>
using namespace arma; 
using namespace std; 

int main(int argc, char* argv[]) {
	int n = atoi(argv[1]); 
	int interact = atoi(argv[2]); 
	string argument = string(argv[3]);
	mat a = zeros<mat>(n,n); 
	mat v = zeros<mat>(n,n);
	vec r = zeros<vec>(n); 
	double Rmin=0,Rmax=20, h, wr, conv; 
	h = Rmax/n; 
	wr = 0.01;  
	conv = 1E-8; 
	string filename = argument + "_N_" + to_string(n) + ".txt";
	// setting up matrices
	if (argument =="buckbeam") {
		init(n, h, a, v); 
	}
	else if (argument=="harmosci") {
		initialize(n, h, a, r, v, interact, wr);
	}
	//using jacobimethod to solve eigenvalueproblem
	jacobi(n, interact, conv, wr, a, r, v);
	mat vecs = zeros<mat>(n,n); 
	int lowest; 
	find_lowest_eigenvalue(a, n, lowest); 
	cout << lowest << endl; 
	ofstream ofile; 
	ofile.open("eigenvalues.txt"); 
	vector<double> eigen = vector<double>(n); 
	eigen = get_eigenvals(a, n); 
	for (int i=0; i<n; i++) {
		ofile << "Eigenvalue"+to_string(i)+":"+to_string(eigen[i]) << endl; 
	}
	ofile.close(); 
	//vecs = get_eigenvecs(a, v, n);
	//vector<double> eigen = vector<double>(n);  
	return 0; 
}
