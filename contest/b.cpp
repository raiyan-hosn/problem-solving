/**
 if we always want to Fi >= Fi+1, 
 then we always need Ai<= Ai+1
 because every Fi is made of An - Ai

 So we have check if A[] is sorted in ascending order.
 we can check this in linear time.
 Time complexity = O(N)
 spcace complexity=O(1) 
 **/


#include<bits/stdc++.h>
using namespace std;

bool isDescendingFriendArray(vector<int>&v){
    for(int i=0;i<v.size()-1;i++){
        if(v[i]>v[i+1])return false;
    }
    return true;
}
int main()
{
    int n;
    scanf("%d",&n);
    vector<int>v(n);
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
    }
    if(isDescendingFriendArray(v)){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
}