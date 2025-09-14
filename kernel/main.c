#include <lib/multiboot.h>
#include <lib/stdio.h>
#include <drivers/keyboard/handler.h>
#include <console/console.h>

__attribute__((section(".multiboot")))
struct multiboot_header_t mboot_header = {
    .magic = MULTIBOOT_MAGIC,
    .flags = MULTIBOOT_FLAGS,
    .checksum = -(MULTIBOOT_MAGIC + MULTIBOOT_FLAGS)
};

void _main(struct multiboot_info_t *mboot_info, uint32_t mboot_magic) { 
    // Initialize the screen
    clear_screen();


    console();

    // Display memory information
    print("Booted successfully!\n");
    print("Welcome to tinos-c v0.0.2 alpha dev build\n");
    print("Copyright (C) 2025 randomusert all rights reserved.\n\n");

    char input_buffer[128];
    int input_pos = 0;
    print("> ");
    // Further initialization can be done here

    while (1) {
        char c = read_char();  // Blocking keyboard input
        if (c == '\b') {
            if (input_pos > 0) {
                input_pos--;
                putchar('\b');  // Erase char on screen
            }
        } else if (c == '\n' || c == '\r') {
            print("\n");
            input_buffer[input_pos] = '\0';
            // Handle input buffer, e.g. check commands here
            print("> ");
            input_pos = 0;
        } else if (input_pos < sizeof(input_buffer) - 1) {
            input_buffer[input_pos++] = c;
            putchar(c);
        }
    }
 }