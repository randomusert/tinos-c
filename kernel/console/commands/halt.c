#include "halt.h"
#include "../../lib/stdio.h"

void halt() {
    print("Halting the system...\n");
    // Implementation-specific code to halt the system
    while (1)
    {
        __asm__ __volatile__ ("hlt");
    }
    
}
