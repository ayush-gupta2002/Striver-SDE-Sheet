//BRUTE

#include <bits/stdc++.h> 
using namespace std;
long long getInversions(long long *arr, int n){

    long long ans = 0;

    for(int i = 0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] > arr[j]){
                ans++;
            }
        }
    }
    return ans;

}

//OPTIMAL

#include <bits/stdc++.h> 
using namespace std;

long long merge(long long *arr,int l,int r,int mid){
    long long cnt = 0;

    vector<long long> temp;

    int pnt1 = l;
    int pnt2 = mid+1;

    while(pnt1 <= mid && pnt2 <= r){
        if(arr[pnt1] <= arr[pnt2]){
            temp.push_back(arr[pnt1]);
            pnt1++;
        }
        else{
            temp.push_back(arr[pnt2]);
            pnt2++;
            cnt = cnt + (mid - pnt1 + 1);
        }
    }

    while(pnt1 <= mid){
        temp.push_back(arr[pnt1]);
        pnt1++;
    }
    while(pnt2 <= r){
        temp.push_back(arr[pnt2]);
        pnt2++;
    }

    for(int i=l;i<=r;i++){
        arr[i] = temp[i-l];
    }

    return cnt;
}

void mergeSort(long long *arr, int l, int r,long long& ans){
    if(l >= r){
        return;
    }

    int mid = (l+r)/2;

    mergeSort(arr,l,mid,ans);
    mergeSort(arr,mid+1,r,ans);
    ans += merge(arr,l,r,mid);
    
}

long long getInversions(long long *arr, int n){

    long long ans = 0;
    mergeSort(arr,0,n-1,ans);
    return ans;



}
