#include <string>
#include <iostream>

using namespace std;

int main(void)
{	
	int test_val = 100;
	int limit_val = 10;
	while (test_val > limit_val) {
		test_val--;
	}

	std::cout << "Hello Lox " << test_val << std::endl;

	return 0;
}
