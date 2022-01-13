#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#include <limits>
#include <cstdlib>
using namespace std;

//to compile this assignment, please do "g++ main.cpp", then "./a.out".
class Card{
	public:
		enum rank{ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
		enum type{CLUBS, DIAMONDS, HEARTS, SPADES};
		Card();//default constructor
		Card(rank number, type color);//contructor with parameters
		int getValue() const;
		void displayCard();
		~Card();//the default destructor
	protected://protected so the inheretence classes could have access to these two variables
		rank number;
		type color;
};
class Hand{
	public: 
		Hand();// the default constructor
		void add(Card random);
		void clear();
		int getTotal() const;
		~Hand(); //the default destructor
		vector<Card> yours;//this vector is the field of this class, I declare it for the use in BlackJackGame function
};
class Deck: public Hand{
	public:
		Deck();
		void populate();
		void shuffle();
		void deal(Hand& a);
		~Deck();
};
class AbstractPlayer:public Hand{
	public:
		AbstractPlayer();
		virtual bool isDrawing() const = 0;//a pure virtual function.Only declared here, it will be implemented in the following two classes
		bool isBusted(Hand a);
		~AbstractPlayer();
};
class HumanPlayer:public AbstractPlayer{
	public:
		HumanPlayer();
		bool isDrawing() const;
		void announce(int x);
		~HumanPlayer();
};
class ComputerPlayer:public AbstractPlayer{
	public:
		ComputerPlayer();
		ComputerPlayer(Hand temp);//this one is used for updating the hand of cards of the ComputerPlayer in the play() function
		bool isDrawing() const;
		~ComputerPlayer();
	protected:
		Hand casinoHand;
};
class BlackJackGame{
	public:
		BlackJackGame();
		void play();
		~BlackJackGame();
	protected:
		Deck m_deck;
		ComputerPlayer m_casino;
};
