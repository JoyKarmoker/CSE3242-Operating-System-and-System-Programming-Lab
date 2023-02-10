#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> gc;
struct Process {
    int process_id;
    int burst_time;
};

vector<Process> sortProcess()
{
    vector<Process> sortedProcess;

    return sortedProcess;
}

void SJF(Process processes[], int n) {
    vector<Process> unsortedProcess;
    for(int i=0; i<n; i++)
    {
        unsortedProcess.push_back(processes[i]);
    }
    Process temp;
    for (int i = 0; i < n; i++) 
    {
        for(int j=i+1; j<n; j++)
        {
            if(processes[i].burst_time > processes[j].burst_time)
            {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;

            }
        }
    }

    int previousEndingTime = 0;
    for(int i=0; i<n; i++)
    {
        //printf("Process id is %d and burst_time is %d\n", processes[i].process_id, processes[i].burst_time);
        previousEndingTime = processes[i].burst_time + previousEndingTime;
        gc.push_back({processes[i].process_id, previousEndingTime});
    }
}

void printLine(int gap)
{
    for(int i=0; i<gap*2; i++)
    {
        printf("-");
    }
    printf("|");
}

void printProcessNumber(int processNumber, int gap)
{

    cout << " p" << processNumber;
    for(int i=1; i<gap*2; i++)
    {
        cout<<" ";
    }
}

void printProcessEndingTime(int processEndingTime, int gap)
{
    for(int i=0; i<(gap*2); i++)
    {
        cout<<" ";
    }
    cout << processEndingTime;
}

void printGanntChart(vector<pair<int, int>> gq)
{
    int length = gq.size();
    pair<int, int> processInfo;
    int gap = 0;
    printf("|");
    for(int i=0; i<length; i++)
    {
        processInfo =  gq[i];
        gap = processInfo.second - gap;
        printLine(gap);
    }
    cout << "\n";
    gap = 0;
    int processNumber;
    for(int i=0; i<length; i++)
    {
        processInfo =  gq[i];
        processNumber = processInfo.first;
        gap = processInfo.second - gap;
        printProcessNumber(processNumber, gap);
    }
    cout << "\n";
    gap = 0;
    printf("|");
    for(int i=0; i<length; i++)
    {
        processInfo =  gq[i];
        gap = processInfo.second - gap;
        printLine(gap);
    }
    
    cout << "\n";
    gap = 0;
    int processEndingTime;
    int totalEndingTime = 0;
    cout << 0;
    for(int i=0; i<length; i++)
    {
        processInfo =  gq[i];
        processEndingTime = processInfo.second;
        totalEndingTime = totalEndingTime + processEndingTime;
        gap = processInfo.second - gap;
        printProcessEndingTime(processEndingTime, gap);
    }

    totalEndingTime = totalEndingTime - gq[length-1].second;
    int averageWaitingTime = totalEndingTime/length;

    cout << "\nAverage Waiting Time is " << averageWaitingTime << endl;
}


int main() {
    int number_of_process;
    cout << "Enter the number of processes: ";
    cin >> number_of_process;

    Process processes[number_of_process];
    for (int i = 0; i < number_of_process; i++)
    {
        int process_id = (i+1);
        cout << "Enter burst time for process " << process_id << ": ";
        processes[i].process_id = process_id;
        cin >> processes[i].burst_time;

    }

    SJF(processes, number_of_process);
    printf("\n");
    printf("Gannt Chart: \n");
    printGanntChart(gc);
    return 0;
}
