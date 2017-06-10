/*This is the consol executable , that makes use of the BullCow class
This acts as the view ine MVC, and is responisble for all user 
interaction. For game logic see the FBullsAndCows class.
*/
#pragma once
#include <iostream>
#include <string>
#include "FBullsAndCows.h"

using namespace std;

using FText = string;
using int32 = int;

void print_info();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummart();

FBullsAndCows BCGame; //instantiate new game 

int main()
{
	cout<<BCGame.GetCurrentTry();

	int32 MaxTries = BCGame.GetMaxTries();
	cout << MaxTries << endl;

	print_info();
	do 
	{
		PlayGame(); 
	}
	while (AskToPlayAgain() == 1);
	system("pause");
	return 0;
}  

void print_info()
{
	cout << "WELCOM IN BULLS AND COWS , A FAN WORD GAME\n";
	cout << "can u guess - " << BCGame.GetHiddenWordLength()<<" letter isogram i'm thinking of "<<endl;
}

FText GetValidGuess()
{
	FText Guess = "";
	EWordStatus Status = EWordStatus::Invalic_status;
	do
	{
		int32 CurrentTry = BCGame.GetCurrentTry();
		cout << "Try " << CurrentTry <<" of "<<BCGame.GetMaxTries() << ".";
		cout << " Try to guess ";
		getline(cin, Guess);

		 Status = BCGame.CheckGuessValidaty(Guess);

		switch (Status)
		{
		case EWordStatus::Wrong_Length:
			cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word\n";
			break;
		case EWordStatus::Not_Isogram:
			cout << "Please enter a isogram\n ";
			break;
		case EWordStatus::Not_Lowercase:
			cout << "Please enter a lowercase word\n";
			break;
		default:
			break;
		}
	} while (Status != EWordStatus::ok);
	return Guess;
}

bool AskToPlayAgain()
{
	cout << "Do you want play again ?(Y/N)";
	FText Response = " ";
	getline(cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');
}

void PrintGameSummart()
{
	if (BCGame.IsGameWon() == true){
		cout << "Well done, you win\n";
	} else {
		cout << "One more time ?\n";
	}
}

void PlayGame()
{
	BCGame.Reset();
	int32 Max_Tries = BCGame.GetMaxTries();

	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry()<= Max_Tries)
	{
		FText Guess = GetValidGuess();
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		cout << "Bulls = " << BullCowCount.Bull<<endl;
		cout << "Cows = " << BullCowCount.Cow<<endl;
		cout << endl;
	}
	PrintGameSummart();
}
