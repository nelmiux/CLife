// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <utility>  // pair

#include "gtest/gtest.h"

#include "Life.h"

using namespace std;

bool input = false;

vector<string> results;

// -----------
// TestLife
// -----------

// ----
// iterable
// ----

TEST(LifeFixture, iterable_1) {
    results.resize(0);

    Life<ConwayCell> _life_("ConwayCell");

    stringstream in("2\n7\n5\n1\n.*****.\n...*...\n");

	stringstream out;

	_life_->evolve(in, out);

	results.push_back("*** Life<ConwayCell> 2x7 ***\n\nGeneration = 0, Population = 6.\n.*****.\n...*...\n");
	results.push_back("*** Life<ConwayCell> 2x7 ***\n\nGeneration = 1, Population = 4.\n..***..\n...*...\n");
	results.push_back("*** Life<ConwayCell> 2x7 ***\n\nGeneration = 2, Population = 6.\n..***..\n..***..\n");
	results.push_back("*** Life<ConwayCell> 2x7 ***\n\nGeneration = 3, Population = 4.\n..*.*..\n..*.*..\n");
	results.push_back("*** Life<ConwayCell> 2x7 ***\n\nGeneration = 4, Population = 0.\n.......\n.......\n");
	results.push_back("*** Life<ConwayCell> 2x7 ***\n\nGeneration = 5, Population = 0.\n.......\n.......\n");
    
    int j = 0;

    Life<ConwayCell>::Iterator first = _life_.begin();

    Life<ConwayCell>::Iterator last = _life_.end();

    while (first != last) {
        ASSERT_EQ(*first, results[j]);
        ++j;
        ++first;
    }
}

TEST(LifeFixture, iterable_2) {
	results.resize(0);

    Life<FredkinCell> _life_("FredkinCell");

    stringstream in("2\n4\n10\n1\n-00-\n-00-\n");

	stringstream out;

	_life_->evolve(in, out);

	results.push_back("*** Life<FredkinCell> 2x4 ***\n\nGeneration = 0, Population = 4.\n-00-\n-00-\n");
	results.push_back("*** Life<FredkinCell> 2x4 ***\n\nGeneration = 1, Population = 4.\n0--0\n0--0\n");
	results.push_back("*** Life<FredkinCell> 2x4 ***\n\nGeneration = 2, Population = 8.\n1001\n1001\n");
	results.push_back("*** Life<FredkinCell> 2x4 ***\n\nGeneration = 3, Population = 4.\n-11-\n-11-\n");
	results.push_back("*** Life<FredkinCell> 2x4 ***\n\nGeneration = 4, Population = 4.\n1--1\n1--1\n");
	results.push_back("*** Life<FredkinCell> 2x4 ***\n\nGeneration = 5, Population = 8.\n2112\n2112\n");
	results.push_back("*** Life<FredkinCell> 2x4 ***\n\nGeneration = 6, Population = 4.\n-22-\n-22-\n");
	results.push_back("*** Life<FredkinCell> 2x4 ***\n\nGeneration = 7, Population = 4.\n2--2\n2--2\n");
	results.push_back("*** Life<FredkinCell> 2x4 ***\n\nGeneration = 8, Population = 8.\n3223\n3223\n");
	results.push_back("*** Life<FredkinCell> 2x4 ***\n\nGeneration = 9, Population = 4.\n-33-\n-33-\n");
	results.push_back("*** Life<FredkinCell> 2x4 ***\n\nGeneration = 10, Population = 4.\n3--3\n3--3\n");

    int j = 0;

    Life<FredkinCell>::Iterator first = _life_.begin();

    Life<FredkinCell>::Iterator last = _life_.end();

    while (first != last) {
        ASSERT_EQ(*first, results[j]);
        ++j;
        ++first;
    }
}

