#!/bin/bash
g++ src/main.cpp
valgrind --leak-check=full --log-file="logfile.out" -v ./a.out
