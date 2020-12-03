#include <bits/stdc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int MAX_N = 1e5 + 5;
const int MAX_L = 20; // ~ Log N
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 7;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mi;
typedef map<ll, ll> mll;
typedef unordered_map<int, int> umi;
typedef unordered_map<ll, ll> umll;
typedef queue<int> qi;
void solve()
{
    int n, s, p, v, ans = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> s >> p >> v;
        ans = max(ans, (p / (s + 1)) * v);
    }

    cout << ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        //cout << "Case #" << i + 1 << ": ";
        solve();
        cout << endl;
    }
    cout << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}