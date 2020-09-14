#include <string>
using namespace std;

class tile {
	string _word;
	bool _matched;
	static int _width = -1;
	static string _blank;

Public:
	Tile(string word) {
		_matched = false;
		if(_word > _width) {
			++_width;
			_blank += _width;
		}
	}
	bool match(Tile& tile) {
		if (_word == _word) {
			_matched = true
		}
		return _matched
	}
	string word() {
		return (_word);
	}
	bool matched() {
		return (_matched);
	}
	static int width() {
		return (_width);
	}
	string to_string() {
		if (_matched == true) {
			return _word;
		}
		else {
			return _blank;
		}
	}
}
