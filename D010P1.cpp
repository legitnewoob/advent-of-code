#include <bits/stdc++.h>
using namespace std;

void testcase() 
{
    string s;
    vector<string> chart;
    while (getline(cin, s)) chart.push_back(s);
    string top, bottom, left, right, c_t, c_b, c_l, c_r;
    top = "|7F"; bottom = "|LJ"; left = "-LF"; right = "-7J"; 
    c_t = "SLJ|"; c_b = "S|F7"; c_l = "S-J7"; c_r = "S-LF";

    int x = -1, y = -1;

    for (int i = 0; i < chart.size(); i++) {
        for (int j = 0; j < chart[0].size(); j++) {
            if (chart[i][j] == 'S') {
                x = i;
                y = j;
            }
        }
    }

    int n = chart.size(), m = chart[0].size();

    set<pair<int, int>> visited;
    queue<pair<int, int>> q;

    visited.insert({x, y});
    q.push({x, y});

    while (q.size()) {
        pair<int, int> p = q.front();
        q.pop();

        int x = p.first, y = p.second;

        int a = c_t.find(chart[x][y]), b = c_b.find(chart[x][y]), c = c_l.find(chart[x][y]), d = c_r.find(chart[x][y]);
        
        if (x > 0 and a != -1 and top.find(chart[x - 1][y]) != string::npos and visited.find({x - 1, y}) == visited.end()) {
            visited.insert({x - 1, y});
            q.push({x - 1, y});
        }
        if (x < n - 1 and b != -1 and bottom.find(chart[x + 1][y]) != string::npos and visited.find({x + 1, y}) == visited.end()) {
            visited.insert({x + 1, y});
            q.push({x + 1, y});
        }
        if (y > 0 and c != -1 and left.find(chart[x][y - 1]) != string::npos and visited.find({x, y - 1}) == visited.end()) {
            visited.insert({x, y - 1});
            q.push({x, y - 1});
        }
        if (y < m - 1 and d != -1 and right.find(chart[x][y + 1]) != string::npos and visited.find({x, y + 1}) == visited.end()) {
            visited.insert({x, y + 1});
            q.push({x, y + 1});
        }
    }
    
    for(auto &[x , y] : visited)
    {
        chart[x][y] = 'Q';
    }

    // for(auto &i : chart) cout << i << endl;
    //     cout << endl;
    cout << visited.size() / 2 << endl;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int tc = 1;
    //cin >> tc;
    while (tc--) testcase();

    return 0;
}