TEST(LifeFixture, iterable_3) {
	results.resize(0);

    Life<Cell> _life_("Cell");

    stringstream in("4\n6\n7\n1\n------\n--00--\n-0000-\n------\n");

	stringstream out;

	_life_->evolve(in, out);

	results.push_back("*** Life<Cell> 4x6 ***\n\nGeneration = 0, Population = 6.\n------\n--00--\n-0000-\n------\n");
	results.push_back("*** Life<Cell> 4x6 ***\n\nGeneration = 1, Population = 12.\n--00--\n------\n011110\n-0000-\n");
	results.push_back("*** Life<Cell> 4x6 ***\n\nGeneration = 2, Population = 16.\n-0110-\n00--00\n1****1\n--11--\n");
	results.push_back("*** Life<Cell> 4x6 ***\n\nGeneration = 3, Population = 6.\n------\n-1001-\n-....-\n0----0\n");
	results.push_back("*** Life<Cell> 4x6 ***\n\nGeneration = 4, Population = 16.\n-0110-\n0*--*0\n1****1\n-0--0-\n");
	results.push_back("*** Life<Cell> 4x6 ***\n\nGeneration = 5, Population = 4.\n------\n-.00.-\n-....-\n-1--1-\n");
	results.push_back("*** Life<Cell> 4x6 ***\n\nGeneration = 6, Population = 10.\n--11--\n-.11.-\n-.**.-\n0-11-0\n");
	results.push_back("*** Life<Cell> 4x6 ***\n\nGeneration = 7, Population = 8.\n-0--0-\n-****-\n1....1\n------\n");

    int j = 0;

    Life<Cell>::Iterator first = _life_.begin();

    Life<Cell>::Iterator last = _life_.end();

    while (first != last) {
        ASSERT_EQ(*first, results[j]);
        ++j;
        ++first;
    }
}


// ----
// indexable
// ----

TEST(LifeFixture, indexable_1) {
	results.resize(0);

    Life<ConwayCell> _life_("ConwayCell");

    stringstream in("4\n3\n7\n1\n...\n.*.\n.*.\n.*.\n...\n");

	stringstream out;

	_life_->evolve(in, out);

	results.push_back("*** Life<ConwayCell> 4x3 ***\n\nGeneration = 0, Population = 3.\n...\n.*.\n.*.\n.*.\n");
	results.push_back("*** Life<ConwayCell> 4x3 ***\n\nGeneration = 1, Population = 3.\n...\n...\n***\n...\n");
	results.push_back("*** Life<ConwayCell> 4x3 ***\n\nGeneration = 2, Population = 3.\n...\n.*.\n.*.\n.*.\n");
	results.push_back("*** Life<ConwayCell> 4x3 ***\n\nGeneration = 3, Population = 3.\n...\n...\n***\n...\n");
	results.push_back("*** Life<ConwayCell> 4x3 ***\n\nGeneration = 4, Population = 3.\n...\n.*.\n.*.\n.*.\n");
	results.push_back("*** Life<ConwayCell> 4x3 ***\n\nGeneration = 5, Population = 3.\n...\n...\n***\n...\n");
	results.push_back("*** Life<ConwayCell> 4x3 ***\n\nGeneration = 6, Population = 3.\n...\n.*.\n.*.\n.*.\n");
	results.push_back("*** Life<ConwayCell> 4x3 ***\n\nGeneration = 7, Population = 3.\n...\n...\n***\n...\n");

    for (int j = 0; j < int(_life_.size()); ++j) {
        ASSERT_EQ(_life_[j], results[j]);
        ASSERT_EQ(_life_.at(j), results[j]);
    } 
}

TEST(LifeFixture, indexable_2) {
	results.resize(0);

    Life<FredkinCell> _life_("FredkinCell");

    stringstream in("3\n2\n12\n1\n-0\n-0\n-0\n");

	stringstream out;

	_life_->evolve(in, out);

	results.push_back("*** Life<FredkinCell> 3x2 ***\n\nGeneration = 0, Population = 3.\n-0\n-0\n-0\n");
	results.push_back("*** Life<FredkinCell> 3x2 ***\n\nGeneration = 1, Population = 5.\n01\n0-\n01\n");
	results.push_back("*** Life<FredkinCell> 3x2 ***\n\nGeneration = 2, Population = 3.\n-2\n-0\n-2\n");
	results.push_back("*** Life<FredkinCell> 3x2 ***\n\nGeneration = 3, Population = 5.\n03\n0-\n03\n");
	results.push_back("*** Life<FredkinCell> 3x2 ***\n\nGeneration = 4, Population = 3.\n-4\n-0\n-4\n");
	results.push_back("*** Life<FredkinCell> 3x2 ***\n\nGeneration = 5, Population = 5.\n05\n0-\n05\n");
	results.push_back("*** Life<FredkinCell> 3x2 ***\n\nGeneration = 6, Population = 3.\n-6\n-0\n-6\n");
	results.push_back("*** Life<FredkinCell> 3x2 ***\n\nGeneration = 7, Population = 5.\n07\n0-\n07\n");
	results.push_back("*** Life<FredkinCell> 3x2 ***\n\nGeneration = 8, Population = 3.\n-8\n-0\n-8\n");
	results.push_back("*** Life<FredkinCell> 3x2 ***\n\nGeneration = 9, Population = 5.\n09\n0-\n09\n");
	results.push_back("*** Life<FredkinCell> 3x2 ***\n\nGeneration = 10, Population = 3.\n-+\n-0\n-+\n");
	results.push_back("*** Life<FredkinCell> 3x2 ***\n\nGeneration = 11, Population = 5.\n0+\n0-\n0+\n");
	results.push_back("*** Life<FredkinCell> 3x2 ***\n\nGeneration = 12, Population = 3.\n-+\n-0\n-+\n");

    for (int j = 0; j < int(_life_.size()); ++j) {
        ASSERT_EQ(_life_[j], results[j]);
        ASSERT_EQ(_life_.at(j), results[j]);
    }
}

