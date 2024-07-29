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

void p1()
{
    string x;
    vstr land;
    while (cin >> x)
    {
        land.push_back(x);
    }

    set<pair<int, int>> on;
    set<pair<int, int>> next;
    fo(i, 0, land.size())
    {
        fo(j, 0, land[i].size())
        {
            if (land[i][j] == 'S')
            {
                on.insert({i, j});
                land[i][j] = '.';
                break;
            }
        }
    }
    fo(i, 0, 64) // 64 for proper
    {
        foe(itr, on)
        {
            if (itr.first > 0 && land[itr.first - 1][itr.second] == '.')
                next.insert({itr.first - 1, itr.second});
            if (itr.first < land.size() - 1 && land[itr.first + 1][itr.second] == '.')
                next.insert({itr.first + 1, itr.second});
            if (itr.second > 0 && land[itr.first][itr.second - 1] == '.')
                next.insert({itr.first, itr.second - 1});
            if (itr.second < land.size() - 1 && land[itr.first][itr.second + 1] == '.')
                next.insert({itr.first, itr.second + 1});
        }
        on.clear();
        on = next;
        next.clear();
    }

    cout << on.size() << endl;
}

ull quadratic(ll one, ll two, ll three, int x)
{
    ll a, b, c;
    a = ((three - two) - (two - one)) / 2;
    b = (two - one) - 3 * a;
    c = one - a - b;
    // cout << x << endl;
    // cout << a << endl;
    // cout << b << endl;
    // cout << c << endl;

    return a * x * x + b * x + c;
}
/*191190      97615       35218       3957
          93575      62397    31261
                31178   31136

    658807        315899      97615        3957
            342908      218284      93658
                   124626     124626


    3957,97615,315899,658807


    ax^2+bx+c:
    a = 124626/2
    b = 93658-3*a
    c = 3957-a-b
    */

void p2() // this does not work (or takes too long to run). I solved this problem with a lot of math, deductions, some code, and a decent amount of guesswork
{

    cout << quadratic(3957, 97645, 315957, ((26501365 - 65) / 131) / 2) << endl;
    cout << quadratic(3957, 97615, 315899, 1) << endl;
    cout << quadratic(3957, 97615, 315899, 2) << endl;
    cout << quadratic(3957, 97615, 315899, 3) << endl;
    cout << quadratic(3957, 97615, 315899, 4) << endl;
    return;
    string x;
    vstr land;
    while (cin >> x)
    {
        land.push_back(x);
    }

    set<pair<int, int>> on;
    set<pair<int, int>> next;
    fo(i, 0, land.size())
    {
        fo(j, 0, land[i].size())
        {
            if (land[i][j] == 'S')
            {
                on.insert({i, j});
                land[i][j] = '.';
                break;
            }
        }
    }
    cout << land.size() << endl;
    // vll res;
    fo(i, 0, 65 + 131 * 6) // 64 for proper
    {
        foe(itr, on)
        {
            if (land[(itr.first - 1) % land.size()][(itr.second) % land[0].size()] == '.')
                next.insert({itr.first - 1, itr.second});
            if (land[(itr.first + 1) % land.size()][(itr.second) % land[0].size()] == '.')
                next.insert({itr.first + 1, itr.second});
            if (land[(itr.first) % land.size()][(itr.second - 1) % land[0].size()] == '.')
                next.insert({itr.first, itr.second - 1});
            if (land[(itr.first) % land.size()][(itr.second + 1) % land[0].size()] == '.')
                next.insert({itr.first, itr.second + 1});
        }
        on.clear();
        on = next;
        next.clear();

        // cout << i + 1 << "  " << on.size() << endl;
        // res.push_back(on.size());
    }
    cout << on.size() << endl;

    // fo(i, 0, res.size() - 1)
    // {
    //     cout << res[i + 1] - res[i] << endl;
    // }
    // highr than 4107 on 66

    // int fi=131*1;
    // int se = -131*2;
    // int count = 0;
    // foe(itr, on)
    // {
    //     if (itr.first + fi >= 0 && itr.first + fi < land.size() && itr.second+se >= 0 && itr.second+se < land[0].size())
    //         land[itr.first + fi][itr.second+se] = 'O', count++;
    // }
    // printall(land);
    // cout << count << endl;

    /*
    after 65:       3957
    after 65+131:   35218
    after 65+131*2: 97615
    after 65+131*3: 191190
    after 65+131*4: 315899
    after 65+131*6: 658807


    191190      97615       35218       3957
          93575      62397    31261
                31178   31136

    658807        315899      97615        3957
            342908      218284      93658
                   124624     124626


    3957,97615,315899,658807
3957,97645,315957,658893


3957,35223,97645,191223,315957,471847,658893
    ax^2+bx+c:
    a = 124626/2
    b = 93658-3*a
    c = 3957-a-b

    */

    // count = 0;
    // foe(itr, on)
    // {
    //     if (itr.first + 131 >= 0 && itr.first + 131 < land.size() && itr.second >= 0 && itr.second < land[0].size())
    //         count++;
    // }
    // cout << count << endl;
    // count = 0;
    // foe(itr, on)
    // {
    //     if (itr.first >= 0 && itr.first < land.size() && itr.second - 131 >= 0 && itr.second - 131 < land[0].size())
    //         count++;
    // }
    // cout << count << endl;
    // count = 0;
    // foe(itr, on)
    // {
    //     if (itr.first >= 0 && itr.first < land.size() && itr.second + 131 >= 0 && itr.second + 131 < land[0].size())
    //         count++;
    // }
    // cout << count << endl;
}

