#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n; 						// size of array
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i]; // input array
	int k;
	cin>>k; 						// window size (size of subarray given)
	int j,cs=0;
	for(j=0;j<k;j++) cs+=a[j]; 		// finding sum of 1st subarray/window
	int maxs=cs; 					// saving maximum result
	for(;j<n;j++)
	{
		cs=(cs-a[j-k])+a[j]; 		// moving (sliding) window by removing prev cell ans adding new cell
		maxs=max(maxs,cs); 			// updating maximum result
	}
}