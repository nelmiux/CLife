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
   		virtual void mySym () = 0; 
   	public:
   		AbstractCell() {};
   		AbstractCell(char);

   		/**
   		 * Return -1 if the cell is dead.
   		 * If the cell is Alive, return 1 in ConwayCell,
   		 * the age in FredkinCell
   		 * Pure virtual, implemented in children.
   		 */
   		virtual int isAlive() = 0;

		/**
   		 * Return true is the cells is FredkinCell, false otherwise
   		 * Pure Virtual here, implemented in children classes.
   		 */
   		virtual bool isFred() = 0;

   		/**
   		 * Clone this object
   		 * Pure Virtual here, implemented in children classes.
   		 */
   		virtual AbstractCell* clone() const = 0;

   		/**
   		 * Execute cells evolutions following their rules
   		 * Pure Virtual here, implemented in children classes.
   		 */
   		virtual void evolve(int) = 0;

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
		/**
   		 * Use inside the object to define its symbol after
   		 * an evolution process.
   		 */
		void mySym ();
	public:
		ConwayCell() {};
		ConwayCell(char);

		/**
   		 * Return 1 if the cell is alive, return -1 otherwise.
   		 */
		int isAlive();

		/**
   		 * Return false, since this is not FredkinCell object.
   		 */
		bool isFred();

		/**
   		 * Clone this object
   		 */
		ConwayCell* clone() const;

		/**
   		 * Execute cells evolutions following its rules,
   		 * receive number of alive neighbors, and if there
   		 * is 3 neighbors alive the cell become to live,
   		 * if there is less than 2 o more than 3 neighbors
   		 * alive the cell dies.
   		 */
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
		/**
   		 * Use inside the object to define its symbol after
   		 * an evolution process.
   		 */
		void mySym ();

		/**
		 * Keep track of the age of the cell.
		 */
		int _age;

	public:
		FredkinCell() {};
		FredkinCell(char);

		/**
   		 * Return 1 if the cell is alive, return the current 
   		 * age otherwise.
   		 */
		int isAlive();

		/**
   		 * Return true, since this is FredkinCell object.
   		 */
		bool isFred();

		/**
   		 * Clone this object.
   		 */
		FredkinCell* clone() const;

		/**
   		 * Execute cells evolutions following its rules,
   		 * receive number of alive neighbors, and if the
   		 * number of neighbors alive is odd the cell become 
   		 * to live, if even or 0 the cell dies.
   		 */
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
		/**
   		 * Pointer to a current AbstractCell received.
   		 */
		AbstractCell* _cell;

		/**
   		 * Transform cell from anything to a live ConwayCell.
   		 */
		void mutate();

		FRIEND_TEST(LifeFixture, mutateCell_3);
		FRIEND_TEST(LifeFixture, mutateCell_4);
		FRIEND_TEST(LifeFixture, mutateCell_5);

	public:
		Cell() {};
		Cell(AbstractCell*);
		Cell(const Cell&);

		/**
   		 * Return the isAlive() method of its corresponding object.
   		 */
		int isAlive();

		/**
   		 * Return the isFred() method of its corresponding object.
   		 */
		bool isFred();

		/**
   		 * Execute cells evolutions of its corresponding object,
   		 * after the evolution if the cell is a FredkinCell and
   		 * its age is 2, then cell mutates to a live ConwayCell.
   		 */
		void evolve (int);

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
		    // check for self-assignment
		    if (this == &c)
		        return *this;

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
    	/**
   		 * Cell type.
   		 */
        string _type;

        /**
   		 * Height of the grid.
   		 */
        int _rows;

        /**
   		 * Width of the grid.
   		 */
        int _cols;

        /**
   		 * Number of evolution to execute.
   		 */
        int _evol;

        /**
   		 * Output frequency to print.
   		 */
        int _outFreq;

        /**
   		 * Generations counter.
   		 */
        int _gen;

        /**
   		 * Population counter.
   		 */
        int _pop;

        /**
   		 * 2D representation of a grid of cells.
   		 */
        vector<vector<T>> _cells;

        /**
   		 * 2D representation of a grid of cells alive neighbors.
   		 */
        vector<vector<int>> _neighbors;


        // -------------
		// read
		// -------------

        /**
   		 * Read values from std in and populate the grid with the
   		 * received characters from std in.
   		 * make the grid of the cells.
   		 */
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

		/**
   		 * Overloaded read method helper.
   		 */
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

		/**
   		 * Overloaded read method helper.
   		 */
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


		/**
   		 * Count the number of alive neighbors of every cell and populate
   		 * the mirror grid of neighbors.
   		 */
		void neighborsCount () {
		    for (int i = 1; i < _rows + 1; ++i) {
		        for (int j = 1; j < _cols + 1; ++j) {
		            _neighbors[i][j] = 0;
		            if (_cells[i - 1][j]->isAlive() > -1) ++_neighbors[i][j];
		            if (_cells[i + 1][j]->isAlive() > -1) ++_neighbors[i][j];
		            if (_cells[i][j - 1]->isAlive() > -1) ++_neighbors[i][j];
		            if (_cells[i][j + 1]->isAlive() > -1) ++_neighbors[i][j];
					if (!(_cells[i][j]->isFred())) {
						if (_cells[i - 1][j - 1]->isAlive() > -1) ++_neighbors[i][j];
			            if (_cells[i - 1][j + 1]->isAlive() > -1) ++_neighbors[i][j];
			            if (_cells[i + 1][j + 1]->isAlive() > -1) ++_neighbors[i][j];
			            if (_cells[i + 1][j - 1]->isAlive() > -1) ++_neighbors[i][j];
			        }
		        }
		    }
		};

		// -------------
		// print
		// -------------

		/**
   		 * Responsable to print the final result to std out and storage
   		 * them, to be able to iterate through life.
   		 */
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

        /**
   		 * Vector of generations.
   		 */
        generations _gens;

		// -------------
		// run
		// -------------

        /**
   		 * Execute grid evolutions, creating generation states.
   		 * main ejecutor of the simulation.
   		 */
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
		                if (_cells[i][j]->isAlive() > -1) ++_pop;
		            }       
		        }
		        neighborsCount();
		        write(w, g);
		    }

		};

		Life* operator-> () {
   			return this;
   		};

   		/**
		 * Life iterator definitions, helpers and operations.  
		 */
   		typedef generations::iterator Iterator;
		typedef generations::iterator* pointer;

		Iterator it;

		int size() {
			return _gens.size();
		}

		/**
		 * Life iterator: begin  
		 */
  		const Iterator begin() {
  			return _gens.begin();
  		}

  		/**
		 * Life iterator: end  
		 */
		const Iterator end() {
			return _gens.end();
		}

		/**
		 * Life iterator: post increment  
		 */
		Iterator operator++() {
			Life<T>::Iterator i = (*this).it; 
			_ptr++; 
			return i; 
		}

		/**
		 * Life iterator: pre increment  
		 */
		Iterator operator++(int junk) {
			_ptr++; 
			return this->it; 
		}

		/**
		 * Life iterator: equal equal  
		 */
		bool operator==(const Life<T>& rhs) {
			return _ptr == rhs._ptr;
		}

		/**
		 * Life iterator: not equal  
		 */
		bool operator!=(const Life<T>& rhs) {
			return _ptr != rhs._ptr;
		}

		/**
		 * Life iterator: return the value the 
		 * iterator is pointing of  
		 */
		template<typename U>
		U& operator* () {
			return *_ptr; 
		}

		/**
		 * Life iterator: at  
		 */
		const string& at(int i) const {
			assert((i < int(_gens.size())) && (i >= 0));
			return _gens.at(i); 
		}

		/**
		 * Life iterator: indexing  
		 */
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