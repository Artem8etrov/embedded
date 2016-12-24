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

#define ON      (1)      
#define OFF     (0)

void set_led_state(char id, char state)
{
    switch(id)
    {
        case 1:     OUT_1 = state;  break;
        case 2:     OUT_2 = state;  break;
        case 3:     OUT_3 = state;  break;
        case 4:     OUT_4 = state;  break;
        case 5:     OUT_5 = state;  break;
        case 6:     OUT_6 = state;  break;
        case 7:     OUT_7 = state;  break;
        case 8:     OUT_8 = state;  break;
        case 9:     OUT_9 = state;  break;
        case 10:    OUT_10 = state;  break;
        case 11:    OUT_11 = state;  break;
        case 12:    OUT_12 = state;  break;
        case 13:    OUT_13 = state;  break;
        case 14:    OUT_14 = state;  break;
        case 15:    OUT_15 = state;  break;
        case 16:    OUT_16 = state;  break;    
    }
    
    return;    
}

char get_input_state(char id)
{
    char state;
     
    switch(id)
    {
        case 1:     state = IN_1;   break;
        case 2:     state = IN_2;   break;
        case 3:     state = IN_3;   break;
        case 4:     state = IN_4;  break;
        case 5:     state = IN_5;  break;
        case 6:     state = IN_6;  break;
        case 7:     state = IN_7;  break;
        case 8:     state = IN_8;  break;
        case 9:     state = IN_9;  break;
        case 10:    state = IN_10;  break;
        case 11:    state = IN_11;  break;
        case 12:    state = IN_12;  break;
        case 13:    state = IN_13;  break;
        case 14:    state = IN_14;  break;
        case 15:    state = IN_15;  break;
        case 16:    state = IN_16;  break; 
        default:    state = 0xFF;   break;   
    }
    
    if (state == 0)   
        return ON;
    else          
        return OFF;
}

void led_on(char id)
{
    set_led_state(id, ON);
    
    return;
} 

void led_off(char id)
{
    set_led_state(id, OFF);   
    
    return;    
} 

void main(void)
{
    char id;
    int counter_ms[16];
                                              
    init();  

    for (id = 1; id <= 16; id++)
    {
        counter_ms[id - 1] = 0;
    }
     
    while (1)
    {      
        for (id = 1; id <= 16; id++)
        {
            if (get_input_state(id) == ON)
                counter_ms[id - 1] = 3000;
              
            if (counter_ms[id - 1] != 0) 
            {
                counter_ms[id - 1]--;         
                led_on(id);
            }
            else
            {
                led_off(id);
            }      
        }
                   
        delay_ms(1);    
    }   
  
    return;
}