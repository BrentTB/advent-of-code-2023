#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define endl "\n"
#define elif else if
#define fo(i, a, b) for (int i = a; i < (int)b; i++)
#define foe(a, b) for (auto a : b)
#define rfo(i, a, b) for (int i = a - 1; i >= b; i--)
#define v(i) vector<i>
#define vll vector<long long>
#define vint vector<int>
#define vstr vector<string>
#define pairll pair<long long, long long>
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

#define printall2(x)         \
    for (auto zz : x)        \
    {                        \
        for (auto z : zz)    \
        {                    \
            cout << z << ""; \
        }                    \
        cout << "\n";        \
    }

#define printallpair(x)            \
    for (auto zz : x)              \
    {                              \
        cout << zz.first << " ";   \
        cout << zz.second << "\n"; \
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

pair<int, int> nextStart(vstr &maze, pair<int, int> on, pair<int, int> used)
{

    if (maze[on.first + 1][on.second] == '|' || maze[on.first + 1][on.second] == 'L' || maze[on.first + 1][on.second] == 'J')
    {
        if (on.first + 1 != used.first || on.second != used.second)
            return {on.first + 1, on.second};
    }

    if (maze[on.first - 1][on.second] == '|' || maze[on.first - 1][on.second] == '7' || maze[on.first - 1][on.second] == 'F')
    {
        if (on.first - 1 != used.first || on.second != used.second)
            return {on.first - 1, on.second};
    }

    if (maze[on.first][on.second + 1] == '-' || maze[on.first][on.second + 1] == 'J' || maze[on.first][on.second + 1] == '7')
    {
        if (on.first != used.first || on.second + 1 != used.second)
            return {on.first, on.second + 1};
    }

    if (maze[on.first][on.second - 1] == '-' || maze[on.first][on.second - 1] == 'F' || maze[on.first][on.second - 1] == 'L')
    {
        if (on.first != used.first || on.second - 1 != used.second)
            return {on.first, on.second - 1};
    }

    // cout << on.first << " " << on.second<< endl<<endl;
    // cout << used.first << " " << used.second<< endl<<endl;
    return {-1, -1};
}

pair<int, int> next(vstr &maze, pair<int, int> prev, pair<int, int> on)
{

    if (maze[on.first][on.second] == '|')
    {
        if (on.first - 1 != prev.first || on.second != prev.second)
            return {on.first - 1, on.second};
        return {on.first + 1, on.second};
    }

    if (maze[on.first][on.second] == '-')
    {
        if (on.first != prev.first || on.second - 1 != prev.second)
            return {on.first, on.second - 1};
        return {on.first, on.second + 1};
    }

    if (maze[on.first][on.second] == 'L')
    {
        if (on.first - 1 != prev.first || on.second != prev.second)
            return {on.first - 1, on.second};
        return {on.first, on.second + 1};
    }

    if (maze[on.first][on.second] == '7')
    {
        if (on.first + 1 != prev.first || on.second != prev.second)
            return {on.first + 1, on.second};
        return {on.first, on.second - 1};
    }

    if (maze[on.first][on.second] == 'F')
    {
        if (on.first + 1 != prev.first || on.second != prev.second)
            return {on.first + 1, on.second};
        return {on.first, on.second + 1};
    }

    if (maze[on.first][on.second] == 'J')
    {
        if (on.first - 1 != prev.first || on.second != prev.second)
            return {on.first - 1, on.second};
        return {on.first, on.second - 1};
    }
    // cout << maze[on.first][on.second]<<endl;
    return {-1, -1};
}

pair<int, int> next2(vstr &maze, pair<int, int> prev, pair<int, int> on, v(v(char)) & wall)
{
    if (maze[on.first][on.second] == '|')
    {
        if (on.first - 1 != prev.first || on.second != prev.second)
            return {on.first - 1, on.second};
        return {on.first + 1, on.second};
    }

    if (maze[on.first][on.second] == '-')
    {
        if (on.first != prev.first || on.second - 1 != prev.second)
            return {on.first, on.second - 1};
        return {on.first, on.second + 1};
    }

    if (maze[on.first][on.second] == 'L')
    {
        if (on.first - 1 != prev.first || on.second != prev.second)
            return {on.first - 1, on.second};
        return {on.first, on.second + 1};
    }

    if (maze[on.first][on.second] == '7')
    {
        if (on.first + 1 != prev.first || on.second != prev.second)
            return {on.first + 1, on.second};
        return {on.first, on.second - 1};
    }

    if (maze[on.first][on.second] == 'F')
    {
        if (on.first + 1 != prev.first || on.second != prev.second)
            return {on.first + 1, on.second};
        return {on.first, on.second + 1};
    }

    if (maze[on.first][on.second] == 'J')
    {
        if (on.first - 1 != prev.first || on.second != prev.second)
            return {on.first - 1, on.second};
        return {on.first, on.second - 1};
    }
    // cout << maze[on.first][on.second]<<endl;
    return {-1, -1};
}

pair<int, int> next3(vstr &maze, pair<int, int> prev, pair<int, int> on, v(v(char)) & wall, char &dir)
{
    // cout << on.first << " " << on.second << " " << dir<<endl;
    if (dir == 'w' && wall[on.first - 1][on.second] == '.')
        wall[on.first - 1][on.second] = 'I';
    if (dir == 's' && wall[on.first + 1][on.second] == '.')
        wall[on.first + 1][on.second] = 'I';
    if (dir == 'a' && wall[on.first][on.second - 1] == '.')
        wall[on.first][on.second - 1] = 'I';
    if (dir == 'd' && wall[on.first][on.second + 1] == '.')
        wall[on.first][on.second + 1] = 'I';

    // if (dir == 'w' && wall[on.first - 1][on.second+1] == '.')
    //     wall[on.first - 1][on.second+1] = 'I';
    // if (dir == 's' && wall[on.first + 1][on.second+1] == '.')
    //     wall[on.first + 1][on.second+1] = 'I';
    // if (dir == 'a' && wall[on.first+1][on.second - 1] == '.')
    //     wall[on.first+1][on.second - 1] = 'I';
    // if (dir == 'd' && wall[on.first+1][on.second + 1] == '.')
    //     wall[on.first+1][on.second + 1] = 'I';

    // if (dir == 'w' && wall[on.first - 1][on.second-1] == '.')
    //     wall[on.first - 1][on.second-1] = 'I';
    // if (dir == 's' && wall[on.first + 1][on.second-1] == '.')
    //     wall[on.first + 1][on.second-1] = 'I';
    // if (dir == 'a' && wall[on.first-1][on.second - 1] == '.')
    //     wall[on.first-1][on.second - 1] = 'I';
    // if (dir == 'd' && wall[on.first-1][on.second + 1] == '.')
    //     wall[on.first-1][on.second + 1] = 'I';

    if (maze[on.first][on.second] == '|')
    {
        if (on.first - 1 != prev.first || on.second != prev.second)
            return {on.first - 1, on.second};
        return {on.first + 1, on.second};
    }

    if (maze[on.first][on.second] == '-')
    {
        if (on.first != prev.first || on.second - 1 != prev.second)
            return {on.first, on.second - 1};
        return {on.first, on.second + 1};
    }

    if (maze[on.first][on.second] == 'L')
    {
        if (on.first - 1 != prev.first || on.second != prev.second) // coming from the right
        {
            if (dir == 'w')
            {
                dir = 'd';
            }
            else
            {
                dir = 'a';

                if (wall[on.first + 1][on.second] == '.')
                    wall[on.first + 1][on.second] = 'I';
                if (wall[on.first + 1][on.second - 1] == '.')
                    wall[on.first + 1][on.second - 1] = 'I';
                if (wall[on.first][on.second - 1] == '.')
                    wall[on.first][on.second - 1] = 'I';
            }
            return {on.first - 1, on.second};
        }
        if (dir == 'd')
        {
            dir = 'w';
        }
        else
        {
            dir = 's';
            if (wall[on.first + 1][on.second] == '.')
                wall[on.first + 1][on.second] = 'I';
            if (wall[on.first + 1][on.second - 1] == '.')
                wall[on.first + 1][on.second - 1] = 'I';
            if (wall[on.first][on.second - 1] == '.')
                wall[on.first][on.second - 1] = 'I';
        }
        return {on.first, on.second + 1};
    }

    if (maze[on.first][on.second] == '7')
    {
        if (on.first + 1 != prev.first || on.second != prev.second) // come from left
        {
            if (dir == 'w')
            {
                dir = 'd';

                if (wall[on.first - 1][on.second] == '.')
                    wall[on.first - 1][on.second] = 'I';
                if (wall[on.first - 1][on.second + 1] == '.')
                    wall[on.first - 1][on.second + 1] = 'I';
                if (wall[on.first][on.second + 1] == '.')
                    wall[on.first][on.second + 1] = 'I';
            }
            else
                dir = 'a';
            return {on.first + 1, on.second};
        }
        if (dir == 'd')
        {
            dir = 'w';

            if (wall[on.first - 1][on.second] == '.')
                wall[on.first - 1][on.second] = 'I';
            if (wall[on.first - 1][on.second + 1] == '.')
                wall[on.first - 1][on.second + 1] = 'I';
            if (wall[on.first][on.second + 1] == '.')
                wall[on.first][on.second + 1] = 'I';
        }
        else
            dir = 's';
        return {on.first, on.second - 1};
    }

    if (maze[on.first][on.second] == 'F')
    {
        if (on.first + 1 != prev.first || on.second != prev.second) // coming from right
        {
            if (dir == 'w')
            {
                dir = 'a';

                if (wall[on.first - 1][on.second] == '.')
                    wall[on.first - 1][on.second] = 'I';
                if (wall[on.first - 1][on.second - 1] == '.')
                    wall[on.first - 1][on.second - 1] = 'I';
                if (wall[on.first][on.second - 1] == '.')
                    wall[on.first][on.second - 1] = 'I';
            }
            else
                dir = 'd';
            return {on.first + 1, on.second};
        }
        if (dir == 'd')
            dir = 's';
        else
        {
            dir = 'w';

            if (wall[on.first - 1][on.second] == '.')
                wall[on.first - 1][on.second] = 'I';
            if (wall[on.first - 1][on.second - 1] == '.')
                wall[on.first - 1][on.second - 1] = 'I';
            if (wall[on.first][on.second - 1] == '.')
                wall[on.first][on.second - 1] = 'I';
        }
        return {on.first, on.second + 1};
    }

    if (maze[on.first][on.second] == 'J')
    {
        if (on.first - 1 != prev.first || on.second != prev.second) // from the left
        {
            if (dir == 'w')
                dir = 'a';
            else
            {
                dir = 'd';

                if (wall[on.first + 1][on.second] == '.')
                    wall[on.first + 1][on.second] = 'I';
                if (wall[on.first + 1][on.second + 1] == '.')
                    wall[on.first + 1][on.second + 1] = 'I';
                if (wall[on.first][on.second + 1] == '.')
                    wall[on.first][on.second + 1] = 'I';
            }
            return {on.first - 1, on.second};
        }
        if (dir == 'd')
        {
            dir = 's';

            if (wall[on.first + 1][on.second] == '.')
                wall[on.first + 1][on.second] = 'I';
            if (wall[on.first + 1][on.second + 1] == '.')
                wall[on.first + 1][on.second + 1] = 'I';
            if (wall[on.first][on.second + 1] == '.')
                wall[on.first][on.second + 1] = 'I';
        }
        else
            dir = 'w';
        return {on.first, on.second - 1};
    }
    // cout << maze[on.first][on.second]<<endl;
    return {-1, -1};
}

void p1()
{
    vstr maze;
    string x;
    while (getline(cin, x))
        maze.push_back(x);

    pair<int, int> on1 = {-1, -1};
    pair<int, int> on2 = {-1, -1};

    fo(i, 0, maze.size())
    {
        fo(j, 0, maze[i].length())
        {
            if (maze[i][j] == 'S')
            {
                on2 = {i, j};
                break;
            }
        }
    }
    pair<int, int> prev1 = on2;
    pair<int, int> prev2 = on2;
    on1 = nextStart(maze, on2, on1);
    on2 = nextStart(maze, on2, on1);
    int steps = 1;

    while (on1 != on2) // && steps < 100)
    {
        auto tmp1 = on1;
        auto tmp2 = on2;
        on1 = next(maze, prev1, on1);
        on2 = next(maze, prev2, on2);
        prev1 = tmp1;
        prev2 = tmp2;
        steps++;
    }
    cout << steps << endl;
}

void p2()
{

    char dir = 'u'; // will work either for dir = 'u' or dir = 'd', depending on the landscape.
    // I could have made a way to check which is correct (if we start counting things on the edge of the mpa, the direction must be wrong)
    // but it was quicker to just run it twice, once with dir = 'd' and once with dir = 'u' and see which one is correct
    // for the 2 examples given, dir = d, but for the real puzzle input, dir = u

    vstr maze;
    string x;
    while (getline(cin, x))
        maze.push_back(x);

    v(v(char)) wall(maze.size(), v(char)(maze[0].length(), '.')); // . = other, W = wall, I = any in or nex to in
    pair<int, int> on = {-1, -1};

    fo(i, 0, maze.size())
    {
        fo(j, 0, maze[i].length())
        {
            if (maze[i][j] == 'S')
            {
                on = {i, j};
                break;
            }
        }
    }
    pair<int, int> start = on;
    wall[on.first][on.second] = 'W';
    pair<int, int> prev = on;
    on = nextStart(maze, on, on);
    wall[on.first][on.second] = 'W';

    while (on != start) // get the walls
    {
        auto tmp = on;
        on = next2(maze, prev, on, wall);
        prev = tmp;
        wall[on.first][on.second] = 'W';

        // steps++;
    }

    int area = 0;
    fo(i, 0, maze.size())
    {
        fo(j, 0, maze[0].length())
        {
            if (wall[i][j] != 'W')
                maze[i][j] = '.';
        }
    }

    on = nextStart(maze, start, start);
    prev = start;
    while (on != start) // && steps < 100)
    {
        auto tmp = on;
        on = next3(maze, prev, on, wall, dir);
        prev = tmp;
    }
    // cout << steps << endl;

    // vpairint todo;
    bool change = true;
    while (change)
    {
        change = false;
        fo(i, 0, maze.size())
        {
            fo(j, 0, maze[0].length())
            {
                if (i == 0 || i == maze.size() - 1 || j == 0 || j == maze[0].length() - 1)
                    continue;
                if (wall[i][j] == '.' && (wall[i + 1][j] == 'I' || wall[i - 1][j] == 'I' || wall[i][j + 1] == 'I' || wall[i + 1][j - 1] == 'I'))
                {
                    wall[i][j] = 'I';
                    change = true;
                }
            }
        }
    }
    fo(i, 0, maze.size())
    {
        fo(j, 0, maze[0].length())
        {
            if (wall[i][j] == 'I')
                area++;
        }
    }
    cout << area << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // p1();
    p2();
}
