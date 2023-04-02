#include<bits/stdc++.h>
using namespace std;
struct process{
    int processNumber;
    int burstTime;
    int priority;
};

vector<int> PS(process processes[], int n) {
    process temp;
    vector<int> timeTable;

    for (int i = 0; i < n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(processes[i].priority > processes[j].priority)
            {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;

            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<processes[i].burstTime; j++)
        {
            timeTable.push_back(processes[i].processNumber);
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

int main()
{
    float totalWaitingTime;
    float avergaeWaitingTime;
    int numberOfProcess;
    int burstTime;
    int priority;
    printf("How many number of Process?");
    cin >> numberOfProcess;

    process processes[numberOfProcess];
    vector<int> timeTable;

    for(int i=0; i<numberOfProcess; i++)
    {
        printf("Burst Time for process %d: ", (i+1));
        cin >> burstTime;
        printf("Priority For Process %d: ", (i+1));
        cin >> priority;

        processes[i].processNumber = (i+1);
        processes[i].burstTime = burstTime;
        processes[i] .priority= priority;
    }

    timeTable = PS(processes, numberOfProcess);

    printf("Gantt Chart: \n");
    totalWaitingTime = printGanttChart(timeTable);
    avergaeWaitingTime = totalWaitingTime / (numberOfProcess * 1.0);
    printf("Average Waiting Time %0.2f\n", avergaeWaitingTime);

    return 0;
}
