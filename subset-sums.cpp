#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& ans,int n,int curri,int currSum,vector<int>& nums){
    if(curri == n){
        ans.push_back(currSum);
        return;
    }

    currSum += nums[curri];
    solve(ans,n,curri+1,currSum,nums);
    currSum -= nums[curri];
    solve(ans,n,curri+1,currSum,nums);
}

vector<int> subsetSum(vector<int> &nums)
{
    vector<int> ans;
    int n = nums.size();
    solve(ans,n,0,0,nums);
    sort(ans.begin(),ans.end());

    return ans;
}
