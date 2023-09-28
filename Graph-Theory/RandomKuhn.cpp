#include <bits/stdc++.h>
using namespace std;

//rng
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
//blossom ko trong so
const int N = 1e4 + 5;
const int M = 1e5 + 5;
array<int, 3> edge[M];
vector<int> a[N];
bool f[N], ml[N];
int mr[N];
bool dfs(int u) {
    f[u] = true;
    for(auto i : a[u]) {
        if (f[mr[i]])
            continue;
        if (!mr[i] || dfs(mr[i]))
        {
            mr[i] = u;
            return true;
        }
    }
    return false;
}
int max_matching(int n)
{
    int cnt = 0;
    for(int i=1;i<=n;++i) shuffle(a[i].begin(), a[i].end(), default_random_engine(seed));
    for(int i=1;i<=n;++i)
    {
        for(auto j : a[i])
        {
            if (!mr[j])
            {
                mr[j] = i;
                ml[i] = true;
                ++cnt;
                break;
            }
        }
    }
    for (bool run = 1; run;)
    {
        for(int i=1;i<=n;++i) f[i] = false;
        run = 0;
        for(int i=1;i<=n;++i)
        {
            if (ml[i])
                continue;
            if (dfs(i))
                ml[i] = true, ++cnt, run = 1;
        }
    }
    return cnt;
}