TEST(LifeFixture, indexable_3) {
	results.resize(0);

    Life<Cell> _life_("Cell");

    stringstream in("4\n4\n8\n1\n.--.\n0..0\n0**0\n*--*\n");

	stringstream out;

	_life_->evolve(in, out);

	results.push_back("*** Life<Cell> 4x4 ***\n\nGeneration = 0, Population = 8.\n.--.\n0..0\n0**0\n*--*\n");
	results.push_back("*** Life<Cell> 4x4 ***\n\nGeneration = 1, Population = 6.\n.--.\n1..1\n1..1\n*--*\n");
	results.push_back("*** Life<Cell> 4x4 ***\n\nGeneration = 2, Population = 6.\n.--.\n*..*\n-**-\n.00.\n");
	results.push_back("*** Life<Cell> 4x4 ***\n\nGeneration = 3, Population = 2.\n.--.\n.**.\n-..-\n.--.\n");
	results.push_back("*** Life<Cell> 4x4 ***\n\nGeneration = 4, Population = 2.\n.00.\n....\n-..-\n.--.\n");
	results.push_back("*** Life<Cell> 4x4 ***\n\nGeneration = 5, Population = 2.\n.11.\n....\n-..-\n.--.\n");
	results.push_back("*** Life<Cell> 4x4 ***\n\nGeneration = 6, Population = 2.\n.**.\n....\n-..-\n.--.\n");
	results.push_back("*** Life<Cell> 4x4 ***\n\nGeneration = 7, Population = 0.\n....\n....\n-..-\n.--.\n");
	results.push_back("*** Life<Cell> 4x4 ***\n\nGeneration = 8, Population = 0.\n....\n....\n-..-\n.--.\n");

    for (int j = 0; j < int(_life_.size()); ++j) {
        ASSERT_EQ(_life_[j], results[j]);
        ASSERT_EQ(_life_.at(j), results[j]);
    }  
}


// ----
// addCelltoLife
// ----

TEST(LifeFixture, addCelltoLife_1) {
    Life<ConwayCell> _life_("ConwayCell");

    stringstream in("4\n3\n7\n1\n...\n.*.\n.*.\n.*.\n...\n");

	_life_->read(in);

	string cellsString = "...\n.*.\n.*.\n.*.\n...\n";

	for (int i = 1; i < (_life_->_rows + 1); ++i) {
		for (int j = 1; j < (_life_->_cols + 1); ++j) {

			int index = (_life_->_cols + 1) * (i - 1) + (j - 1);

			char lifeCell = char(_life_->_cells[i][j]);
			
			ASSERT_EQ(lifeCell, cellsString[index]);
		}
	}  
}

TEST(LifeFixture, addCelltoLife_2) {
	Life<FredkinCell> _life_("FredkinCell");

    stringstream in("3\n4\n10\n1\n-00-\n-00-\n0000\n");

	_life_->read(in);

	string cellsString = "-00-\n-00-\n0000\n";

	for (int i = 1; i < (_life_->_rows + 1); ++i) {
		for (int j = 1; j < (_life_->_cols + 1); ++j) {

			int index = (_life_->_cols + 1) * (i - 1) + (j - 1);

			char lifeCell = char(_life_->_cells[i][j]);

			ASSERT_EQ(lifeCell, cellsString[index]);
		}
	}  
    
}

