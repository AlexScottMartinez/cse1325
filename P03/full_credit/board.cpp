#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class board {
	vector<Tile> _tiles {
	"bang", "beam", "bear", "cafe", "came",
	"cold", "come", "cool", "date", "diet",
	"door", "doth", "echo", "exes", "exit",
	"face", "fame", "feed", "fire", "five",
	"four", "free", "frog", "from", "game",
	"goes", "good", "grit", "have", "heal",
	"hear", "here", "hide", "hole", "home",
	"hope", "huge", "keep", "kill", "lace",
	"lame", "leek", "life", "live", "maps",
	"mass", "mate", "maze", "move", "near",
	"need", "nine", "once", "quit", "ques",
	"race", "read", "reed", "reef", "rice",
	"roof", "sins", "stay", "tame", "teen",
	"tens", "tide", "tied", "tree", "twin",
	"zero", "zips",
	};

Public:
	Board(int tiles) {
		random_shuffle (tiles.begin(), tiles.end(), rand()%tiles);
	}
	string attempt(int tile1, int tile2) {
		if (tile1 == tile2) {
			return tile1 && tile2;
			cout << "MATCHES" ;
		}
		else {
			return tile1 && tile2;
		}
	}
	bool solved() {
		if (attempt == 0) {
			return true;
		}
		else {
			return false
		}
	}
	string to_string() {
		return board;
	}	
}
