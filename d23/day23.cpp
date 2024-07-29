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

void recur(pairint prev, pairint on, ll &longest, set<pairint> been, vstr &maze, ll length)
{
    vpairint next;
    while (true)
    {

        if (on.first == maze.size() - 1)
        {
            longest = max(longest, length);
            return;
        }

        if (on.first > 0 && (maze[on.first - 1][on.second] == '.' || maze[on.first - 1][on.second] == '^') && prev.first != on.first - 1)
            next.push_back({on.first - 1, on.second});
        if ((maze[on.first + 1][on.second] == '.' || maze[on.first + 1][on.second] == 'v') && prev.first != on.first + 1) // on.first < maze.size() - 1 &&
            next.push_back({on.first + 1, on.second});
        if ((maze[on.first][on.second - 1] == '.' || maze[on.first][on.second - 1] == '<') && prev.second != on.second - 1) // on.second > 0 &&
            next.push_back({on.first, on.second - 1});
        if ((maze[on.first][on.second + 1] == '.' || maze[on.first][on.second + 1] == '>') && prev.second != on.second + 1) // on.second < maze[0].length() - 1 &&
            next.push_back({on.first, on.second + 1});

        int count = next.size();
        if (count == 0)
            return;
        if (count == 1)
        {
            prev = on;
            on = next[0];
            length++;
            next.clear();
        }
        else
        {
            if (been.count(on) != 0) // if we entered the current path from the other side
                return;

            length++;
            foe(mv, next)
            {
                if (been.count(mv) == 0)
                {
                    been.insert(mv);
                    recur(on, mv, longest, been, maze, length);
                    been.erase(mv);
                }
            }

            return;
        }
    }
}

void recur2(pairint prev, pairint on, ll &longest, set<pairint> been, vstr &maze, ll length)
{
    vpairint next;
    while (true)
    {

        if (on.first == maze.size() - 1)
        {
            longest = max(longest, length);
            if (length == longest)
                // cout << length << " " << longest << endl;
                return;
        }

        if (on.first > 0 && maze[on.first - 1][on.second] != '#' && prev.first != on.first - 1)
            next.push_back({on.first - 1, on.second});
        if (maze[on.first + 1][on.second] != '#' && prev.first != on.first + 1) // on.first < maze.size() - 1 &&
            next.push_back({on.first + 1, on.second});
        if (maze[on.first][on.second - 1] != '#' && prev.second != on.second - 1) // on.second > 0 &&
            next.push_back({on.first, on.second - 1});
        if (maze[on.first][on.second + 1] != '#' && prev.second != on.second + 1) // on.second < maze[0].length() - 1 &&
            next.push_back({on.first, on.second + 1});

        int count = next.size();
        if (count == 0)
            return;
        if (count == 1)
        {
            prev = on;
            on = next[0];
            length++;
            next.clear();
        }
        else
        {

            if (been.count(on) != 0) // if we entered the current path from the other side
                return;

            been.insert(on);
            length++;
            foe(mv, next)
            {
                if (been.count(mv) == 0)
                {
                    been.insert(mv);
                    recur2(on, mv, longest, been, maze, length);
                    been.erase(mv);
                }
            }

            return;
        }
    }
}
void p1()
{
    string x;
    vstr maze;
    while (cin >> x)
        maze.push_back(x);

    set<pairint> been;

    int xPos = maze[0].find('.');
    ll longest = 0;
    pairint prev = {-1, xPos}, on = {0, xPos};
    recur(prev, on, longest, been, maze, 0);

    cout << longest << endl;
}

void p2() // this works but is very slow (took 10 minutes on my computer)
{
    string x;
    vstr maze;
    while (cin >> x)
        maze.push_back(x);

    set<pairint> been;

    int xPos = maze[0].find('.');
    ll longest = 0;
    pairint prev = {-1, xPos}, on = {0, xPos};
    recur2(prev, on, longest, been, maze, 0);

    cout << longest << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // p1();
    p2();
}
