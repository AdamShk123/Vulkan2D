all: clean compile link

FILES := src/main.cpp

LIBS := -l SDL2 -l vulkan -l fmt -l SDL2_image

clean:
	rm obj/* prog

compile:
	g++ --std=c++20 -g ${FILES} -c
	mv *.o obj/

link:
	g++ obj/*.o -o prog ${LIBS}

run:
	./prog
