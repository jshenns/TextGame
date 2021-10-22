#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
using namespace std;

int plantedGrain = 0;
int plantDay = 0;
int feedDay = 0;
int grain = 0;
int seeds = 0;
int day = 1;
int water = 0;
int cattle = 0;
int score = 0;
int gold = 100;
int actioncounter = 0;
string player;
void displayPrices();
void introMenu();
void perish();
void marketplace();
int random(int  lower, int upper);
void plantCrops();
void tavern();


int main()
{
	int select;
	introMenu();
	
	while(select != 5 )
	{
		if(score < 0 )
		{
			perish();
			select = 6;
		}
		cout << "\n\n\n\n\n\tDay: "<< day  <<" | Score: " << score << " | Gold: "<< gold<< endl;
		cout << "\t+---------------------------------------------------------------------------+" << endl;
		cout << "\t|                                 Main Menu                                 |" << endl;
		cout << "\t+---------------------------------------------------------------------------+" << endl;
		cout << "\t+---------------------------------------------------------------------------+" << endl;
		cout << "\t|                              1. Go to Market                              |" << endl;
		cout << "\t|                              2. Farming                                   |" << endl;
		cout << "\t|                              3. Adventure                                 |" << endl;
		cout << "\t|                              4. Go to Tavern                              |" << endl;
		cout << "\t|                              5. Quit                                      |" << endl;
		cout << "\t+---------------------------------------------------------------------------+" << endl;

		cout << "\n\t> ";
		cin >> select;

		if(select == 1)
		{
			marketplace();
			system("pause");
		}
		else if(select ==2 )
		{
			plantCrops();
			system("pause");
		}
		else if(select == 3)
		{
			cout << "\tFeature not yet availible" <<endl;
			cout << "\n" <<endl;
			system("pause");
		}
		else if(select == 4)
		{
			tavern();
			system("pause");
		}

		actioncounter++;
		score = (day + cattle*7 + grain*3 + gold*.5)*10;

		if(score <= 0)
		{
			perish();
			select = 6;
		}
		else if(actioncounter == 5)
		{
			day++;
			actioncounter = 0;
		}

		if(plantedGrain > 0 && day - plantDay > 2)
		{
			score -= plantedGrain*100;
			plantedGrain = 0;
			cout << "\n\tYou forgot to water your grain, " << player << ". It has all withered away." << endl;
		}
		if(cattle > 0 && day - feedDay > 2)
		{
			score -= cattle*200;
			cattle = 0;
			cout << "\n\tYou forgor to feed your cattle, " << player << ". They have all died of starvation." << endl;
		}

		


	}

	return 0;
}

void displayPrices()
{
	cout<<"\n\n\t\t\t\t\tPRICES OF RESOURCES"<<endl;
	cout<<"\n\t\t\t\t\tGrain: 5 gold"<<endl;
	cout<<"\t\t\t\t\tWater: 2 gold"<<endl;
	cout<<"\t\t\t\t\tCattle: 10 gold"<<endl;
	cout<<"\t\t\t\t\tSeeds: 3 gold"<<endl;
	cout << "\n" <<endl;
}

void introMenu()
{
	int exit;
	cout << "\n\tShall we play a game? (press 1 to play) : " <<endl;
	cout << "\n\t> ";
	cin >> exit;

	while(exit == 1)
	{
		cout <<"\t\t\t\t\tWelcome to the ancient land of Egypt"<<endl;
		cout << "\tEnter your name: "<<endl;
		cout << "\n\t> ";
		cin >> player;
		cout << "\n\tWelcome " << player << endl;
		cout << "\tIn Egypt, we must farm for a living, we must also save up resources"<<endl;
		cout << "\tYou will begin with 100 gold, as you buy and sell, your gold may increase or decrease" << endl;
		cout << "\tAre you ready to begin? (2 to continue, 1 to reinput name): " << endl;
		cout << "\n\t> ";
		cin >> exit;
	}
}

