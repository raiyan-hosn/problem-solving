#include<bits/stdc++.h>
using namespace std;
map<char,int>m;
string arr="IVXLCDM";
int repeateN(char c,int n,string &s)
{

    int k=0,cnt=0;
    while(cnt<3){
        if(k+m[c]>n)break;
        s+=c;
        k+=m[c];
        cnt++;
    }
//    printf("for %d cnt=%d\n",n,cnt);
//    int x;
//    cin>>x;
    return cnt;
}
string cnvrtToRoman(int n)
{
    string s;
    if(n==0)
        return s;

    char k;
    for(int i=0;i<arr.size();i++){
        if(m[arr[i]]>n)
            break;
        k=arr[i];
    }
    if(k=='I'){
        if(n==4){
            s+=("IV");
            n-=4;
        }
        else{
            n-=repeateN('I',n,s);
        }
    }
    else if(k=='V'){
        if(n==9){
            s+=("IX");
            n-=9;
        }
        else{
            s+="V";
            n-=5;
        }
    }
    else if(k=='X'){
        if(n>=40){
            s+="XL";
            n-=40;
        }
        else{
            n-=10*repeateN('X',n,s);

        }
    }
    else if(k=='L'){
            if(n>=90){
                s+="XC";
                n-=90;
            }
            else{
                s+='L';
                n-=50;
            }
    }
    else if(k=='C'){
        if(n>=400){
            s+="CD";
            n-=400;
        }
        else{
            n-=100*repeateN('C',n,s);
        }
    }
    else if(k=='D'){
        if(n>=900){
            s+="CM";
            n-=900;
        }
        else{
            s+="D";
            n-=500;
        }
    }
    else{
        n-=1000*repeateN('M',n,s);
    }
    return s+cnvrtToRoman(n);
}
int cnvrToInt(string s){
    int n=0;
    int l=s.size();
    if(l==1)return m[s[0]];
    bool b=true;
    for(int i=1;i<l;i++){
        if(m[s[i]]>m[s[i-1]]){
            n+=(m[s[i]]-m[s[i-1]]);
            i++;
        }
        else{
            n+=m[s[i-1]];

        }
    }
    if(m[s[l-1]]<=m[s[l-2]]){
        n+=m[s[l-1]];
    }
    return n;
}
int main(void)
{
    m['I']=1;m['V']=5;m['X']=10;m['L']=50;m['C']=100;m['D']=500;m['M']=1000;
    string str;
//    freopen("i.txt","r",stdin);
//    freopen("o.txt","w",stdout);

    while(cin>>str){
        if(str[0]>='0'&&str[0]<='9'){
            int n=stoi(str);
            cout<<cnvrtToRoman(n)<<endl;
        }
        else{
            cout<<cnvrToInt(str)<<endl;
        }
    }
}
