LDLIBS = $(shell pkg-config absl_statusor absl_strings --libs | sed 's/-Wl//g')
TEST_LDLIBS = -lgtest
SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build
RFL_DIR=/usr/local/include/rfl
STD= c++20
# TODO: Add documentation on how to compile this project. 


cli: $(SRC_DIR)/main.cpp parser runner
	g++ $(SRC_DIR)/main.cpp --std=$(STD) $(BUILD_DIR)/parser.o $(BUILD_DIR)/runner.o $(LDLIBS) -o $(BUILD_DIR)/cli 

autoparser: $(SRC_DIR)/autoparser.cpp 
	g++ $(SRC_DIR)/autoparser.cpp --std=$(STD) $(RFL_DIR)/rfl/thirdparty/yyjson.c  -I$(RFL_DIR) -o $(BUILD_DIR)/autoparser

test: clean autoparser_test

autoparser_test:
	g++ -std=$(STD) $(TEST_DIR)/autoparser.cpp $(RFL_DIR)/rfl/thirdparty/yyjson.c  -I$(RFL_DIR)  $(TEST_LDLIBS) $(LDLIBS) -o $(BUILD_DIR)/test 
parser_test: parser
	g++ -std=$(STD) $(TEST_DIR)/parser.cpp $(BUILD_DIR)/parser.o $(TEST_LDLIBS) -o $(BUILD_DIR)/test 

%: $(SRC_DIR)/%.cpp
	g++ -c $(SRC_DIR)/$*.cpp --std=$(STD) -o $(BUILD_DIR)/$*.o $(LDLIBS)
		
clean:
	rm build/* -f
