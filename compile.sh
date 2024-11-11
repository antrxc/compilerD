#!/bin/bash

# Check if input file is provided
if [ $# -ne 1 ]; then
    echo "Usage: $0 <input-file>"
    echo "Example: $0 input.c"
    exit 1
fi

INPUT_FILE=$1

# Check if input file exists
if [ ! -f "$INPUT_FILE" ]; then
    echo "Error: Input file '$INPUT_FILE' not found"
    exit 1
fi

# Clean previous builds
rm -f parser lex.yy.c y.tab.c y.tab.h

# Generate parser with debugging
echo "Generating parser..."
yacc -d parser.y
if [ $? -ne 0 ]; then
    echo "Error generating parser"
    exit 1
fi

# Generate lexer
echo "Generating lexer..."
flex lexer.l
if [ $? -ne 0 ]; then
    echo "Error generating lexer"
    exit 1
fi

# Compile with debugging
echo "Compiling..."
gcc -g lex.yy.c y.tab.c -o parser -lfl
if [ $? -ne 0 ]; then
    echo "Error compiling"
    exit 1
fi

echo "Build successful! Running parser on $INPUT_FILE..."
./parser "$INPUT_FILE"