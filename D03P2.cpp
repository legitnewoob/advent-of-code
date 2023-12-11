#include<bits/stdc++.h>
#include <cctype>
using namespace std;

int n , m;
int dirx[] = {-1 , -1 , -1 , 1 , 1 , 1};
int diry[] = {-1 , 0 , 1 , -1 , 0 , 1};


bool inbound(int i , int j)
{
    return (i >= 0 and i < n and j >= 0 and j < m);
}


int find_num(vector<string> input , pair<int , int> p , int number = 0)
{
    int x = p.first , y = p.second;
    
    while(y - 1 >= 0 and input[x][y - 1] >= '0' and input[x][y - 1] <= '9')
    {
        y--;
    }


    while(y < m and input[x][y] >= '0' and input[x][y] <= '9')
    {
        number = number * 10 + (input[x][y] - '0');
        y++;
    }


    return number;

}



void testcase() 
{
    vector<string> input;
    string input_part;
    while(getline(cin , input_part)) input.push_back(input_part);


    n = input.size() ; m = input[0].size() ; int answer = 0;


    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            int count = 0;
            if(input[i][j] == '*')
            {
                vector<pair<int , int >> coords;
                if(inbound(i , j - 1) and isdigit(input[i][j - 1])) {count++; coords.push_back({i , j - 1});}
                if(inbound(i , j + 1) and isdigit(input[i][j + 1])) {count++; coords.push_back({i , j + 1});}
     

                
                int temp_count = 0;
                for(int k = 0 ; k < 3 ; k++)
                {
                    int x = i + dirx[k] , y = j + diry[k];
     
                    if(inbound(x , y) and isdigit(input[x][y]))
                    {
                        if(!temp_count) coords.push_back({x , y});
                        temp_count++;
                    }

                }


                if(temp_count > 1 and isdigit(input[i - 1][j]))
                {
                    temp_count = 1;
                }
                else if(temp_count > 1 and !isdigit(input[i - 1][j]))
                {
                    coords.push_back({i - 1 , j + 1});
                }

                count += temp_count;
                temp_count = 0;

                for(int k = 3 ; k < 6 ; k++)
                {
                    int x = i + dirx[k] , y = j + diry[k];

                    if(inbound(x , y) and isdigit(input[x][y]))
                    {
                        if(!temp_count) coords.push_back({x , y});
                        temp_count++;
                    }
                }

                if(temp_count > 1 and isdigit(input[i + 1][j]))
                {
                    temp_count = 1;
                }
                else if(temp_count > 1 and !isdigit(input[i + 1][j]))
                {
                    coords.push_back({i + 1 , j + 1});
                }
                count += temp_count;

                if(coords.size() == 2)
                {
                        int number1 = find_num(input , coords[0]);
                        int number2 = find_num(input , coords[1]);


                        answer += number1 * number2;
                }
            }
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
