#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
    cin>>s;
    string ptr;
    cin>>ptr;
    int k=ptr.size();
    int j=0;
    map<int,int> m;
    int count=0;
    for(j=0;j<k;j++)
    {
        if(m.find(ptr[j])==m.end())
        {
            m[ptr[j]]=1;
            count++;
        }
        else
        {
            m[ptr[j]]++;
        }
    }
    j=0;
    while(j<k)
    {
        if(m.find(s[j])!=m.end())
        {
            m[s[j]]--;
            if(m[s[j]]==0)
            {
                count--;
            }
        }
        j++;
    }
    int i=0,ans=0;
    while(j<s.size())
    {
        if(count==0) ans++;
        if(m.find(s[i])!=m.end())
        {
            m[s[i]]++;
            if(m[s[i]]==1) count++;
        }
        if(m.find(s[j])!=m.end())
        {
            m[s[j]]--;
            if(m[s[j]]==0) count--;
        }
        i++;
        j++;
    }
    if(count==0) ans++;
    cout<<ans<<endl;
}