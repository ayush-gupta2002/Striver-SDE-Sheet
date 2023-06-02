#include <bits/stdc++.h>
using namespace std;


vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	int pnt1 = m-1;
	int pnt2 = n-1;
	int pnt3 = m+n-1;

	while(pnt1 >=0 && pnt2 >= 0){
		if(arr1[pnt1] >= arr2[pnt2]){
			arr1[pnt3] = arr1[pnt1];
			pnt1--;
			pnt3--;
		}else if(arr1[pnt1] < arr2[pnt2]){
			arr1[pnt3] = arr2[pnt2];
			pnt2--;
			pnt3--;
		}
		//else{
		// 	arr1[pnt3] = arr2[pnt2];
		// 	pnt3--;
		// 	pnt2--;
		// 	pnt1--;
		// }
	}

	while(pnt1 >= 0){
		arr1[pnt3] = arr1[pnt1];
		pnt3--;
		pnt1--;
	}
	while(pnt2 >= 0){
		arr1[pnt3] = arr2[pnt2];
		pnt2--;
		pnt3--;
	}

	return arr1;
}
