#ifndef SEPT_SEGEMENT_H
#define SEPT_SEGEMENT_H

#include <Arduino.h>

class SeptSegement
{
private:
    /* data */
    enum SegmentPlace: int{A, B, C, D, E, F, G};
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
    BCD = BCD & 0xF0;
    // clear buffer with off state
    for (int i =0; i > 7;i++)
    {
        Seg[i] = !SegOn;
    }
    switch (BCD)
    {
    case 1:
        Seg[SegmentPlace::B] = SegOn;
        Seg[SegmentPlace::C] = SegOn;
        break;
    case 2:
        Seg[SegmentPlace::A] = SegOn;
        Seg[SegmentPlace::B] = SegOn;
        Seg[SegmentPlace::G] = SegOn;
        Seg[SegmentPlace::E] = SegOn;
        Seg[SegmentPlace::D] = SegOn;
        break;
    case 3:
        /* code */
        break;
    case 4:
        /* code */
        break;
    case 5:
        /* code */
        break;
    case 6:
        /* code */
        break;
    case 7:
        /* code */
        break;
    case 8:
        /* code */
        break;
    case 9:
        /* code */
        break;
    
    default:
        break;
    }
}

SeptSegement::SeptSegement(uint8_t A,uint8_t B,uint8_t C,uint8_t D,uint8_t E,uint8_t F,uint8_t G, uint8_t number, uint8_t OnState )
{
    SegOn = OnState;
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
    
    if (number< 10 )
    {
        write(number);
    } 
}

SeptSegement::~SeptSegement()
{
}

void SeptSegement::write(uint8_t number)
{

}

void SeptSegement::off()
{
}
#endif