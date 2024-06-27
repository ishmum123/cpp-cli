LDLIBS = $(shell pkg-config absl_statusor absl_strings --libs | sed 's/-Wl//g')
SRC_DIR = src
BUILD_DIR = build

all: clean parser runner cli

cli: $(SRC_DIR)/main.cpp
	g++ $(SRC_DIR)/main.cpp --std=c++20 -o $(BUILD_DIR)/cli $(BUILD_DIR)/parser.o $(BUILD_DIR)/runner.o $(LDLIBS)

%: $(SRC_DIR)/%.cpp
	g++ -c $(SRC_DIR)/$*.cpp --std=c++20 -o $(BUILD_DIR)/$*.o $(LDLIBS)
		
clean:
	rm build/* -f