void marketplace()
{
	int sell;
	int select;
	int count;

	while(select != 7)
	{
		displayPrices();

		cout << "\tGrain(bushels): " << grain << " | Gold: " << gold << " | Seeds(KGs): " << seeds << " | Cattle: " << cattle << " | Water(100L): " << water <<endl;
		cout << "\t+---------------------------------------------------------------------------+" << endl;
		cout << "\t|                                  Market                                   |" << endl;
		cout << "\t+---------------------------------------------------------------------------+" << endl;
		cout << "\n\t+---------------------------------------------------------------------------+" << endl;
		cout << "\t|                              1. Buy Cattle                                |" << endl;
		cout << "\t|                              2. Buy Seeds                                 |" << endl;
		cout << "\t|                              3. Buy Grain                                 |" << endl;
		cout << "\t|                              4. Buy Water                                 |" << endl;
		cout << "\t|                              5. Sell Grain                                |" << endl;
		cout << "\t|                              6. Sell Cattle                               |" << endl;
		cout << "\t|                              7. Quit                                      |" << endl;
		cout << "\t+---------------------------------------------------------------------------+" << endl;
		
		cout << "\n\t> ";
		cin >> select;
		

		if(select == 1 )
		{
			cout << "\tHow many cattle do you want to buy?" <<endl;
			cout << "\n\t> ";
			cin >> count;

			if(gold < 10*count )
			{
				cout << "\tYou do not have enough gold!" << endl;
			}
			else
			{
				
				cattle += count;
				gold -= 10*count;
			}
			
		}
		else if(select == 2)
		{
			cout << "\tHow many seeds do you want to buy?(units of 15 KGs)" <<endl;
			cout << "\n\t> ";
			cin >> count;

			if(gold < 3*count )
			{
				cout << "\tYou do not have enough gold!" << endl;
			}
			else
			{

				seeds += 15*count;
				gold -= 3*count;
			}
			
		}
		else if(select == 3)
		{
			cout << "\tHow much grain do you want to buy(units of 6 bushels)?" <<endl;
			cout << "\n\t> ";
			cin >> count;

			if(gold < 5*count )
			{
				cout << "\tYou do not have enough gold!" << endl;
			}
			else
			{
				grain += 6*count;
				gold -= 5*count;
			}
			
		}
		else if(select == 4)
		{
			cout << "\tHow much water do you want to buy(units of 25 L)?" <<endl;
			cout << "\n\t> ";
			cin >> count;

			if(gold < 2*count )
			{
				cout << "\tYou do not have enough gold!" << endl;
			}
			else
			{
				water += count*25;
				gold -= 2*count;
			}
			
			
		}
		else if(select == 5)
		{
			cout << "\tHow many bushels do you want to sell" <<endl;
			cout << "\n\t> ";
			cin >> sell;
			if(grain - sell < 0)
			{
				cout << "\tYou do not have enogh grain" << endl;
			}
			else
			{
				grain -= sell;
				gold += sell*4;
			}
		}
		else if(select == 6)
		{
			cout << "\tHow many cattle do you want to sell" <<endl;
			cout << "\n\t> ";
			cin >> sell;
			if(cattle - sell < 0)
			{
				cout << "\tYou do not have enogh cattle" << endl;
			}
			else
			{
				cout << "\n\tDon't forget to feed your cattle one bushel of grain per cow every day!!" << endl;
				feedDay = day;
				cattle -= sell;
				gold += sell*7;
			}
		}

	}
}

void perish()
{
	cout << "\n\n\t+---------------------------------------------------------------------------+" << endl;
	cout << "\t|                                 GAME OVER                                 |" << endl;	
	cout << "\t|                                                                           |" << endl;
	cout << "\t|                                 Score < 0                                 |" << endl;
	cout << "\t+---------------------------------------------------------------------------+" << endl;	
	exit(0);
}

int random(int  lower, int upper)
{
	srand(time(0));

	return lower + (rand() % upper);
}

