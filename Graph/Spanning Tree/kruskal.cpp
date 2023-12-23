#include<bits/stdc++.h>
using namespace std;
 
typedef  long long int          ll;
typedef  long double            ld;
typedef  string                 str;
typedef  vector<ll>             vll;
typedef  vector<string>         vs;
typedef  vector<pair<ll, ll>>   vpl;
typedef  set<ll>                sll;
typedef  map<ll,ll>             mll;
typedef  pair<int,int>          pint;
typedef  pair<ll,ll>            pll;
double   pi = acos(-1.0);
#define  debug(x)              cerr<<#x<< <<x<<endl;
#define  loop                   for(ll i=1; i<=n; i++)
#define  all(a)                 (a).begin(), (a).end()
#define  min3(a,b,c)            min(a,min(b,c))
#define  max3(a,b,c)            max(a,max(b,c))
#define  min4(a,b,c,d)          min(a,min(b,min(c,d)));
#define  max4(a,b,c,d)          max(a,max(b,max(c,d)));
#define  endl					"\n"
 
const int N=1e5+10;
const int M=1e9+7;

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

    vector<pair<int,pair<int,int>>>edges; //{w,{u,v}}

    while(e--){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,{u,v}});
    }
    
    sort(edges.begin(),edges.end());

    for(int i=1;i<=n;i++) make(i);

    int totalCost=0;
    for(auto &edge:edges){
        int w=edge.first;
        int u=edge.second.first;
        int v=edge.second.second;

        if(find(u)==find(v)) continue;
        Union(u,v);
        totalCost+=w;
        cout<<u<<" "<<v<<endl;
    }
    cout<<totalCost<<endl;
}