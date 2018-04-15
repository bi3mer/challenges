#!/bin/bash
cp ../SortVisualizer/ArrayHelper.cpp .
cp ../SortVisualizer/ArrayVisualizer.cpp .

g++ main.cpp -lGL -lGLU -lglut
./a.out

rm ArrayHelper.cpp
rm ArrayVisualizer.cpp