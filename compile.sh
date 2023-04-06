#!/bin/bash

g++ -O3 -std=c++2a -m64 -o overcomplicated src/*.cpp src/imgui/*.cpp src/glad/*.c -lGL -lglfw -lm -lpthread -lvulkan