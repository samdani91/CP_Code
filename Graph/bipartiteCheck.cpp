/*				CSES--Building Teams			*/
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

int n,m;
vector<int>graph[N];
vector<int>color;
vector<bool>vis(N,false);
bool isBipartite=true;

void bipartite()
{	
	queue<int>q;

	for(int i=1;i<=n;i++){
		if(color[i]==-1){
			q.push(i);
			color[i]=0;

			while(!q.empty()){
				int v=q.front();
				q.pop();

				for(int u:graph[v]){
					if(color[u]==-1){
						color[u]= color[v] xor 1;
						q.push(u);
					}else{
						isBipartite &= (color[u]!=color[v]);
					}
				}
			}
		}
	}

}

int main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    cin>>n>>m;
    color.assign(n+10,-1);

    for(int i=1;i<=m;i++){
    	int u,v;
    	cin>>u>>v;
    	graph[u].push_back(v);
    	graph[v].push_back(u);
    }

    bipartite();

    if(!isBipartite) cout<<"IMPOSSIBLE";
    else{
    	for(int i=1;i<=n;i++){
    		if(i==1){
    			cout<<1<<" ";
    			continue;
    		}
    		if(color[i]==color[1]) cout<<1<<" ";
    		else cout<<2<<" ";
    	}
    }

 
    return 0;
}