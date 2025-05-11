// Online C++ compiler to run C++ program online
#include <iostream>

#include<cstdlib>

#include<ctime>

#include<limits>

using namespace std;
int main() {
    char play_Again = 'y';
        while(play_Again=='y'|| play_Again=='Y'){
    cout << "WELCOME TO THE GAME WORLD NUMBER GUESSING GAME  " << "'' _ ''" << endl;
    cout << "choose your levels 1, 2 or 3. " << endl;

    int Levels;

    while (true) {
        cin >> Levels;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits < streamsize > ::max(), '\n');
            cout << "Invalid Input! Please Enter an Integer (1,2 or 3)." << endl;
        }
        else if (Levels < 1 || Levels > 3) {
            cout << "Invalid Level! please choose between 1,2 or 3" << endl;
        }
        else {
            break;
        }
    }

    int levelRange = 0;
    int maxAttempts = 0;

    if (Levels == 1) {
        cout << "  choose number between 1 & 50 ." << endl;
        cout << "You Have Only 10 Attempts to predict correct Answer." << endl;
        levelRange = 50;
        maxAttempts = 10;
    }
    else if (Levels == 2) {
        cout << " choose number between 1 & 100 . " << endl;
        cout << "You Have Only 7 Attempts to predict correct Answer." << endl;
        levelRange = 100;
        maxAttempts = 7;
    }
    else if (Levels == 3) {
        cout << " choose number between 1 & 200. " << endl;
        cout << "You Have Only 5 Attempts to predict correct Answer." << endl;
        levelRange = 200;
        maxAttempts = 5;
    }
    srand(static_cast < unsigned > (time(0)));
    int randomRange = rand() % levelRange + 1;
    int playerGuess = 0;
    int Attempts = 0;

    while (playerGuess != randomRange && Attempts < maxAttempts) {
        cout << "guess the no." << endl;

        while (true) {
            cin >> playerGuess;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits < streamsize > ::max(), '\n');
                cout << "Invalid Input! Please Enter an Integer." << endl;
            }
            else {
                break;
            }
        }
        Attempts++;

        if (randomRange == playerGuess) {
            cout << " 7 CRORE...... :" << endl;
        }
        else if (randomRange > playerGuess) {
            cout << "try a little higher!" << endl;
        }
        else {
            cout << "try a little smaller!" << endl;
        }

        if (Attempts == maxAttempts && playerGuess != randomRange) {
            cout << " you've used all  " << maxAttempts << "  Attempts. the correct number was  " << randomRange << " . " << "'' _ ''" << endl;
        }
    }
      cout<<"PRESS Y FOR PLAY AGAIN"<<endl;
      cin>>play_Again;
      cout<<endl;
        }
        cout<<"THANKS FOR PLAYING"<<endl;
    return 0;
}  