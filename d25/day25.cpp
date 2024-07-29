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
#define vvint vector<vector<int>>
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

#define printall(x)        \
    for (auto zz : x)      \
    {                      \
        cout << zz << " "; \
    }                      \
    cout << endl;

#define printallpair(x)            \
    for (auto zz : x)              \
    {                              \
        cout << zz.first << " ";   \
        cout << zz.second << "\n"; \
    }

#define printall2d(x)          \
    for (auto zz : x)          \
    {                          \
        for (auto qq : zz)     \
        {                      \
            cout << qq << " "; \
        }                      \
        cout << "\n";          \
    }

void p1() // i got inspiration from the advent of code reddit for this idea. It is slow but should work
{
    map<string, int> mp;
    string x, tmp;
    int idx = 0, idxon;
    // while (cin >> x)
    vvint wires;
    while (getline(cin, x))
    {
        if (mp.count(x.substr(0, 3)) == 0)
        {
            // cout << idx << " " << x.substr(0, 3) << endl;
            mp[x.substr(0, 3)] = idx++;
            wires.push_back({});
        }
        idxon = mp[x.substr(0, 3)];

        istringstream iss(x.substr(5));
        while (iss >> tmp)
        {
            if (mp.count(tmp) == 0)
            {
                // cout << idx << " " << tmp << endl;
                mp[tmp] = idx++;
                wires.push_back({});
            }
            wires[idxon].push_back(mp[tmp]);
            wires[mp[tmp]].push_back(mp[x.substr(0, 3)]);
            // cout << tmp<<endl;
        }
    }

    set<int> group1, group2;
    int node1 = 0, node2 = 1; // the 'random' nodes to be selected, which is a node and one of its neighbours

    bool done = false;
    while (!done)
    {
        group1.clear();
        group2.clear();

        fo(i, 0, wires.size())
        {
            group1.insert(i);
        }
        bool change = true;

        // choose 2 'random' nodes to be in group 2
        group1.erase(node1);
        group1.erase(node2);
        group2.insert(node1);
        group2.insert(node2);

        // then, if a node has 2/more neighbours in group 2, add it to group 2
        // then after no more changes, check to see if the groups have 3 connections
        // * this does assume that 1 node in group 1 does not have 3 connections to group 2, and instead that 3 nodes in group1 have 1 connection each to a group2 node *
        while (change)
        {
            vint nodeChanges;
            // vint group2Remove; // if all of a nodes neighbours are in group 2, we can remove it from group 2 for computational efficiency
            change = false;

            set<int> toCheck; // to speed up the code, only look at neighbours of nodes that have been added to group 2
            foe(element, group2)
            {
                auto neighbours = wires[element];
                foe(neighbour, neighbours)
                {
                    if (group2.count(neighbour) == 0)
                        toCheck.insert(neighbour);
                }
            }
            foe(element, toCheck)
            {
                auto neighbours = wires[element];
                int count = 0;
                foe(neighbour, neighbours)
                {
                    if (group2.count(neighbour) > 0)
                    {
                        count++;
                    }
                }
                if (count >= 2)
                {
                    nodeChanges.push_back(element);
                    change = true;
                }
            }
            foe(element, nodeChanges)
            {
                group1.erase(element);
                group2.insert(element);
            }
        }

        // check how many neighbours each node has in group 1 has thats in group 2
        int count = 0;
        foe(element, group1)
        {
            auto neighbours = wires[element];
            foe(neighbour, neighbours)
            {
                if (group2.count(neighbour) > 0)
                {
                    count++;
                }
            }
        }

        if (count == 3)
        {
            done = true;
        }

        node2++;
        if (node2 == wires.size())
        {
            node1++;
            node2 = node1 + 1;
        }
        if (node1 == wires.size())
        {
            print("error");
            exit(0);
        }
    }

    print(group1.size() * group2.size());
    // print(group1.size());
    // print(group2.size());
    // print("");
    // printall(group1);
    // printall(group2);
}

void p1dif() // I got got inspiration for this from the advent of code reddit
{

    map<string, int> mp;
    string x, tmp;
    int idx = 0, idxon;
    // while (cin >> x)
    vvint wires;
    while (getline(cin, x))
    {
        if (mp.count(x.substr(0, 3)) == 0)
        {
            // cout << idx << " " << x.substr(0, 3) << endl;
            mp[x.substr(0, 3)] = idx++;
            wires.push_back({});
        }
        idxon = mp[x.substr(0, 3)];

        istringstream iss(x.substr(5));
        while (iss >> tmp)
        {
            if (mp.count(tmp) == 0)
            {
                // cout << idx << " " << tmp << endl;
                mp[tmp] = idx++;
                wires.push_back({});
            }
            wires[idxon].push_back(mp[tmp]);
            wires[mp[tmp]].push_back(mp[x.substr(0, 3)]);
            // cout << tmp<<endl;
        }
    }

    set<int> group1, group2;

    bool done = false;
    fo(i, 0, wires.size())
    {
        group1.insert(i);
    }

    // keep removing the node that has the most neighbours in group 2, as it is likely in group 2.
    // this only works if the first node is by chance in group 2 (which is the case here)
    // if not, you could rerun it with a different first node until it works
    while (!done)
    {

        int maxCount = -1;
        int maxNode = -1;

        foe(element, group1)
        {
            auto neighbours = wires[element];
            int count = 0;
            foe(neighbour, neighbours)
            {
                if (group2.count(neighbour) > 0)
                {
                    count++;
                }
            }
            if (count > maxCount)
            {
                maxCount = count;
                maxNode = element;
            }
        }
        group1.erase(maxNode);
        group2.insert(maxNode);

        // check how many neighbours each node has in group 1 has thats in group 2
        int count = 0;
        foe(element, group1)
        {
            auto neighbours = wires[element];
            foe(neighbour, neighbours)
            {
                if (group2.count(neighbour) > 0)
                {
                    count++;
                }
            }
        }

        if (count == 3)
        {
            done = true;
        }
        if (group1.size() == 0)
        {
            print("error");
            exit(0);
        }
    }

    print(group1.size() * group2.size());
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    p1dif();
}
