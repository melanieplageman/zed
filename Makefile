zed: main.c options.c options.h expression.c expression.h
	clang -o zed `pkg-config --cflags --libs libpcre` main.c options.c expression.c

test: options.c options.h expression.c expression.h
	clang test.c options.c test_expression.c expression.c -o runtest -lcriterion `pkg-config --cflags --libs libpcre`
	./runtest
