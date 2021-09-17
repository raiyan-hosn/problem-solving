#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
#define left st,(st+en)/2,nd+nd
#define right (st+en)/2+1,en,nd+nd+1
int arr[MAX+5];
int tree[4* MAX+5];

void build(int st,int en,int nd)
{
    if(st==en){
        tree[nd]=arr[st];
        return;
    }

    build(left);
    build(right);
    tree[nd]=tree[nd+nd]+tree[nd+nd+1];
}
int query(int st,int en,int nd,int L,int R){
    if(L<=st&&en<=R)return tree[nd];
    if(en<L||R<st)return 0;

    return query(left,L,R)+query(right,L,R);
}
void update(int st,int en,int nd,int idx,int v){
    if(idx<st||en<idx) return;
    if(st==en){
        tree[nd]+=v;
        return;
    }
    update(left,idx,v);
    update(right,idx,v);
    tree[nd]=tree[nd+nd]+tree[nd+nd+1];

}
int main(){
    freopen("i.txt","r",stdin);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    build(0,n-1,1);
//    for(int i=1;i<=15;i++){
//        cout<<i<<" : "<<tree[i]<<endl;
//    }
    int q;
    cin>>q;
    while(q--){
        int com;
        cin>>com;
        if(com==1){
            int L,R;
            cin>>L>>R;
            cout<<query(0,n-1,1,L,R)<<endl;
        }
        else if(com==0){
            int idx,v;
            cin>>idx>>v;
            update(0,n-1,1,idx,v);
        }
    }

}
