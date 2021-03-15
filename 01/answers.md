# SSDS EX 1, Andrin Rehmann

## 3.2

- ```c
  write(1, "Hello World!", 12Hello World!)            = 12
  ```

- ``write`` is a system call, which is executed inside the kernel. ``printf`` on the other hand is a library function which is more high level and accepts arguments of many different formats. 
- Rewriting the program with the POSIX standard (hello.system.c) yields a stack trace which is shorter by 4 lines than the one using stdf.

## 4.1

- Application: Program designed for end users, generally communicates with OS and or kernel and not directly with hardware.

- Operating System: Program designed for end users, provides an interface between the user and the hardware, responsible for resource management.

- Kernel: Part of the Operating System, provides an interface between the applications and the hardware.

- Bootstrap: Loaded at power-up or reboot, does not interact with the user. Loads kernel and starts execution.

## 4.2

Hardware: Mouse, Printer, (ROM, EPROM, CPU, RAM), Alice Computer

Operating System: Linux. Windows, Bob’s Virtual Machine

Application Programs: Pdf Reader, Chrome Browser, Virtual Box

Users: Bob

## 4.3

- 3
- 1
- 2
- 3
- 2
- 3

## 4.4 !

- 2
- 2
- 1
- 2
- 1 / 2
- 1 / 2

## 4.5

- The user mode has less privileges than the kernel mode and its access to the hardware is very limited. Usually has to communicate with modes bits with more privileges to access the hardware.
- The Kernel mode has all the privileges of the user mode, with additions. It is therefore more powerful and much closer to the hardware.

## 4.6 

### Cache Advantages

1. Caches can speedup memory access for frequently accessed data. 
2. Caches can speedup memory access for spatially close data, for example arrays.

### Cache Disadvantages

For some memory accesses they provide little benefits. For example very random memory accesses usually leads to unnecessary overhead caused by transferring data between the main memory and the cache. 

Something about synchronization.

### Why not make it as large as the memory?

The cache itself is in most cases similar to the memory, but its speed comes from the decreased size. Its fair to assume that there cannot be size and speed in the same memory unit. Because the latency of a memory access is decreased when the memory is smaller.

## 4.7

### a)

Processes ran by different users may interfere with each other. For example one process can alter shared resources which another process relies on. This can lead to information leakage, meaning a user can see information he is not supposed to see. Other than that a user might be able to slow down the CPU by running very costly processes, which can also be potentially harmful for other users.

Confidentially, Integrity, Availability

### b)

(Yes it can be ensured, but there needs to be strict rules for the privileges each process has.)

No it is not possible.

## 4.8

In a **client server mode** the workload is shared between the client and the server. The server then communicates back with different users. In a **peer to peer** model the workload is shared between different peers (clients). All those peers have the same privileges. 

## 4.9

Privileged instructions: c, d, e, f, g

## 4.10

With symmetric multi processing all CPU’s are identical, access the same memory and all have access to I/O devices.

On the other hand, a asymmetric multiprocessing computer may have unidentical CPU’s and not all of them have access to I/O devices.





