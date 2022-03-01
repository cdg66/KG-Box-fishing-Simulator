#include "Test.h"
// test les fonctions tel que alumer un sgement 
void test_unitaire(void)
{
    //Init
    Serial.begin(9600);               // Initialisation de la communication serielle

    //init 7 seg
    pinMode(sA1, OUTPUT);
    digitalWrite(sA1, !SEGON );
    pinMode(B1, OUTPUT);
    digitalWrite(B1, !SEGON );
    pinMode(C1, OUTPUT);
    digitalWrite(C1, !SEGON );
    pinMode(D1, OUTPUT);
    digitalWrite(D1, !SEGON );
    pinMode(E1, OUTPUT);
    digitalWrite(E1, !SEGON );
    pinMode(F1, OUTPUT);
    digitalWrite(F1, !SEGON );
    pinMode(G1, OUTPUT);
    digitalWrite(G1, !SEGON );
    pinMode(sA2, OUTPUT);
    digitalWrite(sA2, !SEGON );
    pinMode(B2, OUTPUT);
    digitalWrite(B2, !SEGON );
    pinMode(C2, OUTPUT);
    digitalWrite(C2, !SEGON );
    pinMode(D2, OUTPUT);
    digitalWrite(D2, !SEGON );
    pinMode(E2, OUTPUT);
    digitalWrite(E2, !SEGON );
    pinMode(F2, OUTPUT);
    digitalWrite(F2, !SEGON );
    pinMode(G2, OUTPUT);
    digitalWrite(G2, !SEGON );

    // init bouton
    pinMode(BTN1, INPUT);
    pinMode(BTN2, INPUT);
    pinMode(BTN3, INPUT);
    pinMode(BTN4, INPUT);
    pinMode(JSTICK_BTN, INPUT);

    // init moteur
    pinMode(MOTEUR, INPUT);
    // Test

    //Test segements
    
    digitalWrite(sA1, SEGON );
    delay(1000);
    digitalWrite(sA1, !SEGON );

    digitalWrite(B1, SEGON );
    delay(1000);
    digitalWrite(B1, !SEGON );

    digitalWrite(C1, SEGON );
    delay(1000);
    digitalWrite(C1, !SEGON );

    digitalWrite(D1, SEGON );
    delay(1000);
    digitalWrite(D1, !SEGON );

    digitalWrite(E1, SEGON );
    delay(1000);
    digitalWrite(E1, !SEGON );

    digitalWrite(F1, SEGON );
    delay(1000);
    digitalWrite(F1, !SEGON );

    digitalWrite(G1, SEGON );
    delay(1000);
    digitalWrite(G1, !SEGON );

    digitalWrite(sA2, SEGON );
    delay(1000);
    digitalWrite(sA2, !SEGON );

    digitalWrite(B2, SEGON );
    delay(1000);
    digitalWrite(B2, !SEGON );

    digitalWrite(C2, SEGON );
    delay(1000);
    digitalWrite(C2, !SEGON );

    digitalWrite(D2, SEGON );
    delay(1000);
    digitalWrite(D2, !SEGON );

    digitalWrite(E2, SEGON );
    delay(1000);
    digitalWrite(E2, !SEGON );

    digitalWrite(F2, SEGON );
    delay(1000);
    digitalWrite(F2, !SEGON );

    digitalWrite(G2, SEGON );
    delay(1000);
    digitalWrite(G2, !SEGON );

    // alume tout les segements
    digitalWrite(sA1, SEGON );
    digitalWrite(B1, SEGON );
    digitalWrite(C1, SEGON );
    digitalWrite(D1, SEGON );
    digitalWrite(E1, SEGON );
    digitalWrite(F1, SEGON );
    digitalWrite(G1, SEGON );
    digitalWrite(sA2, SEGON );
    digitalWrite(B2, SEGON );
    digitalWrite(C2, SEGON );
    digitalWrite(D2, SEGON );
    digitalWrite(E2, SEGON );
    digitalWrite(F2, SEGON );
    digitalWrite(G2, SEGON );
    delay(1000);
    digitalWrite(sA1, !SEGON );
    delay(1000);
    digitalWrite(B1, !SEGON );
    delay(1000);
    digitalWrite(C1, !SEGON );
    delay(1000);
    digitalWrite(D1, !SEGON );
    delay(1000);
    digitalWrite(E1, !SEGON );
    delay(1000);
    digitalWrite(F1, !SEGON );
    delay(1000);
    digitalWrite(G1, !SEGON );
    delay(1000);
    digitalWrite(sA2, !SEGON );
    delay(1000);
    digitalWrite(B2, !SEGON );
    delay(1000);
    digitalWrite(C2, !SEGON ); 
    delay(1000);
    digitalWrite(D2, !SEGON );
    delay(1000);
    digitalWrite(E2, !SEGON );
    delay(1000);
    digitalWrite(F2, !SEGON );
    delay(1000);
    digitalWrite(G2, !SEGON );


    // test acc
    int AccX; 
    int AccY; 
    int AccZ;
    int i;
    Serial.print("test Accelerometre bouger le\n");
    for (i = 0; i<2;i++)
    {
        AccX = analogRead(ACC_X);
        AccY = analogRead(ACC_Y);
        AccZ = analogRead(ACC_Z);
        Serial.print("X:");
        Serial.print(AccX);
        Serial.print(", Y:");
        Serial.print(AccY);
        Serial.print(", Z:");
        Serial.print(AccZ);
        Serial.print("\n");
        delay(500);
    }

    // test jstick
    Serial.print("test joystick bouger le\n");
    for (i = 0; i<2;i++)
    {
        AccX = analogRead(JSTICK_A1);
        AccY = analogRead(JSTICK_A2);
        Serial.print("X:");
        Serial.print(AccX);
        Serial.print(", Y:");
        Serial.print(AccY);
        Serial.print("\n");
        delay(500);
    }


    // test boutons
    Serial.print("waiting for Bouton 1\n");
    while( digitalRead(BTN1) != BTNON);
    Serial.print("Bouton 1 pressed\n");

    Serial.print("waiting for Bouton 2\n");
    while( digitalRead(BTN2) != BTNON);
    Serial.print("Bouton 2 pressed\n");

    Serial.print("waiting for Bouton 3\n");
    while( digitalRead(BTN3) != BTNON);
    Serial.print("Bouton 3 pressed\n");

    Serial.print("waiting for Bouton 4\n");
    while( digitalRead(BTN4) != BTNON);
    Serial.print("Bouton 4 pressed\n");

    Serial.print("waiting for Bouton Jstick\n");
    while( digitalRead(JSTICK_BTN) != BTNON);
    Serial.print("Bouton Jstick pressed\n");
    
    Serial.print("Fin du test\n");
}

// test les fonctions tel que afficher 7 sur le display // test de la lib encodeur
void test_fonctionalite(void)
{
    
}