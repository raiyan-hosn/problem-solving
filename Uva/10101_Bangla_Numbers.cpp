#include<bits/stdc++.h>
using namespace std;

int main(){
    // freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    long long int n;
    int tc=1;
    while(scanf("%lld",&n)!=EOF){
        if(n==0){
            printf("%4d. 0\n",tc++);
            continue;
        }
        vector<int>v;
        stack<string>st;
        int state=0;
        while(n){
            if(state==0){
                v.push_back(n%100);
                n/=100;
            }else if(state==1){
                v.push_back(n%10);
                n/=10;
            }else if(state==2){
                v.push_back(n%100);
                n/=100;
            }else if(state==3){
                v.push_back(n%100);
                n/=100;
            }else{
                // v.push_back(n%100);
                // n/=100;
                // state++;
            }
            state= (++state)%5;
        }
       
        state=0;
        for(int i=0;i<v.size();i++){
            
            
            if(state==0){
                
            }else if(state==1&&v[i]){
                st.push("shata");
            }else if(state==2&&v[i]){
                st.push("hajar");
            }else if(state==3&&v[i]){
                st.push("lakh");
            }else if(state==4){
                st.push("kuti");
                state++;
            }
            // if(!st.empty())
            //     printf("state=%d, %s\n",state,st.top().c_str());
            if(v[i])
                st.push(to_string(v[i]));

            
            state= (++state)%5;
        }
        printf("%4d.",tc++);
        while(!st.empty()){
            cout<<" ";
            cout<<st.top();
            st.pop();
        }
        cout<<"\n";
    }
}