CXX=			g++
C=				gcc
# Do not include the -g flag when testing, otherwise your hashes will not match when they normally would.
CXXFLAGS= -Wall -Weffc++ -pedantic -std=gnu++11
SHELL=		bash
MEASURE=	../common/measure


all:		solution-a solution-b

# You may need to edit compilation settings.
solution-a:	solution-a.cpp
	$(CXX) $(CXXFLAGS) solution-a.cpp -o solution-a

# You may need to edit compilation settings.
solution-b: solution-b.cpp
	$(CXX) $(CXXFLAGS) solution-b.cpp -o solution-b

md5-test: md5.o
	$(C) md5.o md5-test.c -o md5-test

md5.o:
	$(C) -c md5.c

clean:
	rm -f solution-a solution-b md5-test md5.o

test: test-time test-output test-hash

test-hash: md5-test solution-a solution-b
	@./md5-test

test-output: solution-a solution-b
	@echo "Testing solution-a output..."
	@diff --suppress-common-lines -y <(./solution-a) output-a
	@echo "Testing solution-b output..."
	@diff --suppress-common-lines -y <(./solution-b) output-b

test-time: $(MEASURE) solution-a solution-b
	@echo "Testing solution-a time..."
	@$(MEASURE) ./solution-a | tail -n 1 | awk '{ if ($$1 > 1.0) { print "Time limit exceeded"; exit 1} }'
	@echo "Testing solution-b time..."
	@$(MEASURE) ./solution-b | tail -n 1 | awk '{ if ($$1 > 1.0) { print "Time limit exceeded"; exit 1} }'
