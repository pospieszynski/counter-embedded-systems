#define LEFT_MODULE (1<<28)
#define RIGHT_MODULE (1<<30)
#define BRIGHTNESS 1<<29
#define SEGMENT_A (1<<25)
#define SEGMENT_B (1<<24)
#define SEGMENT_C (1<<22)
#define SEGMENT_D (1<<21)
#define SEGMENT_E (1<<20)
#define SEGMENT_F (1<<27)
#define SEGMENT_G (1<<26)

#define ZERO (SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_E | SEGMENT_F)
#define ONE (SEGMENT_B | SEGMENT_C )
#define TWO (SEGMENT_A | SEGMENT_B | SEGMENT_G | SEGMENT_D | SEGMENT_E)
#define THREE (SEGMENT_A | SEGMENT_D | SEGMENT_B | SEGMENT_C |  SEGMENT_G )
#define FOUR (SEGMENT_F | SEGMENT_G | SEGMENT_B | SEGMENT_C) 
#define FIVE (SEGMENT_F | SEGMENT_A | SEGMENT_C | SEGMENT_D | SEGMENT_G)
#define SIX (SEGMENT_A | SEGMENT_F | SEGMENT_G | SEGMENT_C | SEGMENT_D | SEGMENT_E)
#define SEVEN (SEGMENT_A | SEGMENT_B | SEGMENT_C)
#define EIGHT (SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_E | SEGMENT_F | SEGMENT_G)
#define NINE (SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_G | SEGMENT_F)

#define DELAY 10


void dbgu_print_ascii(const char *a) {}
void initLED();
void setNumber(int no);
void clearNumber(int digit);
void enableRightLED();
void enableLeftLED();
void initBrightness();
void clearAllSegments();
void delay();

volatile unsigned int* PIO_PER = (volatile unsigned int*)0xFFFFF400;
volatile unsigned int* PIO_OER = (volatile unsigned int*)0xFFFFF410;
volatile unsigned int* PIO_SODR = (volatile unsigned int*)0xFFFFF430;
volatile unsigned int* PIO_CODR = (volatile unsigned int*)0xFFFFF434;


void disableRightLED();

void disableLeftLED();

int main(){ 

    initLED();
    enableRightLED();
	
    unsigned int j = 0;
     volatile unsigned int k = 0;
	
// 	while(1){
// 	  setNumber(j%10);
// 	  delay();
// 	  clearNumber(j%10);
// 	  j++;
// 	}
	
	
int i;

	while(1){

		for(i = 0; i<10000; i++){
			
			setNumber(j%10);
			enableRightLED();
			for(k = 0; k < 10; k++){}

			disableRightLED();
			clearNumber(j%10);
			
			setNumber(j/10);

			enableLeftLED();
			for(k = 0; k < 10; k++){}
			disableLeftLED();
			clearNumber(j/10);

		}
			
			j++;
			if(j==100) j=0;
			delay();
		}
	
	
	while(1);
}

void enableRightLED(){
  *PIO_CODR = RIGHT_MODULE;
}

void enableLeftLED(){
  *PIO_CODR = LEFT_MODULE;
}

void disableRightLED(){
  *PIO_SODR = RIGHT_MODULE;
}

void disableLeftLED(){
  *PIO_SODR = LEFT_MODULE;
}


void delay(){
	volatile unsigned int outer_iterator = 0;
	for(outer_iterator = 0; outer_iterator < DELAY; outer_iterator++){}
}

void setNumber(int digit){
  
	switch(digit){
	  case 0:
	    *PIO_SODR = ZERO;
	    break;
	  case 1:
	    *PIO_SODR = ONE;
	    break;
	  case 2:
	    *PIO_SODR = TWO;
	    break;
	  case 3:
	    *PIO_SODR = THREE;
	    break;
	  case 4:
	    *PIO_SODR = FOUR;
	    break;
	  case 5:
	    *PIO_SODR = FIVE;
	    break;
	  case 6:
	    *PIO_SODR = SIX;
	    break;
	  case 7:
	    *PIO_SODR = SEVEN;
	    break;
	  case 8:
	    *PIO_SODR = EIGHT;
	    break;
	  case 9:
	    *PIO_SODR = NINE;
	    break;
	}
}


void clearNumber(int digit){
  
	switch(digit){
	  case 0:
	    *PIO_CODR = ZERO;
	    break;
	  case 1:
	    *PIO_CODR = ONE;
	  break;
	  case 2:
	    *PIO_CODR = TWO;
	    break;
	  case 3:
	    *PIO_CODR = THREE;
	    break;
	  case 4:
	    *PIO_CODR = FOUR;
	    break;
	  case 5:
	    *PIO_CODR = FIVE;
	    break;
	  case 6:
	    *PIO_CODR = SIX;
	    break;
	  case 7:
	    *PIO_CODR = SEVEN;
	    break;
	  case 8:
	    *PIO_CODR = EIGHT;
	    break;
	  case 9:
	    *PIO_CODR = NINE;
	    break;
	}
}


void initLED(){

  clearAllSegments();

  *PIO_PER = LEFT_MODULE;
  *PIO_OER = LEFT_MODULE;
  *PIO_SODR = LEFT_MODULE;
  
  *PIO_PER = RIGHT_MODULE;
  *PIO_OER = RIGHT_MODULE;
  *PIO_SODR =  RIGHT_MODULE;
  
  *PIO_PER = SEGMENT_A;
  *PIO_OER = SEGMENT_A;

  *PIO_PER = SEGMENT_B;
  *PIO_OER = SEGMENT_B;

  *PIO_PER = SEGMENT_C;
  *PIO_OER = SEGMENT_C;

  *PIO_PER = SEGMENT_D;
  *PIO_OER = SEGMENT_D;

  *PIO_PER = SEGMENT_E;
  *PIO_OER = SEGMENT_E;

  *PIO_PER = SEGMENT_F;
  *PIO_OER = SEGMENT_F;

  *PIO_PER = SEGMENT_G;
  *PIO_OER = SEGMENT_G;

  initBrightness();
}

void initBrightness(){
	*PIO_PER = BRIGHTNESS;
	*PIO_OER = BRIGHTNESS;
	*PIO_CODR =  BRIGHTNESS;
}

void clearAllSegments(){
 *PIO_PER = SEGMENT_A | SEGMENT_B| SEGMENT_C | SEGMENT_D | SEGMENT_E | SEGMENT_F | SEGMENT_G;
 *PIO_OER = SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_E | SEGMENT_F | SEGMENT_G;
 *PIO_CODR = SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_E | SEGMENT_F | SEGMENT_G;
}
