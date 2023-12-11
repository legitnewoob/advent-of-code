#include<bits/stdc++.h>
using namespace std;

void testcase() 
{
    string s;
    vector<string> chart;
    while(getline(cin , s)) {chart.push_back(s);}
    int n = chart.size() , m = chart[0].size();
    set<int> emp_row , emp_col;
    vector<pair<int , int>> vp;


    for(int i = 0 ; i < n ; i++)
    {
        bool check = true;
        for(int j = 0 ; j < m ; j++)
        {
            if(chart[i][j] == '#')
            {
                vp.push_back({i , j});
                check = false;
            }
        }

        if(check) emp_row.insert(i);
    }

    for(int j = 0 ; j < m ; j++)
    {
        bool check = true;
        for(int i = 0 ; i < n ; i++)
        {
            if(chart[i][j] == '#') {check = false;}
        }

        if(check) emp_col.insert(j);
    }


    // for(auto &[x , y] : vp) cout << x << " " << y << endl;

    // for(auto &i : emp_col) cout << i << " "; cout << endl;

    // for(auto &i : emp_row) cout << i << " "; cout << endl;

    int answer = 0;
    for(int i = 0 ;  i < vp.size() ; i++)
    {
        for(int j = i + 1 ; j < vp.size() ; j++)
        {

            pair<int , int> p1 = vp[i] , p2 = vp[j];

            int x1 = p1.first , x2 = p2.first , y1 = p1.second , y2 = p2.second , temp_ans = 0;
            

            // cout << x1 << " " << y1 << " " << x2 << " " << y2 << " ";

            if(x1 > x2) swap(x1 , x2);
            if(y1 > y2) swap(y1 , y2);

            for(int k = x1 ; k < x2 ; k++)
            {
                if(emp_row.find(k) != emp_row.end()) temp_ans += 2;
                else temp_ans += 1;
            }

            for(int k = y1 ; k < y2 ; k++)
            {
                if(emp_col.find(k) != emp_col.end()) temp_ans += 2;
                else temp_ans += 1;
            }

            // cout << temp_ans << endl;
            answer += temp_ans;
        }
    }


    cout << answer << endl;


}


int main() 
{

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
            freopen("input.txt", "r", stdin);
            freopen("output.txt", "w", stdout);
        #endif

    int tc = 1;
    //cin >> tc;
    while(tc--) testcase();

    return 0;
}
