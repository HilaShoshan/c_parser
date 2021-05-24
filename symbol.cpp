#include "symbol.h"

Type Symbol::getType() {
    return this->type;
}

int Symbol::getSymbol() {
    return this->symbol;
}

void Symbol::printSymbol() {
    if (type == Type::TERM) {
        cout << terminalStrings[symbol]; 
    }
    else {  // type is nonterminal / token
        cout << tokenStrings[symbol]; 
    }
}