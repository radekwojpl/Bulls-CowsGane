#include "FBullsAndCows.h"
#include <map>
#define TMap std::map
using int32 = int;
 //test do gita
FBullsAndCows::FBullsAndCows(){ Reset(); }
int32 FBullsAndCows::GetMaxTries () const{return MyMaxTries;}
int32 FBullsAndCows::GetCurrentTry() const{return MyCurrentTry;}
int32 FBullsAndCows::GetHiddenWordLength() const{return MyHiddenWord.length();}

void FBullsAndCows::Reset()  
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "what";
	MyHiddenWord = HIDDEN_WORD;
	bGameIsWon = false;
	MyCurrentTry = 1;
	return;
}
//recived VALID guess and incriments turns and returns count
FBullCowCount FBullsAndCows::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;

	int32 WordLenght = MyHiddenWord.length();
	for (int32 i = 0; i < WordLenght; i++)
	{
		for (int32 j = 0; j < WordLenght; j++)
		{
			if (Guess[j]== MyHiddenWord[i])
			{
				if (i == j){
					BullCowCount.Bull++;
				} else {
					BullCowCount.Cow++;
				}
			}
		}
	}
	if (BullCowCount.Bull==WordLenght){
		bGameIsWon = true;
	} else {
		bGameIsWon = false;
	}
	return BullCowCount;
}

bool FBullsAndCows::IsGameWon() const
{
	return bGameIsWon;
}

bool FBullsAndCows::IsIsogram(FString Word) const
{

	if (Word.length() <= 1) { return true; }
	TMap<char, bool> LetterSeen;
	for ( auto Letter : Word)
	{
		Letter = tolower(Letter);
		if (LetterSeen[Letter]){
			return false;
		} else {
			LetterSeen[Letter] = true;
		}
	}
	return true;
}

bool FBullsAndCows::IsLowercase(FString Word) const
{
	for ( auto Letter : Word)
	{
		if (!islower(Letter)){
			return false;
		}
	} return true;
}

EWordStatus FBullsAndCows::CheckGuessValidaty(FString Guess) const
{
	if (!IsIsogram(Guess))
	{
		return EWordStatus::Not_Isogram;
	}
	else if (!IsLowercase(Guess))
	{
		return EWordStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength())
	{
		return EWordStatus::Wrong_Length;
	}
	else
	{
		return EWordStatus::ok;
	}
}
