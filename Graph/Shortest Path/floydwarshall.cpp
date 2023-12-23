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

const int N=100;
const int INF=INT32_MAX;

int dist[N][N];
int p[N][N];

int main()
{
    freopen("floydinput.txt","r",stdin);

    for(int i=1;i<N;i++){
        for(int j=1;j<N;j++){
            if(i==j) dist[i][j]=0;
            else dist[i][j]=INF;
        }
    }
    int v,e;
    cin>>v>>e;
    for(int i=1;i<=e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        dist[u][v]=w;

    }

    for(int k=1;k<=v;k++){
        for(int i=1;i<=v;i++){
            for(int j=1;j<=v;j++){
                if(dist[i][k]!=INF && dist[k][j]!=INF){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }

    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}