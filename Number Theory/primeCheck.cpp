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

void sqrtMethod(ll n);
void seive();
const int N=1e7+10;
vector<bool>is_prime(N,1);

int main()
{
    
    ll n;
    //cin>>n;
    //sqrtMethod(n);
    seive();

    return 0;
}
void sqrtMethod(ll n)
{   
    //checking prime -> O(sqrt(n))
    if(n==0 || n==1) {
        cout<<0<<endl;
        return;
    }
    bool is_prime=true;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            is_prime=false;
            break;
        }
    }
    cout<<is_prime<<endl;
}
void seive()
{   
    // O(nlog(logn))
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<N;i++){
        if(is_prime[i]==true){
            for(int j=2*i;j<N;j+=i){
                is_prime[j]=false;
            }
        }
    }
    for(int i=1;i<=N;i++){
        cout<<i<<"-> "<<is_prime[i]<<endl;;
    }
}