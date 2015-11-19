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

    Life<ConwayCell> l("ConwayCell");

    stringstream in("2\n7\n5\n1\n.*****.\n...*...\n");

	stringstream out;

	l->evolve(in, out);

	results.push_back("*** Life<ConwayCell> 2x7 ***\n\nGeneration = 0, Population = 6.\n.*****.\n...*...\n");
	results.push_back("*** Life<ConwayCell> 2x7 ***\n\nGeneration = 1, Population = 4.\n..***..\n...*...\n");
	results.push_back("*** Life<ConwayCell> 2x7 ***\n\nGeneration = 2, Population = 6.\n..***..\n..***..\n");
	results.push_back("*** Life<ConwayCell> 2x7 ***\n\nGeneration = 3, Population = 4.\n..*.*..\n..*.*..\n");
	results.push_back("*** Life<ConwayCell> 2x7 ***\n\nGeneration = 4, Population = 0.\n.......\n.......\n");
	results.push_back("*** Life<ConwayCell> 2x7 ***\n\nGeneration = 5, Population = 0.\n.......\n.......\n");
    
    int j = 0;

    Life<ConwayCell>::Iterator first = l.begin();

    Life<ConwayCell>::Iterator last = l.end();

    while (first != last) {
        ASSERT_EQ(*first, results[j]);
        ++j;
        ++first;
    }
}

TEST(LifeFixture, iterable_2) {
	results.resize(0);

    Life<FredkinCell> l("FredkinCell");

    stringstream in("2\n4\n10\n1\n-00-\n-00-\n");

	stringstream out;

	l->evolve(in, out);

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

    Life<FredkinCell>::Iterator first = l.begin();

    Life<FredkinCell>::Iterator last = l.end();

    while (first != last) {
        ASSERT_EQ(*first, results[j]);
        ++j;
        ++first;
    }
}

TEST(LifeFixture, iterable_3) {
	results.resize(0);

    Life<Cell> l("Cell");

    stringstream in("4\n6\n7\n1\n------\n--00--\n-0000-\n------\n");

	stringstream out;

	l->evolve(in, out);

	results.push_back("*** Life<Cell> 4x6 ***\n\nGeneration = 0, Population = 6.\n------\n--00--\n-0000-\n------\n");
	results.push_back("*** Life<Cell> 4x6 ***\n\nGeneration = 1, Population = 12.\n--00--\n------\n011110\n-0000-\n");
	results.push_back("*** Life<Cell> 4x6 ***\n\nGeneration = 2, Population = 16.\n-0110-\n00--00\n1****1\n--11--\n");
	results.push_back("*** Life<Cell> 4x6 ***\n\nGeneration = 3, Population = 6.\n------\n-1001-\n-....-\n0----0\n");
	results.push_back("*** Life<Cell> 4x6 ***\n\nGeneration = 4, Population = 16.\n-0110-\n0*--*0\n1****1\n-0--0-\n");
	results.push_back("*** Life<Cell> 4x6 ***\n\nGeneration = 5, Population = 4.\n------\n-.00.-\n-....-\n-1--1-\n");
	results.push_back("*** Life<Cell> 4x6 ***\n\nGeneration = 6, Population = 10.\n--11--\n-.11.-\n-.**.-\n0-11-0\n");
	results.push_back("*** Life<Cell> 4x6 ***\n\nGeneration = 7, Population = 8.\n-0--0-\n-****-\n1....1\n------\n");

    int j = 0;

    Life<Cell>::Iterator first = l.begin();

    Life<Cell>::Iterator last = l.end();

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

    Life<ConwayCell> l("ConwayCell");

    stringstream in("4\n3\n7\n1\n...\n.*.\n.*.\n.*.\n...\n");

	stringstream out;

	l->evolve(in, out);

	results.push_back("*** Life<ConwayCell> 4x3 ***\n\nGeneration = 0, Population = 3.\n...\n.*.\n.*.\n.*.\n");
	results.push_back("*** Life<ConwayCell> 4x3 ***\n\nGeneration = 1, Population = 3.\n...\n...\n***\n...\n");
	results.push_back("*** Life<ConwayCell> 4x3 ***\n\nGeneration = 2, Population = 3.\n...\n.*.\n.*.\n.*.\n");
	results.push_back("*** Life<ConwayCell> 4x3 ***\n\nGeneration = 3, Population = 3.\n...\n...\n***\n...\n");
	results.push_back("*** Life<ConwayCell> 4x3 ***\n\nGeneration = 4, Population = 3.\n...\n.*.\n.*.\n.*.\n");
	results.push_back("*** Life<ConwayCell> 4x3 ***\n\nGeneration = 5, Population = 3.\n...\n...\n***\n...\n");
	results.push_back("*** Life<ConwayCell> 4x3 ***\n\nGeneration = 6, Population = 3.\n...\n.*.\n.*.\n.*.\n");
	results.push_back("*** Life<ConwayCell> 4x3 ***\n\nGeneration = 7, Population = 3.\n...\n...\n***\n...\n");

    for (int j = 0; j < int(l.size()); ++j) {
        ASSERT_EQ(l[j], results[j]);
    } 
}

