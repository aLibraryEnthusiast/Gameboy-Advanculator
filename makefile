all: clear clearc build mvassets test #yes ik this is shorter but cope

release: clear clearc build mvassets cpREADME package #yes ik this is longer but cope


clear:
	@-rm ./build/*
	@-rm ./build/assets/*
	@-rmdir ./build/assets
	@-rmdir ./build
	@-rm ./Sha256Sum.txt

clearc:
	@-clear

build:
	-@mkdir ./build
	g++ ./src/main.cpp -o ./build/main.o -lX11 -I/usr/include/freetype2 -lfreetype -lXft

	@echo "sha256sum:"
	@sha256sum ./build/main.o > Sha256Sum.txt

ptrtst: #part of tests im running, dont worry, they'll be removed later
	-@mkdir nill
	@g++ ./src/ptrExp.cpp -o ./nill/ptr.o
	@./nill/ptr.o

mvassets:
	@-mkdir ./build/assets
	@-cp ./src/assets/* ./build/assets/
	@-cp ./Sha256Sum.txt ./build/Sha256Sum.txt

cpREADME:
	@-cp ./readme.md ./build/readme.txt

test:
	@./build/main.o

package: #packages for release
	7z a Gameboy_Advanceulator ./build/*