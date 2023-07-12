#include <bits/stdc++.h>

using namespace std;

void printState(vector<int> frames)
{
    for (int x: frames)
    {
        cout << " ";
        x == -1 ? cout << "-" : cout << x;
    }
    cout << "\n";
}

int main()
{
    freopen("second.txt", "r", stdin);
    int size; //... Total number of frames
    cin >> size;
    vector<int> frames(size, -1);
    map<int, int> reference; //... Page's reference bit
    int miss = 0, page;
    int index = 0; //... Frame pointer

    while (cin >> page)
    {
        bool found = false;
        for (int x: frames)
        {
            if (x == page)
            {
                reference[page] = 1;
                found = true;
                break;
            }
        }

        if (found)
        {
            cout << page << " ->\n";
            continue;
        }
        miss++;
        while (true)
        {
            if (frames[index] == -1)
            {
                frames[index] = page;
                index = (index + 1) % size;
                break;
            }
            else if (reference[frames[index]] == 0)
            {
                frames[index] = page;
                index = (index + 1) % size;
                break;
            }
            else reference[frames[index]] = 0;
            index = (index + 1) % size;
        }
        cout << page << " ->";
        printState(frames);
    }

    cout << "Total page fault = " << miss;
}
