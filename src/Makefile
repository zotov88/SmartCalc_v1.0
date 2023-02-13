FLAGS=-Werror -Wextra -Wall -std=c11 -g -lm
FLAGS_CHECK=$(shell pkg-config --cflags --libs check)
FLAGS_GCOV=-fprofile-arcs -ftest-coverage
DIR=calculator

all: clean gcov_report install

clean:
	@rm -rf ./report ./latex ./html *.out $(DIR)/*.a $(DIR)/*.o *.info *.gcov *.gcda *.gcno *.tar

dvi:
	@doxygen dox/Doxyfile
	@open ./html/index.html

install: create_dir_build
	@cd ui && qmake && make && make clean && rm Makefile && cd ../ && mv ui/smartcalc build

uninstall:
	@rm -rf build

dist:
	@rm -rf dist.tar
	@tar -cvzf dist.tar build/smartcalc

create_dir_build:
	@rm -rf build
	@mkdir build

test: clean
	@gcc $(CFLAGS) tests/test.c $(DIR)/*.c -o test.out $(FLAGS_CHECK)
	./test.out

gcov_report: clean
	@gcc $(FLAGS_GCOV) $(DIR)/*.c tests/test.c -o report.out $(FLAGS_CHECK)
	./report.out
	@lcov -t "report" -o report.info -c -d .
	@genhtml -o ./report report.info
	@open ./report/$(DIR)/index.html
	@rm -f *.gcov *.gcda *.gcno *.info report.out *.o

calculator.a: $(DIR)/validation.o $(DIR)/stack.o $(DIR)/calculation.o $(DIR)/parcer.o
	@ar src $(DIR)/calculator.a $(DIR)/validation.o $(DIR)/stack.o $(DIR)/calculation.o $(DIR)/parcer.o
	@ranlib $(DIR)/calculator.a

valgrind: all
	valgrind --leak-check=full --track-origins=yes -s calculator.out -lm

validation.o: validation.c
	@gcc $(FLAGS) -c -o $(DIR)/validation.o $(DIR)/validation.c

stack.o: stack.c
	@gcc $(FLAGS) -c -o $(DIR)/stack.o $(DIR)/stack.c

parcer.o: parcer.c
	@gcc $(FLAGS) -c -o $(DIR)/parcer.o $(DIR)/parcer.c

calculation.o: calculation.c
	@gcc $(FLAGS) -c -o $(DIR)/calculation.o $(DIR)/calculation.c

git: clean
	git add .
	git commit -m "from Makefile"
	git push

check_style:
	clang-format -style=Google -n $(DIR)/*.c $(DIR)/headers/*.h tests/test.c

correct_style:
	clang-format -style=Google -i $(DIR)/*.c $(DIR)/headers/*.h tests/test.c

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem $(DIR)/*.c $(DIR)/headers/*.h tests/test.c

cpplint:
	python3 cpplint.py --extensions=c $(DIR)/*.c $(DIR)/headers/*.h tests/test.c

all_check:
	make check_style
	make cppcheck
	make cpplint

check:
	checkmk tests/check.check > tests/test.c

qt_qmake:
	sudo apt-get install qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools

