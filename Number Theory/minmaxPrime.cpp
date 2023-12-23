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

const int N=10000;

vector<bool>isPrime(N,1);
vector<int>hp(N,0),lp(N,0);

int main()
{
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i<N;i++){
        if(isPrime[i]){
            lp[i]=hp[i]=i;
            for(int j=2*i;j<N;j+=i){
                isPrime[j]=false;
                hp[j]=i;
                if(lp[j]==0){
                    lp[j]=i;
                }
            }
        }
    }

    int n;
    cin>>n;

    vector<int>prime_factors;
    while(n>1){
        int pf=hp[n];
        while(n%pf==0){
            n/=pf;
            prime_factors.push_back(pf);
        }
    }
    for(int i=0;i<prime_factors.size()-1;i++) cout<<prime_factors[i]<<"*";
    cout<<prime_factors[prime_factors.size()-1];

    return 0;
}