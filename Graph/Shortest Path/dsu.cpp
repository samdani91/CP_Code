#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int parent[N];

void make(int v){
    parent[v]=v;
}

int find(int v){
    if(v==parent[v]) return v;
    return find(parent[v]);
}
void Union(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        parent[b]=a;
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=1;i<=n;i++) make(i);

    while(e--){
        int u,v;
        cin>>u>>v;
        Union(u,v);

    }
    int cc=0;
    // for(int i=1;i<=n;i++){
    //     if(find[v]==v) cc++;
    // }
}