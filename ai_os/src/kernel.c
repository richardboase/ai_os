#include "kernel.h"
#include "memory.h"
#include "process.h"
#include "io.h"

void init_kernel() {
    init_memory_management();
    init_process_management();
    init_io_operations();
}