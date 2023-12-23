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

void method1(ll n);
void method2(ll n);

vll prime_factors;

int main()
{
    
    ll n;
    cin>>n;
    method1(n);
    // method2(n);
    
    for(int prime:prime_factors){
        cout<<prime<<" ";
    }
    cout<<endl;
    
    return 0;
}
void method1(ll n)
{   
    //O(n)
    
    for(int i=2;i<=n;i++){
        while(n%i==0){
            prime_factors.push_back(i);
            n/=i;
        }
    }
    
}
void method2(ll n)
{   
    //O(sqrt(n))
    
    for(int i=2;i<=sqrt(n);i++){
        while(n%i==0){
            prime_factors.push_back(i);
            n/=i;
        }
    }
    if(n>1){
        prime_factors.push_back(n);
    }
    
}