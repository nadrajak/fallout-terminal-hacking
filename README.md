# fallout-terminal-hacking
CLI clone of the terminal hacking minigame from Fallout games. Originally written in a cursed C/C++ hybrid during first of year university, eventually rewritten into a slightly less cursed C version.

## Demo
<img src="https://github.com/nadrajak/fallout-terminal-hacking/blob/main/demo.gif" alt="Demo gif" width="100%"/>

## Setup

### Prerequisites
- C compiler (GCC recommended)

On Ubuntu/Debian you can install the prerequisites using:
```bash
sudo apt-get install build-essential
```

### Running
1.  **Clone the repository:**
    ```bash
    git clone https://github.com/nadrajak/fallout-terminal-hacking.git
    cd  fallout-terminal-hacking
    ```
2.  **Compile:**
    ```bash
    gcc -Wall -Wextra -pedantic -o hacking hacking.c
    ```
3.  **Run:**
    ```bash
    ./hacking
    ```
