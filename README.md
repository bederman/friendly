friendly
========

Fun With Friendly Numbers

A number's abundancy is the ratio between the sum of the divisors and the number itself.
So, for example, 6 has an abundancy of 2: It's divisors are 1,2,3, and 6, so the sum is 12,
and the abundancy is 12/2. As a side note, any number with an abundancy of 2 is a perfect number.
Two (or more) numbers are considered to be friendly is they share an abundancy.

This program does the following:
*Determine whether or not two integers are friendly.
*Safe search for numbers friendly with a given integer (should only search
less than given integer for obvious reasons). For example, say I want to know what is friendly with 28.
The program should output 6.
*Given an abundancy and an integer, find all integers less than or equal to
the given integer that have the given abundancy (so might not include the given integer).
*Given an integer, return every integer less than or equal to it.
*Do a full search (no longer restricted to just less than the given integer).
So searching for perfect numbers (say, starting with 6) should output 28, 496, 8128,
(and then stops to avoid too much processing).
*For (not very much) more information, here is the wikipedia article: http://en.wikipedia.org/wiki/Friendly_number.
