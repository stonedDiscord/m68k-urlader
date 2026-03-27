#include <stdint.h>
#include <stdbool.h>
#include "duart.h"

volatile uint16_t *SYNCR = (volatile uint16_t *)0xFFFA04;

volatile uint16_t *SCCR0 = (volatile uint16_t *)0xFFFC08;
volatile uint16_t *SCCR1 = (volatile uint16_t *)0xFFFC0A;
volatile uint16_t *SCSR  = (volatile uint16_t *)0xFFFC0C;

volatile uint8_t *SCDR  = (volatile uint8_t *)0xFFFC0F;

void putchar_(char c);
void led_and_send(char value);



void update_led(uint8_t value)
{
    ;
}

void process_header(uint8_t value)
{
    ;
}

void swap_bytes(uint8_t value)
{
    ;
}

void main_loop(void)
{
    led_and_send('P');
    led_and_send('i');
    led_and_send('m');
    led_and_send('m');
    led_and_send('e');
    led_and_send('l');
}

void process_command(uint8_t value)
{
    ;
}

void init_duart(bool slow_mode)
{
    OPCR    = 0x00;
    ACR     = ACR_CT_TIMER_X1D16 | ACR_CT_TIMER_IP2 | ACR_CT_COUNTER_TXCA | ACR_CT_COUNTER_TXCB;
    MR1A    = 0x07;
    if (slow_mode == 0) {
        CSRA    = CSR_38400;
    } else {
        CSRA    = CSR_2400;
    }
    CRA     = 0x45;
}

bool check_magic()
{
    return true;
}

bool verify_checksum()
{
    return true;
}

void reset_wait(uint8_t pattern)
{
    ;
}

void led_and_send(char value)
{
    putchar_(value);
}

void putchar_(char c)
{
    while ((*SCSR & 1) == 0)
        ;
    *SCDR = c;
}

int main(void)
{
    *SYNCR = 0x7f05u;
    *SCCR0 = 0x0009u;
    
    main_loop();

    return 0;
}
