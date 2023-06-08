#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& arr,int n,int target,vector<int>& temp,vector<vector<int>>& ans,int currSum,int curri){
    if(currSum == target){
        ans.push_back(temp);
        return;
    }
    else if(currSum > target){
        return;
    }

    for(int i=curri;i<n;i++){
        if(i != curri && arr[i-1] == arr[i]){
            continue;
        }

        temp.push_back(arr[i]);
        currSum += arr[i];
        solve(arr,n,target,temp,ans,currSum,i+1);
        temp.pop_back();
        currSum -= arr[i];
    }
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    vector<int> temp;
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());

    solve(arr,n,target,temp,ans,0,0);
    return ans;	
}
