# 🧩 Interrupt Simulator – Test Case Usage Guide

### 📄 Overview
This repository contains **20 test case files (`trace_6.txt` to `trace_25.txt`)** designed for use with the **SYSC 4001 – Assignment 1 Interrupt Simulator**.  
Each test case represents a sequence of CPU bursts, system calls, and interrupt completions that simulate the execution of a simple program on a system with one CPU and multiple I/O devices.

---

## ⚙️ 1. Folder Structure

```
Assignment-1/
│
├── src/
│   ├── interrupts.cpp
│   ├── interrupts.hpp
│   ├── build.sh
│
├── input_files/
│   ├── trace_1.txt
│   ├── trace_2.txt
│   ├── ...
│   ├── trace_25.txt   ← includes 20 new test cases
│
├── output_files/
│   ├── execution_1.txt
│   ├── execution_2.txt
│   └── ...
│
├── vector_table.txt
├── device_table.txt
└── README.md
```

---

## 🧠 2. What Each Trace File Contains

Each `.txt` file includes a randomized sequence of:
- **CPU bursts** – how long the CPU is busy (`CPU, duration`)
- **System Calls (SYSCALL)** – which device is called (`SYSCALL, device_number`)
- **End of I/O interrupts (END_IO)** – when the device finishes (`END_IO, device_number`)

Example snippet:
```
CPU, 75
SYSCALL, 5
CPU, 84
END_IO, 5
CPU, 22
SYSCALL, 10
CPU, 80
END_IO, 10
```

---

## 🧪 3. Running the Simulation

### Step 1: Build the Simulator
```bash
source build.sh
```
This compiles `interrupts.cpp` into an executable inside the `bin/` directory.

---

### Step 2: Run a Test Case
To run the simulator with a given trace:
```bash
./bin/interrupts input_files/trace_6.txt
```
Replace `trace_6.txt` with any file from `trace_1.txt` to `trace_25.txt`.

---

### Step 3: View the Output
Each run generates an output log (e.g., `execution.txt`) inside:
```
output_files/
```

Example output:
```
0, 51, CPU Burst
51, 1, switch to kernel mode
52, 10, context saved
62, 1, find vector 14 in memory position 0x001C
63, 1, load address 0x0165 into PC
64, 40, SYSCALL: run the ISR
104, 40, transfer data from device to memory
144, 376, check for errors
```

---

## 📈 4. Performing Your 20 Simulation Cases

Follow the assignment requirements:
1. Run **20 simulation cases** using the provided trace files.
2. Vary:
   - Context save/restore times (10, 20, 30 ms)
   - ISR body durations (40–200 ms)
   - Vector size (2 bytes vs 4 bytes)
   - Device table delays

You can modify parameters in your code or configuration files and re-run the simulator.

---

## 📊 5. Analyzing Results

After each run:
- Record total execution time.
- Compare CPU vs I/O overlap.
- Observe how changing ISR duration or context-switch time affects total performance.
- Save and summarize results in `report.pdf`.

Suggested analysis template:
| Test Case | Context Save | ISR Duration | Vector Size | Total Time | CPU Busy (%) |
|------------|---------------|---------------|--------------|-------------|---------------|

---

## 🧰 6. Notes
- Each interrupt vector is **2 bytes long** (`vector_table.txt`).
- Device delays are defined in `device_table.txt`.
- Assume an I/O device is **always available** (no queueing).
- IRET execution time: **1 ms**.

---

## 🏁 7. Deliverables
Include in your GitHub repository:
```
interrupts.cpp
interrupts.hpp
build.sh
vector_table.txt
device_table.txt
input_files/trace_*.txt
output_files/execution_*.txt
report.pdf
README.md
```
Ensure your repository link and report are submitted on Brightspace.

---
