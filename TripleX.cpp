/* 

Solve the riddles to level up and eat your gummy bears!

Notes:
Remember: Improve readability of your code 

Compile: 'g++ triplex.cpp -o triplex' 
^not case sensitive

Run: ./triplex 
^not case sensitive */

//# represents preprocessor directive
//Preprocessor directive followed by Header File 
#include <iostream>
#include <ctime>

/* placement of function matters
C++ reads line by line 
void means function will return no data*/
void PrintIntroduction (int Difficulty) 
{
    //Print welcome message
    //cout = character output
    //<< insertion operator
    std::cout << "\nYou need to rescue the Gummy Bears from the Evil Gummy Lady but she has a level " << Difficulty << std::endl;
    std::cout << "riddle! Figure out the riddle and you'll get all the Gummy Bears...then get to eat them too!\n";

}


bool PlayGame (int Difficulty)
{
    PrintIntroduction(Difficulty);

    //declare 3-number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //Prints sum and product to terminal
    std::cout << "\n There are 3 numbers in the code";
    std::cout << "\n The code add up to: " << CodeSum;
    std::cout << "\n The codes multiply to give: " << CodeProduct << std::endl;

    /* character in 
    >> extraction operator 
    Waiting for player to input guess */ 
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //Check if player guess is correct
    if (CodeSum == GuessSum && CodeProduct == GuessProduct)
    {
        std::cout << "\n* You Win! Level Up! *" << std::endl;
        return true;
    } 
    else 
    {
        std::cout << "\n* Oh No! Retry! *" << std::endl;
        return false;
    }
}

int main()
{   
    srand(time(NULL)); //create new random sequence based on time of day

    int LevelDifficulty = 1;
    const int MaxLevelDifficulty = 5;

    while (LevelDifficulty <= MaxLevelDifficulty) //Loops game until all levels are complete
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //Clears any errors
        std::cin.ignore(); //Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }

    std::cout << "* Nice work! All the gummies for you! *";
    
    return 0;
}