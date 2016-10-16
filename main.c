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
#define ONE (SEGMENT_B | SEGMENT_C |)
#define TWO (SEGMENT_A | SEGMENT_B | SEGMENT_G | SEGMENT_D)
#define THREE (SEGMENT_A | SEGMENT_D | SEGMENT_B | SEGMENT_C)
#define FOUR (SEGMENT_F | SEGMENT_G | SEGMENT_B | SEGMENT_C) 
#define FIVE (SEGMENT_F | SEGMENT_A | SEGMENT_C | SEGMENT_D | SEGMENT_G)
#define SIX (SEGMENT_A | SEGMENT_F | SEGMENT_G | SEGMENT_C | SEGMENT_D | SEGMENT_E)
#define SEVEN (SEGMENT_A | SEGMENT_B | SEGMENT_C)
#define EIGHT (SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_E | SEGMENT_F | SEGMENT_G)
#define NINE (SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_G | SEGMENT_F)

#define DELAY 10000


void dbgu_print_ascii(const char *a) {}
void setNumber(int no);
void reset();
void delay();

volatile unsigned int* PIO_PER = (volatile unsigned int*)0xFFFFF400;
volatile unsigned int* PIO_OER = (volatile unsigned int*)0xFFFFF410;
volatile unsigned int* PIO_SODR = (volatile unsigned int*)0xFFFFF430;
volatile unsigned int* PIO_CODR = (volatile unsigned int*)0xFFFFF434;

volatile unsigned int numbers[] = { ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};

int main(){ 

	*PIO_PER = LEFT_MODULE;
	*PIO_OER = LEFT_MODULE;
	*PIO_CODR = LEFT_MODULE;

		
	volatile unsigned int j = 0;
	
	while(1){
	  setNumber(j%10);
	  delay();
	  j++;
	}
	
	while(1);
}

void reset(void){
	*PIO_PER = 0<<25 | 0<<24 | 0<<22 | 0<<21 | 0<<20 | 0<<27 | 0<<26;
	*PIO_OER = 0<<25 | 0<<24 | 0<<22 | 0<<21 | 0<<20 | 0<<27 | 0<<26;
	*PIO_CODR = 0<<25 | 0<<24 | 0<<22 | 0<<21 | 0<<20 | 0<<27 | 0<<26;
}

void delay(){
	volatile unsigned int outer_iterator = 0;
	volatile unsigned int inner_iterator = 0;
	for(outer_iterator = 0; outer_iterator < DELAY; outer_iterator++)
	    for(inner_iterator = 0; inner_iterator < DELAY; inner_iterator++)
	    	100*100%k;
}

void setNumber(int no){
	*PIO_PER = numbers[no];
	*PIO_OER = numbers[no];
	*PIO_SODR = numbers[no];
}
