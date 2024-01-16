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

const int N=2*(1e5+10);
const int M=1e9+7;

ll arr[N],tree[4*N];

void build(ll node,ll start,ll end)
{
	if(start==end){
		tree[node]=arr[start];
		return;
	}

	ll mid=start+(end-start)/2;
	build(2*node,start,mid);
	build(2*node+1,mid+1,end);

	tree[node] = min(tree[2*node],tree[2*node+1]);

}

ll query(ll node,ll start,ll end, ll l,ll r)
{
	if(start>r or end<l) return LONG_LONG_MAX;
	if(l<=start and end<=r) return tree[node];

	ll mid=start+(end-start)/2;

	ll q1=query(2*node,start,mid,l,r);
	ll q2=query(2*node+1,mid+1,end,l,r);

	return min(q1,q2);
}

void update(ll node,ll start,ll end,ll idx,ll val)
{
	if(start==end){
		arr[start]=val;
		tree[node]=val;
		return;
	}

	ll mid=start+(end-start)/2;

	if(idx<=mid) update(2*node,start,mid,idx,val);
	else update(2*node+1,mid+1,end,idx,val);

	tree[node] = min(tree[2*node],tree[2*node+1]);


}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    ll n,q;cin>>n>>q;
    for(int i=0;i<n;i++) cin>>arr[i];

    build(1,0,n-1);


    while(q--){
    	ll t,a,b;
    	cin>>t>>a>>b;
    	if(t==2) cout<<query(1,0,n-1,a-1,b-1)<<endl;
    	else update(1,0,n-1,a-1,b);
    }

    

	return 0;
}