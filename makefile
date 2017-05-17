all: a.out b.out

a.out: test.cpp
	icpc -std=c++11 -xMIC-AVX512 $< -o $@

b.out: test2.cpp
	icpc -std=c++11 -xMIC-AVX512 $< -o $@

test:
	./a.out > a.txt
	./b.out > b.txt

clean:
	rm -f a.out b.out
