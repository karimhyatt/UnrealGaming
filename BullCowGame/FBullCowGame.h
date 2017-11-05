#pragma once
#include <string>

using FText = std::string;
using FString = std::string;
using int32 = int;

// All values initialised to 0
struct FGuessResponse
{
	bool Success = false;
	int32 NumberofBulls = 0;
	int32 NumberOfCows = 0;
};

enum class EWordStatus
{
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame
{
public:

	FBullCowGame();

	int32 GetMaxTries() const; 
	int32 GetCurrentTry() const;
	int32 GetWordLength() const;

	void PrintIntro() const;
	void PrintBackGuess() const;

	FString GetGuess();
	FGuessResponse SubmitGuess();

	bool GuessIsLowerCase();
	bool GuessIsIsogram();
	EWordStatus CheckGuessValidity();
	
	void PrintGuessResult(const FGuessResponse response);

	void PrintError(EWordStatus status);
	void PlayGame();
	bool AskToPlayAgain();
	void Reset();

private:

	int32 myCurrentTry = 0;
	int32 myMaxTries = 0;
	FString myHiddenWord = "";
	FString guess = "";
	bool gameIsWon = false;
};
