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

// complexity O(sqrt(n)/ln(sqrt(n))+log2(n))
const int MX = 1e7 + 123;
bool is_prime[MX];
// bitset<MX> is_prime;
vector<int> prime;

void primegen(int n)
{
    n += 123;
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

vector<ll> primefac(ll n)
{
    vector<ll> factor;
    for (auto p : prime)
    {
        if (1LL * p * p > n)
            break;

        if (n % p == 0)
        {
            while (n % p == 0)
            {
                factor.push_back(p);
                n /= p;
            }
        }
    }
    if (n > 1)
        factor.push_back(n);

    return factor;
}
int main()
{
    optimize();
    primegen(1e7);
    ll n;
    cin >> n;
    vector<ll> ans = primefac(n);
    for (auto u : ans)
        cout << u << " ";
    return 0;
}