TEST(LifeFixture, addCelltoLife_3) {
   Life<Cell> _life_("Cell");

    stringstream in("5\n4\n8\n1\n.--.\n0..0\n0**0\n*--*\n****\n");

	_life_->read(in);

	string cellsString = ".--.\n0..0\n0**0\n*--*\n****\n";

	for (int i = 1; i < (_life_->_rows + 1); ++i) {
		for (int j = 1; j < (_life_->_cols + 1); ++j) {

			int index = (_life_->_cols + 1) * (i - 1) + (j - 1);

			char lifeCell = char(_life_->_cells[i][j]);

			ASSERT_EQ(lifeCell, cellsString[index]);
		}
	}  
}


// ----
// evolveLife
// ----

TEST(LifeFixture, evolveLife_1) {
	input = false;

    Life<ConwayCell> _life_("ConwayCell");

    stringstream in("21\n"
					"13\n"
					"3\n"
					"1\n"
    				".............\n"
				 	".............\n"
					".............\n"
					".............\n"
					".............\n"
					".............\n"
					".............\n"
					".............\n"
					"....*****....\n"
					".......*.....\n"
					"......*......\n"
					".....*.......\n"
					"....*****....\n"
					".............\n"
					".............\n"
					".............\n"
					".............\n"
					".............\n"
					".............\n"
					".............\n"
					".............\n");

	stringstream out;

	_life_->evolve(in, out);

	string resultString = 	"*** Life<ConwayCell> 21x13 ***\n\n"
							"Generation = 0, Population = 13.\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n....*****....\n.......*.....\n......*......\n.....*.......\n....*****....\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n\n"
							"*** Life<ConwayCell> 21x13 ***\n\n"
							"Generation = 1, Population = 17.\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n.....***.....\n.....****....\n........*....\n......*......\n....*........\n....****.....\n.....***.....\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n\n"
							"*** Life<ConwayCell> 21x13 ***\n\n"
							"Generation = 2, Population = 14.\n.............\n.............\n.............\n.............\n.............\n.............\n......*......\n.....*..*....\n.....*..*....\n.....*..*....\n.............\n....*..*.....\n....*..*.....\n....*..*.....\n......*......\n.............\n.............\n.............\n.............\n.............\n.............\n\n"
							"*** Life<ConwayCell> 21x13 ***\n\n"
							"Generation = 3, Population = 18.\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n.....***.....\n....******...\n.............\n.............\n.............\n...******....\n.....***.....\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n";

	ASSERT_EQ(resultString, out.str()); 
}

TEST(LifeFixture, evolveLife_2) {
	input = false;

    Life<FredkinCell> _life_("FredkinCell");

    stringstream in("20\n"
					"20\n"
					"6\n"
					"2\n"
					"--------------------\n"
					"--------------------\n"
					"--------------------\n"
					"--------------------\n"
					"--------------------\n"
					"--------------------\n"
					"--------------------\n"
					"--------------------\n"
					"--------------------\n"
					"---------00---------\n"
					"---------00---------\n"
					"--------------------\n"
					"--------------------\n"
					"--------------------\n"
					"--------------------\n"
					"--------------------\n"
					"--------------------\n"
					"--------------------\n"
					"--------------------\n"
					"--------------------\n");

	stringstream out;

	_life_->evolve(in, out);

	string resultString = 	"*** Life<FredkinCell> 20x20 ***\n\n"
							"Generation = 0, Population = 4.\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n---------00---------\n---------00---------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n\n"
							"*** Life<FredkinCell> 20x20 ***\n\n"
							"Generation = 2, Population = 16.\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n---------00---------\n---------11---------\n-------01--10-------\n-------01--10-------\n---------11---------\n---------00---------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n\n"
							"*** Life<FredkinCell> 20x20 ***\n\n"
							"Generation = 4, Population = 16.\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n---------00---------\n---------11---------\n--------------------\n--------------------\n-----01------10-----\n-----01------10-----\n--------------------\n--------------------\n---------11---------\n---------00---------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n\n"
							"*** Life<FredkinCell> 20x20 ***\n\n"
							"Generation = 6, Population = 64.\n--------------------\n--------------------\n--------------------\n---------00---------\n---------11---------\n-------01--10-------\n-------01--10-------\n-----00--11--00-----\n-----11--11--11-----\n---01--11--11--10---\n---01--11--11--10---\n-----11--11--11-----\n-----00--11--00-----\n-------01--10-------\n-------01--10-------\n---------11---------\n---------00---------\n--------------------\n--------------------\n--------------------\n";

	ASSERT_EQ(resultString, out.str()); 
}

