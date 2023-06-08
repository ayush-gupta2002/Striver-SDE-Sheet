class Solution {
public:

    void solve(vector<vector<int>>& ans,vector<int>& candidates,int target,int n,int currSum,int curri,vector<int>& temp){
        if(currSum == target){
            ans.push_back(temp);
            return;
        }
        else if(currSum > target){
            return;
        }
        if(curri == n){
            if(currSum == target){
                ans.push_back(temp);
            }
            return;
        }

        //PICK THE ELEMENT AND DO NOT MOVE FORWARD
        currSum += candidates[curri];
        temp.push_back(candidates[curri]);
        solve(ans,candidates,target,n,currSum,curri,temp);

        //DO NOT PICK THE ELEMENT
        currSum -= candidates[curri];
        temp.pop_back();
        solve(ans,candidates,target,n,currSum,curri+1,temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = candidates.size();

        solve(ans,candidates,target,n,0,0,temp);
        return ans;
    }
};
