CXX = g++
version = -std=c++17
TESTS = ./TEST/
SRC_MODEL_PATH = ./Model/
SRC_MODEL = $(wildcard $(SRC_MODEL_PATH)*.cpp)
SRC_CONTROLLER_PATH = ./Controller/
SRC_CONTROLLER = $(wildcard $(SRC_CONTROLLER_PATH)*.cpp)
SRC_TEST = $(wildcard $(TESTS)*.cpp)
TARGET = tests
REPORT = gcov_report
CXXFLAGS = -Wall -Wextra -Werror -Wpedantic -g
SANITIZE = -fsanitize=address -g
UNAME := $(shell uname)
OPTIMIZATIONFLAGS := -O3


ifeq ($(UNAME), Linux)
 TEST_FLAGS +=  -lgtest -pthread -lm
else
 TEST_FLAGS += -lgtest -lm
endif

all: uninstall clean $(TARGET) install dvi dist

$(TARGET) : $(SRC) $(SRC_TEST)
	$(CXX) $(version) $(CXXFLAGS) $(SRC_TEST) $(SRC_MODEL)  $(TEST_FLAGS) -o $(TARGET) $(OPTIMIZATIONFLAGS)
	./$(TARGET)


install: clean | install_qcustom_plot
	rm -rf View/MLP/Build_MLP
	mkdir View/MLP/Build_MLP
	cd View/MLP/Build_MLP && cmake ../
	cd View/MLP/Build_MLP && make
	open View/MLP/Build_MLP/MLP.app/

uninstall:
	rm -rf View/MLP/Build_MLP View/MLP/build  View/MLP/QCustomPlot-library

dist: install
	tar --totals -cvf MLP.tar View TEST Model Controller

dvi:
	Doxygen Doxyfile
	open ./Documentation/html/index.html
build_file:
	mkdir Build

install_qcustom_plot: 
	cd View/MLP && git clone https://github.com/legerch/QCustomPlot-library

style: 
	clang-format -i ./Model/*h ./Model/*cpp ./Controller/*h ./Controller/*cpp ./View/MLP/*h ./View/MLP/*cpp ./TEST/*cpp
clean : uninstall
	rm -rf View/MLP/Build_MLP $(TARGET) *.a *.out *.tar 
	rm -rf Documentation
	rm -rf $(SRC_MODEL_PATH)/*.out $(SRC_MODEL_PATH)/*.dSYM $(TESTS)/*.dSYM 
	rm -rf *.dSYM 
