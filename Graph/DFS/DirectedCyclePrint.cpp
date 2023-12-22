/* 					CSES--Round Trip II				*/
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

vector<int>graph[N];
vector<int>parent;
vector<int>color;
int cycleStart,cycleEnd;


bool dfs(int v)
{
	color[v]=1;
	for(int u:graph[v]){
		if(color[u]==0){
			parent[u]=v;
			if(dfs(u)) return true;
		}else if(color[u]==1){
			cycleStart=u;
			cycleEnd=v;
			return true;
		}
	}
	color[v]=2;
	return false;
}
int main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    
    int n,m;
    cin>>n>>m;

    color.assign(n+10,0);
    parent.assign(n+10,-1);
    cycleStart=-1;

    for(int i=1;i<=m;i++){
    	int u,v;
    	cin>>u>>v;
    	graph[u].push_back(v);
    }

    for(int i=1;i<=n;i++){
    	if(color[i]==0 and dfs(i)) break;
    }

    if(cycleStart==-1){
    	cout<<"IMPOSSIBLE";
    }else{
    	vector<int>cycle;

    	cycle.push_back(cycleStart);
    	for(int v=cycleEnd;v!=cycleStart;v=parent[v]){
    		cycle.push_back(v);
    	}
    	cycle.push_back(cycleStart);
    	reverse(cycle.begin(),cycle.end());

    	cout<<cycle.size()<<endl;
    	for(auto it:cycle) cout<<it<<" ";
    }
 
    return 0;
}