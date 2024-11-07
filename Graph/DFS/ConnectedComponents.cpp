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
 
bool cycle;
 
void dfs(int vertex,int par,vector<bool>&vis,set<ll>graph[])
{
	vis[vertex]=true;
	for(int child:graph[vertex]){
		if(vis[child]) {
			continue;
		}
		dfs(child,vertex,vis,graph);
	}
}
 
int main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    int t;cin>>t;
    while(t--){
 
    	int n;cin>>n;
    	int cc=0;
 
    	vector<bool>vis(n+50,0);
    	set<ll>graph[n+50];
 
    	for(int u=1;u<=n;u++){
    		int v;cin>>v;
    		graph[u].insert(v);
    		graph[v].insert(u);
    	}
 
    	for(int i=1;i<=n;i++){
    		if(vis[i]) continue;
    		cc++;
    		dfs(i,0,vis,graph);
    	}

    	cout<<cc<<endl;
 
    }
 
 
    return 0;
}