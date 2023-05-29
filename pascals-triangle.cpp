class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> zeroth(1,1);
        vector<int> first(2,1);
        ans.push_back(zeroth);
        if(numRows == 1){
            return ans;
        }
        ans.push_back(first);

        for(int i=2;i<numRows;i++){
            vector<int> row(i+1);
            row[0] = 1;
            row[i] = 1;

            for(int j=1;j<i;j++){
                row[j] = ans[i-1][j-1] + ans[i-1][j];
            }
            ans.push_back(row);
        }
        return ans;
    }
};
