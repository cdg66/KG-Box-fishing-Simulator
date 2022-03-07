#ifndef SEPT_SEGEMENT_H
#define SEPT_SEGEMENT_H

#include <Arduino.h>

class SeptSegement
{
private:
    /* data */
    //enum SegmentPlace: int{A = 0, B, C, D, E, F, G};
    uint8_t Segement[7];
    uint8_t SegOn;
    // retourne un tableau[7] disant quel segement a alumer
    void BCDToSeptSeg(uint8_t *Seg, uint8_t BCD);
public:
    // si number == 10 le sept seg est init wiht all off
    SeptSegement(uint8_t A,uint8_t B,uint8_t C,uint8_t D,uint8_t E,uint8_t F,uint8_t G, uint8_t number,uint8_t OnState );
    ~SeptSegement();
    // ecrit le chifre sur le sept seg prend un chifre binaire de 0 a 9 le reste des bits est ignoree
    void write(uint8_t number);
    // eteint tout les segement
    void off();
};

void SeptSegement::BCDToSeptSeg(uint8_t *Seg, uint8_t BCD)
{
    uint8_t ValOFF;
    uint8_t ValON;
    if (SegOn == 0 )
    {
        ValOFF = 1;
        ValON = 0;
    }
    else
    {
        ValOFF = 0;
        ValON = 1;
    }
    BCD = BCD & 0x0F;
    //Serial.print(BCD);
    // clear buffer with off state
    for (int i =0; i > 7;i++)
    {
        Seg[i] = ValOFF;
    }
    switch (BCD)
    {
    case 0:
        //Serial.print("Case 0");
        Seg[0] = ValON;
        Seg[1] = ValON;
        Seg[2] = ValON;
        Seg[3] = ValON;
        Seg[4] = ValON;
        Seg[5] = ValON;
        break;
    case 1:
        //Serial.print("Case 1");
        Seg[1] = ValON;
        Seg[2] = ValON;
        break;
    case 2:
        //Serial.print("Case 2");
        Seg[0] = ValON;
        Seg[1] = ValON;
        Seg[6] = ValON;
        Seg[4] = ValON;
        Seg[3] = ValON;
        break;
    case 3:
        //Serial.print("Case 3");
        Seg[0] = ValON;
        Seg[1] = ValON;
        Seg[6] = ValON;
        Seg[2] = ValON;
        Seg[3] = ValON;
        break;
    case 4:
        //Serial.print("Case 4");
        Seg[5] = ValON;
        Seg[6] = ValON;
        Seg[1] = ValON;
        Seg[2] = ValON;
        break;
    case 5:
        //Serial.print("Case 5");
        Seg[0] = ValON;
        Seg[5] = ValON;
        Seg[6] = ValON;
        Seg[2] = ValON;
        Seg[3] = ValON;
        break;
    case 6:
        //Serial.print("Case 6");
        Seg[0] = ValON;
        Seg[5] = ValON;
        Seg[4] = ValON;
        Seg[3] = ValON;
        Seg[2] = ValON;
        Seg[6] = ValON;
        break;
    case 7:
        //Serial.print("Case 7");
        Seg[0] = ValON;
        Seg[1] = ValON;
        Seg[2] = ValON;
        break;
    case 8:
        //Serial.print("Case 8");
        Seg[0] = ValON;
        Seg[1] = ValON;
        Seg[2] = ValON;
        Seg[3] = ValON;
        Seg[4] = ValON;
        Seg[5] = ValON;
        Seg[6] = ValON;
        break;
    case 9:
        //Serial.print("Case 9");
        Seg[0] = ValON;
        Seg[1] = ValON;
        Seg[3] = ValON;
        Seg[2] = ValON;
        Seg[5] = ValON;
        Seg[6] = ValON;
        break;
    
    default:
        break;
    }
    //for (int i = 0; i< 7; i++)
    //{
    //    Serial.print(Seg[i]);
    //}
    //Serial.print("\n");
}

SeptSegement::SeptSegement(uint8_t A,uint8_t B,uint8_t C,uint8_t D,uint8_t E,uint8_t F,uint8_t G, uint8_t number, uint8_t OnState )
{
    if (OnState == 0)
    {
        SegOn = 0;
    }
    else 
    {
        SegOn = 1;
    }
    //Serial.print(SegOn);
    pinMode(A, OUTPUT);
    digitalWrite(A, !SegOn );
    pinMode(B, OUTPUT);
    digitalWrite(B, !SegOn );
    pinMode(C, OUTPUT);
    digitalWrite(C, !SegOn );
    pinMode(D, OUTPUT);
    digitalWrite(D, !SegOn );
    pinMode(E, OUTPUT);
    digitalWrite(E, !SegOn );
    pinMode(F, OUTPUT);
    digitalWrite(F, !SegOn );
    pinMode(G, OUTPUT);
    digitalWrite(G, !SegOn );

    Segement[0] = A;
    Segement[1] = B;
    Segement[2] = C;
    Segement[3] = D;
    Segement[4] = E;
    Segement[5] = F;
    Segement[6] = G;
    
    if (number < 10 )
    {
        write(number);
    } 
}

SeptSegement::~SeptSegement()
{
    off();
}

void SeptSegement::write(uint8_t number)
{
    uint8_t seg[7] = {1,1,1,1,1,1,1};

    BCDToSeptSeg(seg, number);
    for (int i = 0; i < 7; i++)
    {
        digitalWrite(Segement[i], seg[i] );
    } 
}

void SeptSegement::off()
{
    for (int i = 0; i < 7; i++)
    {
        digitalWrite(Segement[i],  !SegOn );
    } 
}
#endif