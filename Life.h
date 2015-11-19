#ifndef Life_h
#define Life_h

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <vector>

#include "gtest/gtest.h"

using namespace std;

extern bool input;

// -------------
// AbstractCell Class
// -------------

class AbstractCell {
	protected:
		char _sym;
   		bool _alive;
   		int _pop;
   		int _age;
   		virtual void mySym () = 0; 
   	public:
   		AbstractCell() {};
   		AbstractCell(char);

   		virtual bool isAlive();
   		virtual void evolve(int) = 0;
            
   		virtual AbstractCell* clone() const = 0;
   		virtual int currentAge() = 0;
   		virtual bool isFred() = 0;

   		virtual AbstractCell* operator-> () {
   			return this;
   		};

   		virtual operator char() {
			return this->_sym;
		};

   		friend ostream& operator<< (ostream& o, AbstractCell* c) {
			return o << c->_sym;
		};

		virtual ~AbstractCell() {};
};

// -------------
// ConwayCell Class
// -------------

class ConwayCell: public AbstractCell {
	private:
		void mySym ();
	public:
		ConwayCell() {};
		ConwayCell(char);

		int currentAge();
		bool isFred();
		ConwayCell* clone() const;
		void evolve (int);

		friend ostream& operator<< (ostream& o, ConwayCell c) {
			return o << c._sym;
		};

		~ConwayCell() {};
};

// -------------
// FredkinCell Class
// -------------

class FredkinCell: public AbstractCell {
	private:
		void mySym ();
	public:
		FredkinCell() {};
		FredkinCell(char);

		int currentAge();
		bool isFred();
		FredkinCell* clone() const;
		void evolve (int);

		friend ostream& operator<< (ostream& o, FredkinCell c) {
			return o << c._sym;
		};

		~FredkinCell() {};
};

// -------------
// Cell Class
// -------------

class Cell {
	private:
		AbstractCell* _cell;
		string _type;
		void mutate();

		FRIEND_TEST(LifeFixture, mutateCell_3);
		FRIEND_TEST(LifeFixture, mutateCell_4);
		FRIEND_TEST(LifeFixture, mutateCell_5);

	public:
		Cell() {};
		Cell(AbstractCell*);
		Cell(const Cell&);

		void evolve (int);
		bool isAlive();
		bool isFred();

		Cell* operator-> () {
   			return this;
   		}

   		operator char() {
			return char(*_cell);
		};

		friend ostream& operator<< (ostream &out, Cell& c) {
			return out << c._cell;
		}

		Cell& operator=(Cell& c) {
		    /* check for self-assignment */
		    if (this == &c)
		        return *this;

		 	/*
		 	 * it does not create other pointer just copy source to dest
			 * and overrrides sources
			 */
		    if (c._cell) {
		    	_cell = c._cell->clone();
		    } else
		        _cell = 0;
            return *this;
		}
		~Cell();
};


// -------------
// Life Class
// -------------
template<typename T>
class Life {
    private:
        string _type;
        int _rows;
        int _cols;
        int _evol;
        int _outFreq;
        int _gen;
        int _pop;
        vector<vector<T>> _cells;
        vector<vector<int>> _neighbors;


        // -------------
		// read
		// -------------

		void read (istream& _r) {
		    string s = ".";
		    getline(_r, s);
		    istringstream ( s ) >> _rows;

		    getline(_r, s);
		    istringstream ( s ) >> _cols;

		    getline(_r, s);
		    istringstream ( s ) >> _evol;

		    getline(_r, s);
		    istringstream ( s ) >> _outFreq;

		    _neighbors = vector<vector<int>>(_rows + 2, vector<int>(_cols + 2, 0));

		    _gens.resize(_evol + 1);

		    T x;
		    make_vector(x, _r);
		};

		// -------------
		// make_vector
		// -------------

		void make_vector(AbstractCell& a, istream& _r) {
		     string s;
		    _cells = vector<vector<T>>(_rows + 2, vector<T>(_cols + 2, T('.')));
		    for (int i = 1; i < _rows + 1; ++i) {
		        getline(_r, s);
		        s = '.' + s + '.';
		        for (int j = 1; j < _cols + 1; ++j) {
		            if ((s[j] != '.') && (s[j] != '-')) _pop++;
		            T x(s[j]);
		            _cells[i][j] = x;
		        }
		    }
		};

