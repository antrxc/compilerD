
## Project Structure
- `lexer.l`: Lexical analyzer specification (tokenizer)
- `parser.y`: Syntax analyzer specification (parser)
- `compile.sh`: Build and run script
- `input.c`: Sample C source code to compile

## How to Run

1. Clone or download the project files to your local machine

2. Make the compile script executable:
    ```bash
    chmod +x compile.sh
    ```

3. Run the script with the input file as an argument:
    ```bash
    ./compile.sh input.c
    ``` 


## Output Explanation
The compiler will show:

1. **Lexical Analysis Phase**
   - Shows each token recognized in the input
   - Format: `LEX: <token-type>: <token-value>`

2. **Syntax Analysis Phase**
   - Shows parsing progress
   - Displays any syntax errors encountered
   - Format: `PARSER: <action> processed`

3. **Abstract Syntax Tree**
   - Shows the hierarchical structure of the program
   - Indentation indicates nesting level
   - Format:
     ```
     Program
       Function: main
         Type: int
         Compound
           Declaration: x
             ...
     ```

## Error Handling
- Lexical errors show the unexpected character and line number
- Syntax errors show which part of the grammar failed to parse
- The program will indicate if compilation was successful or failed

## Example Usage
    Create a file named `input.c` and write your C code in it.
    Run the script with the input file as an argument:
    ```bash
    ./compile.sh input.c
    ``` 

## Supported Features
- All 32 C keywords
- All C operators (arithmetic, logical, bitwise, etc.)
- Variable declarations and initializations
- Function definitions
- Control structures (if, while)
- Basic expressions and statements
- Comments (single-line and multi-line)

## Output Format
The compiler generates:
1. Token stream from lexical analysis
2. Parsing actions during syntax analysis
3. Abstract Syntax Tree representation
4. Final compilation status

## Next Steps
The AST output can be used for:
1. Semantic Analysis
2. Intermediate Code Generation
3. Code Optimization
4. Target Code Generation

## Troubleshooting
1. If you get "permission denied":
   ```bash
   chmod +x compile.sh
   ```

2. If you get "flex/bison not found":
   ```bash
   sudo apt-get install flex bison
   ```

3. If compilation fails:
   - Check input file exists
   - Verify C code syntax
   - Look for specific error messages