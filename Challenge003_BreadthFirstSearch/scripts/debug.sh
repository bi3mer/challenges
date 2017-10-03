#!/bin/bash
g++ src/main.cpp -g
valgrind --track-origins=yes ./a.out
