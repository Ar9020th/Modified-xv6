## Description
Scheduling Algorithms implemented in MIT-xv6
In this I have implemented some of the scheduling algorithms in MIT-xv6 operating system.Default scheduling algorithm is Round-Robbin in this operating system.

#FCFS

This is based on first come first serve policy.This is a non-preemptive policy.Processes get opportunity to run based on their time of arrivals.

#PBS

This is a preemptive policy. In this process with higher priority runs first as compared to those with higher priority. Always a process with higher priority will run first. In case a process with lower priority is running and now a new process with higher priority comes then the one with lower priority will get preempted and higher one will run first. Also we have option to change priority of a process with function set_priority implemented which take priority value and pid.

#MLFQ

MLFQ scheduler allows processes to move between different priority queues based on their behavior and CPU bursts. If a process uses too much CPU time, it is pushed to a lower priority queue, leaving I/O bound and interactive processes for higher priority queues. Also, to prevent starvation aging is implemented. In this total of 5 queue's are implemented. The time-slice for priority 0 is 1 timer tick. The times-slice for priority 1 is 2 timer ticks; for priority 2, it is 4 timer ticks; for priority 3, it is 8 timer ticks; for priority 4, it is 16 timer ticks.

##REPORT

To compare the result of the scheduling algorithms a bench.c file is created it creates 20 processes, with increasing IO time and decreasing CPU burst time as the creation time increases.

# Outcome:
The number of ticks correspond to the waiting time of the benchmark program :-
    • Round Robin(DEFAULT): 3199 ticks.
    • PBS : 3323 ticks. (I have a slight doubt in this??Why the number of ticks are so high.)
    • MLFQ: 3244 ticks.
    • FCFS: 4287 ticks.
      
# Conclusion and Comparison

FCFS is waiting for the largest time as there is no preemption and if a process with larger time comes first all the rest processes have to starve for cpu execution.
Round Robin is premptive and yields after every clock cycle hence gives better reults.
MLFQ has the least time as there are many queues with different priorities and a process which takes more CPU time is shifted to less priority queue and also prevents starvation by aging i.e shifting to upper queues after some fixed time.Thus , it takes the least time.
In PBS we give higher prioirty preference to IO bound processes hence they run first and gives a better result. 
FCFS is worst case choice, rest three gave similar result and they somewhat varied for different run.
But most of the time MLFQ gave better result.
FCFS < RR <= PBS <= MLFQ 

##Changes made in files
1. proc.c
2. proc.h
3. trap.c
4. syscall.c
5. syscall.h
6. sysproc.c
7. user.h 
8. usys.S
9. defs.h
10. setPriority.c
11. time.c
12. bench.c
