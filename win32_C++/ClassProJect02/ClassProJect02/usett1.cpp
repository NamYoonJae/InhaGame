#include "stdafx.h"
#include "tabtenn1.h"
#include <iostream>


using namespace std;

void main(void) {

	TableTennisPlayer player1{ "Tara", "Boomdea", false };
	RatedPlayer rplayer1(1140, "Mallory", "Duck", true);
	rplayer1.Name();

	if (rplayer1.HasTable())
		cout << " : Å¹±¸´ë°¡ ÀÖ´Ù.\n";
	else
		cout << " : Å¹±¸´ë°¡ ¾ø´Ù.\n";

	player1.Name();

	if(player1.HasTable())
		cout << " : Å¹±¸´ë°¡ ÀÖ´Ù.\n";
	else
		cout << " : Å¹±¸´ë°¡ ¾ø´Ù.\n";
	
	cout << "ÀÌ¸§: ";
	rplayer1.Name();
	cout << "; ·©Å· : " << rplayer1.Rating() << endl;
	
	RatedPlayer rplayer2(1212, player1);
	cout << "ÀÌ¸§: ";
	rplayer2.Name();
	cout << ";·©Å·: " << rplayer2.Rating() << endl;
}