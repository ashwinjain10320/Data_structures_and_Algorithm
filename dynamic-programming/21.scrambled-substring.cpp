#include<bits/stdc++.h>
using namespace std;
unordered_map<string,bool> m;
bool scrambled(string a,string b)
{
    if(a.compare(b)==0) return true;
    if(a.size()<=1) return false;
    
    bool flag=false;
    int n=a.size();
    for(int i=1;i<n;i++)
    {
        if((scrambled(a.substr(0,i),b.substr(n-i,i)) && scrambled(a.substr(i,n-i),b.substr(0,n-i))) 
        || (scrambled(a.substr(0,i),b.substr(0,i)) && scrambled(a.substr(i,n-i),b.substr(i,n-i))))
        {
            flag=true;
            break;
        }
    }
    return flag;
}
bool scrambledop(string a,string b)
{
    if(a.compare(b)==0) return true;
    if(a.size()<=1) return false;
    string key=a+" "+b;
    if(m.find(key)!=m.end()) return m[key];
    bool flag=false;
    int n=a.size();
    for(int i=1;i<n;i++)
    {
        if((scrambledop(a.substr(0,i),b.substr(n-i,i)) && scrambledop(a.substr(i,n-i),b.substr(0,n-i))) 
        || (scrambledop(a.substr(0,i),b.substr(0,i)) && scrambledop(a.substr(i,n-i),b.substr(i,n-i))))
        {
            flag=true;
            break;
        }
    }
    return m[key]=flag;
}
int main()
{
    string a="great",b="ategr";
    cout<<(scrambledop(a,b)?"yes":"no")<<endl;
}