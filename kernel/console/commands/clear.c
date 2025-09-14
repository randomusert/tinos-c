#include "clear.h"
#include "../../lib/stdio.h"

void clear() {
    clear_screen();
    update_cursor(0, 0);
}
