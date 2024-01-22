![Banner image for Robotic Programming at Staffordshire University](/BB_Banner_RP_ULTRA@4x.png)
# RP-Blinky-Test
## Very basic blinky test for STM32

This example:
- Enables the clock associated with PORT D, using the Hardware Abstraction Layer (HAL)
- Configures the "User Button" (B1) which is associated with PORT A PIN 0 (PA0) although this remains unused for the application
- Configures the outputs for user controlled LED's LD3, LD4, LD5, LD6 (PD13, PD12, PD14, PD14)
- Uses a simple combination of setting the pins high and resetting the pins low after some time is spent in a delay
