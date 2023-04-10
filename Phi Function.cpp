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
const double PI = acos(-1);
const int MX = 1e7 + 123;

inline void normal(ll &a)
{
    a %= MOD;
    (a < 0) && (a += MOD);
}
inline ll modMul(ll a, ll b)
{
    a %= MOD, b %= MOD;
    normal(a), normal(b);
    return (a * b) % MOD;
}
inline ll modAdd(ll a, ll b)
{
    a %= MOD, b %= MOD;
    normal(a), normal(b);
    return (a + b) % MOD;
}
inline ll modSub(ll a, ll b)
{
    a %= MOD, b %= MOD;
    normal(a), normal(b);
    a -= b;
    normal(a);
    return a % MOD;
}
inline ll modPow(ll b, ll p)
{
    ll r = 1;
    while (p)
    {
        if (p & 1)
            r = modMul(r, b);
        b = modMul(b, b);
        p >>= 1;
    }
    return r;
}
inline ll modInverse(ll a) { return modPow(a, MOD - 2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

ll gcd(ll a, ll b) { return __gcd(a, b); }
ll lcm(ll a, ll b) { return a * (b / __gcd(a, b)); }

// bool is_prime[MX];
bitset<MX> is_prime;
vector<int> prime;

void primeGen(int n)
{
    // memset(is_prime, 1, sizeof(is_prime));
    for (int i = 3; i <= n; i += 2)
        is_prime[i] = 1;

    int sq = sqrt(n);
    for (int i = 3; i <= sq; i += 2)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= n; j += 2 * i)
                is_prime[j] = 0;
        }
    }
    prime.push_back(2);
    for (int i = 3; i <= n; i += 2)
    {
        if (is_prime[i])
            prime.push_back(i);
    }
    return;
}
int phi(int n)
{
    int ret = n;
    for (auto p : prime)
    {
        if (1LL * p * p > n || n == 0)
            break;
        if (n % p == 0)
        {
            ret /= p;
            ret *= (p - 1);
            while (n % p == 0)
                n /= p;
        }
    }

    if (n > 1)
    {
        ret /= n;
        ret *= (n - 1);
    }
    return ret;
}
int main()
{
    optimize();
    int lim = 1e6;
    primeGen(lim);

    int t = 1;
    // cin>>t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << phi(n) << endl;
    }
    return 0;
}
