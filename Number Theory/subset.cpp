#include<bits/stdtr1c++.h>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    int n=nums.size();
    int subst_count= (1<<n);

    vector<vector<int>>subsets;

    for(int i=0;i<subst_count;i++){
        vector<int>subset;
        for(int j=0;j<n;j++){
            if((i & (1<<j))){
                subset.push_back(nums[j]);
            }
        }
        subsets.push_back(subset);
    }

    return subsets;
}


int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    auto all_subsets=subsets(v);
    for(auto it:all_subsets){
        for(auto it2:it){
            cout<<it2<<" ";
        }
        cout<<endl;
    }
}