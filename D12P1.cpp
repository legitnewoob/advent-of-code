#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1000;
int dptb[N][N];
bool check(string s , int a , int b)
{
    for(int i = a ; i < a + b ; i++)
    {
        if(s[i] == '.') return false;
    }
    return true;
}

int check2(string s , int a , int b)
{
    for(int i = a ; i < b ; i++)
    {
        if(s[i] == '#') return 0;
    }

    return 1;
}

int dp(string &s , vector<int> &nums , int s_idx , int n_idx , int s_size , int n_size)
{
    if(s_idx >= s_size) return (n_idx == n_size ? 1 : 0);
    if(n_idx == n_size) return check2(s , s_idx , s_size);

    if(dptb[s_idx][n_idx] != -1) return dptb[s_idx][n_idx];

    int answer = 0;
    if(s[s_idx] == '.' or s[s_idx] == '?') 
    {
        answer += dp(s , nums , s_idx + 1 , n_idx , s_size , n_size);
    }

    if(s[s_idx] == '#' or s[s_idx] == '?')
    {
        int size = nums[n_idx];
        if(nums[n_idx] <= s_size - s_idx and check(s , s_idx , nums[n_idx]) and (nums[n_idx] == s_size - s_idx or s[s_idx + nums[n_idx]] != '#'))
        {
            answer += dp(s , nums , s_idx + nums[n_idx] + 1 , n_idx + 1 , s_size , n_size);
        }
    }

    return dptb[s_idx][n_idx] = answer;
}

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
    string s; int final_answer = 0;
    while(cin >> s)
    {
        vector<int> v; int index = 0;
        string num; cin >> num;

        vector<int> v2;
        while(index < num.size())
        {
            int x = parse_num(num , index);
            v.push_back(x);
            index++;
        }

        memset(dptb , -1 , sizeof(dptb));
        final_answer += dp(s , v , 0 , 0 , s.size() , v.size());

    }

    cout << final_answer << endl;
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
