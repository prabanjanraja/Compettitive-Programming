#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ar array

#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

#define F_OR(i, a, b, s) for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...)       \
    F_ORC(__VA_ARGS__) \
    (__VA_ARGS__)
#define EACH(x, a) for (auto &x : a)

template <class A>
void read(vt<A> &v);
template <class A, size_t S>
void read(ar<A, S> &a);
template <class T>
void read(T &x)
{
    cin >> x;
}
void read(double &d)
{
    string t;
    read(t);
    d = stod(t);
}
void read(long double &d)
{
    string t;
    read(t);
    d = stold(t);
}
template <class H, class... T>
void read(H &h, T &... t)
{
    read(h);
    read(t...);
}
template <class A>
void read(vt<A> &x)
{
    EACH(a, x)
    read(a);
}
template <class A, size_t S>
void read(array<A, S> &x)
{
    EACH(a, x)
    read(a);
}

string to_string(char c)
{
    return string(1, c);
}
string to_string(bool b)
{
    return b ? "true" : "false";
}
string to_string(const char *s)
{
    return string(s);
}
string to_string(string s)
{
    return s;
}
string to_string(vt<bool> v)
{
    string res;
    FOR(sz(v))
    res += char('0' + v[i]);
    return res;
}

template <size_t S>
string to_string(bitset<S> b)
{
    string res;
    FOR(S)
    res += char('0' + b[i]);
    return res;
}
template <class T>
string to_string(T v)
{
    bool f = 1;
    string res;
    EACH(x, v)
    {
        if (!f)
            res += ' ';
        f = 0;
        res += to_string(x);
    }
    return res;
}

template <class A>
void write(A x)
{
    cout << to_string(x);
}
template <class H, class... T>
void write(const H &h, const T &... t)
{
    write(h);
    write(t...);
}
void print()
{
    write("\n");
}
template <class H, class... T>
void print(const H &h, const T &... t)
{
    write(h);
    if (sizeof...(t))
        write(' ');
    print(t...);
}

void DBG()
{
    cout << "]" << endl;
}
template <class H, class... T>
void DBG(H h, T... t)
{
    cout << to_string(h);
    if (sizeof...(t))
        cout << ", ";
    DBG(t...);
}
#ifdef _DEBUG
#define dbg(...) cout << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

template <class T>
void offset(ll o, T &x)
{
    x += o;
}
template <class T>
void offset(ll o, vt<T> &x)
{
    EACH(a, x)
    offset(o, a);
}
template <class T, size_t S>
void offset(ll o, ar<T, S> &x)
{
    EACH(a, x)
    offset(o, a);
}

void solve()
{
    long long n, m, k, x, y;
    read(n, m, k);
    vector<long long> v;
    FOR(k)
    {
        read(x, y);
        v.push_back((x - 1) * m + y);
    }
    long long ans = k * 4;
    bool b1, b2;
    sort(all(v));
    EACH(x, v)
    {
        b1 = binary_search(all(v), x + 1);
        b2 = binary_search(all(v), x + m);
        if (b1 && x % m)
            ans -= 2;
        if (b2)
            ans -= 2;
    }
    print(ans);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    read(t);
    FOR(t)
    {
        write("Case #", i + 1, ": ");
        solve();
    }
    cout << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
/* 
There is a field with plants — a grid with N rows (numbered 1 through N) and M columns (numbered 1 through M); out of its NM cells, K cells contain plants, while the rest contain weeds. Two cells are adjacent if they have a common side.

You want to build fences in the field in such a way that the following conditions hold for each cell that contains a plant:

it is possible to move from this cell to each adjacent cell containing a plant without crossing any fences
it is impossible to move from this cell to any cell containing weeds or to leave the grid without crossing any fences
The fences can only be built between cells or on the boundary of the grid, i.e. on the sides of cells. The total length of the built fences is the number of pairs of side-adjacent cells such that there is a fence built on their common side plus the number of sides of cells on the boundary of the grid which have fences built on them. Find the minimum required total length of fences that need to be built.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains three space-separated integers N, M and K.
K lines follow. Each of these lines contains two space-separated integers r and c denoting that the cell in row r and column c contains a plant.
Output
For each test case, print a single line containing one integer — the minimum required length of fences.

Constraints
1≤T≤10
1≤N,M≤109
1≤K≤105
1≤r≤N
1≤c≤M
the cells containing plants are pairwise distinct
Subtasks
Subtask #1 (30 points): 1≤N,M≤1,000
Subtask #2 (70 points): original constraints

Example Input
2
4 4 9
1 4
2 1 
2 2
2 3
3 1
3 3
4 1
4 2
4 3
4 4 1
1 1
Example Output
20
4
Explanation
Example case 1: The field looks like this ('x' denotes a cell containing a plant, '.' denotes a cell containing weeds):

...x
xxx.
x.x.
xxx.
An optimal solution is to build fences around the topmost plant (with length 4), around the remaining eight plants (with length 12) and around the hole between them (with length 4). The total length is 4+12+4=20.
 */
