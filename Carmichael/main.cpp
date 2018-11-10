#include <iostream>
#include <vector>

using namespace std;


long bound = 1000000;
vector<long> results;

long gcd(long a, long b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

long modularExponent(long n, long power, long m) {
	vector<long> factors;
	bool powers[32];
	int maxim = -1;

	long temp = power;

	int cnt = 0;
	while (temp != 0)
	{
		int bit = temp & 1;
		if (bit == 1) {
			powers[cnt] = true;
			maxim = cnt;
		}
		else
			powers[cnt] = false;
		temp = temp >> 1;
		cnt++;
	}

	long long current = -1;
	for (int i = 0; i <= maxim; ++i)
	{
		if (i == 0)
			current = n % m;
		else
			current = (current % m) * (current % m) % m;

		if (powers[i])
			factors.push_back(current);
	}

	long long res = 1;

	for (long i : factors)
	{
		res = (res * i) % m;
	}

	return res;
}



bool relativelyPrime(long a, long b)
{
	if (gcd(a, b) == 1)
		return true;
	return false;
}

bool isPrime(long n)
{
	if (n <= 1)
		return false;
	else if (n <= 3)
		return true;
	else if (n % 2 == 0 || n % 3 == 0)
		return false;
	long i = 5;
	while (i * i <= n)
	{
		if (n % i == 0 || n % (i + 2) == 0)
			return false;
		i = i + 6;
	}
	return true;
}
bool isCarmichael(long a)
{
	for (int b = 1; b < a; ++b)
	{
		if (!relativelyPrime(a, b))
			continue;
		if (modularExponent(b, a - 1, a) != 1)
			return false;
	}
	return true;
}



int main()
{
	
	
	
	
	for (long i = 2; i < bound; ++i)
	{
		if (isPrime(i))
			continue;
		if (isCarmichael(i))
			results.push_back(i);
	}
	
	//cout << isCarmichael(46657);
	//cout << modularExponent(351, 10, 123);

	for (long i : results)
		cout << i << ' ';

	getchar();
	return 0;
}