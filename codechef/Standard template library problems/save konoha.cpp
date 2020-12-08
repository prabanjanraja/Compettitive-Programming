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
    long long n, z;
    priority_queue<long> v;
    read(n, z);
    FOR(n)
    {
        int x;
        read(x);
        v.push(x);
    }
    long ans = 0;
    while (z > 0 && !v.empty())
    {
        long long x = v.top();
        v.pop();
        z -= x;
        x /= 2;
        ans++;
        if (x)
            v.push(x);
    }
    if (v.empty())
        print("Evacuate");
    else
    {
        print(ans);
    }
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
}

/* Pain has a strength of Z and is confident that he will succeed. Naruto has N soldiers under his command numbered 1 through N. Power of i-th soldier is denoted by Ai. When a soldier attacks pain, his strength gets reduced by the corresponding power of the soldier. However, every action has a reaction so the power of the soldier also gets halved i.e. Ai changes to [Ai/2]. Each soldier may attack any number of times (including 0). Pain is defeated if his strength is reduced to 0 or less.

Find the minimum number of times the soldiers need to attack so that the village is saved.

Input:
First line will contain T, number of test cases. Then the test cases follow.
The first line of each test case contains two space-separated integers N and Z.
The second line contains N space-separated integers A1,A2,…,AN the attacking power of the soldiers.
Output:
For each test case, print a single line. If Pain cannot be defeated, this line should contain the string "Evacuate" (without quotes). Otherwise, it should contain the minimum number of times the soldiers need to attack.

Constraints
1≤T≤10
1≤N≤105
1≤Z≤108
1≤Ai≤104
Sample Input:
1
5 25
7 13 8 17 3

Sample Output:
2
EXPLANATION:
Soldier with power 17 hits Pain, The new powers of soldiers become [7,13,8,8,3] and the strength of pain is reduced to 8, after that any soldier with a power greater than equal to 8 can hit Pain and thus defeat him, hence answer is 2. */