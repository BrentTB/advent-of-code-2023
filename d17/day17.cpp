#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define uint unsigned int
#define ull unsigned long long
// #define endl "\n"
#define elif else if
#define fo(i, a, b) for (int i = a; i < (int)b; i++)
#define foe(a, b) for (auto a : b)
#define rfo(i, b, a) for (int i = a - 1; i >= b; i--)
#define v(i) vector<i>
#define vll vector<long long>
#define vint vector<int>
#define vstr vector<string>
#define pairll pair<long long, long long>
#define pairint pair<int, int>
#define vpairll vector<pair<long long, long long>>
#define vpairint vector<pair<int, int>>
#define print(x) cout << x << "\n"

template <typename T>
T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
template <typename T>
T lcm(T a, T b) { return a * b / gcd(a, b); }

#define printall(x)         \
    for (auto zz : x)       \
    {                       \
        cout << zz << "\n"; \
    }

#define printallpair(x)            \
    for (auto zz : x)              \
    {                              \
        cout << zz.first << " ";   \
        cout << zz.second << "\n"; \
    }

#define printall2d(x)         \
    for (auto zz : x)         \
    {                         \
        for (auto qq : zz)    \
        {                     \
            cout << qq << ""; \
        }                     \
        cout << "\n";         \
    }

#define pushall(x, n)                   \
    x.resize(n);                        \
    for (int zz = 0; zz < (int)n; zz++) \
    {                                   \
        cin >> x[zz];                   \
    }

#define pushallpair(x, n)                   \
    x.resize(n);                            \
    for (int zz = 0; zz < (int)n; zz++)     \
    {                                       \
        cin >> x[zz].first >> x[zz].second; \
    }

void recur(v(vint) & heat, pairint on, pairint last, pairint goal, map<pair<pairint, pairint>, ll> &mp, ll length, ll &globalMin) // last = last square you turned
{
    // if(endall)
    // return;
    // cout << on.first << " " << on.second << endl;
    pair<pairint, pairint> at = {on, last};

    if (abs(on.first - last.first) + abs(on.second - last.second) == 1)
    {
        if (mp.count(at) && mp[at] <= length)
        {
            return;
        }
        else
            mp[at] = length;
    }

    if (length > globalMin)
    {
        return;
    }

    if (on == goal)
    {
        globalMin = min(length, globalMin);
        // cout << length << endl;
        return;
    }

    if (on.first < heat.size() - 1 && on.first - last.first < 3 && on.first >= last.first) // down
    {
        if (on.first == last.first) // we are changing direction
        {
            recur(heat, {on.first + 1, on.second}, on, goal, mp, length + heat[on.first + 1][on.second], globalMin);
        }
        else
            recur(heat, {on.first + 1, on.second}, last, goal, mp, length + heat[on.first + 1][on.second], globalMin);
    }
    if (on.first > 0 && last.first - on.first < 3 && on.first <= last.first) // up
    {
        if (on.first == last.first) // we are changing direction
        {
            recur(heat, {on.first - 1, on.second}, on, goal, mp, length + heat[on.first - 1][on.second], globalMin);
        }
        else
            recur(heat, {on.first - 1, on.second}, last, goal, mp, length + heat[on.first - 1][on.second], globalMin);
    }
    if (on.second < heat[0].size() - 1 && on.second - last.second < 3 && on.second >= last.second) // right
    {
        if (on.second == last.second) // we are changing direction
        {
            recur(heat, {on.first, on.second + 1}, on, goal, mp, length + heat[on.first][on.second + 1], globalMin);
        }
        else
            recur(heat, {on.first, on.second + 1}, last, goal, mp, length + heat[on.first][on.second + 1], globalMin);
    }
    if (on.second > 0 && last.second - on.second < 3 && on.second <= last.second) // left
    {
        if (on.second == last.second) // we are changing direction
        {
            recur(heat, {on.first, on.second - 1}, on, goal, mp, length + heat[on.first][on.second - 1], globalMin);
        }
        else
            recur(heat, {on.first, on.second - 1}, last, goal, mp, length + heat[on.first][on.second - 1], globalMin);
    }

    //     if(endall)
    // cout << on.first << " "<<on.second<<endl;
}

