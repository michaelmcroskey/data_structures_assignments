// Challenge 04: Card Rank

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

// Main Execution
struct Card {
    int rank, suit;
	string name;
};

void royalty(Card *c, char rank);
void convert_suits(Card *c, char suit);
bool compare_rank(const Card &a, const Card &b);
bool compare_suit(const Card &a, const Card &b);

int main(int argc, char *argv[]) {
    
    //-------------Gather/Parse Input-------------//
    //      push_back values into int vector      //

	int N;
	char rank, suit;
	cin >> N;

	vector<Card> cards;
	cout << endl;
	
	for (int i=0; i<N; i++) {
		cards.push_back(Card());
		cin >> cards[i].name >> rank >> suit;
		
		royalty(&cards[i], rank);
		convert_suits(&cards[i], suit);
		
//		cout << cards[i].name << " " << cards[i].rank << " " << cards[i].suit << endl;
	}
	
	std::sort(cards.begin(), cards.end(), compare_suit);
	std::sort(cards.begin(), cards.end(), compare_rank);
	
	for (int i=0; i<N; i++) {
		cout << cards[i].name << " ";
		if (i==N-1) {
			break;
		}
	}
	

//    while (getline(std::cin, line)){
//        if (line.empty()) continue;
//        
//        if (firstline) {
//            N = stoi(line);
//            firstline = false;
//            continue;
//        }
//        
//        stringstream s(line);
//        cout << s << endl;
//	}

    return EXIT_SUCCESS;
}

void royalty(Card *c, char rank){
	if (rank == 'J'){
		c->rank = 11;
	} else if (rank == 'Q') {
		c->rank = 12;
	} else if (rank == 'K') {
		c->rank = 13;
	} else if (rank == 'A') {
		c->rank = 14;
	} else {
		c->rank = rank - '0';
	}
}

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

bool compare_rank(const Card &a, const Card &b){
    return a.rank > b.rank;
}

bool compare_suit(const Card &a, const Card &b){
    return a.suit > b.suit;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