pairll series(int num)
{
    ll type1 = 1, type2 = 0;
    ll add = 4;
    fo(i, 0, num - 1)
    {
        if (i % 2 == 0)
        {
            type2 += add;
        }
        else
            type1 += add;
        add += 4;
    }
    return {type1, type2}; // type 1 represents the same type of square as the starting one
}

pairint numEmptyEven(vstr &land)
{
    int t1 = 0, t2 = 0;
    for (int i = 0; i < land.size(); i++)
    {
        for (int j = i % 2; j < land[0].size(); j += 2)
        {
            if (land[i][j] == '.')
                t1++;
        }
    }
    for (int i = 0; i < land.size(); i++)
    {
        for (int j = (i + 1) % 2; j < land[0].size(); j += 2)
        {
            if (land[i][j] == '.')
                t2++;
        }
    }
    return {t1, t2};
}

void p2dif()
{
    cout << series((26501365 - 65) / 131).first << endl;
    cout << series((26501365 - 65) / 131).second << endl;
    string x;
    vstr land;
    while (cin >> x)
    {
        land.push_back(x);
    }
    cout << numEmptyEven(land).first << endl;
    cout << numEmptyEven(land).second << endl;

    int startx, starty;
    set<pair<int, int>> on;
    set<pair<int, int>> next;
    fo(i, 0, land.size())
    {
        fo(j, 0, land[i].size())
        {
            if (land[i][j] == 'S')
            {
                startx = i, starty = j;
                on.insert({i + 1, j}); // 1 move
                on.insert({i - 1, j});
                on.insert({i, j + 1});
                on.insert({i, j - 1});
                land[i][j] = '.';
                break;
            }
        }
    }
    cout << land.size() << endl;
    vll res;
    ll count = 4;
    fo(i, 0, 20) // 64 for proper
    {
        foe(itr, on)
        {
            if (itr.first <= startx && land[(itr.first - 2) % land.size()][(itr.second) % land[0].size()] == '.')
                next.insert({itr.first - 2, itr.second}), count++;
            if (itr.first >= startx && land[(itr.first + 2) % land.size()][(itr.second) % land[0].size()] == '.')
                next.insert({itr.first + 2, itr.second}), count++;
            if (itr.second <= starty && land[(itr.first) % land.size()][(itr.second - 2) % land[0].size()] == '.')
                next.insert({itr.first, itr.second - 2}), count++;
            if (itr.second >= starty && land[(itr.first) % land.size()][(itr.second + 2) % land[0].size()] == '.')
                next.insert({itr.first, itr.second + 2}), count++;
        }
        on.clear();
        on = next;
        next.clear();

        cout << 2 * i + 3 << "  " << count << endl;
        res.push_back(on.size());
    }

    // fo(i,0,res.size()-1)
    // {
    //     cout << res[i+1]-res[i]<<endl;
    // }
    // highr than 4107 on 66

    foe(itr, on)
    {
        land[itr.first][itr.second] = 'O';
    }
    printall(land);
}
/*
it takes 65 steps to reach the end from the beginning, and it would take another 131 steps to go to start of next edge

131x131

26501365
(26501365-65)/131 = 202 300 = number of full blocks it can touch at the end in one direction
there will be 81850175401 full blocks enclosed, and there are 2 types of full blocks (both being indneted one off from each other)
40924885401 type 1 (middle is not included) -> 7791 circles
40925290000 type 2 (middle is included) -> 7787 circles

points have 5870, 5861, 5878, 5872 circles in them
the one to the right of the bottom point = 986, to the left is

    5870
5878    5872
    5861

202300 = x
637531038447447
637128089417857


correct:

10  110
11  128
12  154
13  177
14  206
15  235
16  261
17  295
18  326
19  366
20  402
21  443
22  478
23  519
24  567
25  606
26  663
27  703
28  766
29  812
30  879
31  924
32  983



.....
..p..
.pxp.
..p..
.....

.ppp.
ppxpp
pxxxp
ppxpp
.ppp.

1 5 13 25
+4, +8, +12



..o.o
.o.o.
o.o.o
.o.o.
..o.o

...o.  o.o.o
....o  .o.o.
.....  o.o.o
.....  .o.o.
.....  ..o.o

*/
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // p2dif();
    p1();
    // p2();
}
