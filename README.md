# OS Project

## Test Cases

#### Input : 
```
Enter number of processes : 4

Process 0 PID : 1
Process 0 Arrival Time : 0
Process 0 Burst Time : 4

Process 1 PID : 2
Process 1 Arrival Time : 1
Process 1 Burst Time : 1

Process 2 PID : 3
Process 2 Arrival Time : 2
Process 2 Burst Time : 2

Process 3 PID : 4
Process 3 Arrival Time : 3
Process 3 Burst Time : 2
```

#### Output

```
Total Execution Time : 9

PID     Arrival     Burst     Start     Finish     Response     Waiting
  1           0         4         0          5            0           1
  2           1         1         2          3            1           0
  3           2         2         5          7            3           0
  4           3         2         7          9            4           0
```

