#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long get_random()
{
    return (long long)(rng());
}

long long get_random_in_range(long long L, long long R)
{
    long long rndm = get_random();
    return L + (rndm % (R - L + 1));
}

int main()
{
    cout << get_random() << "\n";
    cout << get_random_in_range(10, 15) << "\n";
    return 0;
}