#include "FBullCowGame.h"
#include <iostream>

FBullCowGame::FBullCowGame()
{
	Reset();
}

int FBullCowGame::GetMaxTries() const { return myMaxTries; }
int FBullCowGame::GetCurrentTry() const { return myCurrentTry; }


void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "planet";
	myCurrentTry = 1;
	myMaxTries = 5;
}


std::string FBullCowGame::GetGuess()
{
	// get the guess from the player
	FText Guess = "";
	FGuessResponse response = SubmitGuess(Guess);
	std::cout << "Bulls = " << response.NumberofBulls;
	


	std::cout << "Try " << GetCurrentTry() << ": Guess the Word: ";
	getline(std::cin, Guess);

	return Guess;
}

FGuessResponse FBullCowGame::SubmitGuess(FString guess)
{
	// increment the turn number
	myCurrentTry++;

	//setup a return variable
	FGuessResponse response;

	int32 hiddenWordLength = myHiddenWord.length();
	for (int32 i = 0; i< hiddenWordLength; i++)
	{
		for (int32 j = 0; j<guess.length(); j++)
		{
			
		}
	}


	return response;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

void FBullCowGame::PrintIntro() const
{
	// Introduce the code
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of\n";
	return;
}

void FBullCowGame::PlayGame()
{
	int maxTries = GetMaxTries();
	std::cout << maxTries << std::endl;

	for (int i = 0; i < WORD_LENGTH; i++)
	{
		std::string Guess = GetGuess();
		// repeat the guess back to them
		PrintBack(Guess);
	}

}

bool FBullCowGame::AskToPlayAgain()
{
	std::cout << "Do you want to play again? ";
	std::string response = "";
	getline(std::cin, response);
	std::cout << std::endl;
	myCurrentTry = 1;
	return (toupper(response[0]) == 'Y');
}

void FBullCowGame::PrintBack(std::string Guess) const
{
	std::cout << "Your guess was: " << Guess << std::endl;
	std::cout << std::endl;
}
