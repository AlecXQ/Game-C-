
#include <iostream>
#include <ctime>


void PrintIntroduction(int Difficulty)
{
      //Presentation of the game
     std::cout <<"\n\nYou are in prision, the only way to scape is finding out the security code of the room "<<Difficulty; 
     std::cout <<std::endl;
     std::cout <<"So, be careful with guards and think it to solve the problem...\n\n";

}

bool playGame(int Difficulty)
{
    PrintIntroduction(Difficulty);


     //Declaring variables
     const int CodeA = rand() % Difficulty + Difficulty;
     const int CodeB = rand() % Difficulty + Difficulty;
     const int CodeC = rand() % Difficulty + Difficulty;


     //Operating with variables
     const int CodeSum= CodeA+CodeB+CodeC;
     const int CodeProduct= CodeA*CodeB*CodeC;

     
     //Giving results to the user
     std::cout <<std::endl;
     std::cout <<"+ There are 3 numbers in the code" << std::endl;
     std::cout <<"+ The codes add-up to: "<<CodeSum <<std::endl;
     std::cout <<"+ The codes multiply to give:  "<<CodeProduct <<std::endl;

     //Store player guess
     int GuessA,GuessB,GuessC;
     std::cin >> GuessA>> GuessB>> GuessC;
     

     int GuessSum = GuessA + GuessB + GuessC;
     int GuessProduct = GuessA * GuessB * GuessC;

     if(GuessSum==CodeSum && GuessProduct==CodeProduct)
     {
          std::cout <<"\nYou did it... for now.";
          return true;
     }else
     {
          std::cout<<"\nYou lost man.";
          return false;
     }
     
}



int main()
{    
     srand(time(NULL)); //create new random sequence based on time of day

     int LevelDifficulty = 1;
     const int MaxDifficulty = 5;
     while (LevelDifficulty <= MaxDifficulty) //loop the game until all level completed!
     {
          bool bLevelComplete = playGame(LevelDifficulty);
           std::cin.clear(); //Clears any errors
           std::cin.ignore();//Discards the buffer

           if (bLevelComplete)
           {
               ++LevelDifficulty;
           }
          if (LevelDifficulty == 5)
          {
                if (bLevelComplete)
                {
                    std::cout <<"\nYou won finally! you are free.";
                    break; 
                }else{
                     std::cout <<"\nYou are dead :("; 
                     break;
                }
          }        
     }

     return 0;

}



   
