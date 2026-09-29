#include <cstdio>
#include <algorithm> 
#include <fstream>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include <vector>

extern "C" {
	#include <lua.h>
	#include <lauxlib.h>
}

int start(std::string filename, std::string text_that_we_will_add);
int delete_file(std::string filename);

static int l_start(lua_State *L) {
	std::string filename = luaL_checkstring(L, 1);	
	std::string text_that_we_will_add = luaL_checkstring(L, 1);	
	int result_file_do = start(filename, text_that_we_will_add);
	lua_pushinteger(L, result_file_do);
	return 1;
}

static int l_delete(lua_State *L) {
	std::string filename = luaL_checkstring(L, 1);	
	int result_file_do = delete_file(filename);
	lua_pushinteger(L, result_file_do);
	return 1;
}

static const luaL_Reg funcs[] = {
	{"start", l_start},
	{"delete_file", l_delete},
	{nullptr, nullptr}
};

extern "C" int luaopen_file_do(lua_State *L) {
	luaL_newlib(L, funcs);
	return 1;
}

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
		switch (result_start) {
			case 1:
				std::cout << "File does not exist, or could not open. Error code: 1" << std::endl;
				break;
			case 3:
				std::cout << "Could not do something in delete, idk. Error code: 1" << std::endl;
				break;
			default:
				std::cout << "Something went wrong, exit code: " << result_start << std::endl;
		}
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
		
	int lines_length = lines.size();
	if (lines_length < 69) {
		int result_delete_file = delete_file(filename);

		if (result_delete_file != 0) return 3;
		return 0;
	}

	for (size_t i = 0; i < lines.size(); i++) {
		if (i == 2 || i == 17 || i == 66 || i == 68) {
			lines[i] = text_that_we_will_add;
		}
	}

	std::ofstream output_file(filename);

	std::ostream_iterator<std::string> output_iterator(output_file, "\n");
	std::copy(std::begin(lines), std::end(lines), output_iterator);

	file.close();
	return 0;
}

int delete_file(std::string filename) {
	if (std::remove(filename.c_str()) != 0) {
		std::cout << "ERROR! Couldn't not delete file, returning with exit code 2" << std::endl;
		return 2;
	} 
	
	std::ofstream new_file(filename);	
	new_file << "WHY THE FUCK WAS THE LESS THEN 69 LINES" << std::endl;

	return 0;
}
