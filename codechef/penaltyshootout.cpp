#include <bits/stdc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int MAX_N = 1e5 + 5;
const int MAX_L = 20; // ~ Log N
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 7;
#define min(a, b) (((a) < (b)) ? (a) : (b))
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
    int n;
    cin >> n;
    int ans = n * 2;
    int ca = 0, cb = 0, ra = n, rb = n;
    char x;
    string s;
    cin >> s;
    for (int i = 0; i < 2 * n; i++)
    {
        if ((ca - cb) > rb || (cb - ca) > ra)
        {
            ans = i;
            break;
        }
        if (i % 2 == 0)
        {
            ca += s[i] - 48;
            ra--;
        }
        else
        {
            cb += s[i] - 48;
            rb--;
        }
    }
    cout << ans;
    return;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        //cout << "Case #" << i + 1 << ": ";
        solve();
        cout << endl;
    }
    return 0;
}