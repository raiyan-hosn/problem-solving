#include<bits/stdc++.h>
using namespace std;
void convertToLower(string &str){
    for(int i=0;i<str.length();i++){
        str[i]=tolower(str[i]);
    }   
}
int main(void)
{
    set<string>s;
    string str;
    while (cin>>str){
        convertToLower(str);
        string word="";
        for(int i=0;i<str.length();i++){
            if(str[i]>='a'&&str[i]<='z'){
                word+=str[i];
            }
            else if(word[0]!=0){
                s.insert(word);
                word="";
            } 
        }
        if(word[0]!=0)
            s.insert(word);
    }
    
    for(auto it=s.begin();it!=s.end();it++){
        cout<<*it<<endl;
    }
          
    
}