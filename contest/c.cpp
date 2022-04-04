#include<bits/stdc++.h>
using namespace std;
bool _find(int arr[],int n,int x){
    for(int i=0;i<n;i++){
        if(arr[i]==x)return true;
    }
    return false;
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)scanf("%d",&arr[i]);
    set<vector<int>> st;
    int cnt=0;
    for(int a=0;a<n;a++){
        for(int b=0;b<n;b++){
            for(int c=0;c<n;c++){
                for(int d=0;d<n;d++){
                    for(int e=0;e<n;e++){
                        if(arr[d]!=0){
                            int res=(arr[a]*arr[b]+arr[c])/arr[d] -arr[e];
                            if(_find(arr,n,res)&& st.count({arr[a],arr[b],arr[c],arr[d],arr[e],res})==0){
                                printf("a=%d, b=%d, c=%d, d=%d, e=%d, f=%d ",arr[a],arr[b],arr[c],arr[d],arr[e],res);
                                printf("lhs=%d , rhs=%d\n",(arr[a]*arr[b]+arr[c])/arr[d], arr[e]+res);
                                cnt++;
                                if(st.count({arr[a],arr[b],arr[c],arr[d],arr[e],res})!=0){
                                    printf("found...............................\n");
                                }
                                st.insert({arr[a],arr[b],arr[c],arr[d],arr[e],res});
                            }
                        }
                    }
                }
            }
        }
    }
    printf("cnt= %d\n",cnt);
    main();

}