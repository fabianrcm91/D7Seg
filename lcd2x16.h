#include <msp430.h>
#include <stdint.h>


#define LCD_2x16_EN   P3OUT
#define LCD_2x16_RS  P3OUT
#define LCD_2x16_D4  P2OUT
#define LCD_2x16_D5  P2OUT
#define LCD_2x16_D6  P2OUT
#define LCD_2x16_D7  P2OUT

#define LCD_2x16_EN_BIT   BIT1
#define LCD_2x16_RS_BIT  BIT0
#define LCD_2x16_D4_BIT  BIT3
#define LCD_2x16_D5_BIT  BIT1
#define LCD_2x16_D6_BIT  BIT2
#define LCD_2x16_D7_BIT  BIT0




void lcd2x16Init(void);
void lcd2x16Cmd(uint8_t cmd);
void lcd2x16Data(uint8_t dat);
void lcd2x16Port(uint8_t lcd_port);


