/*				CSES--Course Schedule				*/
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
#define  debug(x)              cerr<<#x<<" "<<x<<endl;
#define  loop                   for(ll i=1; i<=n; i++)
#define  all(a)                 (a).begin(), (a).end()
#define  min3(a,b,c)            min(a,min(b,c))
#define  max3(a,b,c)            max(a,max(b,c))
#define  min4(a,b,c,d)          min(a,min(b,min(c,d)));
#define  max4(a,b,c,d)          max(a,max(b,max(c,d)));
#define  endl					"\n"

const int N=2e5+10;
const int M=1e9+7;

vector<int>graph[N];
vector<int>indeg(N,0);
vector<int>color(N,0);

bool dfs(int v)
{
	color[v]=1;
	for(int u:graph[v]){
		if(color[u]==0){
			if(dfs(u)) return true;
		}else if(color[u]==1){
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

    int n,m;cin>>n>>m;
    int cnt=0;
    for(int i=0;i<m;i++){
    	int u,v;
    	cin>>u>>v;
    	graph[u].push_back(v);
    	indeg[v]++;
    }

    for(int i=1;i<=n;i++){
    	if(color[i]==0 and dfs(i)){
			// Here bfs check if it is DAG or not.
			// If there is a cycle in a directed graph, we can't dp topological sort
    		cout<<"IMPOSSIBLE";
    		return 0;
    	}
    }

    queue<int>q;
    for(int i=1;i<=n;i++){
    	if(indeg[i]==0){
    		q.push(i);
    	}
    }

    while(!q.empty()){
    	cnt++;
    	int x = q.front();
    	q.pop();
    	cout<<x<<" ";

    	for(auto it:graph[x]){
    		indeg[it]--;
    		if(indeg[it]==0) q.push(it);
    	}
    }

	return 0;
}