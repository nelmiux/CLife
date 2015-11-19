// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <vector>

#include "Life.h"

using namespace std;

AbstractCell::AbstractCell (char sym):_sym(sym), _alive(!((sym == '.') || (sym == '-'))), _age(0) {}

bool AbstractCell::isAlive () {
    return _alive;
}

ConwayCell::ConwayCell (char sym): AbstractCell(sym) {}

void ConwayCell::mySym () {
    if (!_alive) _sym = '.';
    else _sym = '*';
}

int ConwayCell::currentAge() {return 0;}

bool ConwayCell::isFred() {return false;}

ConwayCell* ConwayCell::clone() const {return new ConwayCell(*this);}

void ConwayCell::evolve (int n) {
    bool _pre_alive = _alive;
    if ((!_pre_alive) && (n == 3)) _alive = true;
    if ((_pre_alive) && ((n < 2) || (n > 3))) _alive = false;
    mySym();
}


FredkinCell::FredkinCell(char sym): AbstractCell(sym) {}

void FredkinCell::mySym () {
    if (!_alive) {
        _sym = '-';
        return;
    }
    if (_age < 10) {
        string t = to_string(_age);
        _sym = t[0];
    } else _sym = '+';
}

bool FredkinCell::isFred() {return true;}

int FredkinCell::currentAge() {return _age;}

FredkinCell* FredkinCell::clone() const {return new FredkinCell(*this);}

void FredkinCell::evolve (int n) {
    bool _pre_alive = _alive;
    if ((!_pre_alive) && (n % 2)) _alive = true;
    if ((_pre_alive) && ((n == 0) || (n % 2) == 0)) _alive = false;
    if (_pre_alive && _alive) _age++;
    mySym();
}


Cell::Cell(AbstractCell* cell): _cell(cell ? cell : 0) {}

Cell::Cell(const Cell& c) {
    _cell = c._cell->clone();
}

void Cell::mutate () {
    delete _cell;
    _cell = new ConwayCell('*');
}

bool Cell::isAlive() {return _cell->isAlive();}

bool Cell::isFred() {return _cell->isFred();}

void Cell::evolve (int n) {
    _cell->evolve(n);
    if (_cell->currentAge() == 2) mutate();
}

Cell::~Cell() {delete _cell;}