#include <cstddef>

#include "TestHarness.h"
#include "Symbol.h"
#include "Alternation.h"
#include "Empty.h"
#include "Concatenation.h"
#include "Identifier.h"

// logicalvalue is the test name,
// examples_of_syntax is the test group
TEST( logicalvalue, examples_of_syntax ) {
    Symbol s1(".TRUE");
    Symbol s2(".FALSE");
    Alternation logicalvalue(&s1, &s2);
}

TEST( secondary, examples_of_syntax ) {
    Symbol s1("*");
    Language* primary = 0;
    Empty e2;
    Concatenation c3(&s1, primary);
    Alternation subsecondary(&c3, &e2);
    Concatenation secondary(primary, &subsecondary);
}

// TODO: A
// TODO: A + B
// TODO: A + B * C
// TODO: (A + B) * C

class AlgebraicExpression : public Language {
public:
    // Constructor
    AlgebraicExpression();
private:
    Empty empty;
    Identifier id;
    Symbol closeparen;
    Concatenation ex1_closeparen;
    Symbol openparen;
    Concatenation parenthesized_ex1;
    Alternation EX3;
    Symbol times;
    Concatenation times_ex2;
    Alternation optional_times_ex2;
    Concatenation EX2;
    Symbol plus;
    Concatenation plus_ex1;
    Alternation optional_plus_ex1;
    Concatenation EX1;
};

// Constructor
AlgebraicExpression::AlgebraicExpression() :
    empty(),
    id(),
    closeparen(")"),
    ex1_closeparen(&EX1, &closeparen),
    openparen("("),
    parenthesized_ex1(&openparen, &ex1_closeparen),
    EX3( &id, &parenthesized_ex1),
    times("*"),
    times_ex2(&times, &EX2),
    optional_times_ex2(&times_ex2, &empty),
    EX2(&EX3, &optional_times_ex2),
    plus("+"),
    plus_ex1(&plus, &EX1),
    optional_plus_ex1(&plus_ex1, &empty),
    EX1(&EX2, &optional_plus_ex1)
{
}

TEST( algebraic, examples_of_syntax ) {
    AlgebraicExpression to_test;
}

int main(int argc, char* argv[]) {
    TestResult tr;
    TestRegistry::runAllTests(tr);
    return 0;
}
