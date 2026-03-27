#include <stdint.h>

volatile uint16_t *SCCR0 = (volatile uint16_t *)0xFFFC08;
volatile uint16_t *SCCR1 = (volatile uint16_t *)0xFFFC0A;
volatile uint16_t *SCSR  = (volatile uint16_t *)0xFFFC0C;
volatile uint16_t *SCDR  = (volatile uint16_t *)0xFFFC0E;

int main(void)
{
    return 0;
}
