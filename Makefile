all:
	x86_64-w64-mingw32-g++ -static -static-libgcc -static-libstdc++ -g src/*.cpp -o bin/program -IC:\\Users\\lucas\\Desktop\\SFML-2.5.1\\include -LC:\\Users\\lucas\\Desktop\\SFML-2.5.1\\lib -lsfml-graphics -lsfml-window -lsfml-system
	cp bin/program program

debug: all
	./program