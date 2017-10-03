#!/bin/bash
valgrind --leak-check=full --log-file="logfile.out" -v ./a.out
