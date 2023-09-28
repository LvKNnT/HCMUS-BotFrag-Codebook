#include <bits/stdc++.h>
using namespace std;

//divide and conquer
const long long INF = 1e18;
const int MAXN = 3e3 + 5;
const int MAXM = 3e3 + 5;
int n;
long long f[MAXN][MAXM];
long long c[MAXN][MAXM];
long long sum[MAXN];

long long Cost(int i, int j) {
    if (i > j)
        return 0;
    long long ans = sum[j] - sum[i - 1];
    return ans * ans;
}

void divide(int i, int L, int R, int optL, int optR) {
    if (L > R)
        return;
    int mid = (L + R) / 2, cut = optL;
    f[i][mid] = INF;
    for (int k = optL; k <= min(mid, optR); k++) {
        long long cur = f[i - 1][k] + Cost(k + 1, mid);
        if (f[i][mid] > cur) {
            f[i][mid] = cur;
            cut = k;
        }
    }
    divide(i, L, mid - 1, optL, cut);
    divide(i, mid + 1, R, cut, optR);
}

void solve() {
    long long n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> sum[i];
    for (int i = 1; i <= n; i++)
        sum[i] += sum[i - 1];
    for (int i = 1; i <= n; i++)
        f[1][i] = Cost(1, i);
    for (int i = 2; i <= k; i++) {
        divide(i, 1, n, 1, n);
    }
    cout << f[k][n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}