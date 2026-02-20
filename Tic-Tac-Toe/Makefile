CXX=		g++
CXXFLAGS=	-g -Wall -std=gnu++11
SHELL=		bash

all:		toecheck

toecheck:	toecheck.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f toecheck

test:		test-output1 test-output2 test-output3 test-output4 test-output5 test-output6 test-output7 test-output8

test-output1:	toecheck
	@echo Testing input/output 1...
	@diff --suppress-common-lines -y <(./toecheck < input1) output1

test-output2:   toecheck
	@echo Testing input/output 2...
	@diff --suppress-common-lines -y <(./toecheck < input2) output2

test-output3:	solution
	@echo Testing input/output3...
	@diff --suppress-common-lines -y <(./solution < input3) output3
test-output4:   solution
	@echo Testing input/output4...
	@diff --suppress-common-lines -y <(./solution < input4) output4

test-output5:	solution
	@echo Testing input/output5...
	@diff --suppress-common-lines -y <(./solution < input5) output5
test-output6:   solution
	@echo Testing input/output6...
	@diff --suppress-common-lines -y <(./solution < input6) output6

test-output7:	solution
	@echo Testing input/output7...
	@diff --suppress-common-lines -y <(./solution < input7) output7
test-output8:   solution
	@echo Testing input/output8...
	@diff --suppress-common-lines -y <(./solution < input8) output8
