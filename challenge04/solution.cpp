// Challenge 04: Card Rank

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

// Main Execution

// each player/card in struct
struct Card {
    int rank, suit;
	string name;
};

void convert_royalty(Card *c, string rank);// converts royalty to integers
void convert_suits(Card *c, char suit);	// converts suits to integers
bool compare_rank(Card &a, Card &b);		// compares rank
bool compare_suit(Card &a, Card &b);		// compares suit

int main(int argc, char *argv[]) {
   
	int N = 0;
	string rank;
	char suit;
	
	vector<Card> cards;		// each card stored in vector of structs
	
	while (1){
		
		cin >> N;
		if (N==-1) break;	// sentinel value
		
		for (int i=0; i<N; i++) {
			// create cards and read input
			cards.push_back(Card());
			cin >> cards[i].name >> rank >> suit;
			
			// convertroyalty and suits to ints
			convert_royalty(&cards[i], rank);
			convert_suits(&cards[i], suit);
		}
		
		// sort first by suit, then rank
		std::sort(cards.begin(), cards.end(), compare_suit);
		std::sort(cards.begin(), cards.end(), compare_rank);
		
		// display names
		for (int i=0; i<cards.size(); i++) {
			cout << cards[i].name;
			if (i==cards.size()-1) continue;
			cout << ", ";
		}
		cout << endl;
		cards.clear();
	}

    return EXIT_SUCCESS;
}

// convert royalty to integers
void convert_royalty(Card *c, string rank){
	if (rank.size()<2) {
		if (rank[0] == 'J'){
			c->rank = 11;
		} else if (rank[0] == 'Q') {
			c->rank = 12;
		} else if (rank[0] == 'K') {
			c->rank = 13;
		} else if (rank[0] == 'A') {
			c->rank = 14;
		} else {
			c->rank = rank[0] - '0';
		}
	} else {
		// 10 is the only two-digit rank
		c->rank = 10;
	}
	
}

// convert suits to integers
void convert_suits(Card *c, char suit){
	if (suit == 'C'){
		c->suit = 1;
	} else if (suit == 'D') {
		c->suit = 2;
	} else if (suit == 'H') {
		c->suit = 3;
	} else if (suit == 'S') {
		c->suit = 4;
	}
}

bool compare_rank(Card &a, Card &b){
    return a.rank > b.rank;
}

bool compare_suit(Card &a, Card &b){
    return a.suit > b.suit;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
