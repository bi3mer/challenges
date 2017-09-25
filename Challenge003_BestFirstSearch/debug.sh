#!/bin/bash
g++ main.cpp -g
valgrind --track-origins=yes ./a.out
