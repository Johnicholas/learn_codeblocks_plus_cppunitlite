#include <cstddef>

#include "TestHarness.h"
#include "Symbol.h"
#include "Alternation.h"
#include "Empty.h"
#include "Concatenation.h"

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

int main(int argc, char* argv[]) {
    TestResult tr;
    TestRegistry::runAllTests(tr);
    return 0;
}
