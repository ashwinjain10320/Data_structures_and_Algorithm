#include<bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0) return 0;
        map<char,int> m;
        int i=0,j=1;
        int maxs=0;
        m[s[0]]++;
        int count=1;
        while(j<n)
        {
            if(count==j-i)
            {
                maxs=max(maxs,j-i);
                m[s[j]]++;
                if(m[s[j]]==1) count++;
                j++;
            }
            else
            {
                m[s[i]]--;
                if(m[s[i]]==0) count--;
                i++;
            }
        }
        if(count==j-i) maxs=max(maxs,j-i);
        return maxs;
    }
