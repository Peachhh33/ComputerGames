#include <iostream>
#include <limits>
#include "functions.cpp"

using namespace std;

//Student name:	Xin Shu
//ID:		260773599

int main(){
	greetAndInstruct();
	char board[] = "abcdefghijklmnopqrstuvwxyz{";
	displayBoard(board);
	int count = 0; //this will count the number of total board displayed, so it can determine the winner. 
	while(!checkWinner(board)){//this loop will go until there is a winner
		if(count > 27){//if there are already 27 rounds and we are still in this loop, then this means a tie
			cout << "This is a tie" << endl;
			exit(1);
		}
		int a; //this is a temporary variable to catch the user's input
		cout << "Please pick a number for your move: " << endl;
		cin >> a;
		while(!checkIfLegal(a, board)){
			if(cin.fail()){//this is to prevent the user from typing in something that is not a number
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			cout << "Please try again: \n";
			cin >> a;
		}
		int choice = a; //the variable "choice" is a valid user's input now
		for(int i = 0;i<27; i++){ //go over the char array "board", and update it with the user's input
			if((int)board[i]-96 == choice){
				board[i] = 'X';
			}
		}
		count++;
		displayBoard(board); //display the updated board
		if(count == 1){
			cout << "So far, we had 1 turn." << endl;
		}else{
			cout << "So far, we had " << count << " turns." << endl;
		}
		if(checkWinner(board)){//if user wins after the current, the while loop stops. 
			break;
		}
		computerMove(board); //now computer takes a move.
		cout << "Computer's move: " << endl;
		count++;
		displayBoard(board);
		cout << "So far, we had " << count << " turns.\n";
	}
	cout << "By the end, we had totally " << count << " turns." << endl;
	if(count %2 != 0){
		cout << "Congratulations! You are the winner. \n";
		exit(1);
	}else{
		cout << "Computer wins. \n";
		exit(1);
	}
	return 1;
}
