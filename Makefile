LDLIBS = $(shell pkg-config absl_statusor absl_strings --libs | sed 's/-Wl//g')
TEST_LDLIBS = -lgtest
SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build
RFL_DIR=/usr/local/include/rfl
STD= c++20
# TODO: Add documentation on how to compile this project. 
all: clean runner connector

connector: $(SRC_DIR)/main.cpp  runner
	g++ $(SRC_DIR)/main.cpp --std=$(STD) $(RFL_DIR)/rfl/thirdparty/yyjson.c -I$(RFL_DIR) $(BUILD_DIR)/runner.o $(LDLIBS) -o $(BUILD_DIR)/connector 

test: clean autoparser_test

autoparser_test:
	g++ -std=$(STD) $(TEST_DIR)/autoparser.cpp $(RFL_DIR)/rfl/thirdparty/yyjson.c  -I$(RFL_DIR)  $(TEST_LDLIBS) $(LDLIBS) -o $(BUILD_DIR)/test 

%: $(SRC_DIR)/%.cpp
	g++ -c $(SRC_DIR)/$*.cpp --std=$(STD) -o $(BUILD_DIR)/$*.o $(LDLIBS)
		
clean:
	rm build/* -f