		void make_vector(Cell& y, istream& _r) {
		    string s;
		    _cells = vector<vector<Cell>>(_rows + 2, vector<Cell>(_cols + 2, new FredkinCell('-')));
		    for (int i = 1; i < _rows + 1; ++i) {
		        getline(_r, s);
		        s = '.' + s + '.';
		        for (int j = 1; j < _cols + 1; ++j) {
		            if ((s[j] != '.') && (s[j] != '-')) _pop++;
		            if ((s[j] == '*') || (s[j] == '.')) {
		                Cell x = new ConwayCell(s[j]);
		                y = x;
		                _cells[i][j] = y;
		            } else {
		                Cell x = new FredkinCell(s[j]);
		                y = x;
		                _cells[i][j] = y;
		            }
		        }
		    }
		};

		void neighborsCount () {
		    for (int i = 1; i < _rows + 1; ++i) {
		        for (int j = 1; j < _cols + 1; ++j) {
		            _neighbors[i][j] = 0;
		            if (_cells[i - 1][j]->isAlive()) ++_neighbors[i][j];
		            if (_cells[i + 1][j]->isAlive()) ++_neighbors[i][j];
		            if (_cells[i][j - 1]->isAlive()) ++_neighbors[i][j];
		            if (_cells[i][j + 1]->isAlive()) ++_neighbors[i][j];
		            if (!(_cells[i][j]->isFred())) {
		                if (_cells[i - 1][j - 1]->isAlive()) ++_neighbors[i][j];
		                if (_cells[i - 1][j + 1]->isAlive()) ++_neighbors[i][j];
		                if (_cells[i + 1][j + 1]->isAlive()) ++_neighbors[i][j];
		                if (_cells[i + 1][j - 1]->isAlive()) ++_neighbors[i][j];
		            }
		        }
		    }
		};

		// -------------
		// print
		// -------------
		void write (ostream& _w, int _g) {
			bool print = false;
			if (((_outFreq != 0) && (!(_g % _outFreq))) || (_g == 0)) print = true;
		    if (input && print) _w << "\n";
		    _gens[_g] = "*** Life<" + _type + "> " + to_string(_rows) + "x" + to_string(_cols) + " ***\n\n";
		    _gens[_g] = _gens[_g] + "Generation = " + to_string(_gen) + ", Population = " + to_string(_pop) + ".\n";
		    for (int i = 1; i < _rows + 1; ++i) {
		        for (int j = 1; j < _cols + 1; ++j) {
		            _gens[_g] = _gens[_g] + char(_cells[i][j]);
		        }
		        _gens[_g] = _gens[_g] + "\n";
		    }
			if (print) _w << _gens[_g];
			input = true;
		};

		FRIEND_TEST(LifeFixture, addCelltoLife_1);
		FRIEND_TEST(LifeFixture, addCelltoLife_2);
		FRIEND_TEST(LifeFixture, addCelltoLife_3);

    public:

		Life (string type): _type(type), _evol(0), _outFreq(0), 
                            _gen(0), _pop(0), _cells(), _gens() {};

        typedef vector<string> generations;

        generations _gens;

		// -------------
		// run
		// -------------

		void evolve (istream& r, ostream& w) {
		    read(r);
		    neighborsCount();
		    write(w, 0); 
		    for (int g = 1; g <= _evol; ++g) {
		        _pop = 0;
		        _gen++;
		        for (int i = 1; i < _rows + 1; ++i) {
		            for (int j = 1; j < _cols + 1; ++j) {
		                _cells[i][j]->evolve(_neighbors[i][j]);
		                if (_cells[i][j]->isAlive()) ++_pop;
		            }       
		        }
		        neighborsCount();
		        write(w, g);
		    }

		};

		Life* operator-> () {
   			return this;
   		};

   		typedef generations::iterator Iterator;
		typedef generations::iterator* pointer;

		Iterator it;

		int size() {return _gens.size();}

  		const Iterator begin() {return _gens.begin();}

		const Iterator end() {return _gens.end();}

		Iterator operator++() {
			Life<T>::Iterator i = (*this).it; 
			_ptr++; 
			return i; 
		}

		Iterator operator++(int junk) {
			_ptr++; 
			return this->it; 
		}

		bool operator==(const Life<T>& rhs) {return _ptr == rhs._ptr;}

		bool operator!=(const Life<T>& rhs) {return _ptr != rhs._ptr;}

		template<typename U>
		U& operator* () {return *_ptr; }

		const string& at(int i) const {
			assert((i < int(_gens.size())) && (i >= 0));
			return _gens.at(i); 
		}

		string& operator[](int i) {
		    assert((i < int(_gens.size())) && (i >= 0));
		  	return _gens[i];
		}

	private:
		pointer _ptr;

	public:
   		~Life () {};
};


#endif // Life_h