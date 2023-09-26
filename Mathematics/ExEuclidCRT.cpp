#include <bits/stdc++.h>

using namespace std;

int inv(int a, int m) {
	int m0 = m, t, q;
	int x0 = 0, x1 = 1;

	if (m == 1)
		return 0;

	// Apply extended Euclid Algorithm DARK MAGIC
	while (a > 1) {
		q = a / m;
		t = m;
		m = a % m, a = t;
		t = x0;
		x0 = x1 - q * x0;
		x1 = t;
	}

	if (x1 < 0)
		x1 += m0;

	return x1;
}

// k is size of num[] and rem[]. Returns the smallest
// number x such that:
// x % num[0] = rem[0],
// ..................
// x % num[k-2] = rem[k-1]
int findMinX(vector<int> num, vector<int> rem, int k) {
	int prod = 1;
	for (int i = 0; i < k; i++)
		prod *= num[i];

	int result = 0;

	for (int i = 0; i < k; i++) {
		int pp = prod / num[i];
		result += rem[i] * inv(pp, num[i]) * pp;
	}

	return result % prod;
}

// Driver method
int main(void)
{
    vector<int> num,rem;
    //input num && rem;
	int k = sizeof(num) / sizeof(num[0]);
	cout << "x is " << findMinX(num, rem, k);
	return 0;
}
