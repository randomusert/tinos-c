#include "help.h"
#include "../../lib/stdio.h"

void help() {
    print("Available commands:\n");
    print("  help       - Show this help message\n");
    print("  clear      - Clear the screen\n");
    print("  ver        - Show OS version\n");
    print("  halt       - Halt the system\n");
}