// C++ program to find the Nth Fibonacci
// number using Fast Doubling Method
#include<cstdio>
using namespace std;

long long a, b, c, d;
#define MOD 1000000007
int res[2] = { 0 };
// Function calculate the N-th fibonacci
// number using fast doubling method
void FastDoubling(long long n, int res[])
{
	// Base Condition
	if (n == 0) {
		res[0] = 0;
		res[1] = 1;
		return;
	}
	FastDoubling((n / 2), res);

	// Here a = F(n)
	a = res[0];

	// Here b = F(n+1)
	b = res[1];

	c =( 2% MOD * b% MOD)% MOD - a;

	if (c < 0)
		c += MOD;

	// As F(2n) = F(n)[2F(n+1) – F(n)]
	// Here c = F(2n)
	c = (a % MOD* c% MOD) % MOD;

	// As F(2n + 1) = F(n)^2 + F(n+1)^2
	// Here d = F(2n + 1)
	d = ((a % MOD* a% MOD)% MOD + (b % MOD* b% MOD)% MOD) % MOD;

	// Check if N is odd
	// or even
	if (n % 2 == 0) {
		res[0] = c;
		res[1] = d;
	}
	else {
		res[0] = d;
		res[1] = (c% MOD + d% MOD)% MOD;
	}
}

int main()
{
	long long N ;
    scanf("%lld",&N);
	FastDoubling(N, res);
    printf("%d\n",res[0]);
	return 0;
}
