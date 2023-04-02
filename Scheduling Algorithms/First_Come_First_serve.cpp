#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> gq;
vector<int> FCFS(int processes[], int number_of_process)
{
    vector<int> Timetable;

    for(int j=0; j<number_of_process; j++)
    {

        int current_process_burst_time = processes[j];
        for(int i=0; i<current_process_burst_time; i++)
        {
            Timetable.push_back((j+1));
        }

    }

    return Timetable;
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
    int number_of_process;
    cout << "Give how many number of process ";
    cin >> number_of_process;
    int burst_time;
    int processes[number_of_process];
    vector<int> timeTable;
    float totalWaitingTime;
    float averageWaitingTime;

    for(int i=0; i<number_of_process; i++)
    {
        int process_number = i+1;
        cout << "Enter burst time for process "  << process_number << " : ";
        cin >> burst_time;
        processes[i] = burst_time;
    }
    timeTable = FCFS(processes, number_of_process);
    printf("Time table: ");
    for(auto x: timeTable)
    {
        cout << x << " ";
    }
    cout << endl;
    printf("Gannt Chart: \n");
    totalWaitingTime = printGanttChart(timeTable);
    averageWaitingTime = totalWaitingTime / (number_of_process * 1.0);
    //printf("Total Waiting Time: %0.2f\n", totalWaitingTime);
    printf("Average Waiting Time: %0.2f\n", averageWaitingTime);

    return 0;
}
