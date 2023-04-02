#include <bits/stdc++.h>
using namespace std;

void In_file()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

struct process
{
    char p_id[20];
    int allocation[30];
    int max_need[30];
};

int32_t main()
{
    In_file();
    //cout << "Hello\n";

    int n;
    // cout << "Enter Total Number of processes\n";
    cin >> n;
    struct process pros[n];
    int r = 3;
    int available[r];
    // cout << "Please enter the number of instances of available resources\n";
    for (int i = 0; i < r; i++)
        cin >> available[i];

    //cout << "Max Nedd nedded";
    // cout << "Please enter P-id Allocation Max_need\n";
    for (int i = 0; i < n; i++)
    {
        cin >> pros[i].p_id;
        for (int j=0; j<r; j++)
            cin >> pros[i].allocation[j];
        for (int j=0; j<r; j++)
            cin >> pros[i].max_need[j];
    }

    //cout << "Input taken";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
            pros[i].max_need[j] -= pros[i].allocation[j];
    }

    bool finish[n] = {false};
    vector<int> safe_seq = {0, 3, 4, 1, 2};

    //cout << "Calculating safe sequence";
    for (auto i : safe_seq)
    {
        for (int j = 0; j < r; j++)
        {
            if (pros[i].max_need[j] > available[j])
            {
                cout << "Unsafe Sequence";
                return 0;
            }
        }

        for (int j = 0; j < r; j++)
        {
            available[j] += pros[i].allocation[j];
        }
    }
    cout << "Safe Sequence\n";
    cout << endl;
}
