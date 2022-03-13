#include<bits/stdc++.h>
using namespace std;
vector<pair<string,int>>guid;
string ignor="AEIOUYWH";
bool isignorable(char c)
{
    for(int i=0;i<ignor.length();i++){
        if(ignor[i]==c)
            return true;
    }
    return false;
}
int findValue(char c)
{
    for(int i=0;i<guid.size();i++){
        for(int j=0;j<guid[i].first.length();j++){
            if(guid[i].first[j]==c)
                return guid[i].second;
        }
    }
    return -1;
}
bool isSamevalue(char a,char b)
{
    if(findValue(a)==findValue(b))
        return true;
    return false;
}
void print_space(int space)
{
    for(int i=0;i<space;i++)
        printf(" ");
}
int main(void)
{
//    freopen("i.txt","r",stdin);
//    freopen("o.txt","w",stdout);
    guid.push_back(make_pair("BPFV",1));
    guid.push_back(make_pair("CSKGJQXZ",2));
    guid.push_back(make_pair("DT",3));
    guid.push_back(make_pair("L",4));
    guid.push_back(make_pair("MN",5));
    guid.push_back(make_pair("R",6));

    vector<pair<string,string>>store;
    string name;
    while(cin>>name){
//        cin.ignore();
        store.push_back(make_pair(name,"000000000000000000000"));
    }
    for(int i=0;i<store.size();i++){
        store[i].second[0]=store[i].first[0];
        int k=1;
        for(int j=1;j<store[i].first.length();j++){
            if(isignorable(store[i].first[j]))
                continue;
            if(isSamevalue(store[i].first[j],store[i].first[j-1]))
                continue;
            store[i].second[k++]=findValue(store[i].first[j])+'0';
        }
    }
    print_space(9);
    printf("NAME");
    print_space(21);
    printf("SOUNDEX CODE\n");
    for(int i=0;i<store.size();i++){
        print_space(9);
        cout<<store[i].first;
        print_space(25-store[i].first.length());
        for(int j=0;j<4;j++){
            printf("%c",store[i].second[j]);
        }
        printf("\n");
    }
    print_space(19);
    printf("END OF OUTPUT\n");
    return 0;
}

