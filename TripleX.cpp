// Includes
#include <iostream>
#include <ctime>
// Namespaces
using namespace std;
// Global Variables
int Attempts = 3;

void PrintIntroduction()
{
    // Introduction Message to the User
    cout << "\n\nWelcome to Triple X! You are spy on the mission to hack into a super computer " << endl;
    cout << "The supercomputer is protected with layers of encryption & can be accessed by entering an appropriate code!" << endl
         << endl;
}

bool PlayGame(int Difficulty)
{
    // Variables
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    cout << "\n* Current Encryption Level: " << Difficulty;
    cout << "\n* Attempts Left: " << Attempts;
    cout << "\n* There are 3 numbers in the code ";
    cout << "\n* The codes add up to: " << CodeSum;
    cout << "\n* The codes multiply to give: " << CodeProduct;
    cout << "\n* Enter the 3 number code to break this encryption & continue.. (Numbers can be sperated with a space / enter) \n \n";

    // Storing Player Input
    int PlayerGuessA, PlayerGuessB, PlayerGuessC;
    cin >> PlayerGuessA >> PlayerGuessB >> PlayerGuessC;

    cout << "\nThe 3 number code you entered is: " << PlayerGuessA << " " << PlayerGuessB << " " << PlayerGuessC << endl;

    int PlayerGuessSum = PlayerGuessA + PlayerGuessB + PlayerGuessC;
    int PlayerGuessProduct = PlayerGuessA * PlayerGuessB * PlayerGuessC;

    // Checking if the player entered the correct numbers
    if (PlayerGuessSum == CodeSum && PlayerGuessProduct == CodeProduct)
    {
        cout << "\nThe code you guessed was right! You broke the encryption on the current level. Moving to the next encryption ***\n\n";
        return true;
    }
    else
    {
        cout << "\nThe code you entered is wrong, try again! ***\n\n";
        return false;
    }
}

int main()
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    PrintIntroduction();

    while (LevelDifficulty <= MaxDifficulty && Attempts > 0)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        cin.clear();
        cin.ignore();

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        else
        {
            --Attempts;
        }
    }
    if (Attempts == 0)
    {
        cout << "\nYou failed to beat the encryptions & lost all the attempts! You will need to start over.\n\n";
    }
    else
    {
        cout << "\nYou beat the supercomputer & broke through all levels of encryption. Congratulations!\n\n";
    }

    return 0;
}