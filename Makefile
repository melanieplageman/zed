zed: main.c options.c options.h
	clang -o zed main.c options.c

test: options.c options.h
	clang test.c options.c -o runtest -lcriterion
	./runtest
