```#include<bits/stdc++.h>
using namespace std;

int getNumber(int &index, string &s, int number = 0)
{
    while(index < s.size() && s[index] >= '0' && s[index] <= '9')
    {
        number = number * 10 + (s[index] - '0');
        index++;
    }

    return number;
}

void testcase() 
{

	int answer = 0; string s; 

    while(getline(cin , s))
    {
        int index = 5 , id = getNumber(index , s);
        index += 2; bool possible = true;
        // cout << index << endl;

        while(index < s.size())
        {
            int number = getNumber(index, s);
            if(s[index + 1] == 'r' and number > 12) possible = false;
            else if(s[index + 1] == 'g' and number > 13) possible = false;
            else if(number > 14) possible = false;


            if(s[index + 1] == 'r') index += 6;

            else if(s[index + 1] == 'b') index += 7;

            else if(s[index + 1] == 'g') index += 8;
        }

        if(possible) answer += id;

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
```
