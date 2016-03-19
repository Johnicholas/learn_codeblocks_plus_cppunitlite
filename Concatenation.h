#ifndef CONCATENATION_H_
#define CONCATENATION_H_

#include "Language.h"

class Concatenation : public Language {
public:
    // Constructor
    Concatenation( Language* first, Language* second );
};

#endif // CONCATENATION_H_
