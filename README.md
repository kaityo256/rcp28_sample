# Sample code of vrcp28pd

## Summary

Sample code of using vrcp28pd with accuracy corrections.

* test.cpp (a.out): without corrections
* test2.cpp (b.out): with corrections

## Usage

    $ make
    $ ./a.out
    1.0028231394486751
    0 01111111111 0000000010111001000001000110101110011010101001101100
    1.0028231400601602
    0 01111111111 0000000010111001000001000110111000111010111111001000
    29
    (snip)
    1.1815988407141602
    0 01111111111 0010111001111101010000101111100111011011110111000110
    1.1815988415114642
    0 01111111111 0010111001111101010000101111110101001000100000011000
    29

    $ ./b.out
    1.0028231394486751
    0 01111111111 0000000010111001000001000110101110011010101001101100
    1.0028231394486751
    0 01111111111 0000000010111001000001000110101110011010101001101100
    52
    (snip)
    1.1815988407141602
    0 01111111111 0010111001111101010000101111100111011011110111000110
    1.1815988407141602
    0 01111111111 0010111001111101010000101111100111011011110111000110
    52
