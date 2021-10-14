#include<bits/stdc++.h>
using namespace std;
string minWindow(string s, string t) {
        if(s==t) return s;
        if(s.size()<t.size()) return "";
        int beg=0;
        int i=0,j=0;
        map<char,int> m;
        for(int k=0;k<t.size();k++) m[t[k]]++;
        int count=m.size();
        int size=INT_MAX;
        while(j<=s.size())
        {
            if(m.find(s[i])==m.end() || m[s[i]]<0)
            {
                if(m.find(s[i])!=m.end()) 
                {
                    m[s[i]]++;
                }
                i++;
            }
            if(count<=0)
            {
                if((j-i)<size)
                {
                    size=j-i;
                    beg=i;
                }
                if(m.find(s[i])!=m.end())
                {
                    m[s[i]]++;
                    if(m[s[i]]==1) count++;
                }
                i++;
                
            }
            else
            {
                if(j<s.size() && m.find(s[j])!=m.end())
                {
                    m[s[j]]--;
                    if(m[s[j]]==0) count--;
                }
                j++;
            }
        }
        string ans="";
        if(size==INT_MAX) return ans;
        for(int k=0;k<size;k++)
        {
            ans+=s[beg++];
        }
        return ans;
    }