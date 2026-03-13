# Timer Separator with Timer0, Timer1, and Timer2

**Author:** ANAGH CS  
**Platform:** PIC Microcontroller (PIC16F / compatible)  
**Toolchain:** MPLAB XC8 Compiler

---

## 📌 Project Overview

This project demonstrates the use of **three independent hardware timers** (Timer0, Timer1, Timer2) on a PIC microcontroller to toggle three separate LEDs at different frequencies using **interrupt-driven** (ISR-based) time separation.

Each timer operates independently and fires its interrupt at a different rate, allowing three LEDs on PORTB to blink at distinct intervals — all without using blocking delays in the main loop.

---

## 🗂️ File Structure

```
├── main.c          # Entry point; initializes peripherals and starts the main loop
├── main.h          # Macro definitions for LED1 (RB0), LED2 (RB1), LED3 (RB2)
├── timer0.c        # Initialization routines for Timer0, Timer1, and Timer2
├── timer0.h        # Header declaring init_timer0(), init_timer1(), init_timer2()
├── isr.c           # Interrupt Service Routine handling all three timer overflows
├── isr.h           # ISR header (reserved for future declarations)
├── Makefile        # Build configuration
└── README.md       # This file
```

---

## ⚙️ Hardware Configuration

| LED   | Pin  | Timer   | Toggle Condition              |
|-------|------|---------|-------------------------------|
| LED1  | RB0  | Timer0  | Every 10,000 overflows (8-bit, no prescaler) |
| LED2  | RB1  | Timer1  | Every 40 overflows (16-bit, ~1ms period)     |
| LED3  | RB2  | Timer2  | Every 10,000 overflows (8-bit, PR2 = 124)    |

- **PORTB** is configured as all outputs (`TRISB = 0x00`)
- **ADCON1 = 0x0F** sets all PORTB pins to digital mode
- Global and Peripheral Interrupts are enabled (`GIE = 1`, `PEIE = 1`)

---

## 🔧 Timer Configuration Details

### Timer0
- Mode: **8-bit**
- Clock source: **Internal (Fosc/4)**
- Prescaler: **Disabled** (PSA = 1)
- Initial value: `TMR0 = 6`
- Reload on overflow: `TMR0 = TMR0 + 8`
- LED1 toggles every **10,000 overflows**

### Timer1
- Mode: **16-bit**
- Clock source: **Internal**
- Initial value: `TMR1 = 3036`
- Reload on overflow: `TMR1 = TMR1 + 3038`
- LED2 toggles every **40 overflows** (~1 second blink)

### Timer2
- Mode: **8-bit with Period Register**
- Period Register: `PR2 = 124`
- No manual reload needed (auto-reloads on match)
- LED3 toggles every **10,000 overflows**

---

## 🔁 How It Works

1. `main()` calls `init_config()`, which sets up PORTB, enables interrupts, and initializes all three timers.
2. The `while(1)` loop runs indefinitely — all work is done in the ISR.
3. On each timer overflow, the ISR increments a static counter for that timer.
4. When the counter reaches its threshold, the corresponding LED is toggled and the counter resets.

---

## 🛠️ Build Instructions

### Prerequisites
- MPLAB X IDE
- XC8 Compiler (v2.x or later)

### Build
```bash
make all
```

### Clean
```bash
make clean
```

---

## 📝 Notes

- Timer1 and Timer2 require **Peripheral Interrupt Enable** (`PEIE = 1`) in addition to `GIE`.
- The TMR1 reload value (`3038`) approximates a **~1 ms** tick at common PIC clock frequencies.
- Timer2 uses a **PR2 match** mechanism (auto-reload), unlike Timer0/Timer1 which require manual reload in the ISR.
- All LEDs are initialized to `0` (off) before interrupts are enabled.

---

## 📄 License

This project is submitted as academic coursework. All rights reserved by the author.
