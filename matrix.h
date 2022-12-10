#include <bits/stdc++.h>
using namespace std;
#include "def.h"
#include "polynomial.h"

TEM struct Matrix{ // matrix of ring
	T a[kN][kN]={0};
	int n, m;
	Matrix(){}
	Matrix(int n, int m):n(n), m(m){}
	Matrix(int n, int m, T *b[kN]):n(n), m(m){
		for(int i=0; i<n; ++i)for(int j=0; j<m; ++j)a[i][j]=b[i][j];
	}
	Matrix operator+(const Matrix b)const{
		assert(n==b.n&&m==b.m);
		Matrix c=Matrix(n, m);
		for(int i=0; i<n; ++i)for(int j=0; j<m; ++j)c.a[i][j]=a[i][j]+b.a[i][j];
		return c;
	}
	Matrix operator-()const{
		Matrix b=Matrix(n, m);
		for(int i=0; i<n; ++i)for(int j=0; j<m; ++j)b.a[i][j]=-a[i][j];
		return b;
	}
	Matrix operator-(const Matrix b)const{return *this+(-b);}
	Matrix operator*(const Matrix b)const{
		assert(m==b.n);
		Matrix c=Matrix(n, b.m);
		for(int i=0; i<n; ++i)for(int j=0; j<b.m; ++j)for(int k=0; k<m; ++k)c.a[i][j]+=a[i][k]*b.a[k][j];
		return c;
	}
};

TEM struct matrix{ // matrix of field
};
