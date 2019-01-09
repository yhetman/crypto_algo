#include <math.h>
#include <time.h>
#include <vector>
#include <bitset>
using namespace std;

class Factorize
{
	int gcd(int, int);
	int jacobi(int, int);
	void gauss(vector< vector<int> > &, vector<int> &, vector< vector<int> > &);
	int gcdext(int, int, int &, int &);
	int revMod(int, int);
	struct Point 
	{
		int x, y;
    };
	Point P0, P;
public:
	bool is_prime(int);
	int ferma();
	int polard(int);
	int square();
	int quadroSieve();
	int Lenstra();
	int n;
};




