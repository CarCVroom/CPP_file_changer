#include <algorithm>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include <vector>

int start(std::string filename, std::string text_that_we_will_add);

int main(void) {
	std::cout << "Enter the file name, you will add the exentsion later: " << std::endl;
	std::string filename; std::cin >> filename;
	std::cout << "Enter the file extension: " << std::endl;
	std::string file_extension; std::cin >> file_extension;

	std::string full_filename = filename + file_extension;

	std::cout << "What is the text that we will add? : " << std::endl;
	std::string text_that_we_will_add; 
	std::cin.ignore(); // What does this do? 
	std::getline(std::cin, text_that_we_will_add);

	int result_start = start(full_filename, text_that_we_will_add);
	if (result_start != 0) {
		std::cout << "Something went wrong, error code: " << result_start << std::endl;
	}
}

int start(std::string filename, std::string text_that_we_will_add) {
	std::ifstream file(filename);
	if (!file.is_open()) return 1; 

	std::vector<std::string> lines;

	std::string line;
	while (std::getline(file, line)) {
		lines.push_back(line);
	}
		
	std::cout << lines.size() << std::endl;
	if (lines.size() < 69) return 2;

	for (size_t i = 0; i < lines.size(); i++) {
		if (i == 2 || i == 17 || i == 66 || i == 68) {
			lines[i] = text_that_we_will_add;
		}
	}

	for (size_t i = 0; i < lines.size(); i++) {
		std::cout << i << ":" << lines[i] << std::endl;
	}

	std::ofstream output_file(filename);

	std::ostream_iterator<std::string> output_iterator(output_file, "\n");
	std::copy(std::begin(lines), std::end(lines), output_iterator);

	file.close();
	return 0;
}
