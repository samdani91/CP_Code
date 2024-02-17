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

const int N=1e5+10;
const int M=1e9+7;

void multiply(vector<int>&v,int no,int &size){
	int carry=0;
	for(int i=0;i<size;i++){
		int prod=v[i]*no+carry;
		v[i]=prod%10;
		carry=prod/10;
	}

	while(carry){
		v[size]=carry%10;
		carry/=10;
		size++;
	}
}

void bigFact(int n){
	vector<int>v(1000,0);
	v[0]=1;
	int size=1;

	for(int i=2;i<=n;i++){
		multiply(v,i,size);
	}

	for(int i=size-1;i>=0;i--) cout<<v[i];
	cout<<endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n;
    cin>>n;

    bigFact(n);

	return 0;
}