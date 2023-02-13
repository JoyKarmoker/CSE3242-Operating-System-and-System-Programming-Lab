#include<bits/stdc++.h>
using namespace std;

void printUpperLine(int length)
{
    for(int i=0;i<length;i++)
    {
        printf("-");
    }

    printf("|");
    cout << "\033[B"; //Move down the cursor 1 line;
    
    for(int i=0;i<=length;i++)
    {
        cout << "\b";
    }

}

void printProcessNumber(int length, int processNumber, int endTime)
{
    cout << "P" << processNumber;
    cout << "\033[B"; //Move Down Cursor a line

    //Cursor move back three characters where the lower line will be printed
    cout << "\b";
    cout << "\b";
    cout << "\b";
    
    //Printing The Lower Line
    cout << "|";
    for(int i=0; i<length; i++)
    {
        cout << "-";
    }
    cout << "\033[B"; //Move Down Cursor a line
    cout << endTime; //Printing The Ending Time
    
    //Cursor move up three lines where the upper line will be printed
    cout << "\033[A"; //Move up cursor A line
    cout << "\033[A"; //Move up cursor A line
    cout << "\033[A"; //Move up cursor A line
    //cout << "\033[C"; //Move right cursor
}




void beautifyConsole()
{
    //Print the last | 
    cout << "\033[B";
    cout << "\033[B";
    cout << "\b";
    cout << "|";
    cout << "\033[B";
    cout << "\033[G";
    cout << 0;
    printf("\n");

}

void printGanttChart(int arr[], int size)
{
    int i = 0;
    int lastend = 0;
    //printf("size: %d\n", size);
    //Print the first |   
    printf("|");
    while(i<size)
    {
        if(arr[i+1] == arr[i])
        {
            i = i+1;
        }

        else
        {
            lastend = i-lastend + 1;
            printUpperLine(lastend*2);
            printProcessNumber(lastend*2, arr[i], i+1);
            i = i+1;
        }
    }

    beautifyConsole();
}


int main()
{
   int p[]={1, 2, 2, 2, 2, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3};
   printGanttChart(p, 26);


    return 0;
}