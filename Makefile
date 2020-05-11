
.PHONY = all build run doxygen pack clean

all: build

build icp:
	mkdir -p build
	cd build; qmake ../src/icp.pro; make
	mv build/icp .

run: icp
	./icp

doxygen:
	doxygen Doxyfile

pack: clean
	zip -r xchalo16-xkrulm00.zip src examples doc Makefile Doxyfile LICENSE README.txt

clean:
	rm -rf doc build
	rm -f icp xchalo16-xkrulm00.zip
	mkdir -p doc
