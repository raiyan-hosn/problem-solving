// http://lightoj.com/volume_showproblem.php?problem=1309

#include<bits/stdc++.h>
using namespace std;
string operation(string &s,int l,int r,int p,char op)
{
    string a,b;
    for(int i=l+1;i<p;i++)
        a+=s[i];
    for(int i=p+1;i<r;i++)
        b+=s[i];
    bool xExist=false;
    if(a.back()=='x'){
        a.pop_back();
        xExist=true;
    }
    else if(b.back()=='x'){
        b.pop_back();
        xExist=true;
    }
    int x;
    if(op=='*')
        x=stoi(a)*stoi(b);
    else if(op=='+')
        x=stoi(a)+stoi(b);
    else
        x=stoi(a)-stoi(b);
    if(xExist)
        return to_string(x)+"x";
    return to_string(x);

}

int main(void)
{

    int tc;
    for(int t=1;t<=tc;t++){
        string eq;
        cin>>eq;

    }
}
