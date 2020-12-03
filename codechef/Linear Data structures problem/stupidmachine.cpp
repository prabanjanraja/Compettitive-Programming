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
void read_array(vector<long long> &v)
{
    for (auto &x : v)
    {
        cin >> x;
    }
}
void print_array(vector<long long> &v)
{
    for (auto &x : v)
    {
        cout << x << " ";
    }
}
void solve()
{
    ll Min = 1e9, ans = 0;
    int n;
    cin >> n;
    vector<long long> v(n);
    read_array(v);
    //print_array(v);
    for (auto x : v)
    {
        Min = min(Min, x);
        ans += Min;
    }
    cout << ans << " ";
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