TEST(LifeFixture, evolveLife_3) {
	input = false;

	Life<Cell> _life_("Cell");

    stringstream in("20\n"
					"20\n"
					"400\n"
					"100\n"
					"--------------------\n"
					"--------------------\n"
					"--------------------\n"
					"--------------------\n"
					"--------------------\n"
					"-----***********----\n"
					"--------*****-------\n"
					"------*********-----\n"
					"--------------------\n"
					"--.....--00---------\n"
					"---------00--.....--\n"
					"--------------------\n"
					"------...........---\n"
					"--------------------\n"
					"--------------------\n"
					"-------*********----\n"
					"---------*-*-*------\n"
					"--------------------\n"
					"--------------------\n"
					"--------------------\n");

	stringstream out;

	_life_->evolve(in, out);

	string resultString = 	"*** Life<Cell> 20x20 ***\n\n"
							"Generation = 0, Population = 41.\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n-----***********----\n--------*****-------\n------*********-----\n--------------------\n--.....--00---------\n---------00--.....--\n--------------------\n------...........---\n--------------------\n--------------------\n-------*********----\n---------*-*-*------\n--------------------\n--------------------\n--------------------\n\n"
							"*** Life<Cell> 20x20 ***\n\n"
							"Generation = 100, Population = 44.\n....................\n....................\n....................\n....................\n..................-.\n....................\n...........***......\n..........*.**......\n...........*.*......\n..*..............*..\n.*.**.............*.\n*.....*.........*..*\n*...*..*...........*\n.**.*..*........*..*\n....*.............*.\n.****............*..\n.*.*.......*.*......\n...........***......\n............**......\n...................-\n\n"
							"*** Life<Cell> 20x20 ***\n\n"
							"Generation = 200, Population = 35.\n....................\n....................\n............**......\n...........*..*.....\n...**.......**......\n....................\n....................\n....................\n..........*.........\n........*..*........\n....................\n.......*....*.......\n...****.....*.......\n....*.**.*..*.......\n....*..**...........\n.....**.........*...\n...............*.*..\n....................\n.......*.*..........\n.......*.*..........\n\n"
							"*** Life<Cell> 20x20 ***\n\n"
							"Generation = 300, Population = 16.\n....................\n....................\n............**......\n...........*..*.....\n............**......\n....................\n....................\n....................\n....................\n....................\n....*...............\n...*.*......*.......\n..*..*......*.......\n...**.......*.......\n....................\n....................\n....................\n....................\n....................\n....................\n\n"
							"*** Life<Cell> 20x20 ***\n\n"
							"Generation = 400, Population = 16.\n....................\n....................\n............**......\n...........*..*.....\n............**......\n....................\n....................\n....................\n....................\n....................\n....*...............\n...*.*......*.......\n..*..*......*.......\n...**.......*.......\n....................\n....................\n....................\n....................\n....................\n....................\n";

	ASSERT_EQ(resultString, out.str());
}


// ----
// evolveCell
// ----
   
TEST(LifeFixture, evolveCell_1) {

	ConwayCell liveToDie0('*');

    liveToDie0->evolve(1);

    ASSERT_EQ(char(liveToDie0), '.');

    ASSERT_EQ(liveToDie0->isAlive(), -1);
}

TEST(LifeFixture, evolveCell_2) {

    ConwayCell liveToDie1('*');

    liveToDie1->evolve(4);

    ASSERT_EQ(char(liveToDie1), '.');

    ASSERT_EQ(liveToDie1->isAlive(), -1);
}

TEST(LifeFixture, evolveCell_3) {

    ConwayCell liveTolive('*');

    liveTolive->evolve(2);

    ASSERT_EQ(char(liveTolive), '*');

    ASSERT_EQ(liveTolive->isAlive(), 1);
}

TEST(LifeFixture, evolveCell_4) {

    ConwayCell dieTolive('.');

    dieTolive->evolve(3);

    ASSERT_EQ(char(dieTolive), '*');

    ASSERT_EQ(dieTolive->isAlive(), 1);
}

TEST(LifeFixture, evolveCell_5) {

    ConwayCell dieTodie('.');

    dieTodie->evolve(2);

    ASSERT_EQ(char(dieTodie), '.');

    ASSERT_EQ(dieTodie->isAlive(), -1);
    
}
 
