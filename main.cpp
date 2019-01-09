#include <iostream>
#include "Factorizations.h"
#include "log.h"

using namespace std;

int main()
{
	
	Factorize a;
	a.n = 143;   
	int y = a.ferma();
	cout << "Method 1:      " << a.n << "=" << y << "*" <<a.n/a.ferma()<< endl;
	y = a.polard(50);
	cout << "Method 2:     " << a.n << "=" <<y<< "*" << (a.n )/y << endl;
	y = a.square();
	cout << "Method 3:     " << a.n << "=" << y << "*" << (a.n) / y << endl;
	y = a.quadroSieve();
	cout << "Method 4:   " << a.n << "=" << y << "*" << (a.n) / y << endl;
	y = a.Lenstra();
	cout << "Method 5:    :" << a.n << "=" << y << "*" << (a.n) / y << endl;
	int b=11, g=2, n=13,x;
	x = naive(n, b, g);
	cout <<"Algorithm 1:    "<<g<<"^"<<x<< "=" <<b <<"(mod"<<n<<")"<< endl;
	x= Shank(n, b, g);
	cout << "Algorithm 2:    " << g << "^" << x << "=" << b << "(mod" << n << ")" << endl;
	y = rhoPoll(n, b, g);
	//x = powmod(g, y, n);
	cout << "Algorithm 3:    " << g << "^" << y << "=" << b << "(mod" << n << ")" << endl;
    system("pause");
	return 0;
}
