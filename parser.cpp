#include "parser.h"

void Parser::parse() {
    terminal a = nextToken();  // the first symbol (nonterminal) of w 
    Symbol X = stack.back();  // the top stack symbol
    while (X.getSymbol() != terminal::END) {  // while stack is not empty
        printLM();
        if (X.getType() == Type::TERM && X.getSymbol() == a) {
            stack.pop_back();
            accepted.push_back(X); 
            a = nextToken();  // the next symbol of w
        }
        else if(X.getType() == Type::TERM) {
            cout << "syntax error" << endl;
            break;
        }
        else if(table.at(X.getSymbol()).at(a) == -1) { // error entry
            cout << "syntax error" << endl;
            break;
        }
        else {  // table[X,a] = x -> Y1Y2...Yk
            vector<Symbol> production = rules.at(table.at(X.getSymbol()).at(a));
            // cout << "number of rule: " << table.at(X.getSymbol()).at(a) << endl;
            stack.pop_back();
            for (Symbol s : production) {
                if (s.getType() == Type::TERM && s.getSymbol() == terminal::EPSILON)
                    break;  // do not enter it to the stack 
                stack.push_back(s);
            }
        }
        if (stack.empty()) {
            printLM();
            break;
        }
        X = stack.back();  // the top stack symbol
    }
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
    for (Symbol a : accepted) {
        a.printSymbol();
        cout << " ";
    }
    cout << "| ";
    for (auto it = stack.rbegin(); it != stack.rend(); it++) {  // print stack's items from the end to the start
        it->printSymbol();
        cout << " "; 
    } 
    cout << endl;
}

