// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <vector>

#include "Life.h"

// ----
// main
// ----

int main () {
    using namespace std;
    string s;
    while (getline(cin, s)) {
        s = s.substr(0, s.size() - 1);
        if (s.compare("ConwayCell") == 0) {
            Life<ConwayCell> l(s);
            l->run(cin, cout);
        };
        if (s.compare("FredkinCell") == 0) {
            Life<FredkinCell> l(s);
            l->run(cin, cout);
        };
        if (s.compare("Cell") == 0) {
            Life<Cell> l(s);
            l->run(cin, cout);
        };
        getline(cin, s);
    }
    return 0;
}