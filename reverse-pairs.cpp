#include <bits/stdc++.h>
using namespace std;


   int merge(vector<int>&nums,int l,int r,int mid){
        vector<int> temp;
        int pnt1 = l;
        int pnt2 = mid+1;
        int cnt = 0;
        int j = l;

        for(int i=mid+1;i<=r;i++){
            while(nums[j] <= (long long)2*nums[i] && j<=mid){
                j++;
            }
            if(j != mid+1){
                cnt += (mid - j + 1);
            }
        }

        // for(int i=l;i<=mid;i++){
        //     cout<<nums[i]<<" ";
        // }cout<<endl;
        // for(int i=mid+1;i<=r;i++){
        //     cout<<nums[i]<<" ";
        // }cout<<endl;
        // cout<<endl;

        while(pnt1<=mid && pnt2<=r){
            if(nums[pnt1] <= nums[pnt2]){
                temp.push_back(nums[pnt1]);
                pnt1++;
            }
            else{
                temp.push_back(nums[pnt2]);
                pnt2++;
            }
        }
        while(pnt1 <= mid){
            temp.push_back(nums[pnt1]);
            pnt1++;
        }
        while(pnt2 <= r){
            temp.push_back(nums[pnt2]);
            pnt2++;
        }

        for(int i=l;i<=r;i++){
            nums[i] = temp[i-l];
        }
        return cnt;
    }

	   void mergeSort(vector<int>&nums,int l,int r,int& ans){
        if(l>=r){
            return;
        }

        int mid = (l+r)/2;

        mergeSort(nums,l,mid,ans);
        mergeSort(nums,mid+1,r,ans);
        ans += merge(nums,l,r,mid);
    }
int reversePairs(vector<int> &nums, int n){
	       int ans = 0;
        mergeSort(nums,0,n-1,ans);
        return ans;	
}
