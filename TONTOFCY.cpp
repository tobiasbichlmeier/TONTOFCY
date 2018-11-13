
#include "TONTOFCY.h" //include the declaration for this class

//<<constructor>> setup the LED, make pin 13 an OUTPUT
TONTOFCY::TONTOFCY(){

}

//<<destructor>>
TONTOFCY::~TONTOFCY(){/*nothing to destruct*/}




void TONTOFCY::ton (timeronoff* t) //must be called like this and every cycle:    ton(&yourstructvar);
{
//value when function millis() runs in overflow - 4 byte/ 32 Bit unsigned integer
unsigned long overrun = 4294967295;
	
//building the flag
t->flag = t->e && !t->hm;
t->hm = t->e;

//on rising edge save time of the internal counter
if (t->flag){
	//check if we run into overflow 
	if ((t->delaytime + millis()) > overrun){
		//if overrun
		t->timedo = millis() + t->delaytime - overrun;
		t->ovtime = millis();
	}
	else{
	t->timedo = t->delaytime + millis();
	}
} 	

//Overrun happened 
if (t->ovtime != 0){
	//if overun happened check when millis makes the turn to Zero, then write variable ovtime also back to Zero
	if (t->ovtime > millis()){
		t->ovtime = 0;
	}
}

//check if time is reached
if ((millis() >= t->timedo) && (t->ovtime == 0)){
	t->q = true;
}
else
{t->q = false;}
}



void TONTOFCY::tof (timeronoff* t) //must be called like this and every cycle:    tof(&yourstructvar);
{
//value when function millis() runs in overflow - 4 byte/ 32 Bit unsigned integer
unsigned long overrun = 4294967295;
  
//building the flag
t->flag = !t->e && t->hm;
t->hm = t->e;

//on falling edge save time of the internal counter
if (t->flag){
  //check if we run into overflow 
  if ((t->delaytime + millis()) > overrun){
    //if overrun
    t->timedo = millis() + t->delaytime - overrun;
    t->ovtime = millis();
  }
  else{
  t->timedo = t->delaytime + millis();
  }
}   

//Overrun happened 
if (t->ovtime != 0){
  //if overun happened check when millis makes the turn to Zero, then write variable ovtime also back to Zero
  if (t->ovtime > millis()){
    t->ovtime = 0;
  }
}

//check if time is reached
if (t->e || (millis() <= t->timedo) && (t->ovtime == 0)){
  t->q = true;
}
else
{t->q = false;}
}


void TONTOFCY::cyfl(cycleflag* t) //must be called like this and every cycle:    cycleflags(&yourstructvar);
{
//value when function millis() runs in overflow - 4 byte/ 32 Bit unsigned integer
unsigned long overrun = 4294967295;
unsigned long now;
int i;
int nrcyfl = 10;

//set constants
t->cyfltime[1] = 5;
t->cyfltime[2] = 10;
t->cyfltime[3] = 20;
t->cyfltime[4] = 50;
t->cyfltime[5] = 100;
t->cyfltime[6] = 200;
t->cyfltime[7] = 500;
t->cyfltime[8] = 1000;
t->cyfltime[9] = 2000;
t->cyfltime[10] = 4000;

//if first scan init prevtime variables
if (!t->firstscan){
	   for (int i=0; i <= nrcyfl; i++){
		   t->prevtime[i] = 0;
	   }
}

//get actual time
now = millis();
//run all seven flag/cycles
   for (int i=0; i <= nrcyfl; i++){
	   //reset flag bit
	   t->flag[i] = false;
	if(now >= (t->prevtime[i]+t->cyfltime[i])){
	//set flag bit
	t->flag[i] = true;
	//set cycle if false and reset if true 
	if (t->cycle[i]){
		t->cycle[i] = false;
	}
	else{
		t->cycle[i] = true;
	} 
	//save new previous time
	t->prevtime[i] = now;
   }
   }
}