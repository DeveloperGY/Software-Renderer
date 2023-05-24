make: build run

build:
	g++ src/*.cpp src/**/*.cpp -o bin/exe -Ilib -Llib -ltdRGB -lm3

run:
	./bin/exe