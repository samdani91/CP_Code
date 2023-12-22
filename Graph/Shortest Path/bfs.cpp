/*			CSES--Message Route			*/
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
vector<bool>vis;

void bfs(int source)
{
	queue<int>q;
	q.push(source);
	vis[source]=true;

	while(!q.empty()){
		int curr_v=q.front();
		q.pop();
		for(int child:graph[curr_v]){
			if(!vis[child]){
				q.push(child);
				vis[child]=true;
				parent[child]=curr_v;
			}
		}
	}
}

int main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    int n,m;
    cin>>n>>m;

    vis.assign(n+10,false);
    parent.assign(n+10,-1);


    for(int i=1;i<=m;i++){
    	int u,v;
    	cin>>u>>v;
    	graph[u].push_back(v);
    	graph[v].push_back(u);
    }

    bfs(1);
    if(!vis[n]) cout<<"IMPOSSIBLE";
    else{
    	vector<int>ans;

    	for(int v=n;v!=1;v=parent[v]){
    		ans.push_back(v);
    	}
    	ans.push_back(1);

    	cout<<ans.size()<<endl;
    	for(int i=ans.size()-1;i>=0;i--) cout<<ans[i]<<" ";
    }

 
    return 0;
}