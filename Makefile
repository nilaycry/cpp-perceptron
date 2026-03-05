CXX      = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I includes/
SRC      = src/perceptron.cc src/driver.cc src/dataloader.cc
TARGET   = perceptron

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
