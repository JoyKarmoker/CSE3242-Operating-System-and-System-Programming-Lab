#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include<cstdio>
using namespace std;
void copypaste(string src, string dest)
{
    ifstream input(src, ios::binary);
    if (!input.is_open())
    {
        cout << "Error opening input file: " << src << endl;
    }
    ofstream output(dest, ios::binary);
    if (!output.is_open())
    {
        cout << "Error opening output file: " << endl;
    }

    output << input.rdbuf();
    if (!output)
    {
        cout << "Error writing to output file: " << endl;
    }

    else
    {
        cout << "Successfully copied the file\n";
    }

    input.close();
    output.close();
}

void cutpaste(string src, string dest)
{
    copypaste(src, dest);
    if (remove(src.c_str()) != 0) {
        cout << "Error deleting input file: " << src << endl; 
    }
}

int main()
{
    while (1)
    {
        string command;
        getline(cin, command);
        if (command == "q" || command == "exit")
        {
            printf("Exiting.....");
            return 0;
        }

        // cout << input << endl;

        int number_of_words = 1;
        vector<string> words;
        string temp = "";
        for (int i = 0; command[i] != '\0'; ++i)
        {
            if (command[i] == ' ')
            {
                words.push_back(temp);
                temp = "";
                number_of_words++;
            }

            else
                temp = temp + command[i];
        }
        words.push_back(temp);
        /*printf("total number of words are %d\n", number_of_words);
        cout << "Words are: ";
        for (int i = 0; i < number_of_words; i++)
        {
            cout << words[i] << " ";
        }*/
        if (number_of_words != 3)
        {
            printf("Invalid command, try again\n");
            continue;
        }

        if (words[0] == "Copy" || words[0] == "copy" || words[0] == "COPY")
        {
            copypaste(words[1], words[2]);
        }

        else if(words[0] == "Cut" || words[0] == "cut" || words[0] == "CUT")
        {
            cutpaste(words[1], words[2]);
        }

        else
        {
            printf("Invalid command, try again");
        }
    }

    return 0;
}