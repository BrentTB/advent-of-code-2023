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

void p1()
{
    string x;
    vstr rock;
    while (cin >> x)
    {
        rock.push_back(x);
    }
    string tmp;
    fo(i, 0, rock[0].length())
        tmp.push_back('#');
    rock.insert(rock.begin(), tmp);
    // printall(rock);

    ll sum = 0;
    int count = 0;
    fo(j, 0, rock[0].length())
    {
        fo(i, 0, rock.size())
        {
            if (rock[i][j] == '#') // find how many circles below
            {
                count = 0;
                fo(k, i + 1, rock.size())
                {
                    if (rock[k][j] == 'O')
                        count++;
                    if (rock[k][j] == '#')
                        break;
                }
                // cout << "hi"<<endl;
                fo(z, 0, count)
                {
                    sum += rock.size() - i - z - 1;
                    // cout << i+z<<endl;
                }
                // cout << sum << endl;
            }
        }
    }
    cout << sum << endl;
}

void north(vstr &rock)
{
    fo(j, 0, rock[0].length())
    {
        fo(i, 0, rock.size())
        {
            // cout << i << endl;
            // int next = i+1;
            if (rock[i][j] == '#' || i == 0) // find how many circles below
            {
                int count = 0;
                fo(k, i, rock.size())
                {
                    if (rock[k][j] == 'O')
                    {
                        rock[k][j] = '.';
                        count++;
                    }
                    elif ((rock[k][j] == '#' && k != i))
                    {
                        // next = k;
                        break;
                    }
                }
                if (rock[i][j] == '#')
                {
                    fo(z, 0, count)
                    {
                        rock[i + 1 + z][j] = 'O';
                        // sum += rock.size() - i - z - 1;
                        // cout << i+z<<endl;
                    }
                }
                else
                {
                    fo(z, 0, count)
                    {
                        rock[z][j] = 'O';
                    }
                }
                // i = next-1;
            }
        }
    }
}

void rotate90DegreesClockwise(vstr &rock)
{
    vstr tmp;
    fo(i, 0, rock[0].length())
    {
        string s = "";
        rfo(j, 0, rock.size())
        {
            s += rock[j][i];
        }
        tmp.push_back(s);
    }
    rock = tmp;
}

void west(vstr &rock)
{
    // rotate the vstr (90º clockwise), call north(), rotate back

    fo(i, 0, 1)
    {
        rotate90DegreesClockwise(rock);
    }
    north(rock);
    fo(i, 0, 3)
    {
        rotate90DegreesClockwise(rock);
    }
}

void south(vstr &rock)
{
    // rotate the vstr (180º clockwise), call north(), rotate back

    fo(i, 0, 2)
    {
        rotate90DegreesClockwise(rock);
    }
    north(rock);
    fo(i, 0, 2)
    {
        rotate90DegreesClockwise(rock);
    }
}

void east(vstr &rock)
{
    // rotate the vstr (270º clockwise), call north(), rotate back

    fo(i, 0, 3)
    {
        rotate90DegreesClockwise(rock);
    }
    north(rock);
    fo(i, 0, 1)
    {
        rotate90DegreesClockwise(rock);
    }
}

// void west(vstr &rock)
// {
//     fo(i, 0, rock.size())
//     {
//         fo(j, 0, rock[0].length())
//         {
//             // int next = j+1;
//             if (rock[i][j] == '#' || j == 0) // find how many circles below
//             {
//                 int count = 0;
//                 fo(k, j, rock[0].length())
//                 {
//                     if (rock[i][k] == 'O')
//                     {
//                         rock[i][k] = '.';
//                         count++;
//                     }
//                     if (rock[i][k] == '#' && k != j)
//                     {
//                         // next = k;
//                         break;
//                     }
//                 }
//                 if (rock[i][j] == '#')
//                 {
//                     fo(z, 0, count)
//                     {
//                         rock[i][j + 1 + z] = 'O';
//                     }
//                 }
//                 else
//                 {
//                     fo(z, 0, count)
//                     {
//                         rock[i][z] = 'O';
//                     }
//                 }
//                 // j = next - 1;
//             }
//         }
//     }
// }
// void south(vstr &rock)
// {
//     fo(j, 0, rock[0].length())
//     {
//         rfo(i, 0, rock.size())
//         {
//             // int next = i-1;
//             if (rock[i][j] == '#' || i == rock.size() - 1) // find how many circles below
//             {
//                 int count = 0;
//                 rfo(k, 0, i)
//                 {
//                     if (rock[k][j] == 'O')
//                     {
//                         rock[k][j] = '.';
//                         count++;
//                     }
//                     if (rock[k][j] == '#' && k != i)
//                     {
//                         // next = k;
//                         break;
//                     }
//                 }
//                 if (rock[i][j] == '#')
//                 {
//                     fo(z, 0, count)
//                     {
//                         rock[i - 1 - z][j] = 'O';
//                         // sum += rock.size() - i - z - 1;
//                         // cout << i+z<<endl;
//                     }
//                 }
//                 else
//                 {
//                     fo(z, 0, count)
//                     {
//                         rock[rock.size() - 1 - z][j] = 'O';
//                     }
//                 }
//                 // i = next + 1;
//             }
//         }
//     }
// }
// void east(vstr &rock)
// {
//     fo(i, 0, rock.size())
//     {
//         rfo(j, 0, rock[0].length())
//         {
//             // int next = j-1;
//             if (rock[i][j] == '#' || j == rock[0].length() - 1) // find how many circles below
//             {
//                 int count = 0;
//                 rfo(k, 0, j)
//                 {
//                     if (rock[i][k] == 'O')
//                     {
//                         rock[i][k] = '.';
//                         count++;
//                     }
//                     if (rock[i][k] == '#' && k != j)
//                     {
//                         // next = k;
//                         break;
//                     }
//                 }
//                 if (rock[i][j] == '#')
//                 {
//                     fo(z, 0, count)
//                     {
//                         rock[i][j - 1 - z] = 'O';
//                     }
//                 }
//                 else
//                 {
//                     fo(z, 0, count)
//                     {
//                         rock[i][rock.size() - 1 - z] = 'O';
//                     }
//                 }
//                 // j = next + 1;
//             }
//         }
//     }
// }

string vstrToString(vstr rock)
{
    string s = "";
    fo(i, 0, rock.size())
    {
        s += rock[i];
    }
    return s;
}

int rockInPrev(vstr rock, vstr allPrev)
{
    string s = vstrToString(rock);
    for (int i = 0; i < allPrev.size(); i++)
    {
        if (s == allPrev[i])
            return i;
    }
    return -1;
}

void p2()
{
    string x;
    vstr rock;
    while (cin >> x)
    {
        rock.push_back(x);
    }

    ll sum = 0;
    ll count = 0;
    v(vstr) prev;

    vstr allPrev;
    bool foundPeriod = false;

    int billion = 1000000000;
    while (count < billion)
    {

        allPrev.push_back(vstrToString(rock));

        north(rock);
        west(rock);
        south(rock);
        east(rock);

        int index = rockInPrev(rock, allPrev);

        if (index != -1 && !foundPeriod)
        {

            int period = count + 1 - index;
            count = billion - (billion - count) % period;
            foundPeriod = true;
        }
        count++;
    }

    // printall(rock);

    fo(i, 0, rock.size())
    {
        fo(j, 0, rock[0].length())
        {
            if (rock[i][j] == 'O')
            {
                sum += rock.size() - i;
            }
        }
    }
    cout << sum << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // p1();
    p2();
}
