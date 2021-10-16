#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int missing = n;
        
        for (int i = 0; i < n; i++)
            missing ^= i ^ nums[i];
        
        return missing;
    }
};
int main()
{
   vector<int>v={4,7,1,2,3,5,8,6};
   Solution s;
   printf("%d\n",s.missingNumber(v));
    
}