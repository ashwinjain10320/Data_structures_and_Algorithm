#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n,k;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	cin>>k;
	int j=0;
    queue<int> q;
    while(j<k-1)
    {
        if(a[j]<0) q.push(j);
        j++;
    }
    vector<int> res;
    for(j=k-1;j<n;j++)
    {
        if(q.front()==j-k) q.pop();
        if(a[j]<0) q.push(j);
        if(q.empty()) res.push_back(0);
        else res.push_back(a[q.front()]);
    }
    for(int i=0;i<res.size();i++)
    {
    	cout<<res[i]<<" ";
    }
}
