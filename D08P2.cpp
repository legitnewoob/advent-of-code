#include<bits/stdc++.h>
using namespace std;
#define int long long


    
void testcase() 
{

    string rule; cin >> rule;

    map<string , vector<string>> map;

    string s;
    vector<string> starting_nodes;
    while(cin >> s)
    {
        if(s[2] == 'A') starting_nodes.push_back(s);
        string a , b; cin >> a >> b;
        map[s].push_back(a);
        map[s].push_back(b);
    }



    int count = 0 , index = 0;

    vector<int> paths;

    for(int i = 0 ; i < starting_nodes.size() ; i++)
    {
        string curr = starting_nodes[i];
        int count = 0 , index = 0 , idx = 0;

        while(curr[2] != 'Z')
        {
            if(rule[index] == 'L') idx = 0;
            else idx = 1;

            curr = map[curr][idx];
            count++;
            index = (index + 1) % (rule.size());
        }

        paths.push_back(count);
    }

    int mega_gcd = paths[0]; for(auto &i : paths) mega_gcd = __gcd(mega_gcd , i);
    int product = paths[0];

    for(int i = 0 ; i < paths.size() ; i++)
    {
        product = (paths[i] * product) / __gcd(paths[i] , product);
    }

    cout << product << endl;

    
}


    int32_t main() 
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
