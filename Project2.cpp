//Program:              Project2.cpp
//Course:               CSE1311/W01
//Name:                 Christian Cruz
//Assignment #:         Project 2
//Due date:             10/14/18

/* This program let's you play a Guessing Game
of Hi-Lo, which basically generates a random number
and the user has to find out what that number is. */


#include <iostream>
#include <cstdlib>
#include <time.h>
    
using namespace std;
    
int main()
{
    int guess, random;
    char response;
    
    do
    {
        int count = 0;
        srand(time(0));
        random = rand() % 100 +1;
        
        cout << endl;
        cout << "Guess My Number Game " << endl;
        cout << endl;
        
        do
        {
            cout << "Enter a number between 1 and 100 " << endl;
            cin >> guess;
            count++;
            
            if (guess == -1)
            {
                break;
            }
            else if ((guess < 1) || (guess > 100))
            {
                cout << "Wrong choice! " << endl;
                cout << endl;
            }
            else if (guess > random)
            {
                cout << "Too high! " << endl;
                cout << endl;
            }
            else if (guess < random)
            {
                cout << "Too low! " << endl;
                cout << endl;
            }
        } while (guess != random);
        if (guess == -1)
        {
            cout << "User terminated the game " << endl;
            cout << "You tried guessing the number " << count << " times " <<endl;
            cout << endl;
        }
        else
        {
            cout << "You guessed it correctly in " << count << " tries! " << endl;
            cout << endl;
        }
        cout << "Do you want to play again? Y/N " << endl;
        cin >> response;
    } while (response == 'Y');

    cout << endl;
    cout << "Coded by Christian Cruz" << endl;
    return 0;

}
