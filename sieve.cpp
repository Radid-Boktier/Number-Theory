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

const int MX = 1e6 + 123;

// bool is_prime[MX];
bitset<MX> is_prime;
vector<int> prime;

void solve(int n)
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

    for (auto u : prime)
        cout << u << " ";
    return;
}
int main()
{
    optimize();
    int t = 1;
    // cin>>t;
    while (t--)
    {
        int n;
        cin >> n;
        solve(n);
    }

    return 0;
}
