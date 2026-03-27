#include <stdint.h>

volatile uint16_t *SYNCR = (volatile uint16_t *)0xFFFA04;

volatile uint16_t *SCCR0 = (volatile uint16_t *)0xFFFC08;
volatile uint16_t *SCCR1 = (volatile uint16_t *)0xFFFC0A;
volatile uint16_t *SCSR  = (volatile uint16_t *)0xFFFC0C;

volatile uint8_t *SCDR  = (volatile uint8_t *)0xFFFC0F;

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
    
    putchar_('E');

    return 0;
}
