#include <iostream>
#include <limits>

using namespace std;

//Student name:	Xin Shu
//ID:		260773599

void greetAndInstruct(){	
	cout << "\nHello and welcome to the Tic Tac Toe challenge: Player against Computer.\n";
	cout << "The board is numbered from 1 to 27 as per the following: \n";
	cout << "\n1 | 2 | 3     10 | 11 | 12     19 | 20 | 21 \n";
	cout << "---------     ------------     ------------\n";
	cout << "4 | 5 | 6     13 | 14 | 15     22 | 23 | 24\n";
	cout << "---------     ------------     ------------\n";
	cout << "7 | 8 | 9     16 | 17 | 18     25 | 26 | 27\n";
	cout << "\nPlayer starts first. Simply input the number of the cell you want to occupy. Player's move is marked with X. Computer's move is marked with O.\n";
	cout << "Start? (y/n):\n";
	cout << endl;
	string answer;
	cin >> answer;
	if (answer  == "y"){
		cout << "Let the game start! Good luck!" << endl;
	}else if (answer == "n"){
		exit(1);
	}else{
		cout << "Your input is invalid, please try again. \n";
		greetAndInstruct();
		//make a recursive call if the user is typing in something neither 'y' nor 'n', and this recursion terminates until user inputs either 'y' or 'n'
	}
}

