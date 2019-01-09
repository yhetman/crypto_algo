#include <vector>
#include <map>
using namespace std;

int powmod(int a, int n, int m)
{
	int res = 1;
	while (n > 0)
	{
		if (n & 1)
		{
			res = (res * a) % m;
			--n;
		}
		else
		{
			a = (a * a) % m;
			n >>= 1;
		}
	}
	return res % m;
}

int naive(int n, int b, int g)
{
	int fnd = 1, x = 0;
	while (fnd) {
		int t = powmod(g, x, n);
		if (t == b)
			fnd = 0;
		else
			x++;
	}
	return x;
}

int Shank(int n, int b, int g)
{
	int a = ceil(sqrt(n));
	map<int, int> vals;
	for (int i = a; i > 0; i--)
		vals[powmod(g, i * a, n)] = i;
	for (int i = 0; i <= a; i++) 
	{
		int cur = (powmod(g, i, n) * b) % n;
		if (vals.count(cur))
		{
			int ans = vals[cur] * a - i;
			if (ans < n)
				return ans;
		}
	}
	return -1;
}

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int gcdext(int a, int b, int & x, int & y)
{
	if (a == 0)
	{
		x = 0;
		y = 1;
		return b;
	}
	int x1, y1;
	int d = gcdext(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

int revMod(int a, int m)
{
	int x, y;
	int g = gcdext(a, m, x, y);
	if (g != 1)
		return 0;
	else
	{
		x = (x % m + m) % m;
		return x;
	}
}

int rhoPoll(int n, int b, int a)
{
	srand(time(nullptr));
	int x, c, d, x2, c2, d2;
	x2 = x = 1;//= rand() % (n - 1) + 1;
	c2 = c = 0;//= rand() % n;
	d2 = d = 0;//= rand() % n;
	int i = 1;
	while (i && i <= n * n)
	{
		switch (x % 3)	{
		case 2:
			x = x * x % n;
			c = c * 2 % (n - 1);
			d = d * 2 % (n - 1);
			break;
		case 1:
			x = x * b % n;
			d = (d + 1) % (n - 1);
			break;
		case 0:
			x = x * a % n;
			c = (c + 1) % (n - 1);
			break;
		default: break;
		}
		switch (x2 % 3)	{
		case 2:
			x2 = x2 * x2 % n;
			c2 = c2 * 2 % (n - 1);
			d2 = d2 * 2 % (n - 1);
			break;
		case 1:
			x2 = x2 * b % n;
			d2 = (d2 + 1) % (n - 1);
			break;
		case 0:
			x2 = x2 * a % n;
			c2 = (c2 + 1) % (n - 1);
			break;
		default: break;
		}
		switch (x2 % 3)	{
		case 2:
			x2 = x2 * x2 % n;
			c2 = c2 * 2 % (n - 1);
			d2 = d2 * 2 % (n - 1);
			break;
		case 1:
			x2 = x2 * b % n;
			d2 = (d2 + 1) % (n - 1);
			break;
		case 0:
			x2 = x2 * a % n;
			c2 = (c2 + 1) % (n - 1);
			break;
		default: break;
		}
		if (x == x2)
		{
			int ans = 0;
			int g = gcd(abs(c - c2), n - 1);
			if (g == 1)
			{
				int rev = revMod(d2 - d, n - 1);
				ans = (c - c2) * rev % (n - 1);
				if (ans < 0) ans = (n - 1) + ans;
				return ans;
			}

			if ((d2 - d) % g == 0)
			{
				int rev = revMod((d2 - d) / g, (n - 1) / g);
				ans = ((c - c2) / g) * rev % (n - 1);
			}
			if (ans < 0) ans = (n - 1) - ans;
			for (int i = 1; i < g; i++)
			{
				if (powmod(a, ans, n) == b)
					return ans;
				ans += (n - 1) / g;
			}
		}
		i++;
	}
	return -1;
}
