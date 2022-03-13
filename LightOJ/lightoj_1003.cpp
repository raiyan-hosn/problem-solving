// Alhamdulillah solved!!.

#include<bits/stdc++.h>
using namespace std;
typedef unordered_set<string> st;
typedef unordered_map<string,st> mp;

bool isPossible=true;

void copyVector(st &a,vector<string>&b){
    for(int i=0;i<b.size();i++){
        a.insert(b[i]);
    }
}


st fullList(string source,mp &temporaryList,mp &permanentList,st &inQueue){

    if(inQueue.count(source)==1){
        isPossible=false;
        return st();
    }

    inQueue.insert(source);
    if(permanentList.count(source)==1){
        printf("ase\n");
        return permanentList[source];
    }


    st s;


    for(auto it = temporaryList[source].begin();it!=temporaryList[source].end();it++){
        if(permanentList.count(*it)==1){
            s=permanentList[*it];
        }


        else{

            s=fullList(*it,temporaryList,permanentList,inQueue);
            permanentList[*it]=s;
        }
    }
    return s;
}


int main(void)
{
//    freopen("i.txt","r",stdin);
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        isPossible=true;
        int m;
        char dummy;
        scanf("%d",&m);
//        scanf("%c",&dummy);
        mp temporaryList;
        mp permanentList;
        st inQueue;
        while(m--){

            char str[12];
//            scanf("%c",&dummy);
            scanf("%s",str);
//            scanf("%c",&dummy);
            string a(str);
//            convert.........
            scanf("%s",str);
            string b(str);
//            convert..........

            temporaryList[b].insert(a);
        }

        for(auto it=temporaryList.begin();it!=temporaryList.end();it++){
            if(permanentList.count(it->first)==0){
                permanentList[it->first]= fullList(it->first,temporaryList,permanentList,inQueue);

                if(!isPossible)
                    break;

            }
        }
        printf("Case %d: ",t);
        if(isPossible)
            printf("Yes\n");
        else
            printf("No\n");
    }

}

