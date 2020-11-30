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
int priority(char x)
{
    if (x == '(')
        return 0;
    if (x == '^')
        return 3;
    if (x == '*' || x == '/')
        return 2;
    return 1;
}
void solve()
{
    string ans;
    int n;
    string s;
    cin >> n;
    cin >> s;
    stack<char> st;
    for (auto x : s)
    {
        if (isalpha(x))
        {
            ans.push_back(x);
        }
        else if (x == '(')
            st.push(x);
        else if (x == ')')
        {
            while (st.top() != '(')
            {
                ans.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else
        {
            int z = priority(x);
            while (!st.empty() && priority(st.top()) >= z)
            {
                ans.push_back(st.top());
                st.pop();
            }
            st.push(x);
        }
    }
    while (!st.empty())
        ans.push_back(st.top()),
            st.pop();
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