#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define optimize()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define fraction()                \
    cout.unsetf(ios::floatfield); \
    cout.precision(10);           \
    cout.setf(ios::fixed, ios::floatfield);

#define MOD 1000000007
const int MX = 1e6 + 123;

ll gcd(ll a, ll b) { return __gcd(a, b); }
ll lcm(ll a, ll b) { return a * (b / __gcd(a, b)); }

ll modpow(ll b, ll p)
{
    ll ret = 1;
    while (p > 0)
    {
        if (p % 2)
        {
            ret *= b;
            ret %= MOD;
        }
        p /= 2;
        b *= b;
        b %= MOD;
    }
    return ret;
}

int main()
{
    optimize();
    ll a, b;
    cin >> a >> b;
    cout << ((a % MOD) * modpow(b, MOD - 2)) % MOD << endl;
    return 0;
}
