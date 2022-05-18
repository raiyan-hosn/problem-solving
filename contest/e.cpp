
#include <bits/stdc++.h>
using namespace std;
bool HaveDuplicate(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int tmp = nums[i];
        if (tmp < 0)
            tmp = -tmp;

        if (nums[tmp - 1] < 0)
        {
            return true;
        }
        else
        {
            nums[tmp - 1] = -nums[tmp - 1];
        }
    }
    return false;
}

int main()
{
   vector<int>v={3,1,4,2};
   printf("%d\n",HaveDuplicate(v));
}