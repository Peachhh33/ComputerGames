#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <limits>
#include "blackjack.cpp"
using namespace std;

//to compile this assignment, please do "g++ main.cpp", then "./a.out".
int main(){
	cout << "\tWelcome to the Comp322 Blackjack game!" << endl << endl;
	BlackJackGame game;
	bool playAgain = true;
	char answer = 'y';
	while(playAgain){
		game.play();
		cout << "\tWould you like another round? (y/n): ";
		cin >> answer;
		cout << endl << endl;
		playAgain = (answer == 'y' ? true:false);
	}	
	cout << "\tGave over!\n\n";
	return 0;
}
