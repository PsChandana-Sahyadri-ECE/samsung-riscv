# LED Fading with PWM

## Overview
This project demonstrates a **smooth LED fading effect** using **Pulse Width Modulation (PWM)** on a **CH32V003 microcontroller**. Four LEDs, connected to **GPIO pins PC3, PC4, PC5, and PC6**, gradually transition in brightness, creating a visually appealing **wave-like pattern**. The microcontroller precisely controls the brightness using PWM, ensuring a seamless and smooth transition.

## Applications
- LED lighting effects and animations
- Visual indicators for embedded systems
- Smooth transition effects in smart lighting solutions
- Learning platform for PWM-based brightness control

## Components Required
| Component               | Quantity | Description                                        |
|-------------------------|----------|----------------------------------------------------|
| CH32V003 Microcontroller | 1        | The core microcontroller used for LED control     |
| LEDs                    | 4        | Light-emitting diodes for visual output          |
| Resistors (330Ω)        | 4        | Used to limit current through the LEDs           |
| Connecting wires        | As needed| Used for establishing electrical connections      |
| Breadboard              | 1        | Platform for prototyping the circuit             |
| Power supply (3.3V/5V)  | 1        | Provides power to the microcontroller and LEDs   |

## Circuit Connections
| LED  | GPIO Pin | Connection Details |
|------|---------|-------------------|
| LED1 | PC3     | Connected via a 330Ω resistor |
| LED2 | PC4     | Connected via a 330Ω resistor |
| LED3 | PC5     | Connected via a 330Ω resistor |
| LED4 | PC6     | Connected via a 330Ω resistor |
| GND  | Common  | All LED grounds connected to microcontroller GND |

## Working Mechanism
1. **PWM Control:**
   - The microcontroller modulates the brightness of each LED using **Pulse Width Modulation (PWM)**.
   - Each LED is assigned a varying duty cycle to create a fading effect.
2. **Wave Effect:**
   - The first LED starts at a dim level, with each subsequent LED increasing in brightness until the last one reaches full intensity.
   - The pattern then reverses, smoothly dimming the LEDs back down, creating a **wave-like flow**.
3. **Timing & Delay Adjustments:**
   - Delays are carefully adjusted to ensure a smooth transition without abrupt changes.
   - The fading effect repeats continuously, creating an eye-catching **dynamic lighting effect**.

## Conclusion
This project effectively demonstrates the **use of PWM for LED brightness control** in embedded systems. The smooth transitions between brightness levels showcase precise **timing and duty cycle adjustments**, creating an appealing **wave-like LED animation**. The implementation can be further extended for advanced LED control applications, making it a useful foundation for larger embedded projects.

