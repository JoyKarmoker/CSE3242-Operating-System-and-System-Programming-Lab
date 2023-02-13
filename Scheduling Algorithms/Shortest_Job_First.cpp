#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> gc;
struct Process {
    int process_id;
    int burst_time;
};

vector<int> SJF(Process processes[], int n) {
    Process temp;
    vector<int> timeTable;
    
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

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<processes[i].burst_time; j++)
        {
            timeTable.push_back(processes[i].process_id);
        }
    }

    return timeTable;
}

void printLine(vector<int> timeTable)
{
    int length = timeTable.size();
    printf("|--");
    for(int i=1; i<length; i++)
    {
        if(timeTable[i]==timeTable[i-1])
        {
            printf("--");
        }
        else
        {
            printf("|--");
        }
    }
    printf("|");
    printf("\n");
}

void printProcessNumber(vector<int> timeTable)
{
    int i=0;
    printf("P%d", timeTable[i]);
    int length = timeTable.size();
    for(int i=1; i<length; i++)
    {
        if(timeTable[i]==timeTable[i-1])
        {
            printf("  ");
        }
        else
        {
            printf(" P%d", timeTable[i]);
        }
    }
    printf("\n");
}

int printEndingTime(vector<int> timeTable)
{
    printf("0");
    int totalWaitingTime = 0;
    int previousEnding = 0;
    int length = timeTable.size();
    for(int i=1; i<length; i++)
    {
        if(timeTable[i]==timeTable[i-1])
        {
            printf("  ");
        }
        else
        {
            printf("  %d", i);
            //previousEnding = previousEnding - i;
            totalWaitingTime = totalWaitingTime + i;
        }
    }
    printf("%d", length);
    printf("\n");

    return totalWaitingTime;
}
float printGanttChart(vector<int> timeTable)
{
    float totalWaitingTime;
    int waitingTime;
    printLine(timeTable);
    printProcessNumber(timeTable);
    printLine(timeTable);
    waitingTime = printEndingTime(timeTable);
    //printf("Waiting Time %d\n", waitingTime);
    totalWaitingTime = (waitingTime*1.0);
    //printf("Total Waiting Time in gant chart function %f\n", totalWaitingTime);
    return totalWaitingTime;
}



int main() {
    int number_of_process;
    vector<int> timeTable;
    float totalWaitingTime;
    float avergaeWaitingTime;
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

    timeTable = SJF(processes, number_of_process);
    
    /*printf("Time Table: \n");
    int length = timeTable.size();
    for(int i=0; i<length; i++)
    {
        printf("%d ", timeTable[i]);
    }
    cout << endl;*/
    
    printf("Gantt Chart: \n");
    totalWaitingTime = printGanttChart(timeTable);
    avergaeWaitingTime = totalWaitingTime / (number_of_process * 1.0);
    printf("Average Waiting Time %0.2f\n", avergaeWaitingTime);
    
    return 0;
}