void plantCrops()
{
	int plant = 0;
	int select = 0;
	
	
	while(select != 5)
	{
		cout << "\n\n\tGrain(bushels): " << grain << " | Gold: " << gold << " | Seeds(KGs): " << seeds << " | Cattle: " << cattle << " | Water(100L): " << water <<endl;
		cout << "\t+---------------------------------------------------------------------------+" << endl;
		cout << "\t|                                  Farming                                  |" << endl;
		cout << "\t+---------------------------------------------------------------------------+" << endl;
		cout << "\t+---------------------------------------------------------------------------+" << endl;
		cout << "\t|                              1. Plant Grain                               |" << endl;
		cout << "\t|                              2. Feed Cattle                               |" << endl;
		cout << "\t|                              3. Harvest Grain                             |" << endl;
		cout << "\t|                              4. Water Grain                               |" << endl;
		cout << "\t|                              5. Quit                                      |" << endl;
		cout << "\t+---------------------------------------------------------------------------+" << endl;

		cout << "\n\t> ";
		cin >> select;
		if(select == 1)
		{
			cout << "\n\tHow much grain do you want to plant? (kg of seeds)" <<endl;
			cout << "\n\t> ";
			cin >> plant;

			if(plant > seeds)
			{
				cout << "\n\tYou do not have enough seeds!" <<endl;
			}
			else
			{
				seeds -= plant;
				plantedGrain += plant;

				cout << "\n\tRemember to give your planted grain 100L of water per kg of planted seeds every day!!" << endl;
				plantDay = day;
			}
			
		}
		else if(select == 2)
		{
			if(cattle > 0 && grain - cattle >= 0)
			{
				grain -= cattle;

			}
			else if(cattle <= 0)
			{
				cout << "\n\tYou don't have any cattle." << endl;
			}
			else if(grain - cattle < 0)
			{
				cout << "\n\tYou don't have enough grain." << endl;
			}
			
		}
		else if(select >=3  && select < 5)
		{
			cout << "\tFeature not yet availible" << endl;
			system("pause");
		}
		else if(select > 5)
		{
			cout << "\tEnter a number 1 - 5" <<endl;
			system("pause");
		}

	}

}

void tavern()
{
	int select;
	int bet;
	int roll;

	while(select != -1)
	{
		cout << "\n\n\tGold: " << gold << endl;
		cout << "\t+---------------------------------------------------------------------------+" << endl;
		cout << "\t|                                  Tavern                                   |" << endl;
		cout << "\t+---------------------------------------------------------------------------+" << endl;

		cout << "\n\t+---------------------------------------------------------------------------+" << endl;
		cout << "\t|                           Welcome To The Tavern                           |" << endl;
		cout << "\t|                                                                           |" << endl;
		cout << "\t|                                                                           |" << endl;
		cout << "\t|                   Bet an ammount of gold on a dice roll                   |" << endl;
		cout << "\t|                   Bet by typing a number (1-6), and the bet ammount       |" << endl;
		cout << "\t|                   I.E. (5 26)                                             |" << endl;
		cout << "\t|                   (-1 -1 to quit)                                         |" << endl;
		cout << "\t|                                                                           |" << endl;
		cout << "\t|                                                                           |" << endl;
		cout << "\t|                                                                           |" << endl;
		cout << "\t+---------------------------------------------------------------------------+" << endl;

		cout << "\n\t> ";
		cin >> select >> bet;


		roll = random(1, 6);
		if(select > 0 && select <=6 && gold - bet >= 0)
		{
			cout << "\n\tDice: " << roll <<endl;
			if(select == roll)
			{
				cout << "\n\tCongrats, "<< player << "! You win " << pow(bet, 2) << " gold!" <<endl;
				gold += pow(bet, 2);
			}
			else if(select != roll)
			{
				cout << "\n\tSorry " << player << ", you lose! " << endl;
				gold -= bet;
			}

		}
		else if(select > 6)
		{
			cout << "\n\tYou must input a number between 1 and 6" <<endl;
		}
		else if(gold - bet < 0)
		{
			cout << "\n\tYou do not have enough gold to make that bet" <<endl;
		}

	}
}
	
	

