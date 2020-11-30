#include <bits/stdc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int MAX_N = 1e5 + 5;
const int MAX_L = 20; // ~ Log N
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 7;
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define mp(i, j) make_pair((i), (j))
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
int mul(int a, int b)
{
    return a * (long long)b % MOD;
}
void solve()
{
    stack<ii> st;
    long long ans = 1;
    int n, k, i, j;
    cin >> n >> k;
    int a[n];
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < n; i++)
    {
        while (!st.empty() && st.top().first > a[i])
        {
            ans = mul(i - st.top().second + 1, ans);
            st.pop();
        }
        st.push(mp(a[i], i));
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
    /* int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        solve();
        cout << endl;
    } */
    solve();
    return 0;
}