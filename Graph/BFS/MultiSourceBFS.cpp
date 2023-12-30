/*					CSES--Monsters					*/
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
 
const int N=1e3+10;
const int M=1e9+7;

int n,m;

vector<vector<int>>g(N,vector<int>(N,M));
pair<int,int>si,se;
map<pair<int,int>,pair<int,int>>par_mp;
vector<pair<int,int>>monsters;
vector<pair<int,int>> moves = {{-1,0}, {1,0}, {0,-1}, {0,1}};

bool isValid(int i,int j,int timer)
{
	if(i<1 or i>n or j<1 or j>m) return false;
	if(g[i][j]<=timer) return false;
	return true;
}

bool isEscape(int i,int j,int timer)
{
	if(!isValid(i,j,timer)) return false;
	if(i==1 or j==1 or i==n or j==m) return true;
	return false;
}

void preprocess_lava_flow()
{
	queue<pair<pair<int,int>,int>>q;
	for(auto it:monsters){
		q.push({it,0});
	}

	while(!q.empty()){
		int currX=q.front().first.first;
		int currY=q.front().first.second;
		int timer=q.front().second;
		timer++;
		q.pop();

		for(auto it:moves){
			int moveX=it.first+currX;
			int moveY=it.second+currY;

			if(isValid(moveX,moveY,timer)){
				g[moveX][moveY] = timer;
        		q.push({{moveX,moveY},timer});
			}
		}
	}
}

bool multi_bfs()
{	
	queue<pair<pair<int,int>,int>>q;

	q.push({si,0});
	par_mp[si]={-1,-1};

	while(!q.empty()){
		int currX=q.front().first.first;
		int currY=q.front().first.second;
		int timer=q.front().second;
		timer++;
		q.pop();

		for(auto it:moves){
			int moveX=it.first+currX;
			int moveY=it.second+currY;

			if(isEscape(moveX,moveY,timer)){
				par_mp[{moveX,moveY}]={currX,currY};
				se={moveX,moveY};
				return true;
			}

			if(isValid(moveX,moveY,timer)){
				par_mp[{moveX,moveY}]={currX,currY};
				g[moveX][moveY]=timer;
				q.push({{moveX,moveY},timer});
			}
		}
	}

	return false;

}

int main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    cin>>n>>m;

    for(int i=1;i<=n;i++){
    	string line;
    	cin>>line;
    	for(int j=0;j<m;j++){
    		if(line[j]=='#') {
    			g[i][j+1]=0;
    		}
    		else if(line[j]=='A'){
    			g[i][j+1]=0;
				si={i,j+1};
    		}
    		else if(line[j]=='M') {
    			g[i][j+1]=0;
				monsters.push_back({i,j+1});
    		}	
    		
    	}
    }

    if(si.first==1 or si.second==1 or si.first==n or si.second==m){
    	cout<<"YES\n";
    	cout<<0;
    	return 0;
    }
    
    preprocess_lava_flow();

    if(!multi_bfs()) cout<<"NO";
    else{
    	vector<pair<int,int>>path_ans;
    	pair<int,int>end=se;
    	pair<int,int>temp=par_mp[se];
    	pair<int,int>finish={-1,-1};

    	while(temp!=finish){
    		path_ans.push_back({(end.first-temp.first),(end.second-temp.second)});
    		end=par_mp[end];
    		temp=par_mp[temp];
    	}
    	reverse(path_ans.begin(),path_ans.end());
    	cout<<"YES\n";
    	cout<<path_ans.size()<<endl;

    	for(auto it:path_ans){
    		if(it.first==1 and it.second==0) cout<<"D";
    		else if(it.first==-1 and it.second==0) cout<<"U";
    		else if(it.first==0 and it.second==1) cout<<"R";
    		else if(it.first==0 and it.second==-1) cout<<"L";
    	}
    }
    
    return 0;
}