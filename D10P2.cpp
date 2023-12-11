#include <bits/stdc++.h>
using namespace std;

int n , m;

vector<int> dirx = {-1 , 1 , 0 , 0};
vector<int> diry = {0 , 0 , -1 , 1};



void intersect(set<char> &a , set<char> &b)
{
    set<char> to_rem;
    for(auto &i : a)
    {
        if(b.find(i) == b.end()) to_rem.insert(i);
    }

    for(auto &i : to_rem) a.erase(i);

}


void testcase() 
{
    string s;
    vector<string> chart;

    while (getline(cin, s)) chart.push_back(s);

    string top, bottom, left, right, c_t, c_b, c_l, c_r;
    top = "|7F"; bottom = "|LJ"; left = "-LF"; right = "-7J"; 
    c_t = "SLJ|"; c_b = "S|F7"; c_l = "S-J7"; c_r = "S-LF";

    set<char> s_t = {'|' , 'L' , 'J'} , s_b = {'|' , 'F' , '7'} , s_l = {'-' , 'J' , '7'} , s_r = {'-' , 'L' , 'F'};


    int x = -1, y = -1;

    for (int i = 0; i < chart.size(); i++) {
        for (int j = 0; j < chart[0].size(); j++) {
            if (chart[i][j] == 'S') {
                x = i;
                y = j;
            }
        }
    }

    n = chart.size(); m = chart[0].size();

    set<pair<int, int>> visited;
    queue<pair<int, int>> q;
    set<char> main = {'|' , '-' , '7' , 'F' , 'L' , 'J'};
    for(auto &i : main) cout << i << " ";cout << endl;


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
            if(chart[x][y] == 'S') intersect(main , s_t);
        }
        if (x < n - 1 and b != -1 and bottom.find(chart[x + 1][y]) != string::npos and visited.find({x + 1, y}) == visited.end()) {
            visited.insert({x + 1, y});
            q.push({x + 1, y});
            if(chart[x][y] == 'S') intersect(main , s_b);
        }
        if (y > 0 and c != -1 and left.find(chart[x][y - 1]) != string::npos and visited.find({x, y - 1}) == visited.end()) {
            visited.insert({x, y - 1});
            q.push({x, y - 1});
            if(chart[x][y] == 'S') intersect(main , s_l);
        }
        if (y < m - 1 and d != -1 and right.find(chart[x][y + 1]) != string::npos and visited.find({x, y + 1}) == visited.end()) {
            visited.insert({x, y + 1});
            q.push({x, y + 1});
            if(chart[x][y] == 'S') intersect(main , s_r);
        }
    }
    

    chart[x][y] = *main.begin();

    

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(visited.find({i , j}) == visited.end()) chart[i][j] = '.';
        }
    }

    // for(auto &i : chart) cout << i << endl;

    int count = 0;

    for(int i = 0 ; i < n ; i++)
    {
        bool within = false;
        int dir = 0;

        for(int j = 0 ; j < m ; j++)
        {
            if(chart[i][j] == '|')
            {
                within = !within;
            }
            else if(chart[i][j] == 'L') dir = 1;
            else if(chart[i][j] == 'F') dir = -1;
            else if(chart[i][j] == 'J' or chart[i][j] == '7')
            {
                if(dir == 1 and chart[i][j] == '7') within = !within;
                if(dir == -1 and chart[i][j] == 'J') within = !within;

                dir = 0;
            }
            else if(chart[i][j] == '.')
            {
                if(!within) count++;
            }
            
        }
    }


   
    cout << n * m - (visited.size() + count) << endl;



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
