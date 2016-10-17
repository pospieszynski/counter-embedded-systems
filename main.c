#define LEFT_MODULE (1<<28)
#define RIGHT_MODULE (1<<30)
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

#define DELAY 100000


void dbgu_print_ascii(const char *a) {}
void initLED();
void setNumber(int no);
void clearNumber(int digit);
void enableRightLED();
void enableLeftLED();
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
	
    volatile unsigned int j = 0;
      volatile unsigned int k = 0;
	
// 	while(1){
// 	  setNumber(j%10);
// 	  delay();
// 	  clearNumber(j%10);
// 	  j++;
// 	}
	
	
	while(1){
	  enableRightLED();
	  setNumber(j%10);
	  delay();
	  clearNumber(j%10);
	  disableRightLED();
	  if(j>9){
	    enableLeftLED();
	     setNumber(j/10);
	     delay();
	     clearNumber(j/10);
	     disableLeftLED();
	  }
	  if(k%999999)j++;
	  k++;
	  if(j==100) j=0;
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
  *PIO_PER = LEFT_MODULE;
  *PIO_OER = LEFT_MODULE;
    *PIO_SODR = LEFT_MODULE;
  
  *PIO_PER = RIGHT_MODULE;
  *PIO_OER = RIGHT_MODULE;
  *PIO_SODR =  RIGHT_MODULE;
  
  *PIO_PER = ZERO;
  *PIO_OER = ZERO;

  *PIO_PER = ONE;
  *PIO_OER = ONE;

  *PIO_PER = TWO;
  *PIO_OER = TWO;

  *PIO_PER = THREE;
  *PIO_OER = THREE;

  *PIO_PER = FOUR;
  *PIO_OER = FOUR;

  *PIO_PER = FIVE;
  *PIO_OER = FIVE;

  *PIO_PER = SIX;
  *PIO_OER = SIX;

  *PIO_PER = SEVEN;
  *PIO_OER = SEVEN;

  *PIO_PER = EIGHT;
  *PIO_OER = EIGHT;

  *PIO_PER = NINE;
  *PIO_OER = NINE;
  
}
