LDLIBS = $(shell pkg-config absl_statusor absl_strings --libs | sed 's/-Wl//g')
TEST_LDLIBS = -lgtest
SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build

all: clean parser runner cli

cli: $(SRC_DIR)/main.cpp parser runner
	g++ $(SRC_DIR)/main.cpp --std=c++20 $(BUILD_DIR)/parser.o $(BUILD_DIR)/runner.o $(LDLIBS) -o $(BUILD_DIR)/cli 

test: clean autoparser_test

autoparser_test:
	g++ -std=c++20 $(TEST_DIR)/autoparser.cpp third-party/rfl/thirdparty/yyjson.c  -Ithird-party  $(TEST_LDLIBS) -o $(BUILD_DIR)/test 
parser_test: parser
	g++ -std=c++20 $(TEST_DIR)/parser.cpp $(BUILD_DIR)/parser.o $(TEST_LDLIBS) -o $(BUILD_DIR)/test 

%: $(SRC_DIR)/%.cpp
	g++ -c $(SRC_DIR)/$*.cpp --std=c++20 -o $(BUILD_DIR)/$*.o $(LDLIBS)
		
clean:
	rm build/* -f
