# fallout-terminal-hacking
CLI clone of the terminal hacking minigame from Fallout games. Originally written in a cursed C/C++ hybrid during first of year university, eventually rewritten into a slightly less cursed C version.

## Demo
<img src="https://github.com/nadrajak/fallout-terminal-hacking/blob/main/demo.gif" alt="Demo gif" width="100%"/>

## Building

### Prerequisites
- C compiler (GCC recommended)

On Ubuntu/Debian you can install the prerequisites using:
```bash
sudo apt-get install build-essential
```

### Compile & Run
```bash
cd fallout-terminal-hacking
gcc -Wall -Wextra -pedantic -o hacking hacking.c
./hacking
```
