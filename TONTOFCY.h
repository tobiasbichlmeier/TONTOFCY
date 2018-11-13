
#ifndef TONTOFCY_H
#define TONTOFCY_H

#include <Arduino.h>


struct cycleflag {

	unsigned long prevtime[7]; //variable where the previous time value is saved
	unsigned long cyfltime[7]; //variables with the fixed flag/cycl-times 
	bool firstscan; //first scan
	bool flag[10]; //the flags 
	bool cycle[10];//the cycles on/off 50%/50% means at 10ms -> 10ms ON / 10ms OFF

/*
flag[1]  = 5ms flag
cycle[1] = 5ms cyle 
flag[2]  = 10ms flag
cycle[2] = 10ms cyle 
flag[3]  = 20ms flag
cycle[3] = 20ms cyle 
flag[4]  = 50ms flag
cycle[4] = 50ms  cyle 
flag[5]  = 100ms  flag
cycle[5] = 100ms  cyle 
flag[6]  = 200ms  flag
cycle[6] = 200ms cyle 
flag[7]  = 500ms flag
cycle[7] = 500ms cyle 
flag[8]  = 1000ms flag
cycle[8] = 1000ms cyle 
flag[9]  = 2000ms flag
cycle[9] = 2000ms cyle 
flag[10]  = 4000ms flag
cycle[10] = 4000ms cyle 

values set at first scan inside function cyfl()

*/
};

//structure for the delay ON/OFF-timer
struct timeronoff {
	unsigned long delaytime; //time in ms for delay ON or OFF
	unsigned long timedo; //variable where the time value is saved
    unsigned long ovtime; // time when overrun happened
	bool hm; // bool for getting rising edge
    bool flag; // the rising edge 
 	bool e; // input to start the timer
	bool q; // output from the timer 
};

class TONTOFCY {


public:

        TONTOFCY();

        ~TONTOFCY();

		void ton (timeronoff *t);
		void tof (timeronoff *t);
		void cyfl(cycleflag *t);
};
#endif
