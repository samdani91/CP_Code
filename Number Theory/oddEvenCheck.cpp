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

void printBinary(int num){
    for(int i=7;i>=0;i--){
        cout<<((num>>i) & 1);
    }
    cout<<endl;
}

int main()
{

    //odd ->0th bit 1
    //even->0th bit 0
    for(int i=1;i<=10;i++){
        printBinary(i);
        if(i&1) cout<<"Odd"<<endl;
        else cout<<"Even"<<endl;
    }

    //divided by 2 -> n>>1
    //multiple of 2 -> n<<1

    // 'C' | ' ' -> c
    // 'c' & '_' -> C

    cout<< char('M' | ' ') <<endl;
    cout<< char('m' & '_') <<endl;


    return 0;
}