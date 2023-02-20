#include "d7SegX3.h"

//Segmento A -> BIT0
//Segmento B -> BIT1
//Segmento C -> BIT2
//Segmento D -> BIT3
//Segmento E -> BIT4
//Segmento F -> BIT5
//Segmento G -> BIT6
//Segmento DOT -> BIT7



uint8_t d7SegVec[10] = {63,//0
                        6, //1
                        91,//2
                        79,//3
                        102,//4
                        109,//5
                        125,//6
                        7,//7
                        127,//8
                        111};

void d7SegX3Init(void){
    D7SEG_DDIR = 255;//D7SEG_DDIR = 0;
    D7SEG_SUD |= D7SEG_SUB;//D7SEG_SUD &= ~D7SEG_SUB;
    D7SEG_SDD |= D7SEG_SDB;//D7SEG_SDD &= ~D7SEG_SDB;
    D7SEG_SCD |= D7SEG_SCB;//D7SEG_SCD &= ~D7SEG_SCB;

    D7SEG_DPORT = d7SegVec[0];
    D7SEG_SUP |= D7SEG_SUB;
    D7SEG_SDP |= D7SEG_SDB;
    D7SEG_SCP |= D7SEG_SCB;

}
void d7SegX3Print(uint16_t varIn){
    uint8_t varC=varIn/100;
    uint8_t varD=(varIn%100)/10;
    uint8_t varU=varIn%10;
    d7SegX3Load(d7SegVec[varC], d7SegVec[varD], d7SegVec[varU]);

}
void d7SegX3Load(uint8_t varC,uint8_t varD,uint8_t varU){
    D7SEG_DPORT = varC;
    D7SEG_SCP &= ~D7SEG_SCB;//Activa centena
    D7SEG_SDP |= D7SEG_SDB;//Apaga decena
    D7SEG_SUP |= D7SEG_SUB;//Apaga unidades
    __delay_cycles(10000);//__delay_ms(10);
    D7SEG_DPORT = varD;
    D7SEG_SDP &= ~D7SEG_SDB;//Activa decena
    D7SEG_SCP |= D7SEG_SCB;//Apaga centena
    __delay_cycles(10000);//__delay_ms(10);
    D7SEG_DPORT = varU;
    D7SEG_SUP &= ~D7SEG_SUB;//Activa unidades
    D7SEG_SDP |= D7SEG_SDB;//Apaga decena
    __delay_cycles(10000);//__delay_ms(10);
    D7SEG_SUP |= D7SEG_SUB;//Apaga unidades

}

