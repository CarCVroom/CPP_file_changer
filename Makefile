main: main.cpp
	g++ -std=c++11 -Wall -Wextra -Wpedantic main.cpp -o main
lua: main.cpp
	g++ -std=c++11 -O2 -fPIC -shared main.cpp  -o file_do.so $(pkg-config --cflags lua5.4)
