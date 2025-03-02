_start_test:
	cd tests/ && \
	mkdir -p build && \
	cd build && \
	cmake .. -DCMAKE_BUILD_TYPE=Coverage && \
	make && \
	./run_tests

_start_test_coverage:
	cd tests/build && \
	make coverage

_start_test_main:
	make && g++ -std=c++17 -o main main.cpp && ./main > main.log 2>&1 && cat main.log
