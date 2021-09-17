#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n=4;
    char arr[]={'A','B','C','D','E'};
    for(int mask=0;mask<1<<n;mask++){
        for(int i=0;i<n;i++){
            if(mask&(1<<i)){
                printf("%c ",arr[i]);
            }
            
        }
        printf("\n");
    }
}
/*
১। কোন বিটকে অন করাঃ
To turn on jth bit:
msk|=(1<<j);
২। কোন বিটকে অফ করাঃ
To turn off jth bit:
msk&=~(1<<j);
৩। কোন বিটকে চেক করাঃ
To check the jth bit:
T=msk&(1<<j);
if T is true then jth bit is on else, jth bit is off.
৪। কোন বিটকে টোগল করাঃ
To toggle the jth bit:
msk^=(1<<j);
৫। সর্বনিম্ন স্থানীয় মান বিশিষ্ট যে বিটটি অন তা বের করাঃ
z=(msk&-msk);
৬। প্রথম n টি বিট অন করাঃ
msk=(1<<n)-1;
৭। কোন সেটের সকল সাবসেট নির্ণয়ঃ
for(msk=0;msk<(1<<n);msk++)
৮। কোন সাবসেট y এর সকল সাবসেট নির্ণয়ঃ
for(msk=y;msk;msk=(y&(msk-1)))

*/