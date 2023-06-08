#include <bits/stdc++.h>
using namespace std;

void solve(int n,vector<int>& arr,vector<int>& ds,vector<vector<int>>& ans,int curri){
        ans.push_back(ds);

    for(int i = curri;i<n;i++){
        if(i > curri && arr[i-1] == arr[i]){
            continue;
        }

        //PICK THE ELEMENT
        ds.push_back(arr[i]);
        solve(n,arr,ds,ans,i+1);

        //DO NOT PICK THE ELEMENT
        ds.pop_back();
    }
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    sort(arr.begin(),arr.end());
    vector<int> ds;
    vector<vector<int>> ans;

    solve(n,arr,ds,ans,0);   
    sort(ans.begin(),ans.end());

    return ans;
}
