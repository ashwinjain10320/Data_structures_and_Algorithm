#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,sum;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    cin>>sum;
    int i=0,j=1,currsum=a[i];
    int maxsize=0;
    while(j<n)
    {
        if(currsum<sum)
        {
            currsum+=a[j++];
        }
        else
        {
            if(currsum==sum) maxsize=max(maxsize,j-i);
            currsum-=a[i++];
        }
    }
    if(currsum==sum) maxsize=max(maxsize,j-i);
    cout<<maxsize<<endl;
}
