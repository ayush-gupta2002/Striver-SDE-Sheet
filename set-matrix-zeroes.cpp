//BRUTE FORCE

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> ans = matrix;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<matrix[i][j]<<" ";
                if(matrix[i][j] == 0){
                    for(int k=0;k<n;k++){
                        ans[k][j] = 0;
                    }
                    for(int l=0;l<m;l++){
                        ans[i][l] = 0;
                    }
                }
            }cout<<endl;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                matrix[i][j] = ans[i][j];
            }
        }
    }
};

//BETTER 

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> rows(n,1),cols(m,1);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 0){
                    rows[i] = 0;
                    cols[j] = 0;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(rows[i] == 0 || cols[j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

    }
};

//OPTIMAL

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();
        
        int zerothCol = 1;

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    if(j == 0){
                        zerothCol = 0;
                    }
                    else{
                        matrix[0][j] = 0;
                    }
                }
            }
        }

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=1;j--){
                if(matrix[i][j] != 0){
                    if(matrix[i][0] == 0 || matrix[0][j] == 0){
                        matrix[i][j] = 0;
                    }
                }

            }
        }
        if(zerothCol == 0){
            for(int i=0;i<n;i++){
                matrix[i][0] = 0;
            }
        }

    }
};
