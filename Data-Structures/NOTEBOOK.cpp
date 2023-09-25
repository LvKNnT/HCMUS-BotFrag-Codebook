#include<bits/stdc++.h>
using namespace std;

struct Query{
    int l, r, c;
};

struct DSU{
    vector<int> parent;
    vector<int> size;
    vector<int> rank;
    DSU(int maxn){
        parent.assign(maxn,-1);
        size.assign(maxn,-1);
        rank.assign(maxn,-1);
    }
    void makeset(int v){
        parent[v] = v;
        size[v] = 1;
        rank[v] = 0;
    }
    int findset(int v){
        if(v == parent[v]){
            return v;
        }
        return findset(parent[v]);
    }
    void unionsizerank(int a, int b){
        a = findset(a);
        b = findset(b);
        if(a != b){
            if(rank[a] < rank[b]){
                swap(a,b);
            }
            else if(size[a] < size[b]){
                swap(a,b);
            }
        }
        parent[b] = a;
        if(rank[a] == rank[b]){
            rank[a]++;
        }
        size[a] += size[b];
    }
    void unionsize(int a, int b){
        a = findset(a);
        b = findset(b);
        if(a != b){
            if(size[a] < size[b]){
                swap(a,b);
            }
        }
        parent[b] = a;
        size[a] += size[b];
    }
    void unionrank(int a, int b){
        a = findset(a);
        b = findset(b);
        if(a != b){
            if(rank[a] < rank[b]){
                swap(a,b);
            }
        }
        parent[b] = a;
        if(rank[b] == rank[a]){
            rank[a]++;
        }
    }
    void pathcompression(int a, int b){
        a = findset(a);
        b = findset(b);
        if(a != b){
            parent[b] = a;
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<Query> query(q);
    vector<int> ans(n+1);
    for(int i = 0; i < q; i++){
        cin >> query[i].l >> query[i].r >> query[i].c;
    }
    DSU dsu(n+1);
    for(int i = 0; i <= n; i++){
        dsu.makeset(i);
    }
    for(int i = q-1; i >= 0; i--){
        int l = query[i].l; l--;
        int r = query[i].r; r--;
        int c = query[i].c;
        for(int v = dsu.findset(l); v <= r; v = dsu.findset(v)){
            ans[v] = c;
            dsu.parent[v] = v + 1;
        }
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << '\n';
    }
    return 0;
}