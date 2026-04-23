#include <stdio.h>
#include <string.h>
#include "uart.h"

extern volatile int flag; // access the flag defined in uart.c

int main()
{
    int lightOn = 0, fanOn = 0; // device state — 0 = OFF, 1 = ON

    // simulate commands arriving over UART (in real hardware, interrupts would do this)
    simulate_uart_receive("LIGHT_ON");
    simulate_uart_receive("FAN_ON");
    simulate_uart_receive("STATUS");
    simulate_uart_receive("LIGHT_OFF");
    simulate_uart_receive("STATUS");
    simulate_uart_receive("FAN_OFF");

    // outer loop — keeps processing as long as commands are arriving
    while(flag == 1)
    {
        flag = 0; // clear the flag before processing

        char* cmd;

        // inner loop — dequeue and process all commands one by one
        while((cmd = dequeue()) != NULL)
        {
            printf("[PROC] Executing: %s\n", cmd);

            // check which command arrived and update device state
            if(strcmp(cmd, "LIGHT_ON") == 0)
                lightOn = 1;
            else if(strcmp(cmd, "LIGHT_OFF") == 0)
                lightOn = 0;
            else if(strcmp(cmd, "FAN_ON") == 0)
                fanOn = 1;
            else if(strcmp(cmd, "FAN_OFF") == 0)
                fanOn = 0;
            else if(strcmp(cmd, "STATUS") == 0)
            {
                // print current state of all devices
                printf("  Light: %s\n", lightOn ? "ON" : "OFF");
                printf("  Fan:   %s\n", fanOn ? "ON" : "OFF");
                printf("  Commands processed this session: %d\n", getCommandCount());
            }

            flag = 1; // keep flag set while queue still has commands
        }

        flag = 0; // all commands processed — clear flag
    }

    return 0;
}
