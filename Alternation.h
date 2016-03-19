#ifndef ALTERNATION_H_
#define ALTERNATION_H_

#include "Language.h"

class Alternation : public Language {
public:
    // Constructor
    Alternation( Language* first, Language* second );
};

#endif // ALTERNATION_H_
