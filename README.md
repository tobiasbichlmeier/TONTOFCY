# TONTOFCY
Library for Arduino. Delay On-Timer (TON), Delay Off-Timer, Cycle Bits and Cycle Flags

This Library includes three functions.
A Delay-ON-Timer 
A Delay-OFF-Timer
Cycle Bits and Flags

		void ton (timeronoff *t);
		void tof (timeronoff *t);
		void cyfl(cycleflag *t);

Cycle Bits and Flags like following

flag[0]  = 5ms flag

cycle[0] = 5ms cyle 
flag[1]  = 10ms flag
cycle[1] = 10ms cyle 
flag[2]  = 20ms flag
cycle[2] = 20ms cyle 
flag[3]  = 50ms flag
cycle[3] = 50ms  cyle 
flag[4]  = 100ms  flag
cycle[4] = 100ms  cyle 
flag[5]  = 200ms  flag
cycle[5] = 200ms cyle 
flag[6]  = 500ms flag
cycle[6] = 500ms cyle 
flag[7]  = 1000ms flag
cycle[7] = 1000ms cyle 
flag[8]  = 2000ms flag
cycle[8] = 2000ms cyle 
flag[9]  = 4000ms flag
cycle[9] = 4000ms cyle 
