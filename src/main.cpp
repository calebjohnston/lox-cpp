#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <list>

using namespace std;

class Token {
	friend std::ostream& operator<<(std::ostream& os, const Token& rhs) {
		os << "<Token>";
		return os;
	}
};

class Scanner {
  public:
  	Scanner(const std::string& src) {}
	std::list<Token> scanTokens() const { return {}; };
};

static bool had_error = false;

void report(int line, const std::string& where, const std::string& msg)
{
	std::cout << "[line " << line << "] Error" << where << ": " << msg << std::endl;
	
	had_error = true;
}

static void error(int line, const std::string& msg) 
{
	report(line, "", msg);
}

void run(const std::string& source)
{
	Scanner scanner(source);
	std::list<Token> tokens = scanner.scanTokens();

	for (Token tok : tokens) {
		std::cout << tok << std::endl;
	}

	if (had_error) std::exit(65);
}

void run_file(const std::string& path)
{
    std::ifstream file(path, std::ios::in | std::ios::binary);
    if (!file) {
        std::cerr << "Error: Could not open the file " << path << std::endl;
        return;
    }

	std::string source((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

	run(source);
}

void run_prompt() 
{
	std::string input;
	while (!had_error) {
		std::cout << "> ";
		std::getline(std::cin, input);
		if (input.empty()) break;
		run(input);
		had_error = false;
	}
}

int main(int argc, const char *argv[])
{
	if (argc > 1) {
		std::cout << "Usage: loxcc [script]" << std::endl;
		std::exit(64);
	}
	else if (argc == 1) {
		run_file(argv[0]);
	}
	else {
		run_prompt();
	}

	return 0;
}
