//Program:              Project4.cpp
//Course:               CSE1311/W01
//Name:                 Chrisian Cruz
//Assignment #:         Project 4
//Due Date:             12/02/18

/* This program simulates an elevator in which
 it reads a given set of data with different
 people and their weights. The elevator has a
 load limit so the program determines how many
 people can get on the elevator, printing the
 name and weight of the person plus how many
 got in the elevator. It later sorts them in
 descending and ascending order. Lastly it tells
 the user which method allowed he most people on
 the elevator. It compares three different counts. */

#include <iostream>
#include <string>

using namespace std;

int fillElevator(string Names[], int Weights[], int n)
{
    int i = 0;
    int loadLimit = 0;
    
    while (loadLimit <= 1100)
    {
        loadLimit += Weights[i];
        
        i++;
    }
    
    i--;
    loadLimit -= Weights[i];
    
    cout << i << " people could board the elevator. Total Weight = " << loadLimit << endl;
    return i;
}

void sortDescending(string Names[], int Weights[], int n)
{
    int temp, hole;
    string N;
    for (int i = 0; i < n - 1; i++)
    {
        hole = i;
        
        for(int j = i + 1; j < n; ++j)
            if (Weights[j] > Weights[hole])
            {
                hole = j;
            }
        if (hole != i)
        {
            temp = Weights[i];
            Weights[i] = Weights[hole];
            Weights[hole] = temp;
            
            N = Names[i];
            Names[i] = Names[hole];
            Names[hole] = N;
        }
    }
}

void sortAscending(string Names[], int Weights[], int n)
{
    int weightData;
    string nameData;
    for (int i = 1; i < n; i++)
    {
        nameData = Names[i];
        weightData = Weights[i];
       
        int j;
        for (j = i - 1; ((j >= 0) && (nameData.compare(Names[j]) < 0)); j--)
        {
            Names[j + 1].swap(Names[j]);
            Weights[j + 1] = Weights[j];
        }
        Names[j + 1].swap(nameData);
        Weights[j + 1] = weightData;
    }
}



void printArrays(string Names[], int Weights[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << Names[i] << " " << Weights[i] << endl;
    }
    cout << endl;
}

void max(int countAscending, int countDescending, int countUnsorted)
{
    if (countAscending > countDescending && countAscending > countUnsorted)
        cout << "countAscending is the best" << endl;
    
    else if (countDescending > countUnsorted && countDescending > countAscending )
    {
        cout << "countDescending is the best" << endl;
    }
    
    else
        cout << " countUnsorted is the best" << endl;
}

int main()
{
    string Names[] = {"Anne", "Bob", "Ralph", "Tim", "Barbara", "Jane", "Steve", "Tom", "Mike", "Shirley", "Pam", "Frank"};
    int Weights[] = {30, 150, 305, 225, 135, 160, 80, 200, 165, 90, 100, 120};
    int countAscending, countDescending, countUnsorted;
    int n = 12;
    
    cout << "Full Array Unsorted:" << endl;
    printArrays(Names, Weights, n);
    countUnsorted = fillElevator(Names, Weights, n);
    cout << "Those that got on:" << endl;
    printArrays(Names, Weights, countUnsorted);
    
    sortDescending(Names, Weights, n);
    cout << "Full Array Sorted by Weights:" << endl;
    printArrays(Names, Weights, n);
    countDescending = fillElevator(Names, Weights, n);
    cout << "Those that got on:" << endl;
    printArrays(Names, Weights, countDescending);
    
    sortAscending(Names, Weights, n);
    cout << "Full Array Sorted by Names:" << endl;
    printArrays(Names, Weights, n);
    countAscending = fillElevator(Names, Weights, n);
    cout << "Those that got on:" << endl;
    printArrays(Names, Weights, countAscending);
    
    max(countAscending, countDescending, countUnsorted);
    
    cout << endl;
    cout << "Coded by Christian Cruz " << endl;
    return 0;
}