//this is a very long function because the 2-character case and the single-character case are considered seperately.
//for example, '10' will occupy one more space than '9'.
//I will print the 3 matrices vertically, so there will have 3 spots on each row and totally 9 rows.
void displayBoard(char board[]){
	for(int i = 0; i<27; i++){
		if(i<9){ //since digit larger than 9 will have two chracters, it needs one more space for each
			cout << "   |    |   \n";
		}else{
			cout << "    |     |   \n";
		}
		if(board[i] == 'X' || board[i] == 'O'){//if the first one on the row is an input
			if(board[i] == 'X'){//print each respectively
				if(i<9){
					cout << 'X' << "  | ";
				}else{
					cout << 'X' << "   | ";//with one more space, as always for numbers 10 and 10+.
				}
			}else if (board[i] == 'O'){
				if(i<9){
					cout << 'O' << "  | ";
				}else{
					cout << 'O' << "   | ";
				}
			}
			if(board[i+1] == 'X' || board[i+1] == 'O'){//if the second one on the row is an input
				if(board[i+1] == 'X'){
					if(i<9){
						cout << 'X' << "  | ";
					}else{
						cout << 'X' << "   | ";
					}
				}else if (board[i+1] == 'O'){
					if(i<9){
						cout << 'O' << "  | ";
					}else{
						cout << 'O' << "   | ";
					}
				}
				if(board[i+2] == 'X' || board[i+2] == 'O'){//if the third one on the row is an input
					if(board[i+2] == 'X'){
						cout << 'X' << endl;
						//since there are only 3 spots on one row, when we reach the third one, the program goes to the next row, so "endl" here. 
					}else if (board[i+2] == 'O'){
						cout << 'O' << endl;
					}
					//follwing if-else statement is for printing out the line between each row.
					if(i<6){//same reason as above, digits larger than 9 will have 2 characters in each, need one more space
						cout << "___|____|___" << endl;
						cout << "   |    |   " << endl;
					}else if(i>8 && i<24){
						cout << "____|_____|____" << endl;
						cout << "    |     |    " << endl;
					//if we are at the last row on each 3x3 matrix, we do not print out the line, since we move on to the next matrix.
					}else if(i==6){
						cout << "   |    |   " << endl;
					}else{
						cout << "    |     |    " << endl;
					}
				}else{
					cout << (int)board[i+2]-96 << endl;//if the third one on the row is not an input
					if(i<6){
						cout << "___|____|___" << endl;
						cout << "   |    |   " << endl;
					}else if(i>8 && i<24){
						cout << "____|_____|____" << endl;
						cout << "    |     |    " << endl;
					}else if(i ==6){
						cout << "   |    |   "<< endl;
					}else{
						cout << "    |     |    " << endl; 
					}
				}
			}else{
				cout << (int)board[i+1]-96 << "  | ";//if the second one on the row is not an input
				if(board[i+2] == 'X' || board[i+2] == 'O'){//but if the third one is an input
					if(board[i+2] == 'X'){
						cout << 'X' << endl;
					}else if (board[i+2] == 'O'){
						cout << 'O' << endl;
					}
					if(i<6){
						cout << "___|____|___" << endl;
						cout << "   |    |   " << endl;
					}else if(i>8 && i<24){ 
						cout << "____|_____|____" << endl;
						cout << "    |     |    " << endl;
					}else if(i==6){
						cout << "   |    |   " << endl;
					}else{
						cout << "    |     |    " << endl;
					}
				}else{
					cout << (int)board[i+2]-96 << endl;//if the third one is not an input
					if(i<6){
						cout << "___|____|___" << endl;
						cout << "   |    |   " << endl;
					}else if(i>8 && i<24){	
						cout << "____|_____|____" << endl;
						cout << "    |     |    " << endl;
					}else if(i==6){
						cout << "   |    |   " << endl;
					}else{
						cout << "    |     |    " << endl;
					}
				}
			}	
		}else{
			cout << (int)board[i]-96 << "  | ";//if the first one is not an input
			if(board[i+1] == 'X' || board[i+1] == 'O'){//but if the second one is the input
				if(board[i+1] == 'X'){
					if(i<9){
						cout << 'X' << "  | ";
					}else{
						cout << 'X' << "   | ";
					}
				}else if (board[i+1] == 'O'){
					if(i<9){
						cout << 'O' << "  | ";
					}else{
						cout << 'O' << "   | ";
					}
				}
				if(board[i+2] == 'X' || board[i+2] == 'O'){//if the third one is an input
					if(board[i+2] == 'X'){
						cout << 'X' << endl;
					}else if (board[i+2] == 'O'){
						cout << 'O' << endl;
					}
					if(i<6){
						cout << "___|____|___" << endl;
						cout << "   |    |   " << endl;
					}else if(i>8 && i<24){
						cout << "____|_____|____" << endl;
						cout << "    |     |    " << endl;
					}else if(i == 6){
						cout << "   |    |   " << endl;
					}else{
						cout << "    |     |    " << endl;
					}
				}else{
					cout << (int)board[i+2]-96 << endl;//if the third one is not an input
					if(i<6){
						cout << "___|____|___" << endl;
						cout << "   |    |   " << endl;
					}else if(i>8 && i<24){
						cout << "____|_____|____" << endl;
						cout << "    |     |    " << endl;
					}else if(i == 6){
						cout << "   |    |   " << endl;
					}else{
						cout << "    |     |    " << endl;
					}
				}
			}else{
				cout << (int)board[i+1]-96 << "  | ";//the second one is not an input
				if(board[i+2] == 'X' || board[i+2] == 'O'){//the third one is an input
					if(board[i+2] == 'X'){
						cout << 'X' << endl;
					}else if (board[i+2] == 'O'){
						cout << 'O' << endl;
					}
					if(i<6){
						cout << "___|____|___" << endl;
						cout << "   |    |   " << endl;
					}else if(i>8 && i<24){
						cout << "____|_____|____" << endl;
						cout << "    |     |    " << endl;
					}else if(i == 6){
						cout << "   |    |   " << endl;
					}else{
						cout << "    |     |    " << endl;
					}
				}else{
					cout << (int)board[i+2]-96 << endl;//the third one is an input
					if(i<6){
						cout << "___|____|___" << endl;
						cout << "   |    |   " << endl;
					}else if(i>8 && i<24){
						cout << "____|_____|____" << endl;
						cout << "    |     |    " << endl;
					}else if(i == 6){
						cout << "   |    |   " << endl;
					}else{
						cout << "    |     |    " << endl;
					}
				}
			}
		}
		i++;//i+2 since we need to skip to the next row.
		i++;
	}
}

