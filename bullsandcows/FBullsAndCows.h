#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bull = 0;
	int32 Cow = 0;
};

enum class EWordStatus
{
	Invalic_status,
	ok,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullsAndCows
{
public:
	FBullsAndCows(); //constractor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	void Reset();
	void PrintGameSummart();
	void GetHint();
	FBullCowCount SubmitValidGuess(FString); //counts bulls and cows, and increases try number
	bool IsGameWon() const;
	EWordStatus CheckGuessValidaty(FString Guess) const;
	
	

private:
	//see constructor for initialisation
	int32 MyCurrentTry ;
	int32 MyMaxTries ;
	FString  MyHiddenWord = " ";
	bool bGameIsWon;
	bool IsIsogram(FString Word) const;
	bool IsLowercase(FString Word) const;

};
