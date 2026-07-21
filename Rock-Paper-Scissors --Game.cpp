#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "inputslib.h"
#include "RandLib.h"


using namespace std;
using namespace inputslib;
using namespace RandLib;















enum enRockPaperSCISSORS {

	rock = 1 , paper , scissors
};
enum loseWinDraw
{
	lose =1 , win =2 ,draw =3
};
int read_Number_1to3()
{
	int number;
	do {
		cout <<"\nEnter [ 1 ] ROCK , [ 2 ] PAPER, [ 3 ] SCISSORS" << endl;
		cin >> number;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max() , '\n');
			cout << "Wrong Index, Enter A valid One\n";
			cin >> number;


		}
	} while (number < 0 || number > 3);
	return number;
}
int fun_random_number(int from, int to)
{
	int randomnumber = 0;

	randomnumber = rand() % (to - from + 1) + from;

	return randomnumber;
}
int rounds()
{
	int rounds = 0;
	rounds = read_PositiveNumber("Enter How Many Rounds You Want To Play");
	

	return rounds;
}
void LWD_counter(loseWinDraw result, int& win, int& lose, int& draw)
{

	switch (result)
	{
	case (loseWinDraw::draw):
	{
		draw++;
	}break;
	case (loseWinDraw::win):
	{
		win++;
	}break;
	case (loseWinDraw::lose):
	{
		lose++;
	}


	}

}

loseWinDraw computer_vs_player(enRockPaperSCISSORS &computer, enRockPaperSCISSORS &player)
{

	if (computer == enRockPaperSCISSORS::paper && player == enRockPaperSCISSORS::paper)
	{
		return loseWinDraw::draw;
		
	}
	
	else if (computer == enRockPaperSCISSORS::rock && player == enRockPaperSCISSORS::rock)
	{
		return loseWinDraw::draw;
	}
	else if (computer == enRockPaperSCISSORS::scissors && player == enRockPaperSCISSORS::scissors)
	{
		return loseWinDraw::draw;
	}
	else if (computer == enRockPaperSCISSORS::scissors && player == enRockPaperSCISSORS::rock)
	{
		return loseWinDraw::win;
	}
	else if (computer == enRockPaperSCISSORS::paper &&  player == enRockPaperSCISSORS::scissors)
	{											    
		return loseWinDraw::win;				    
	}											     
	else if (computer == enRockPaperSCISSORS::rock  && player == enRockPaperSCISSORS:: paper)
	{
		return loseWinDraw::win;
	}
	else if (computer == enRockPaperSCISSORS::scissors && player == enRockPaperSCISSORS::paper)
	{
		return loseWinDraw::lose;
	}
	else if (computer == enRockPaperSCISSORS::rock && player == enRockPaperSCISSORS::scissors)
	{
		return loseWinDraw::lose;
	}
	else if (computer == enRockPaperSCISSORS::paper && player == enRockPaperSCISSORS::rock)
	{
		return loseWinDraw::lose;
	}
	
	
	
	


	


}
enRockPaperSCISSORS converse_toEnum(int number)
{
	
	if (number == 1)
	{
		
		return enRockPaperSCISSORS::rock;
		
	}
	else if (number == 2)
	{
		return enRockPaperSCISSORS::paper;
	}
	else if (number == 3)
	{
		return enRockPaperSCISSORS::scissors;
	}


}
string to_word(enRockPaperSCISSORS choice)
{
	string word;
	switch (choice)
	{
	case(enRockPaperSCISSORS::paper):
	{
	word = "Paper";
	}break;
    case(enRockPaperSCISSORS::rock):
	{
		word = "Rock";
	}break;
	case(enRockPaperSCISSORS::scissors):
	{
		word = "scissors";

	}break;


	}
	return word;
	
	
	
	
	

	

}

bool askusertorepate()
{
	string y_n = "";
	do {
  	cout << "Do You Want to reapet ? y/n\n";
		cin >> y_n;

	}while (y_n != "y" && y_n != "n");
	
	if (y_n == "y")
	{
		return true;
	}
	return false;
}

void TheGame(int i , int &winc , int &losec , int &drawc)
{
	

	enRockPaperSCISSORS player_choice = converse_toEnum(read_Number_1to3());
	enRockPaperSCISSORS computer_choice = converse_toEnum(fun_random_number(1, 3));
	
	loseWinDraw result = computer_vs_player(computer_choice ,player_choice);
	LWD_counter(result, winc, losec, drawc);
	cout << "\n__________Round [" << i << "] ____________\n";
	switch (result)
{
	case (loseWinDraw::draw):
	{
		cout << "Player Choice :" << to_word(player_choice) << endl;
		cout << "computer Choice :" << to_word(computer_choice) << endl;
		cout << "Game Result : Draw\n";
		cout << "______________________________\n";
		system("color 8F");

	}break;
	case (loseWinDraw::win):
	{
		cout << "Player Choice :" << to_word(player_choice) << endl;
		cout << "computer Choice :" << to_word(computer_choice) << endl;
		cout << "Game Result : Player won\n";
		cout << "______________________________\n";
		system("color 2F");

	}break;
	case (loseWinDraw::lose):
	{
		cout << "Player Choice :" << to_word(player_choice) << endl;
		cout << "computer Choice :" << to_word(computer_choice) << endl;
		cout << "Game Result : Computer Won\n";
		cout << "______________________________\n";
		system("color 4F");
		cout << "\a";

	}break;
		

}
	
}
void Gameover(int &winc , int &losec , int &drawc)
{
	cout << "\n\n     ________________ Game Over ___________________\n";
	cout << "\n                       Results \n\n";
	cout << "       Player : " << winc;
	cout << "\n     Computer : " << losec;
	cout << "\n         Draw : " << drawc << endl;
	cout << "     _______________________________________________\n\n\n";

}
void TheGame_Repater()
{
	do
	{
		system("cls");
	int win = 0, lose = 0, draw = 0;
	
	int roundsnumber = 0;
	roundsnumber = rounds();

		for (int i = 1; i <= roundsnumber; i++)
		{
			cout << "\n\nRound [" << i << "] Begins : **Press Enter To Continoue**\n";
			cin.ignore();
			cin.get();
			TheGame(i, win, lose, draw);


		}

		Gameover(win, lose, draw);
	} while (askusertorepate() == true);
}


int main()
{
	srand(unsigned(time(NULL)));
	TheGame_Repater();
	
	
	
	
	
	
	


}