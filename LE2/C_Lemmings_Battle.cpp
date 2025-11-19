#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

void solve()
{
    int B, SG, SB;
    cin >> B >> SG >> SB;

    priority_queue<int> green_army;
    for (int i = 0; i < SG; ++i)
    {
        int power;
        cin >> power;
        green_army.push(power);
    }

    priority_queue<int> blue_army;
    for (int i = 0; i < SB; ++i)
    {
        int power;
        cin >> power;
        blue_army.push(power);
    }

    while (!green_army.empty() && !blue_army.empty())
    {
        vector<int> green_survivors;
        vector<int> blue_survivors;

        int battles = min({B, (int)green_army.size(), (int)blue_army.size()});

        for (int i = 0; i < battles; ++i)
        {
            int green_power = green_army.top();
            green_army.pop();
            int blue_power = blue_army.top();
            blue_army.pop();

            if (green_power > blue_power)
            {
                green_survivors.push_back(green_power - blue_power);
            }
            else if (blue_power > green_power)
            {
                blue_survivors.push_back(blue_power - green_power);
            }
        }

        for (int power : green_survivors)
        {
            green_army.push(power);
        }
        for (int power : blue_survivors)
        {
            blue_army.push(power);
        }
    }

    if (green_army.empty() && blue_army.empty())
    {
        cout << "green and blue died" << endl;
    }
    else if (green_army.empty())
    {
        cout << "blue wins" << endl;
        while (!blue_army.empty())
        {
            cout << blue_army.top() << endl;
            blue_army.pop();
        }
    }
    else
    {
        cout << "green wins" << endl;
        while (!green_army.empty())
        {
            cout << green_army.top() << endl;
            green_army.pop();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    while (N--)
    {
        solve();
        if (N > 0)
        {
            cout << "\n";
        }
    }

    return 0;
}
