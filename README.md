# UART Command Handler

Firmware module simulating a UART command handler in C.
Implements a linked list command queue, volatile interrupt flag,
static session counter, and multi-file extern sharing.

## Overview

In real embedded systems, commands arrive over UART via hardware
interrupts. This project simulates that behaviour on a desktop
environment — demonstrating bare-metal firmware patterns without
requiring physical hardware.

Commands are received by a simulated interrupt handler, stored in
a linked list queue, and processed one by one in a main loop.

## Concepts Demonstrated

- `volatile` — flag shared between the interrupt handler and main loop
- `static` — session command counter that persists between function calls
- `extern` — sharing the volatile flag across multiple files
- Linked list — dynamic command queue (enqueue on receive, dequeue on process)

## Project Structure

- `uart.h` — shared header, Node struct and function declarations
- `uart.c` — queue implementation and simulated interrupt handler
- `main.c` — processing loop and command execution

## Supported Commands

- `LIGHT_ON` — turn the light on
- `LIGHT_OFF` — turn the light off
- `FAN_ON` — turn the fan on
- `FAN_OFF` — turn the fan off
- `STATUS` — print current state of all devices and session command count

## Build and Run
