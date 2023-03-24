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
    n += 12;
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

ll SOD(ll n)
{
    ll ret = 1;
    for (auto p : prime)
    {
        if (1LL * p * p > n)
            break;

        if (n % p == 0)
        {
            ll currSum = 1, powP = 1;
            while (n % p == 0)
            {
                powP *= p;
                currSum += powP;
                n /= p;
            }
            ret *= currSum;
        }
    }
    if (n > 1)
        ret *= (1 + n);

    return ret;
}
int main()
{
    optimize();
    primegen(1e7);
    ll n;
    cin >> n;

    cout << SOD(n) << endl;
    return 0;
}
