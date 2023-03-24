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

ll gcd(ll a, ll b)
{
    return __gcd(a, b);
}
ll lcm(ll a, ll b) { return a * (b / __gcd(a, b)); }

const int mx = 1e6 + 123;

ll SNOD(ll n)
{
    ll res = 0;
    ll sq = sqrt(n);
    for (int i = 1; i <= sq; i++)
        res += (n / i) - i;
    res *= 2;
    res += sq;
    return res;
}
int main()
{
    optimize();
    ll n;
    cin >> n;

    cout << SNOD(n) << endl;

    return 0;
}
