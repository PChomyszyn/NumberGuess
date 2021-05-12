#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout << "\n\nYou're a new hacker initiated into a training program at the CIA.\nYou are currently at level " << Difficulty;
    std::cout << ".\nYou need to enter the correct numbers...\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    //Declare three number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //Print sum and product
    std::cout << "- There are 3 numbers in the code";
    std::cout << "\n- The numbers add up to: " << CodeSum;
    std::cout << "\n- The numbers multiply to: " << CodeProduct << std::endl;

    //Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //Check answers
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nCongratulations, you got the right numbers!\nOnwards to the next level!";
        return true;
    }
    else
    {
        std::cout << "\nYou failed the level, you must try again!";
        return false;
    }
}

int main()
{
    srand(time(NULL));

    int LevelDifficulty = 1;
    const int MaxDifficulty = 10;

    while (LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //Clears any errors
        std::cin.ignore(); //Discards the bufer
        if (bLevelComplete)
        {
            LevelDifficulty++;
        }
    }

    std::cout << "Congratulations you passed the training!";
    return 0;
}
