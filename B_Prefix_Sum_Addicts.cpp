#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(k);
    for (auto &it : arr)
        cin >> it;
    if (n - k != 0)
    {
        ll first = arr[0] / (n - k + 1);
        if (arr[0] % (n - k + 1) != 0)
            first++;
        // cout << first << endl;
        int increaser = first;
        for (int i = 1; i < k; i++)
        {
            ll toBe = arr[i - 1] + increaser;
            if (arr[i] < toBe)
            {
                cout << "No" << endl;
                return;
            }
            else
            {
                increaser = arr[i] - arr[i - 1];
            }
        }
        cout << "Yes" << endl;
    }
    else
    {
        int increaser = arr[0];
        for (int i = 1; i < k; i++)
        {
            ll toBe = arr[i - 1] + increaser;
            if (arr[i] < toBe)
            {
                cout << "No" << endl;
                return;
            }
            else
            {
                increaser = arr[i] - arr[i - 1];
            }
        }
        cout << "Yes" << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    // solve();

    ll t;

    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

/*
ulimit -s unlimited
g++ solution.cpp -o solution
./solution
*/

/*
g++ -Wl,--stack,1073741824 solution.cpp -o solution
./solution < input.txt > output.txt
*/