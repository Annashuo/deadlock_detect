# deadlock_detect

compile: sh build.sh

run: ./deadlock2

example:

input:

4

1 a

2 b

1 b

2 a

result:

get cycle: 2 -> 1 for a   1 -> 2 for b
