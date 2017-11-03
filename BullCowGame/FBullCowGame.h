#pragma once
#include <string>

using FText = std::string;
using FString = std::string;
using int32 = int;

// All values initialised to 0
struct FGuessResponse
{
	int32 NumberofBulls = 0;
	int32 NumberOfCows = 0;
};

class FBullCowGame
{
public:

	FBullCowGame();

	int32 GetMaxTries() const; 
	int32 GetCurrentTry() const;
	void PrintIntro() const;
	void PrintBack(FString Guess) const;

	bool IsGameWon() const;

	FString GetGuess();
	FGuessResponse SubmitGuess(FString);
	
	bool CheckGuessValidity(FString);
	
	
	void PlayGame();
	bool AskToPlayAgain();
	void Reset();

private:
	const int32 WORD_LENGTH = 5;

	int32 myCurrentTry;
	int32 myMaxTries;
	FString myHiddenWord;
};
