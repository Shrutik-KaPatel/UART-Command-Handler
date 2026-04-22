# UART Command Handler

Firmware module simulating a UART command handler in C.
Implements a linked list command queue, volatile interrupt flag,
static session counter, and multi-file extern sharing.

## Files
- uart.h  — shared header, structures and extern declarations
- uart.c  — queue implementation and simulated interrupt handler
- main.c  — processing loop and command execution

## Build
gcc main.c uart.c -o uart_handler
./uart_handler
