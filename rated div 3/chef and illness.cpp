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
void read(H &h, T &...t)
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
void write(const H &h, const T &...t)
{
    write(h);
    write(t...);
}
void print()
{
    write("\n");
}
template <class H, class... T>
void print(const H &h, const T &...t)
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
    ll k;
    read(k);
    /* vt<ll> illness(k, 0);
    read(illness); */
    priority_queue<pair<int, int>> illness;
    FOR(k)
    {
        ll x;
        read(x);
        illness.push({x, -i});
    }
    vt<int> ans(k, 0);
    int z = 0;
    while (!illness.empty())
    {
        pair<int, int> x = illness.top();
        illness.pop();
        ++z;
        ans[-x.second] = z;
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
        //write("Case #", i + 1, ": ");
        solve();
    }
    //cout << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
}