bool checkIfLegal(int cellNbre, char board[]){
	if(board[cellNbre-1] == 'X' || board[cellNbre-1] == 'O'){ //check if this slot is already occupied by a previous move.
		cout << "The position is already occupied." << endl;
		return false;
	}else if(board[cellNbre-1]-96 < 1 || board[cellNbre-1]-96 >27){//check if out of range, i.e., input is not number between 1 to 27.
		cout << "Your input is either not a number or is out of range. " << endl;
		return false;
	}
	return true;
}

//remark: by "flat", I mean "on the same 3x3 matrix"; by "3D", I mean "crossing over the 3 matrices".
bool checkWinner(char board[]){
	for(int i = 0; i<27; i+=3){//check 3 consecutive horizontal flat spots
		if(board[i] == board[i+1] && board[i+1] == board[i+2]){
			return true;
		}
	}
	for(int i = 0; i<21; i++){ //check vertical consecutive 3 positions
		if(i == 3){//there are only 3 vertical flat diagonals possible, one on each matrix
			i=9;
		}
		if(i == 12){
			i=18;
		}
		if(board[i] == board[i+3] && board[i+3] == board[i+6]){
			return true;
		}
	}
	for(int i = 0; i<21; i+=9){//check flat diagonals, shape like "\"
		if(board[i] == board[i+4] && board[i+4] == board[i+8]){
			return true;
		}
	}
	for(int i = 2; i<21; i+=9){//check reverse flat diagonals, shape like "/"
		if(board[i]== board[i+2] && board[i+2] == board[i+4]){
			return true;
		}
	}
	for(int i = 0; i<9; i++){//check 3D same postion on each matrix
		//for example, always the first one on each matrix, position 1, 10 and 19
		if(board[i] == board[i+9] && board[i+9] == board[i+18]){
			return true;
		}
	}
	if(board[0] == board[12] && board[12] == board[24]){ //3D diagonal on the same face
		return true;
	}else if(board[2] == board[14] && board[14] == board[26]){
		return true;
	}else if(board[6] == board[12] && board[12] == board[18]){
		return true;
	}else if(board[8] == board[14] && board[14] == board[20]){
		return true;
	}
	
	if(board[0] == board[13] && board[13] == board[26]){ //totally 8 3D diagonals through center index 13
		return true;
	}else if(board[1] == board[13] && board[13] == board[25]){
		return true;
	}else if(board[2] == board[13] && board[13] == board[24]){
		return true;
	}else if(board[3] == board[13] && board[13] == board[23]){
		return true;
	//there is no case for index 4 because it is the straight 3D diagonal, it was included in other loop above.
	}else if(board[5] == board[13] && board[13] == board[21]){
		return true;
	}else if(board[6] == board[13] && board[13] == board[20]){
		return true;
	}else if(board[7] == board[13] && board[13] == board[19]){
		return true;
	}else if(board[8] == board[13] && board[13] == board[18]){
		return true;
	}
	return false;
}

void computerMove(char board[]){
	//scan over the board, if find an empty slot, see if input here will result winning of computer
	for(int i = 0; i<27; i++){//scan over the board
		if(board[i] != 'X' && board[i] != 'O'){
			char temp = board[i];
			board[i] = 'O';
			if(checkWinner(board)){
				board[i] = 'O';
				return;
			}else{
				board[i] = temp;//if not, update the board by its original numbers
			}
		}
	}
	//see if input here will result user's winning, if yes, input here
	for(int i = 0;i<27; i++){
		if(board[i] != 'X' && board[i] != 'O'){
			char temp = board[i];
			board[i] = 'X';
			if(checkWinner(board)){
				board[i] = 'O';
				return;
			}else{
				board[i] = temp;
			}
		}
	}
	//if none of the 2 cases above are reached, then simply find the next empty slot and input.
	for(int i = 0; i<27; i++){
		if(board[i] != 'X' && board[i] != 'O'){
			board[i] = 'O';
			return;
		}
	}
}
