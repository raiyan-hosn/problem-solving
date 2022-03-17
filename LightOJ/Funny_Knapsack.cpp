#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void makeAllCombinations(vector<ll> &arr, vector<ll> &c)
{
    
    int n = pow(2, (int)arr.size());
    for (int i = 0; i < n; i++)
    {
        ll sum = 0;
        for (int j = 0; j < arr.size(); j++)
        {
            if (i & (1 << j))
            {
                sum += arr[j];
            }
        }
        c.push_back(sum);
    }
    sort(c.begin(), c.end());
    // printf("\n\n");
    // for(int i=0;i<c.size();i++)printf("%lld ",c[i]);
    // printf("\n\n");
}
ll findNumOfCombinations(vector<ll> &x, vector<ll> &y, ll w)
{
    ll combiations=0;
   
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] > w)
            break;
        ll need = w - x[i];
        auto it = upper_bound(y.begin(), y.end(), need);
        
        combiations+=  (it-y.begin());
        if(it-y.begin()==0)combiations++;
        // if(need==0)printf("it-begin %d\n\n",it-y.begin());
        // mx = max(mx, sum);
    }
    for(int i=0;i<y.size();i++){
        // if(y[i]<=w)combiations++;
    }
    return combiations;
}
int main()
{
    // freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    int tc;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++)
    {
        int n, w;

        scanf("%d %d",&n,&w);
       
        vector<ll> arr(n);
 
        vector<ll> x, y;
        for (int i = 0; i < n; i++)
        {
            scanf("%lld",&arr[i]);
        }

        int half = (int)arr.size() / 2;
        vector<ll> lo(arr.begin(), arr.begin() + half);
        makeAllCombinations(lo, x);

        vector<ll> hi(arr.begin() + half, arr.end());
        makeAllCombinations(hi, y);

        ll combinations= findNumOfCombinations(x, y, w);
        if(n==1){
            if(w<arr[0])combinations=1;
            else combinations=2;
        }
        
        printf("Case %d: %lld\n",t,combinations);
    }
}