TEST(LifeFixture, indexable_2) {
	results.resize(0);

    Life<FredkinCell> l("FredkinCell");

    stringstream in("3\n2\n12\n1\n-0\n-0\n-0\n");

	stringstream out;

	l->evolve(in, out);

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

    for (int j = 0; j < int(l.size()); ++j) {
        ASSERT_EQ(l[j], results[j]);
    }
}

TEST(LifeFixture, indexable_3) {
	results.resize(0);

    Life<Cell> l("Cell");

    stringstream in("4\n4\n8\n1\n.--.\n0..0\n0**0\n*--*\n");

	stringstream out;

	l->evolve(in, out);

	results.push_back("*** Life<Cell> 4x4 ***\n\nGeneration = 0, Population = 8.\n.--.\n0..0\n0**0\n*--*\n");
	results.push_back("*** Life<Cell> 4x4 ***\n\nGeneration = 1, Population = 6.\n.--.\n1..1\n1..1\n*--*\n");
	results.push_back("*** Life<Cell> 4x4 ***\n\nGeneration = 2, Population = 6.\n.--.\n*..*\n-**-\n.00.\n");
	results.push_back("*** Life<Cell> 4x4 ***\n\nGeneration = 3, Population = 2.\n.--.\n.**.\n-..-\n.--.\n");
	results.push_back("*** Life<Cell> 4x4 ***\n\nGeneration = 4, Population = 2.\n.00.\n....\n-..-\n.--.\n");
	results.push_back("*** Life<Cell> 4x4 ***\n\nGeneration = 5, Population = 2.\n.11.\n....\n-..-\n.--.\n");
	results.push_back("*** Life<Cell> 4x4 ***\n\nGeneration = 6, Population = 2.\n.**.\n....\n-..-\n.--.\n");
	results.push_back("*** Life<Cell> 4x4 ***\n\nGeneration = 7, Population = 0.\n....\n....\n-..-\n.--.\n");
	results.push_back("*** Life<Cell> 4x4 ***\n\nGeneration = 8, Population = 0.\n....\n....\n-..-\n.--.\n");

    for (int j = 0; j < int(l.size()); ++j) {
        ASSERT_EQ(l[j], results[j]);
    }  
}

/*
	results.push_back("");
	results.push_back("");
	results.push_back("");
	results.push_back("");
	results.push_back("");
	results.push_back("");*/

// ----
// addInstructions
// ----

TEST(LifeFixture, addIntructions_1) {
    
}

TEST(LifeFixture, addIntructions_2) {
    
}

TEST(LifeFixture, addIntructions_3) {
   
}


// ----
// createCreature
// ----

TEST(LifeFixture, createCreature_1) {
    
}

TEST(LifeFixture, createCreature_2) {

}

TEST(LifeFixture, createCreature_3) {
   
}


// ----
// addCreature
// ----
   
TEST(LifeFixture, addCreature_1) {
    
}
 
TEST(LifeFixture, addCreature_2) {
    
}

TEST(LifeFixture, addCreature_3) {
   
}


// -----
// runSimulations
// -----

TEST(LifeFixture, runSimulations_1) {

}

TEST(LifeFixture, runSimulations_2) {
    
}

TEST(LifeFixture, runSimulations_3) {
    
}


