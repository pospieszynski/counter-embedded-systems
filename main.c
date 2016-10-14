#define LEFT_MODULE (1<<28)
#define RIGHT_MODULE (1<<30)
#define M_A (1<<25)
#define M_B (1<<24)
#define M_C (1<<22)
#define M_D (1<<21)
#define M_E (1<<20)
#define M_F (1<<27)
#define M_G (1<<26)

#define ZERO (M_A | M_B | M_C | M_D | M_E | M_F | 0<<26)
#define ONE (M_B | M_C |  0<<25 |  0<<21  | 0<<20  | 0<<27 | 0<<26)
#define TWO (M_A | M_B | 0<<22 | 0<<21 | M_G | M_D | 0<<20 | 0<<27)
#define THREE (M_A | M_D | M_B | M_C | 0<<20 | 0<<27 | 1<<26)
#define FOUR (M_F | M_G | M_B | M_C | 0<<25 | 0<<21 | 0<<20) 
#define FIVE (M_F | M_A | M_C | M_D | M_G | 0<<24 | 0<<20)
#define SIX (M_A | M_F | M_G | M_C | M_D | M_E | 0<<24)
#define SEVEN (M_A | M_B | M_C | 0<<21 | 0<<20 | 0<<27 | 0<<26)
#define EIGHT (M_A | M_B | M_C | M_D | M_E | M_F | M_G)
#define NINE (M_A | M_B | M_C | M_D | M_G | M_F | 0<<20)


void dbgu_print_ascii(const char *a) {}

volatile unsigned int* PIO_PER = (volatile unsigned int*)0xFFFFF400;
volatile unsigned int* PIO_OER = (volatile unsigned int*)0xFFFFF410;
volatile unsigned int* PIO_SODR = (volatile unsigned int*)0xFFFFF430;
volatile unsigned int* PIO_CODR = (volatile unsigned int*)0xFFFFF434;

int main(){ 

	*PIO_PER = LEFT_MODULE;
	*PIO_OER = LEFT_MODULE;
	*PIO_CODR = RIGHT_MODULE;

	volatile unsigned int numbers[] = { ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
	  
	volatile unsigned int delay = 1000;
	
	volatile unsigned int i = 0;
	
	volatile unsigned int j = 0;
	
	volatile unsigned int k = 0;
	
	while(1){
	  *PIO_PER = numbers[j%9];
	  *PIO_OER = numbers[j%9];
	  *PIO_SODR = numbers[j%9];
	  for(i=0; i<delay; i++){
	    for(k=0; k<delay; k++){
	    }
	  }
	  j++;
	}
	
	while(1);
}