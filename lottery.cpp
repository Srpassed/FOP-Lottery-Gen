/*
Juan Rivera
COSC-1436
Lottery Simulation
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

void generateLotteryNumber(int winningDigits[])
{
	srand(static_cast<unsigned int>(time(NULL)));
	for( int i = 0; i < 5; ++i)
	{
		winningDigits[i] = rand() % 10;
	}
}

void getUserInput(int playerDigits[])
{
	std::cout << "Enter five digits (0-9) for the lottery:\n";
	for(int i = 0; i < 5; ++i)
	{
		while(true)
		{
			std::cout << "Enter digit " << i + 1 << ": ";
			std::cin >> playerDigits[i];

			if(std::cin.good() && playerDigits[i] >= 0 && playerDigits[i] <= 9)
			{
				break;
			}
			else
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input. please enter a digit between 0 and 9.\n";
			}
		}
	}
}

void determineAndDisplayMatches(const int winningDigits[], const int playerDigits[])
{
	int matchedCount = 0;

	std::cout << "\nMatching Digits:\n:";
	for (int i = 0; i < 5; ++i)
	{
		if (winningDigits[i] == playerDigits[i])
		{
			std::cout << "Element " << i + 1 << " - Winning Digit: " << winningDigits[i]
				<< ", Player Digit: " << playerDigits[i] << "\n";
			++matchedCount;
		}
	}
	if(matchedCount == 5)
	{
		std::cout << "\nCongratulations! You are the grand prize winner!\n";
	}
	else if(matchedCount > 0)
	{
		std::cout << "\nYou matched " << matchedCount << " digit(s)!\n";
	}
	else
	{
		std::cout << "\nSorry, no matches.\n";
	}
}


using namespace std;

int main()
{
/*
	                              [Major parts to Lottery Simulation]
	1) Make array of randomly generated 5 integers called "winningDigits" each element ranging from (0-9)
	2) Ask user to input 5 integers from (0-9) and store them in array called "player"
	3) Count how many digits match and display count along with numbers that match
	                              [Sub parts to Lottery Simulatiom]
	Part 1)
	*we need a array and random number generator - to get random numbers we can get (time % 10) the remainder will be each of the numbers (1-5)
	Part 2)
	*just cout user to input an int 5 times (0-9) and store them in arrat
	Part 3)
	*compare int and cycle  through to display a count and which numbers match
*/
	int winningDigits[5];
	int playerDigits[5];

	generateLotteryNumber(winningDigits);
	getUserInput(playerDigits);

	cout << "Winning Digits: ";
	for(int i = 0; i < 5; ++i)
	{
		cout << winningDigits[i] << " ";
	}

	cout << "Player Digits: ";
	for(int i = 0; i < 5; ++i)
	{
		cout << playerDigits[i] << " ";
	}

	determineAndDisplayMatches(winningDigits, playerDigits);




	return 0;
}
