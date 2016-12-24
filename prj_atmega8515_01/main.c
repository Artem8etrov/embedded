#include <mega8515.h>
#include <delay.h>
                                        
#define LED_Y  PORTD.2  //yellow LED

#define IN_1    PIND.3    //green LEDs
#define IN_2    PIND.4 
#define IN_3    PIND.5 
#define IN_4    PIND.6 
#define IN_5    PIND.7 
#define IN_6    PINC.0 
#define IN_7    PINC.1 
#define IN_8    PINC.2 
#define IN_9    PINC.3 
#define IN_10   PINC.7 
#define IN_11   PINC.6 
#define IN_12   PINC.4 
#define IN_13   PINC.5 
#define IN_14   PINE.2 
#define IN_15   PINE.1 
#define IN_16   PINE.0

#define OUT_1   PORTB.7  //red LEDs
#define OUT_2   PORTB.6 
#define OUT_3   PORTB.5 
#define OUT_4   PORTB.4 
#define OUT_5   PORTB.3 
#define OUT_6   PORTB.2 
#define OUT_7   PORTB.1 
#define OUT_8   PORTB.0 
#define OUT_9   PORTA.0 
#define OUT_10  PORTA.1 
#define OUT_11  PORTA.2 
#define OUT_12  PORTA.3 
#define OUT_13  PORTA.4 
#define OUT_14  PORTA.5 
#define OUT_15  PORTA.6 
#define OUT_16  PORTA.7
                            
void init (void)
{
    //ports direction configuration  
    DDRA=0b11111111;                    
    DDRB=0b11111111;
    DDRC=0b00000000;
    DDRD=0b00000110;
    DDRE=0b00000000;

    //ports initialization
    PORTA=0b00000000;
    PORTB=0b00000000;
    PORTC=0b00000000;
    PORTD=0b00000000;
    PORTE=0b00000000;
       
    //periphery initialization
              
    
    //Global enable interrupts    
    #asm("sei")
    
    return;
}

void main(void)
{
    init();  

    PORTB = 0xFF;
    PORTA = 0xFF;
    delay_ms(500);

    PORTB = 0x00;
    PORTA = 0x00;
    delay_ms(500);
    
    PORTB = 0xFF;
    PORTA = 0xFF;
    delay_ms(500);
    
    PORTB = 0x00;
    PORTA = 0x00;
    delay_ms(500);
    
    while (1)
    {       
        if (IN_1 == 0)
            OUT_1 = 1;
        else 
            OUT_1 = 0;
                 
        if (IN_2 == 0)
            OUT_2 = 1;
        else 
            OUT_2 = 0;                         

        if (IN_3 == 0)
            OUT_3 = 1;
        else 
            OUT_3 = 0;

        if (IN_4 == 0)
            OUT_4 = 1;
        else 
            OUT_4 = 0;
            
        if (IN_5 == 0)
            OUT_5 = 1;
        else 
            OUT_5 = 0;
             
        if (IN_6 == 0)
            OUT_6 = 1;
        else 
            OUT_6 = 0; 
             
        if (IN_7 == 0)
            OUT_7 = 1;
        else 
            OUT_7 = 0;
               
        if (IN_8 == 0)
            OUT_8 = 1;
        else 
            OUT_8 = 0;     
        
        if (IN_9 == 0)
            OUT_9 = 1;
        else 
            OUT_9 = 0;   
        
        if (IN_10 == 0)
            OUT_10 = 1;
        else 
            OUT_10 = 0;  
        
        if (IN_11 == 0)
            OUT_11 = 1;
        else 
            OUT_11 = 0;  
        
        if (IN_12 == 0)
            OUT_12 = 1;
        else 
            OUT_12 = 0;   
        
        if (IN_13 == 0)
            OUT_13 = 1;
        else 
            OUT_13 = 0;;    
        
        if (IN_14 == 0)
            OUT_14 = 1;
        else 
            OUT_14 = 0;    
        
        if (IN_15 == 0)
            OUT_15 = 1;
        else 
            OUT_15 = 0;    
        
        if (IN_16 == 0)      
            OUT_16 = 1;
        else
            OUT_16 = 0;  
            
        //delay_ms(300);    
    }   
  
    return;
}