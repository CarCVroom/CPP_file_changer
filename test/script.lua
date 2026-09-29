-- This file will test the opening and writing of files of a C++ program. 
-- The C++ will be the same as a previos lua program, 
-- where the 3,18,67, and 69 line of a file will be changed.
-- If the file is not long anought the file will be replaced.
-- This is a test to see if I can link a C++ program and a Lua script

local file_do = require("file.do")

-- function to test if it can replace text
function make_test_files()
	
end
function test_replace_text()
	file_do.start("test_from_lua.txt")
	file_do.start("test_from_lua.cpp")
	file_do.start("test_from_lua.lua")
end

-- function to test if it can replace the file if it has under 69 lines
