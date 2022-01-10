#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <limits>
#include "blackjack.h"
using namespace std;

//Student name:	Xin Shu
//ID:		260773599

//to compile this assignment, please do "g++ main.cpp", then "./a.out".
//for the same class, I will not add an extra line between each method; I will be adding an extra line between each class. 
Card::Card(){}//the default constructor
Card::Card(rank number, type color){//constructor with parameters
	this->number = number;
	this->color = color;
}
int Card::getValue() const{
	if(number <=10){
		return number;
	}else if(number == JACK){
		return 10;
	}else if(number == QUEEN){
		return 10;
	}else if(number == KING){
		return 10;
	}
}
void Card::displayCard(){
	char temp;
	if(color == 0){
		temp = 'C';
	}else if(color == 1){
		temp = 'D';
	}else if(color == 2){
		temp = 'H';
	}else if(color == 3){
		temp = 'S';
	}
	if(number <= 10){
		cout << number << temp;
	}else if(number == JACK){
		cout << "J" << temp;
	}else if (number == QUEEN){
		cout << "Q" << temp;
	}else if (number == KING){
		cout << "K" << temp;	
	}
}
Card::~Card(){}//the default destructor

Hand::Hand(){}//default constructor
void Hand::add(Card random){//random means any card that is been added to the hand
	yours.push_back(random);
}
void Hand::clear(){
	yours.clear();
}
int Hand::getTotal() const{
	int x = yours.size();
	int total = 0;//initially total is 0.
	for(int i = 0; i<x; i++){ //add value of each card in the vector. 
		total += yours[i].getValue();
	}
	for(int i = 0; i<x; i++){//if the Player is better off when ACE is 11, then add 10 to the total value. 
		if(yours[i].getValue() == 1 && total <=11){
			total +=10;
		}
	}
	return total;
}
Hand::~Hand(){}//default destructor

Deck::Deck(){}//default constructor
void Deck::populate(){	
	clear();//I first will clean my deck so it is an empty deck. 
	for(int i = Card::ACE; i<= Card::KING; ++i){
		for(int j = Card::CLUBS; j<= Card::SPADES; ++j){
			Card addTemp(static_cast<Card::rank>(i), static_cast<Card::type>(j));
			add(addTemp);//I can direct use the add method since I inhereted from the Hand class. 
		}
	}
}
void Deck::shuffle(){
	srand((unsigned)time(NULL));//seed
	random_shuffle(yours.begin(), yours.end());//shuffle the vector from beginning to the end. 
}
void Deck::deal(Hand& a){//using a pointer so that the vectors are different for hand and for deck
	Card x = yours.back();//this returns the last element in the vector yours. 
	yours.pop_back();//this removes the last element and reduce the vector size by 1. 
	a.add(x); //add this Card to the hand input. 
}
Deck::~Deck(){}//default destructor

AbstractPlayer::AbstractPlayer(){}
bool AbstractPlayer::isBusted(Hand a){
	if(a.getTotal() > 21){//if total value exceed 21, then the generic player is busted. 
		return true;
	}else{
		return false;
	}	
}
AbstractPlayer::~AbstractPlayer(){}

