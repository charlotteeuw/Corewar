# Corewar

Store and sort elements in a linked list

## Table of Contents

- [About](#about)
- [Getting Started](#getting-started)
- [How to use](#how-to-use)

## About

The Corewar tournament is a game in which several programs called Champions will fight to
stay the last one alive. Corewar is actually a computer simulation in which processors will share
memory to run on.
The project is based on a virtual machine in which the champions will fight for memory by all
possible means in order to win, the last champion being able to signal that he is alive wins the
game. In other words, the last champion to execute the live instruction is declared winner.

## How to use

-dump nbr_cycle dumps the memory after the nbr_cycle execution (if the round isn’t
already over) with the following format: 32 bytes/line in hexadecimal (A0BCDEFE1DD3...)
-n prog_number sets the next program’s number. By default, the first free number in the
parameter order
-a load_address sets the next program’s loading address. When no address is specified,
optimize the addresses so that the processes are as far away from each other as
possible. The addresses are MEM_SIZE modulo.


```bash
    ./corewar [-dump nbr_cycle] [[-n prog_number] [-a load_address] prog_name] ...
    ```
