#include <stdio.h>
#include <string>
#include "TestHarness.h"

static inline SimpleString StringFrom(const std::string& value) {
    return SimpleString(value.c_str());
}

// Hello is the test name, world is the test group
TEST( Hello, world ) {
  std::string s1("Hello");
  std::string s2("Hello");
  std::string s3("world");

  CHECK_EQUAL(s1, s2);
  CHECK_EQUAL(s2, s1);

  CHECK(s1 != s3);
}

int main(int argc, char* argv[]) {
    TestResult tr;
    TestRegistry::runAllTests(tr);
    return 0;
}
