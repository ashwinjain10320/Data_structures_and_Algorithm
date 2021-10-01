#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int k;
    cin>>k;
    map<char,int> mp;
    int c=k-1;
    int i=0,j=1;
    mp[s[i]]=1;
    int ans=0;
    while(j<s.size())
    {
        if(c>0)
        {
            mp[s[j]]++;
            if(mp[s[j]]==1) c--;
            j++;
        }
        else
        {
            if(c==0) ans=max(ans,j-i);
            mp[s[i]]--;
            if(mp[s[i]]==0) c++;
            i++;
        }
    }
    ans=max(ans,j-i);
    cout<<ans<<endl;
}