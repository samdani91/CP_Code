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

const int M=1e9+7;

ll binExpRec(int a,int b)
{
    if(b==0) return 1;
    ll res=binExpRec(a,b/2);
    if(b&1) return ( a * ((res * res)%M)) %M;
    else return (res * res)%M;
}

ll binExpItr(ll a,ll b)
{   
    //iterativr > recirsive
    ll ans=1;
    while(b){
        if(b&1){
            ans = (ans * a)%M;
        }
        a= (a*a)%M;
        b>>=1;
    }
    return ans;
}

int main()
{

    int a,b;
    cin>>a>>b;

    cout<<binExpRec(a,b)<<endl;
    cout<<binExpItr(a,b)<<endl;


    return 0;
}