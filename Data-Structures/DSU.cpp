#include<bits/stdc++.h>
using namespace std;
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
}
