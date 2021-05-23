#include "parser.h"

void Parser::parse() {
    // string a = tokens.at(0);  // the first symbol of w 
    for (int i = 0; i < 5; i++)
        cout << nextToken() << endl;
}

terminal Parser::nextToken() {
    string token;
    if (index >= tokens.size()) {
        return terminal::END;
    }
    token = tokens[index]; 
    index++;
    int length = sizeof(terminalStrings)/sizeof(terminalStrings[0]);
    for (int i = 0; i < length; i++) {
        if (terminalStrings[i] == token) {
            return (terminal)i;
        }
    }
    throw "‫‪syntax‬‬ ‫‪error\n‬‬"; 
}

void Parser::printLM() {

}

