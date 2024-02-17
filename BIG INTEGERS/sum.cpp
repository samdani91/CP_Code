#include<bits/stdc++.h>
using namespace std;


/* Positive Values Only */


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

string addBig(string a,string b){

	//swap
	if(a.size()>b.size()){
		swap(a,b);
	}

	//reverse
	reverse(all(a));
	reverse(all(b));

	//add
	string output="";
	int carry=0;

	for(int i=0;i<a.size();i++){
		int d1=a[i]-'0';
		int d2=b[i]-'0';
		int dSum=d1+d2+carry;
		output.push_back((dSum%10)+'0');
		carry=dSum/10;
	}

	for(int i=a.size();i<b.size();i++){
		int d=b[i]-'0';
		int dSum=d+carry;
		output.push_back((dSum%10)+'0');
		carry=dSum/10;
	}

	if(carry>0){
		output.push_back(carry+'0');
	}

	reverse(all(output));

	return output;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    string a,b;
    cin>>a>>b;

    string res=addBig(a,b);

    cout<<res<<endl;

	return 0;
}