# Copilot Instructions for Hashing Machine Project

## Architecture Overview
This is a single-file C program (`src/main.c`) implementing a console-based hash table with a menu-driven interface. The program uses Windows-specific APIs for console output and screen clearing.

## Key Components
- `greet()`: Displays ASCII art title and menu options (1-4)
- `hash_function()`: Stub for hash calculation (currently empty)
- `main()`: Menu loop handling user choices with input validation

## Development Patterns
- Use `SetConsoleOutputCP(CP_UTF8)` for Unicode console output
- Clear screen with `system("cls")` on invalid inputs or transitions
- Validate scanf input with range checks and consume extra characters with `while (getchar() != '\n');`
- Exit confirmation requires 'Y'/'N' input, loops on invalid

## Build and Run
Compile with: `gcc src/main.c -o hashing-machine.exe` (or equivalent C compiler)
Run the executable to start the interactive menu.

## Implementation Notes
- Cases 1-3 in switch are placeholders; implement hash table operations there
- Hash table data structure not yet defined; consider array or linked list based on requirements
- Follow the ASCII art style for any new UI elements