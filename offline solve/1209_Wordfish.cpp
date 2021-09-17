//Alhamdulillah
#include<bits/stdc++.h>
using namespace std;
bool nextPermutation(string &s,int n){
    int i=n-1;
    if(n==1)return false;
    while (s[i-1]>=s[i])
    {
        if(--i==0)
            return false;
    }
    int j=n-1;
    while(j>i && s[i-1]>=s[j]){
        j--;
    }
    swap(s[i-1],s[j]);
    reverse(s.begin()+i,s.end()); //ei khane sort korleo hoto, kintu i...n porjonto already decreasing order.
    return true; // get this idea from: https://www.techiedelight.com/std_next_permutation-overview-implementation/
    
}
bool prevPermutation(string &s,int n){// n==1
    int i=n-1;
    if(n==1)return false;
    while(s[i-1]<=s[i]){
        if(--i==0)
            return false;
    }
    int j=n-1;
    while(j>i && s[i-1]<=s[j]){
        j--;
    }
    swap(s[i-1],s[j]);
    reverse(s.begin()+i,s.end());
    return true;
}
int minimunDistance(string &s){
    if(s.length()==1)return 0;
    int mn=INT_MAX;
    for(int i=1;i<s.length();i++){
        mn=min(mn,abs(s[i]-s[i-1]));
    }
    return mn;
}
int main(void)
{
  string s;
  while(getline(cin,s)){
      vector<string>twentyOnePermutations;
      string t=s;
      twentyOnePermutations.push_back(s);
      int n=10;
      while(prevPermutation(t,t.length())&&n--){
          twentyOnePermutations.push_back(t);
      }
      reverse(twentyOnePermutations.begin(),twentyOnePermutations.end());
      n=10;
      t=s;
      while(nextPermutation(t,t.length())&&n--){
          twentyOnePermutations.push_back(t);
      }
      vector<int>minDis((int)twentyOnePermutations.size());
      int largestValue=INT_MIN;
      for(int i=0;i<twentyOnePermutations.size();i++){
         minDis[i]=minimunDistance(twentyOnePermutations[i]);
         largestValue=max(largestValue,minDis[i]);
      }
      for(int i=0;i<minDis.size();i++){
          if(minDis[i]==largestValue){
              cout<<twentyOnePermutations[i]<<largestValue<<endl;
              break;
          }
      }

  }

}