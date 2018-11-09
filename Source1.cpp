//Skynet Part 2 by Christian Mangione
//initial inclusions 
#include <iostream>
#include <cstdlib>
#include <ctime>
//Starts the program
int main()
{
	//namespace had to be moved when everything became ambiguous
	using namespace std;
	//PLay loop
	//Starts Skynet
	cout << "Welcome to Skynet! Please eliminate evil today!\n" << endl;
	//Set Param
	int searchGridLow = 1;
	int	searchGridHigh = 64;
	//Seed random number generator
	srand(static_cast<unsigned int>(time(0)));
	//random number
	int enemyLocation = rand()% 64 + 1;
	//tries counter
	int playerTries = 0;
	int enemyTries = 0;
	int enemyLinearTries = 0;
	int enemyRandomTries = 0;
	//define guess
	int targetLocationPrediction = 0;
	int targetLocationPredictionLinear = 1;
	int targetLocationPredictionRandom = 0;
	int guess = 0;
	//if loop for guesses
		//Human Loop
		do
		{
			//Make human guess
			cout << "Choose a number between 1 and 64:";
			cin >> guess;
			//Less than for human
			if (guess < enemyLocation)
			{
				cout << "You aimed too low!\n\n";
				playerTries++;
			}
			//more than for human
			else if (guess > enemyLocation)
			{
				cout << "You aimed too high!\n\n";
				playerTries++;
			}
			//found for human
			else if (guess == enemyLocation)
			{
				cout << "\nYou finally defeated the enemy\n";
				playerTries++;
				break;
			}
		//end loop
		} while (guess != enemyLocation);
		//enemy loop
		do
		{
			//Make computer guess
			int targetLocationPrediction = ((searchGridHigh - searchGridLow) / 2) + searchGridLow;
			//less than for enemy
			if (targetLocationPrediction < enemyLocation)
			{
				cout << "Enemy aimed too low!\n\n";
				searchGridLow = targetLocationPrediction;
				enemyTries++;
			}
			//more than for enemy
			else if (targetLocationPrediction > enemyLocation)
			{
				cout << "Enemy aimed too high!\n\n";
				searchGridHigh = targetLocationPrediction;
				enemyTries++;
			}
			//found for enemy
			else if (targetLocationPrediction == enemyLocation)
			{
				cout << "\nEnemy finally defeated you\n";
				//Display Enemy Location on grid
				cout << "Enemy located at " << enemyLocation << "!\n" << endl;
				enemyTries++;
				break;
			}
		//end loop
		} while (targetLocationPrediction != enemyLocation);
		//enemy linear loop
		do
		{
			//less than for enemy linear
			if (targetLocationPredictionLinear < enemyLocation)
			{
				cout << "Enemy linear aimed too low!\n\n";
				targetLocationPredictionLinear++;
				enemyLinearTries++;
			}
			//more than for enemy linear
			else if (targetLocationPredictionLinear > enemyLocation)
			{
				cout << "Enemy linear aimed too high!\n\n";
				targetLocationPredictionLinear++;
				enemyLinearTries++;
			}
			//found for enemy linear
			else if (targetLocationPredictionLinear == enemyLocation)
			{
				cout << "\nEnemy linear finally defeated you\n";
				enemyLinearTries++;
				break;
			}
		} while (targetLocationPredictionLinear != enemyLocation);
		//enemy random loop
		do
		{
			//Make computer guess randomly
			targetLocationPredictionRandom = rand() % 64 + 1;
			//less than for enemy random
			if (targetLocationPredictionRandom < enemyLocation)
			{
				cout << "Enemy Random aimed too low!\n\n";
				enemyRandomTries++;
			}
			//more than for enemy linear
			else if (targetLocationPredictionRandom > enemyLocation)
			{
				cout << "Enemy Random aimed too high!\n\n";
				enemyRandomTries++;
			}
			//found for enemy linear
			else if (targetLocationPredictionRandom == enemyLocation)
			{
				cout << "\nEnemy Random finally defeated you\n";
				enemyRandomTries++;
				break;
			}
		//end loop
		} while (targetLocationPredictionRandom != enemyLocation);
	//Display Enemy Location on grid
	cout << "Enemy located at " << enemyLocation << "!\n" << endl;
	//Tries output
	cout << "Player took " << playerTries << endl;
	cout << "Enemy took " << enemyTries << endl;
	cout << "Enemy Linear took " << enemyLinearTries << endl;
	cout << "Enemy Random took " << enemyRandomTries << endl;
	return 0;
}