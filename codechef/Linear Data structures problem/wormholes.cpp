#include <bits/stdc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int MAX_N = 1e5 + 5;
const int MAX_L = 20; // ~ Log N
const long long MOD = 1e9 + 7;
const long long INF = 1e6 + 7;
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
    long long int ans = INF;
    int n, s, e;
    vii contest;
    set<int> st, en;
    cin >> n >> s >> e;
    for (size_t i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        contest.push_back(make_pair(x, y));
    }
    for (size_t i = 0; i < s; i++)
    {
        int x;
        cin >> x;
        st.insert(x);
    }
    for (size_t i = 0; i < e; i++)
    {
        int x;
        cin >> x;
        en.insert(x);
    }
    st.insert(-INF);
    st.insert(INF);
    en.insert(INF);
    for (auto x : contest)
    {
        int start, end_;
        start = x.first;
        end_ = x.second;
        long long int z = *en.lower_bound(end_) - *(--st.upper_bound(start)) + 1;
        ans = min(ans, z);
    }
    cout << ans;
    return;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("C:/Users/ASUS/Downloads/Competitive-Coding/c progrmming/input.txt", "r", stdin);
    freopen("C:/Users/ASUS/Downloads/Competitive-Coding/c progrmming/output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    //cin >> T;
    /* for (int i = 0; i < T; i++)
    {
        //cout << "Case #" << i + 1 << ": ";
        solve();
        cout << endl;
    } */
    solve();
    return 0;
}
