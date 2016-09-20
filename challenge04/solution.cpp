// Challenge 04: Card Rank

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

// Main Execution

template <typename T>
void display(vector<T> &v){
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
    cout << "\n" << endl;
}

int main(int argc, char *argv[]) {
    
    //-------------Gather/Parse Input-------------//
    //      push_back values into int vector      //

	int N;
	char temp;
	cin >> N;
	
	struct Card {
	    int rank;
		string name;
	    char suit;
		int index;
	};

	vector<Card> cards;
	
	for (int i=0; i<N; i++) {
		cards.push_back(Card());
		
		cin >> cards[i].name >> temp >> cards[i].suit;
		
		if (temp == 'J'){
			cards[i].rank = 11;
		} else if (temp == 'Q') {
			cards[i].rank = 12;
		} else if (temp == 'K') {
			cards[i].rank = 13;
		} else if (temp == 'A') {
			cards[i].rank = 14;
		} else {
			cards[i].rank = (int)temp;
		}
		
		cards[i].index = i;
	}
	
	cout << cards[1].name << cards[1].rank << cards[1].suit << endl;

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

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
