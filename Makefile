FILES_SOURCE =	Rubik.cpp \
				RubikCollector.cpp \
				RubikCollector_checking.cpp \
				RubikCollector_firstCross.cpp \
				main.cpp

.PHONY: build
build:
	@printf "\e[32m"
	c++ -std=c++11 $(FILES_SOURCE) -o rubik
	@printf "\e[34mTest: ./rubik \"U2 L2 R2 B' U2 B' R2 U2 F' D2 F' L' D R' D' F' D' B' R2 F2 U'\"\n"

.PHONY: fclean
fclean:
	@printf "\e[31m"
	rm rubik