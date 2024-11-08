#include <bits/stdc++.h>
using namespace std;

int main()
{
    int guess_count = 0;
start:
    cout << "-----------------------------------------------------------" << endl;
    cout << "--------------Welcome To Number Guessing Game--------------" << endl;
    cout << "-----------------------------------------------------------" << endl
         << endl;
    cout << "Choose One Option : " << endl;
    cout << "1-> Play The Game" << endl;
    cout << "2-> Exit From The Game" << endl;
    cout << "3-> See Last Game Score" << endl;
    cout << endl
         << "Enter One Option : ";
    int option;
    cin >> option;

    switch (option)
    {
    case 1:
        cout << endl;
        goto play;
        break;

    case 2:
        cout << "Thanks For Playing This Game" << endl
             << endl;
        exit(0);
        break;

    case 3:
        if (guess_count == 0)
        {
            cout << "No Score Found" << endl
                 << endl;
            goto start;
        }
        else
        {
            cout << "You Won The Game In " << guess_count << " Guesses" << endl
                 << endl;
            goto start;
        }
        break;

    default:
        cout << "Invalid Option" << endl
             << endl;
        goto start;
        break;
    }

play:
    cout << "----------Welcome----------" << endl;
    guess_count = 1;
    int lower, upper;
    cout << "Enter The Lower Bound : ";
    cin >> lower;
    cout << "Enter The Upper Bound : ";
    cin >> upper;

    int random_number = (rand() % (upper - lower + 1)) + lower;
    int guess_num;

    do
    {
        cout << endl
             << "Enter Your Guess Number : " << endl;
        cin >> guess_num;
        if (guess_num > random_number)
        {
            cout << "Your Guess Number Is Higher Than The Number" << endl;
            guess_count++;
        }
        else if (guess_num < random_number)
        {
            cout << "Your Guess Number Is Lower Than The Number" << endl;
            guess_count++;
        }
        else
        {
            cout << endl
                 << "Great.! You Guessed The Correct Number...!!!" << endl;
            cout << endl
                 << "You guessed the Number In " << guess_count << " Tries...!" << endl
                 << endl;
            goto start;
        }
    } while (guess_num != random_number);

    return 0;
}