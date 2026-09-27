#include <fstream>
#include <iostream>
#include <string>

int start(std::string filename, std::string text_that_we_will_add);

int main(void) {
	std::cout << "Enter the file name: " << std::endl;
	std::string filename; std::cin >> filename;

	std::cout << "What is the text that we will add? : " << std::endl;
	std::string text_that_we_will_add; 
	std::cin.ignore(); // What does this do? 
	std::getline(std::cin, text_that_we_will_add);

	int result_start = start(filename, text_that_we_will_add);
	if (result_start != 0) {
		std::cout << "Something went wrong, error code: " << result_start << std::endl;
	}
}

int start(std::string filename, std::string text_that_we_will_add) {
	std::ifstream file(filename);
	if (!file.is_open()) return 1; 

	std::string line;
	while (std::getline(file, line)) {
		std::cout << line << std::endl;	
	}

	file.close();
	return 0;
}
