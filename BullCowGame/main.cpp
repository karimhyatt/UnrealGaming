
#include "FBullCowGame.h"

FBullCowGame BCGame; //instantiate a new game.



// the entrypoint 
int main()
{
	do
	{
		BCGame.Reset();
		BCGame.PrintIntro();
		BCGame.PlayGame();
	} 
	while (BCGame.AskToPlayAgain());
	return 0;
}

