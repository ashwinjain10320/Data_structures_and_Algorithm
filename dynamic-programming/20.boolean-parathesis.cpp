#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int> m;
int bolparadp(string s,int i,int j,bool istrue)
{
    if(i>j) return 0;
    if(i==j)
    {
        if(istrue==true)
        {
            return s[i]=='T';
        }
        else
        {
            return s[i]=='F';
        }
    }
    string key=to_string(i)+" "+to_string(j)+" "+to_string(istrue);
    if(m.find(key)!=m.end()) return m[key];
    int ans=0;
    for(int k=i+1;k<j;k+=2)
    {
        int lt=bolparadp(s,i,k-1,true);
        int rt=bolparadp(s,k+1,j,true);
        int lf=bolparadp(s,i,k-1,false);
        int rf=bolparadp(s,k+1,j,false);

        if(s[k]=='&')
        {
            if(istrue) ans+=(lt*rt);
            else ans+=(lf*rf + lf*rt + lt*rf);
        }
        else if(s[k]=='|')
        {
            if(istrue) ans+=(lf*rt + lt*rf + lt*rt);
            else ans+=(lf*rf);
        }
        else if(s[k]=='^')
        {
            if(istrue) ans+=(lf*rt + lt*rf);
            else ans+=(lf*rf + lt*rt);
        }
    }
    return m[key]=ans;
}

int bolpararec(string s,int i,int j,bool istrue)
{
    if(i>j) return 0;
    if(i==j)
    {
        if(istrue==true)
        {
            return s[i]=='T';
        }
        else
        {
            return s[i]=='F';
        }
    }
    int ans=0;
    for(int k=i+1;k<j;k+=2)
    {
        int lt=bolpararec(s,i,k-1,true);
        int rt=bolpararec(s,k+1,j,true);
        int lf=bolpararec(s,i,k-1,false);
        int rf=bolpararec(s,k+1,j,false);

        if(s[k]=='&')
        {
            if(istrue) ans+=(lt*rt);
            else ans+=(lf*rf + lf*rt + lt*rf);
        }
        else if(s[k]=='|')
        {
            if(istrue) ans+=(lf*rt + lt*rf + lt*rt);
            else ans+=(lf*rf);
        }
        else if(s[k]=='^')
        {
            if(istrue) ans+=(lf*rt + lt*rf);
            else ans+=(lf*rf + lt*rt);
        }
    }
    return ans;
}

int main()
{
    string s="T&F|T^T^F^F&T|F|T";
    cout<<bolparadp(s,0,s.size()-1,true);
    return 0;
}