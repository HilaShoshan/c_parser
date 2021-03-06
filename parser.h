#include "symbol.h"

class Parser {
	ifstream& inputFile;
	vector<vector<Symbol>> rules {
		{ Symbol(E_, NONTERM) , Symbol(T, NONTERM) },
		{ Symbol(E_, NONTERM) , Symbol(T, NONTERM) , Symbol(PLUS, TERM) },
		{ Symbol(EPSILON, TERM) },
		{ Symbol(T_, NONTERM) , Symbol(F, NONTERM) },
		{ Symbol(T_, NONTERM) , Symbol(F, NONTERM) , Symbol(ASTERISK, TERM) },
		{ Symbol(EPSILON, TERM) },
		{ Symbol(RPAREN, TERM) , Symbol(E, NONTERM) , Symbol(LPAREN, TERM) },
		{ Symbol(ID, TERM) }
	};
	vector<vector<int>> table {
		{ 0 , -1 , -1 , 0 , -1 , -1 },
		{ -1 , 1 , -1 , -1 , 2 , 2 },
		{ 3 , -1 , -1 , 3 , -1 , -1 },
		{ -1 , 5 , 4 , -1 , 5 , 5 },
		{ 7 , -1 , -1 , 6 , -1 , -1 }
	};
	vector<Symbol> stack;
	vector<Symbol> accepted;

	vector<string> tokens;
	int index = 0;
	
public:
	Parser(ifstream& file) : inputFile(file) {
		string txt;
        while (file >> txt) {
            tokens.push_back(txt);
        }  
        file.close();
		stack.push_back(Symbol(nonTerminal::E, Type::NONTERM)); 
	}
	void parse();
	terminal nextToken();
	void printLM();
};
