all: a.out b.out

CPPFLAGS= -std=c++11 -mavx512f -mavx512er
CC=g++

a.out: test.cpp
	$(CC) $(CPPFLAGS) $< -o $@

b.out: test2.cpp
	$(CC) $(CPPFLAGS) $< -o $@

clean:
	rm -f a.out b.out

