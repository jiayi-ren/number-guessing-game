#include <iostream>
#include <ctime>

using namespace std;

void PrintIntroduction(int Difficulty){
    cout << "\nYou are a secret agent breaking into a level "<< Difficulty <<" classified room\n";
    cout << "Enter corrent combination to continue\n\n";
}
bool PlayGame(int Difficulty){

    PrintIntroduction(Difficulty);
 
    int CodeA = rand() % 3+ Difficulty;
    int CodeB = rand() % 3+ Difficulty;
    int CodeC = rand() % 3+ Difficulty;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC; 

    cout << "++There are three numbers in the combination";
    cout << "\n++The code add-up to " << CodeSum;
    cout << "\n++The code multiply to give " << CodeProduct << endl;

    //Player Guess
    int GuessA, GuessB, GuessC;

    cin >> GuessA;
    cin >> GuessB;
    cin >> GuessC;
    cout << "\nYou entered: " << GuessA <<" "<< GuessB <<" "<< GuessC << endl;
    
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
  
    //Check if guess is correct
 
    if (GuessSum == CodeSum && GuessProduct == CodeProduct){
        cout << "\nCorrect\n";
        return true;
    }else{
        cout << "\nWrong Codes, Try again\n";
        return false;
    }
}


int main(){

    srand(time(NULL)); // create new random sequence based on time

    int LevelDifficulty = 1;
    int const MaxDifficulty = 1;
    int MaxGuessAttempt = 1;

    while(LevelDifficulty <= MaxDifficulty && MaxGuessAttempt <=3){
        bool bLevelComplete = PlayGame(LevelDifficulty);
        cin.clear();    //clears any errors
        cin.ignore();   //Discards the buffer

        if(bLevelComplete){
            ++LevelDifficulty;
            MaxGuessAttempt = 1;
        }else{
            MaxGuessAttempt++;
        }

    }

    if(LevelDifficulty > MaxDifficulty ){
        cout << "\nGood job, You have cleared all the classified levels";
    }else{
        cout << "\nAccess locked.\n  Game Over";
    }
    return 0;
}