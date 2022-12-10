#include <bits/stdc++.h>
using namespace std;
#include "def.h"

TEM struct poly{
	vt a;
	poly(){a.clear();}
	poly(T x){a.clear(), a.pb(x);}
	poly(T x, T y){a.clear(), a.pb(x), a.pb(y);}
	poly(T x, T y, T z){a.clear(), a.pb(x), a.pb(y), a.pb(z);}
	poly(vi &b){a=b;}
	void reduce0(){while(a.size()&&!a[a.size()-1])a.pop_back();}
	int deg(){reduce0(); return (int)a.size()-1;}
	poly operator+(const poly b)const{
		poly c;
		int n=max(a.size(), b.a.size());
		rep(i, n)c.a.pb((i<a.size()?a[i]:0)+(i<b.a.size()?b.a[i]:0));
		c.reduce0();
		return c;
	}
	poly operator-()const{
		poly b;
		for(auto i:a)b.a.pb(-i);
		b.reduce0();
		return b;
	}
	poly operator-(const poly b)const{return *this+(-b);}
	poly operator*(const poly b)const{
		poly c;
		c.a.resize(max((int)a.size()+(int)b.a.size()-1, 0), 0);
		rep(i, a.size())rep(j, b.a.size())c.a[i+j]+=a[i]*b.a[i];
		c.reduce0();
		return c;
	}
	poly operator+=(const poly b){return *this=*this+b;}
	poly operator-=(const poly b){return *this=*this-b;}
	poly operator*=(const poly b){return *this=*this*b;}
};
