class Solution {
public:

    bool isPalindrome(string s,int l,int r){
        while(l<=r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    void solve(vector<vector<string>>& ans,string s,int curri,vector<string>& temp){
        if(curri == s.size()){
            ans.push_back(temp);
            return;
        }

        string toPush = "";

        for(int i=curri;i<s.size();i++){
            toPush.push_back(s[i]);
            if(isPalindrome(s,curri,i)){
                temp.push_back(toPush);
                solve(ans,s,i+1,temp);
                temp.pop_back();
            }
        }

    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(ans,s,0,temp);
        return ans;
    }
};
