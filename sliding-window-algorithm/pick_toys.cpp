#include<bits/stdc++.h>
using namespace std;

// input: string of characters (a,b,c,...,z) denoting different types of toys
// output: maximum number of toys
// condition 1: max 2 types of toys
// condition 2: pick toys as per sequence in shell
int picktoys(string toys)
{
    int maxtoys=0;
    int j=0,i=0;
    int n=toys.size();
    int currcat = 2;
    map<char,int> m;
    while(j<n)
    {
        if(currcat>=0)
        {
            m[toys[j]]++;
            if(m[toys[j]]==1) currcat--;
            maxtoys=max(maxtoys,j-i);
            j++;
        }
        else
        {
            while(currcat<0)
            {
                m[toys[i]]--;
                if(m[toys[i]]==0) currcat++;
                i++;
            }
        }
    }
    if(currcat>=0) maxtoys=max(maxtoys,j-i);
    return maxtoys;
}
int main()
{
    string s;
    cin>>s;
    cout<<picktoys(s)<<endl;
}