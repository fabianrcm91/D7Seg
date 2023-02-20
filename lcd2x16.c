
#include "lcd2x16.h"



//D4 - P3.0
//D5 - P3.1
//D6 - P3.2
//D7 - P3.3
//EN - P3.7
//RS - P3.5

#define LCD_EN      0x80
#define LCD_RS      0x20

void lcd2x16Init(void){
    P3DIR |= 3;//(BIT1 + BIT0);0b00000011
    P2DIR |= 0x0F;//0b00001111
    //LCD RESET
    lcd2x16Port(0xFF);
    __delay_cycles(20000);
    lcd2x16Port(0x03+LCD_EN);
    lcd2x16Port(0x03);
    __delay_cycles(10000);
    lcd2x16Port(0x03+LCD_EN);
    lcd2x16Port(0x03);
    __delay_cycles(1000);
    lcd2x16Port(0x03+LCD_EN);
    lcd2x16Port(0x03);
    __delay_cycles(1000);
    lcd2x16Port(0x02+LCD_EN);
    lcd2x16Port(0x02);
    __delay_cycles(1000);

    //LCDINIT
    lcd2x16Cmd(0x28);       // 4-bit mode - 2 line - 5x7 font.
    lcd2x16Cmd(0x0C);       // Display no cursor - no blink.
    lcd2x16Cmd(0x06);       // Automatic Increment - No Display shift.
    lcd2x16Cmd(0x80);       // Address DDRAM with 0 offset 80h.
}


void lcd2x16Port(uint8_t lcd_port){
    if (lcd_port & BIT0 ) {
        LCD_2x16_D4 |= LCD_2x16_D4_BIT;
    }else{
        LCD_2x16_D4 &= ~LCD_2x16_D4_BIT;
    }
    if (lcd_port & BIT1 ) {
        LCD_2x16_D5 |= LCD_2x16_D5_BIT;
    }else{
        LCD_2x16_D5 &= ~LCD_2x16_D5_BIT;
    }
    if (lcd_port & BIT2) {
        LCD_2x16_D6 |= LCD_2x16_D6_BIT;
    }else{
        LCD_2x16_D6 &= ~LCD_2x16_D6_BIT;
    }
    if (lcd_port & BIT3 ) {
        LCD_2x16_D7 |= LCD_2x16_D7_BIT;
    }else{
        LCD_2x16_D7 &= ~LCD_2x16_D7_BIT;
    }
    if (lcd_port & BIT5 ) {
        LCD_2x16_RS |= LCD_2x16_RS_BIT;
    }else{
        LCD_2x16_RS &= ~LCD_2x16_RS_BIT;
    }
    if (lcd_port & BIT7 ) {
        LCD_2x16_EN |= LCD_2x16_EN_BIT;
    }else{
        LCD_2x16_EN &= ~LCD_2x16_EN_BIT;
    }
}


void lcd2x16Cmd(uint8_t cmd){
    lcd2x16Port(((cmd >> 4) & 0x0F)|LCD_EN);
    lcd2x16Port((cmd >> 4) & 0x0F);
    lcd2x16Port((cmd & 0x0F)|LCD_EN);
    lcd2x16Port(cmd & 0x0F);
    __delay_cycles(400);
}
void lcd2x16Data(uint8_t dat){
    lcd2x16Port(((dat >> 4) & 0x0F)|LCD_EN|LCD_RS);
    lcd2x16Port(((dat >> 4) & 0x0F)|LCD_RS);
    lcd2x16Port((dat & 0x0F)|LCD_EN|LCD_RS);
    lcd2x16Port((dat & 0x0F)|LCD_RS);
    __delay_cycles(400);

}