TEST(LifeFixture, evolveCell_6) {

	FredkinCell liveToDie0('5');

    liveToDie0->evolve(0);

    ASSERT_EQ(char(liveToDie0), '-');

    ASSERT_EQ(liveToDie0->isAlive(), -1);
}

TEST(LifeFixture, evolveCell_7) {

    FredkinCell liveToDie1('+');

    liveToDie1->evolve(4);

    ASSERT_EQ(char(liveToDie1), '-');

    ASSERT_EQ(liveToDie1->isAlive(), -1);
}

TEST(LifeFixture, evolveCell_8) {

    FredkinCell liveTolive('0');

    liveTolive->evolve(1);

    ASSERT_EQ(char(liveTolive), '1');

    ASSERT_EQ(liveTolive->isAlive(), 1);
}

TEST(LifeFixture, evolveCell_9) {

    FredkinCell dieTolive('-');

    dieTolive->evolve(3);

    ASSERT_EQ(char(dieTolive), '0');

    ASSERT_EQ(dieTolive->isAlive(), 0);
}

TEST(LifeFixture, evolveCell_10) {

    FredkinCell dieTodie('-');

    dieTodie->evolve(2);

    ASSERT_EQ(char(dieTodie), '-');

    ASSERT_EQ(dieTodie->isAlive(), -1);
}

TEST(LifeFixture, evolveCell_11) {

	Cell liveToDie0(new ConwayCell('*'));

    liveToDie0->evolve(0);

    ASSERT_EQ(char(liveToDie0), '.');

    ASSERT_EQ(liveToDie0->isAlive(), -1);
}

TEST(LifeFixture, evolveCell_12) {

    Cell liveToDie1(new FredkinCell('0'));

    liveToDie1->evolve(2);

    ASSERT_EQ(char(liveToDie1), '-');

    ASSERT_EQ(liveToDie1->isAlive(), -1);
}

TEST(LifeFixture, evolveCell_13) {

    Cell liveTolive(new FredkinCell('0'));

    liveTolive->evolve(1);

    ASSERT_EQ(char(liveTolive), '1');

    ASSERT_EQ(liveTolive->isAlive(), 1);
}

TEST(LifeFixture, evolveCell_14) {

    Cell dieTolive(new ConwayCell('.'));

    dieTolive->evolve(3);

    ASSERT_EQ(char(dieTolive), '*');

    ASSERT_EQ(dieTolive->isAlive(), 1);
}

TEST(LifeFixture, evolveCell_15) {

    Cell dieTodie(new ConwayCell('.'));

    dieTodie->evolve(2);

    ASSERT_EQ(char(dieTodie), '.');

    ASSERT_EQ(dieTodie->isAlive(), -1);
   
}


// -----
// mutateCell
// -----

TEST(LifeFixture, mutateCell_1) {

	Cell cell0(new FredkinCell('0'));

    cell0->evolve(1);

    cell0->evolve(3);

    ASSERT_EQ(char(cell0), '*');

    ASSERT_EQ(cell0->isAlive(), 1);

}

TEST(LifeFixture, mutateCell_2) {

	Cell cell1(new FredkinCell('-'));

	cell1->evolve(1);

    cell1->evolve(3);

    cell1->evolve(1);

    ASSERT_EQ(char(cell1), '*');

    ASSERT_EQ(cell1->isAlive(), 1);
    
}

TEST(LifeFixture, mutateCell_3) {

	Cell cell2(new FredkinCell('0'));

	cell2->mutate();

    ASSERT_EQ(char(cell2), '*');

    ASSERT_EQ(cell2->isAlive(), 1);
}

TEST(LifeFixture, mutateCell_4) {

	Cell cell3(new FredkinCell('+'));

	cell3->mutate();

    ASSERT_EQ(char(cell3), '*');

    ASSERT_EQ(cell3->isAlive(), 1);

    cell3->evolve(5);

    ASSERT_EQ(char(cell3), '.');

   ASSERT_EQ(cell3->isAlive(), -1);

}

TEST(LifeFixture, mutateCell_5) {

	Cell cell4(new FredkinCell('-'));

	cell4->mutate();

    ASSERT_EQ(char(cell4), '*');

    ASSERT_EQ(cell4->isAlive(), 1);

    cell4->evolve(7);

    ASSERT_EQ(char(cell4), '.');

    ASSERT_EQ(cell4->isAlive(), -1);

}
