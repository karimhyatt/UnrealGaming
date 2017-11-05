#include "FBullCowGame.h"
#include <iostream>
#include <cctype>
#include <map>
#define TMap std::map


FBullCowGame::FBullCowGame()
{
	Reset();
}

int FBullCowGame::GetMaxTries() const { return myMaxTries; }
int FBullCowGame::GetCurrentTry() const { return myCurrentTry; }

int32 FBullCowGame::GetWordLength() const {	return myHiddenWord.length(); }

const FString HIDDEN_WORD = "planet";


void FBullCowGame::PlayGame()
{
	int maxTries = GetMaxTries();
	std::cout << maxTries << std::endl;
	for (int i = 0; i < maxTries; i++)
	{
		guess = GetGuess();
		EWordStatus status = CheckGuessValidity();
		if (status != EWordStatus::OK)
		{
			PrintError(status);
			i--;
			continue;
		}
		FGuessResponse response = SubmitGuess();
		PrintGuessResult(response);
		if (gameIsWon)
			break;

		myCurrentTry++;

	}
	std::cout << "Better Luck Next time\n\n";

}


void FBullCowGame::Reset()
{
	myHiddenWord = HIDDEN_WORD;
	myCurrentTry = 1;
	myMaxTries = 3;
	gameIsWon = false;
}


std::string FBullCowGame::GetGuess()
{
	// get the guess from the player
	FText Guess = "";
	std::cout << "Try " << GetCurrentTry() << ": Guess the Word: ";
	getline(std::cin, Guess);

	return Guess;
}

FGuessResponse FBullCowGame::SubmitGuess()
{
	//setup a return variable
	FGuessResponse response;;

	int32 hiddenWordLength = (int32)myHiddenWord.length();
	for (int32 i = 0; i< hiddenWordLength; i++)
	{
		for (int32 j = 0; j<(int32)guess.length(); j++)
		{
			if ((guess[i] == myHiddenWord[j]) && (i == j))
				response.NumberofBulls++;
			if ((guess[i] == myHiddenWord[j]) && (i != j))
				response.NumberOfCows++;
		}
	}

	if (response.NumberofBulls == myHiddenWord.length())
		response.Success = true;
	
	return response;
}

bool FBullCowGame::GuessIsLowerCase()
{
	int32 guesslen = guess.length();
	for (int32 i = 0; i < guesslen; i++)
		if (std::isupper(guess[i]))
			return false;
	return true;
}

bool FBullCowGame::GuessIsIsogram()
{
	int32 guesslen = guess.length();

	TMap<char, bool> LetterSeen;

	for (auto c : guess)
	{
		if (LetterSeen[c] == true)
			return false;

		LetterSeen[c] = true;
	}
	return true;
}

EWordStatus FBullCowGame::CheckGuessValidity()
{
	if (guess.length() != GetWordLength())
		return EWordStatus::Wrong_Length;
	else if (!GuessIsLowerCase())
		return EWordStatus::Not_Lowercase;
	else if (!GuessIsIsogram())
		return EWordStatus::Not_Isogram;
	
	return EWordStatus::OK;
}

void FBullCowGame::PrintGuessResult(const FGuessResponse response)
{
	// repeat the guess back to them
	PrintBackGuess();
	std::cout << "Bulls = " << response.NumberofBulls << std::endl;
	std::cout << "Cows = " << response.NumberOfCows << std::endl;

	if (response.Success)
	{
		std::cout << "Contratulations. You Guessed the isogram in " << myCurrentTry << " turns\n\n";
		gameIsWon = true;
	}
}

void FBullCowGame::PrintError(EWordStatus status)
{
	std::cout << std::endl;

	switch (status)
	{
	case EWordStatus::Not_Isogram:
		std::cout << "Error: Your guess was not an isogram\n";
		break;
	case EWordStatus::Not_Lowercase:
		std::cout << "Error: Your guess was not in lower case\n";
		break;
	case EWordStatus::Wrong_Length:
		std::cout << "Error: Your guess has the wrong word length\n";
		break;
	default:
		std::cout << "You should not be seeing this message\n";
		break;

	}
		
}


void FBullCowGame::PrintIntro() const
{
	// Introduce the code
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " <<  GetWordLength() << " letter isogram I'm thinking of\n";
	return;
}

bool FBullCowGame::AskToPlayAgain()
{
	std::cout << "Do you want to play again? ";
	std::string response = "";
	getline(std::cin, response);
	std::cout << std::endl;

	return (toupper(response[0]) == 'Y');
}

void FBullCowGame::PrintBackGuess() const
{
	std::cout << "Your guess was: " << guess << std::endl;
	std::cout << std::endl;
}