HumanPlayer::HumanPlayer(){}
bool HumanPlayer::isDrawing() const{//this method asks the player if he/she want to draw a new card
	char choice;
	cout << "\tDo you want to draw? (y/n): ";
	cin >> choice;
	while(choice != 'y' && choice != 'n'){//as long as the player gives the wrong input, this loop will ask the user to type finally either y or n.
		if(cin.fail()){
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		cout << "\tYour input is invalid, please try again: ";
		cin >> choice;
	}
	if(choice == 'y'){
		return true;	
	}else if (choice == 'n'){
		return false;
	}
}
void HumanPlayer:: announce(int x){//print message on the screen according to different x value. 
	if(x == 5){
		cout << "\tPlayer wins.\n\n";
	}else if(x == 6){
		cout << "\tCasino wins.\n\n";
	}else if(x == 7){
		cout << "\tPush: No one wins.\n\n";
	}
}
HumanPlayer::~HumanPlayer(){}

ComputerPlayer::ComputerPlayer(){}
ComputerPlayer::ComputerPlayer(Hand temp){//this constructor is created for later use in the BlackJackGame
//because a computer player needs to have a hand of cards as well. 	
	this->casinoHand = temp;
}
bool ComputerPlayer::isDrawing() const{
	if(casinoHand.getTotal() <= 16){//casino stops drawing card if it has more than 16 total value on the hand
		return true;
	}else{
		return false;
	}
}
ComputerPlayer::~ComputerPlayer(){}

BlackJackGame::BlackJackGame(){}
void BlackJackGame::play(){
	int result;//this variable is used to print message on the screen for the result, as an input of the announce function. 
	m_deck.populate();//first I populate a deck of 52 cards
	m_deck.shuffle();//shuffle these 52 cards
	Hand me;//the player has a hand of cards
	Hand casino;//the casino also has a hand of cards
	m_deck.deal(me);//player gets two cards at the beginning
	m_deck.deal(me);
	m_deck.deal(casino);//casino gets 1 card. 
	ComputerPlayer update(casino);//update the ComputerPlayer as a ComputerPlayer with a hand of cards
	m_casino = update;
	cout << "\tCasino: "; //print all card info for the casino side
	for(int i =0; i<casino.yours.size(); i++){
		casino.yours[i].displayCard();
		cout << " ";
	}
	cout << "[" <<  casino.getTotal() << "]\n";
	cout << "\tPlayer: ";//print cards info for the player side
	for(int i =0; i<me.yours.size(); i++){
		me.yours[i].displayCard();
		cout << " ";
	}
	cout << "[" <<  me.getTotal() << "]\n";
	//it is  possible that the player gets 21 at this moment since an ACE and J/Q/K would make a 21 right away. 
	//so now the player need to wait for casino to draw the cards, so can make a comparison at the end. 
	HumanPlayer m;
	while(m.isDrawing()==true){//ask the human player if he/she wants to draw a new card
		m_deck.deal(me);//if yes, then give a card
		cout << "\tPlayer: ";//print the updated information
		for(int i =0; i<me.yours.size(); i++){
			me.yours[i].displayCard();
			cout << " ";
		}
		cout << "[" <<  me.getTotal() << "]\n";
		if(me.getTotal() == 21){
			break;//we should break this loop and wait for casino's result to compare
		}
		if(m.isBusted(me) == true){//if the player busted after drawing this new card
			cout << "\tPlayer busts.\n";
			result = 6;
			m.announce(result);//pass on the result integer to announce so the result message gets printed out
			me.clear();//since this round is over, clean the hand of the player
			casino.clear();//clean also the hand for the casino side
			return;//this turn is over, so end this function and continue witht the following program
		}
	}
	//casino is not winning nor busted at this point, it has only one card. 
	while(m_casino.isDrawing() == true){//so, if the player was not winning or busted with above code, it is now casino's turn. 
		m_deck.deal(casino);//give casino a new card
		cout << "\tCasino: ";
		for(int i =0; i<casino.yours.size(); i++){
			casino.yours[i].displayCard();
			cout << " ";
		}
		cout << "[" <<  casino.getTotal() << "]\n";
		m_casino = ComputerPlayer(casino);//update the ComputerPlayer m_casino to be the one with a hand of cards
		if(casino.getTotal() == 21){//if casino gets 21, end the loop immediately and move on the comparison with result of the player
			break;
		}
		if(casino.getTotal() > 21){//check if casino busts. 
			cout << "\tComputer busts.\n";
			result = 5;
			m.announce(result);
			me.clear();
			casino.clear();
			return;
		}
	}
	//if no one gets busted, we now compare their results
	int x = me.getTotal();
	int y = casino.getTotal();
	if( x > y){
		result = 5;
	}else if( x < y){
		result = 6;
	}else{
		result = 7;
	}
	m.announce(result);
	me.clear();
	casino.clear();
}
BlackJackGame::~BlackJackGame(){}//the default destructor
