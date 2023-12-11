#include<bits/stdc++.h>
using namespace std;
#define int long long


int parse_num(string s , int &index , int number = 0)
{
    while(index < s.size() and s[index] >= '0' and s[index] <= '9')
    {
        number = number * 10 + (s[index] - '0');
        index++;
    }
    return number;
}

void testcase() 
{
    string s; int index = 7 , data_idx = 0 , map_idx = 0;

    vector<string> data; while(getline(cin , s)) data.push_back(s);
    
    vector<int> seeds ; 
    vector<map<int , int>> vmp(8);



    for( ; index < data[0].size() ; index++)
    {
        int number = parse_num(data[0] , index);
        seeds.push_back(number);
    }

    for(auto &i : seeds) vmp[0][i] = i;


    data_idx++;


    for( ; data_idx < data.size() ; data_idx++)
    {

        if(data[data_idx] == "") continue;
        

        else if(!isdigit(data[data_idx][0]))
        {
            map_idx++;


            for(auto &[x , y] : vmp[map_idx - 1])
            {
                vmp[map_idx][y] = y;
            }
        }

        else
        {
            vector<int> temp;
            for(int idx = 0 ; idx < data[data_idx].size() ; idx++)
            {
                int number = parse_num(data[data_idx] , idx);
                temp.push_back(number);
            }

            
            int i = temp[1] , j = temp[0] , k = temp[2];
            

            for(auto &[x , y] : vmp[map_idx])
            {
                if(x >= i and x <= i + k)
                {
                    vmp[map_idx][x] = (x - i) + j;
                }
            }

        }


    }

    int answer = LONG_LONG_MAX;
    for(auto &seed : seeds)
    {
        int value = seed;

        for(int j = 1 ; j <= 7 ; j++)
        {
            value = vmp[j][value];
        }

        answer = min(value , answer);
    }

    cout << answer << endl;

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
