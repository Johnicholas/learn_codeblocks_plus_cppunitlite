#ifndef SYMBOL_H_
#define SYMBOL_H_

#include "Language.h"

#include <string>

class Symbol : public Language {
public:
    // Constructor
    explicit Symbol(std::string literal);
};

#endif // SYMBOL_H_
