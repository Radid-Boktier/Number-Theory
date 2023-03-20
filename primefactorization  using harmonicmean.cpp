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

// complexity-----> nln(n);

const int MX = 1e5 + 123;
bool is_prime[MX];
vector<int> prime;
vector<int> primeFactors[MX];

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

int main()
{
    optimize();
    int lim;
    // lim = 1e6;
    cin >> lim;

    primegen(lim);

    for (auto p : prime)
    {
        for (int i = p; i <= lim; i += p)
        {

            int temp = i;
            while (temp > 0 && temp % p == 0)
            {
                primeFactors[i].push_back(p);
                temp /= p;
            }
        }
    }

    for (int i = 1; i <= lim; i++)
    {
        cout << "Prime factor of " << i << " : ";
        for (auto u : primeFactors[i])
            cout << u << " ";
        cout << endl;
    }

    return 0;
}
