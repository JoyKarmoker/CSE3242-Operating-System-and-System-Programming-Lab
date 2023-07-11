#include <bits/stdc++.h>
using namespace std;

bool contains(queue<int> q, int n)
{
    while (!q.empty())
    {
        if (q.front() == n)
            return true;
        q.pop();
    }

    return false;
}

int main()
{
    vector<int> reference_string = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    vector<int> page_faults;
    int frame_size = 3;
    queue<int> frames;
    int page_fault = 0;
    int current_frame_size;
    bool is_present;
    int i = 0;

    for (auto x : reference_string)
    {

        if (!contains(frames, x))
        {
            cout << "Fault: " << x << " at:" << i << endl;
            page_fault++;
            page_faults.push_back(x);
            cout << "Page Frames: ";
            // Create a copy of the frame queue to print its elements without modifying it.
            std::queue<int> q_copy = frames;
            while (!q_copy.empty())
            {
                std::cout << q_copy.front() << " ";
                q_copy.pop();
            }
            cout << endl;

            current_frame_size = frames.size();
            if (current_frame_size < frame_size)
                frames.push(x);

            else
            {
                frames.pop();
                frames.push(x);
            }
        }
        //i = i + 1;
    }

    cout << "Total Page Faults: " << page_fault << endl;

    return 0;
}
