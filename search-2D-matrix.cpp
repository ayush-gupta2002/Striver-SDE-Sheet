//BRUTE

bool search(vector<vector<int>>& mat,int target){
  int n = mat.size();
  int m = mat[0].size();
  
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(mat[i][j] == target){
        return true;
      }
    }
  }
  return false;
}


//OPTIMAL

#include <iostream>
using namespace std;

bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n = mat.size();
    int m = mat[0].size();

    int lo = 0;
    int hi = n*m - 1;

    while(lo<=hi){
        int mid = lo + (hi-lo)/2;

        int current = mat[mid/m][mid%m];

        if(target < current){
            hi = mid -1;
        }else if(target > current){
            lo = mid + 1;
        }else{
            return true;
        }
    }
    return false;
}
