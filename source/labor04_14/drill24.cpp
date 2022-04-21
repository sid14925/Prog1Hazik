#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>
#include <cerrno>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace std;
using namespace Numeric_lib;

int main()
try{
		cout << "sizeof:\n";
		cout << "char:\t" << sizeof(char) << "\n";
		cout << "short:\t" << sizeof(short) << "\n";
		cout << "int:\t" << sizeof(int) << "\n";
		cout << "long:\t" << sizeof(long) << "\n";
		cout << "float:\t" << sizeof(float) << "\n";
		cout << "double:\t" << sizeof(double) << "\n";
		cout << "int*:\t" << sizeof(int*) << "\n";
		cout << "double*:\t" << sizeof(double*) << "\n";
		cout << "long*:\t" << sizeof(long*) << "\n";
		cout << "float*:\t" << sizeof(float*) << "\n";

		cout << "Matrix sizes: \n";
		Matrix<int> a(10);
		Matrix<int> b(100);
		Matrix<double> c(10);
		Matrix<int, 2> d(10, 10);
		Matrix<int, 3> e(10, 10, 10);
		cout << "1D int 10 elem\t\t" << sizeof(a) << endl;
		cout << "1D int 100 elem\t\t" << sizeof(b) << endl;
		cout << "1D int 10 elem\t\t" << sizeof(c) << endl;
		cout << "2D int 10x10 elem\t\t" << sizeof(d) << endl;
		cout << "3D int 10x10x10 elem\t\t" << sizeof(e) << endl;

		cout<< "\nNumber of elements:\n";
		cout<< "a:\t" << a.size() << '\n';
		cout<< "b:\t" << b.size() << '\n';
		cout<< "c:\t" << c.size() << '\n';
		cout<< "d:\t" << d.size() << '\n';
		cout<< "e:\t" << e.size() << '\n';

		//4.feladat
		//errno függvénnyel
		int i;
		cout << "\nEnter ints: ";
		while(cin >> i){
			errno = 0;
			double d = sqrt(i);
			if(errno == EDOM)
				cout << "no square root\n";
			else
				cout << "sqrt(" << i << ") = " << d << '\n';
		}

		

		//5.feladat

		cin.clear();
		cin.ignore();
		cout << "\n Enter 10 floats: ";
		Matrix<double> m(10);
		double d2;
		for(int i=0; i<m.size(); i++){
			cin>>d2;
			if(!cin) throw runtime_error("Error while reading from cin!");
			m[i] = d2;
		}

		cout << "Matrix:\n " << m << '\n';

		//6. feladat
		//Szorzótábla


		cout<<"Multiplication table:\nEnter n:\n";
		int n;
		cin >> n;
		cout << "Enter m: \n";
		int m3;
		cin >> m3;
		Matrix<int, 2> mtable(n, m3);

		for(Index i=0; i< mtable.dim1(); ++i){
				for(Index j=0; j< mtable.dim2(); ++j){
					mtable(i, j) = (i+1)*(j+1);
					cout << setw(4) << mtable(i,j);
				}
				cout << '\n';
		}

		//7. feladat

		Matrix<complex<double>> m4(10);
		cout << "\nEnter 10 complex numbers (Re, Im): ";
		complex<double> comp;
		for(int i=0; i< 10; ++i){
				cin >> comp;
				if(!cin) throw runtime_error("Problem reading complex number!");
				m4[i] = comp;
		}
		complex<double> sum;
		for(Index i = 0; i<m4.size(); ++i)
			sum += m4[i];
	}
	cout << "Sum: "<< sum << '\n';





} catch(exception& e) {
	cerr << "exception: "<< e.what() << '\n';
} catch(...) {
	cerr << "Unknown exception!" << '\n';
}
