class Solution {
public:

    void solve(vector<int>& temp,vector<vector<int>>& ans,int curri){
        if(curri == temp.size()){
            ans.push_back(temp);
            return;
        }

            for(int i=curri;i<temp.size();i++){
                swap(temp[i],temp[curri]);
                solve(temp,ans,curri+1);
                swap(temp[i],temp[curri]);
            }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        temp = nums;
        vector<vector<int>> ans;
        solve(temp,ans,0);
        return ans;
    }
};
