#include <stdint.h>
#include <stdbool.h>
#include "duart.h"

#define SIMCR (* (volatile uint16_t *) (0xFFFA00) )
#define SYNCR (* (volatile uint16_t *) (0xFFFA04) )

#define PORTE0 (* (volatile uint16_t *) (0xFFFA10) )
#define PORTE1 (* (volatile uint16_t *) (0xFFFA12) )
#define DDRE  (* (volatile uint16_t *) (0xFFFA14) )
#define PEPAR (* (volatile uint16_t *) (0xFFFA16) )
#define PORTF0 (* (volatile uint16_t *) (0xFFFA18) )
#define PORTF1 (* (volatile uint16_t *) (0xFFFA1A) )
#define DDRF  (* (volatile uint16_t *) (0xFFFA1C) )
#define PFPAR (* (volatile uint16_t *) (0xFFFA1E) )
#define SYPCR (* (volatile uint16_t *) (0xFFFA20) )
#define PICR  (* (volatile uint16_t *) (0xFFFA22) )
#define PITR  (* (volatile uint16_t *) (0xFFFA24) )

#define CSPAR0 (* (volatile uint16_t *) (0xFFFA44) )
#define CSPAR1 (* (volatile uint16_t *) (0xFFFA46) )
#define CSBARBT (* (volatile uint16_t *) (0xFFFA48) )
#define CSORBT (* (volatile uint16_t *) (0xFFFA4A) )

#define CSBAR0 (* (volatile uint16_t *) (0xFFFA4C) )
#define CSOR0 (* (volatile uint16_t *) (0xFFFA4E) )
#define CSBAR1 (* (volatile uint16_t *) (0xFFFA50) )
#define CSOR1 (* (volatile uint16_t *) (0xFFFA52) )
#define CSBAR2 (* (volatile uint16_t *) (0xFFFA54) )
#define CSOR2 (* (volatile uint16_t *) (0xFFFA56) )
#define CSBAR3 (* (volatile uint16_t *) (0xFFFA58) )
#define CSOR3 (* (volatile uint16_t *) (0xFFFA5A) )
#define CSBAR4 (* (volatile uint16_t *) (0xFFFA5C) )
#define CSOR4 (* (volatile uint16_t *) (0xFFFA5E) )
#define CSBAR5 (* (volatile uint16_t *) (0xFFFA60) )
#define CSOR5 (* (volatile uint16_t *) (0xFFFA62) )
#define CSBAR6 (* (volatile uint16_t *) (0xFFFA64) )
#define CSOR6 (* (volatile uint16_t *) (0xFFFA66) )
#define CSBAR7 (* (volatile uint16_t *) (0xFFFA68) )
#define CSOR7 (* (volatile uint16_t *) (0xFFFA6A) )
#define CSBAR8 (* (volatile uint16_t *) (0xFFFA6C) )
#define CSOR8 (* (volatile uint16_t *) (0xFFFA6E) )
#define CSBAR9 (* (volatile uint16_t *) (0xFFFA70) )
#define CSOR9 (* (volatile uint16_t *) (0xFFFA72) )
#define CSBAR10 (* (volatile uint16_t *) (0xFFFA74) )
#define CSOR10 (* (volatile uint16_t *) (0xFFFA76) )

#define QSMCR (* (volatile uint16_t *) (0xFFFC00) )
#define QILR (* (volatile uint16_t *) (0xFFFC04) )

#define SCCR0 (* (volatile uint16_t *) (0xFFFC08) )
#define SCCR1 (* (volatile uint16_t *) (0xFFFC0A) )
#define SCSR  (* (volatile uint16_t *) (0xFFFC0C) )

#define SCDR  (* (volatile char *) (0xFFFC0F) )

#define PORTQS (* (volatile uint16_t *) (0xFFFC14) )
#define PQSPAR (* (volatile uint16_t *) (0xFFFC16) )
#define SPCR0 (* (volatile uint16_t *) (0xFFFC18) )
#define SPCR1 (* (volatile uint16_t *) (0xFFFC1A) )
#define SPCR2 (* (volatile uint16_t *) (0xFFFC1C) )
#define SPCR3 (* (volatile uint16_t *) (0xFFFC1E) )

#define CR0 (* (volatile uint16_t *) (0xFFFD40) )
#define CR1 (* (volatile uint16_t *) (0xFFFD42) )
#define CR2 (* (volatile uint16_t *) (0xFFFD44) )
#define CR3 (* (volatile uint16_t *) (0xFFFD46) )
#define CR4 (* (volatile uint16_t *) (0xFFFD48) )
#define CR5 (* (volatile uint16_t *) (0xFFFD4A) )
#define CR6 (* (volatile uint16_t *) (0xFFFD4C) )
#define CR7 (* (volatile uint16_t *) (0xFFFD4E) )

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
    while ((SCSR & 1) == 0)
        ;
    SCDR = c;
}

int main(void)
{
    SIMCR = 0x40c5;
    SYPCR = 0x4c;
    SYNCR = 0x7f05;
    CSORBT = 0x6c70;

    CSPAR0 = 0x3fff;
    
    CSBAR5 = 0xfff8;
    CSBAR6 = 0x8000;
    CSBAR8 = 0x8000;
    CSBAR9 = 0x8000;
    CSBAR10 = 0x8000;
    CSOR5 = 0x2bca;
    CSOR6 = 0x2fc4;

    CSOR8 = 0x2ff0;
    CSOR9 = 0x7bf0;
    CSOR10 = 0x37f0;
    PORTE0 = 0;
    PORTE1 = 0;
    PORTF0 = 0;
    PORTF1 = 0;
    DDRE = 0xf8;
    DDRF = 0;
    PEPAR = 0xff;
    PFPAR = 0x60;
    PICR = 0xf;
    PITR = 0;
    QSMCR = 0x8a;
    QILR = 0x550;
    PORTQS = 0;
    PQSPAR = 0x82;
    CR0 = 0;
    CR1 = 0;
    CR2 = 0;
    CR3 = 0;
    CR4 = 0;
    CR5 = 0;
    CR6 = 0;
    CR7 = 0;
    SPCR0 = 0x104;
    SPCR2 = 0;
    SPCR3 = 0;
    SPCR1 = 0x404;
    SCCR0 = 9;
    SCCR1 = 0x2c;

    main_loop();

    return 0;
}