void recur2(v(vint) & heat, pairint on, pairint last, pairint goal, map<pair<pairint, pairint>, ll> &mp, ll length, ll &globalMin) // last = last square you turned
{
    pair<pairint, pairint> at = {on, last};

    if (abs(on.first - last.first) + abs(on.second - last.second) == 1)
    {
        if (mp.count(at) && mp[at] <= length)
        {
            return;
        }
        else
            mp[at] = length;
    }

    if (length > globalMin)
    {
        return;
    }

    if (on == goal)
    {
        if (abs(on.first - last.first) + abs(on.second - last.second) >= 4)
            globalMin = min(length, globalMin);
        return;
    }

    if (on.first - last.first < 4 && on.first - last.first != 0 && on.first > last.first)
    {
        if (on.first < heat.size() - 1)
            recur2(heat, {on.first + 1, on.second}, last, goal, mp, length + heat[on.first + 1][on.second], globalMin);
        return;
    }
    if (last.first - on.first < 4 && on.first - last.first != 0 && on.first < last.first)
    {
        if (on.first > 0)
            recur2(heat, {on.first - 1, on.second}, last, goal, mp, length + heat[on.first - 1][on.second], globalMin);
        return;
    }
    if (on.second - last.second < 4 && on.second - last.second != 0 && on.second > last.second)
    {
        if (on.second < heat[0].size() - 1)
            recur2(heat, {on.first, on.second + 1}, last, goal, mp, length + heat[on.first][on.second + 1], globalMin);
        return;
    }
    if (last.second - on.second < 4 && on.second - last.second != 0 && on.second < last.second)
    {
        if (on.second > 0)
            recur2(heat, {on.first, on.second - 1}, last, goal, mp, length + heat[on.first][on.second - 1], globalMin);
        return;
    }

    if (on.first < heat.size() - 1 && on.first - last.first < 10 && on.first >= last.first) // down
    {
        if (on.first == last.first) // we are changing direction
        {
            recur2(heat, {on.first + 1, on.second}, on, goal, mp, length + heat[on.first + 1][on.second], globalMin);
        }
        else
            recur2(heat, {on.first + 1, on.second}, last, goal, mp, length + heat[on.first + 1][on.second], globalMin);
    }
    if (on.first > 0 && last.first - on.first < 10 && on.first <= last.first) // up
    {
        if (on.first == last.first) // we are changing direction
        {
            recur2(heat, {on.first - 1, on.second}, on, goal, mp, length + heat[on.first - 1][on.second], globalMin);
        }
        else
            recur2(heat, {on.first - 1, on.second}, last, goal, mp, length + heat[on.first - 1][on.second], globalMin);
    }
    if (on.second < heat[0].size() - 1 && on.second - last.second < 10 && on.second >= last.second) // right
    {
        if (on.second == last.second) // we are changing direction
        {
            recur2(heat, {on.first, on.second + 1}, on, goal, mp, length + heat[on.first][on.second + 1], globalMin);
        }
        else
            recur2(heat, {on.first, on.second + 1}, last, goal, mp, length + heat[on.first][on.second + 1], globalMin);
    }
    if (on.second > 0 && last.second - on.second < 10 && on.second <= last.second) // left
    {
        if (on.second == last.second) // we are changing direction
        {
            recur2(heat, {on.first, on.second - 1}, on, goal, mp, length + heat[on.first][on.second - 1], globalMin);
        }
        else
            recur2(heat, {on.first, on.second - 1}, last, goal, mp, length + heat[on.first][on.second - 1], globalMin);
    }
}
void p1() // this is inefficient, but it does work
{
    v(vint) heat;
    string x;
    while (cin >> x)
    {
        heat.push_back({});
        foe(i, x)
        {
            heat[heat.size() - 1].push_back(i - '0');
        }
    }

    pairint on = {0, 0};
    pairint goal = {heat.size() - 1, heat[0].size() - 1};

    map<pair<pairint, pairint>, ll> mp;
    ll globalMin = INT32_MAX - 1;

    recur(heat, on, on, goal, mp, 0, globalMin);

    cout << globalMin << endl;

    // printall2d(heat);
    // while(getline(cin,x))
    // istringstream iss(x);
}

void p2() // this is inefficient, but it does work
{

        v(vint) heat;
    string x;
    while (cin >> x)
    {
        heat.push_back({});
        foe(i, x)
        {
            heat[heat.size() - 1].push_back(i - '0');
        }
    }

    pairint on = {0, 0};
    pairint goal = {heat.size() - 1, heat[0].size() - 1};

    map<pair<pairint, pairint>, ll> mp;
    ll globalMin = INT32_MAX - 1;

    recur2(heat, on, on, goal, mp, 0, globalMin);

    cout << globalMin << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    p2();
}

/*
   if (on.first < heat.size() - 1 && on.first - last.first < 10 && on.first - last.first > 4 && on.first >= last.first) // down
    {
        if (on.first == last.first) // we are changing direction
        {
            recur(heat, {on.first + 1, on.second}, on, goal, mp, length + heat[on.first + 1][on.second], globalMin);
        }
        else
            recur(heat, {on.first + 1, on.second}, last, goal, mp, length + heat[on.first + 1][on.second], globalMin);
    }
    if (on.first > 0 && last.first - on.first < 10 && last.first - on.first > 4 && on.first <= last.first) // up
    {
        if (on.first == last.first) // we are changing direction
        {
            recur(heat, {on.first - 1, on.second}, on, goal, mp, length + heat[on.first - 1][on.second], globalMin);
        }
        else
            recur(heat, {on.first - 1, on.second}, last, goal, mp, length + heat[on.first - 1][on.second], globalMin);
    }
    if (on.second < heat[0].size() - 1 && on.second - last.second < 10 && on.second - last.second > 4 && on.second >= last.second) // down
    {
        if (on.second == last.second) // we are changing direction
        {
            recur(heat, {on.first, on.second + 1}, on, goal, mp, length + heat[on.first][on.second + 1], globalMin);
        }
        else
            recur(heat, {on.first, on.second + 1}, last, goal, mp, length + heat[on.first][on.second + 1], globalMin);
    }
    if (on.second > 0 && last.second - on.second < 10 && last.second - on.second > 4 && on.second <= last.second) // down
    {
        if (on.second == last.second) // we are changing direction
        {
            recur(heat, {on.first, on.second - 1}, on, goal, mp, length + heat[on.first][on.second - 1], globalMin);
        }
        else
            recur(heat, {on.first, on.second - 1}, last, goal, mp, length + heat[on.first][on.second - 1], globalMin);
    }
    */