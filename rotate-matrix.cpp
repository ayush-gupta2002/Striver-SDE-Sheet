//BRUTE FORCE

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0;i<m;i++){
            vector<int> row;
            for(int j=n-1;j>=0;j--){
                row.push_back(matrix[j][i]);
            }
            ans.push_back(row);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                matrix[i][j] = ans[i][j];
            }
        }
    }
};

//OPTIMAL APPROACH

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();


        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
