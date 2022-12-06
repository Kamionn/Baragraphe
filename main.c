/* **********************************************************
 * Nom du projet : bargraphe.c
 * fichier: bargraphe.c
 * Auteur: M.Le Fur, 21/11/2022.
 * Description: Augmentation du niveau en fonction d'une variable "Niveau"
 * NOTES:
************************************************************************/

// Variables
#define LD11 LATA.F4
#define LD10 LATC.F5
#define LD9  LATE.F2
#define LD8  LATD.F7
#define LD7  LATD.F6
#define LD6  LATD.F5
#define LD5  LATD.F4
#define LD4  LATD.F3
#define LD3  LATD.F2
#define LD2  LATD.F1
#define LD1  LATD.F0
#define Wait delay_ms
unsigned char Niveau;
unsigned char  Cent; 
unsigned char  Diz; 
unsigned char  Unite;
unsigned char  Reste;

// LCD module connections
sbit LCD_RS at RC1_bit;
sbit LCD_EN at RE0_bit;
sbit LCD_D4 at RB2_bit;
sbit LCD_D5 at RB3_bit;
sbit LCD_D6 at RB4_bit;
sbit LCD_D7 at RB5_bit;

sbit LCD_RS_Direction at TRISC1_bit;
sbit LCD_EN_Direction at TRISE0_bit;
sbit LCD_D4_Direction at TRISB2_bit;
sbit LCD_D5_Direction at TRISB3_bit;
sbit LCD_D6_Direction at TRISB4_bit;
sbit LCD_D7_Direction at TRISB5_bit;
// End LCD module connections

// **************************Déclarations des SP et Fonctions ******************
void Affiche_Niveau (unsigned char Valeur);
void Affichage_Valeur (unsigned char Valeur);

// ***************************** Main ******************************************
void main()
{
 OSCTUNE=0X00; OSCCON=0X72; ADCON1=0x0F;
 TRISA= 0b1110111; TRISC= 0b10011101; TRISD= 0x00; TRISE= 0x00; PORTA=0b11101111;
 Lcd_Init();
  Lcd_Cmd(_LCD_CLEAR);
  Lcd_Cmd(_LCD_CURSOR_OFF);
  
  Lcd_Out(1,1, "Niveau :");
 while (1)
 {
   Lcd_Out(2,1, "Monte :");
   for (Niveau = 0; Niveau < 110; Niveau++)
   {
     Affichage_Valeur(Niveau);  // sur LCD
     Affiche_Niveau(Niveau);
     Wait(50);
   }
   Lcd_Out(2,1, "Baisse:");
   for(Niveau = 110; Niveau > 0; Niveau--)
   {
     Affichage_Valeur(Niveau);  // sur LCD
     Affiche_Niveau(Niveau);    // Sur Bargraphe
     Wait(50);
   }
 }
}

// Functions   *****************************************************************
void Affiche_Niveau (unsigned char Valeur)
{
     LATD = 0x00; LD9 = 0; LD10 = 0;
     if(Valeur >= 10 & Valeur<20) LD10 = 1;
     if (Valeur >= 20 & Valeur <30)   {LD9 = 1; LD10 = 1;}
     if (Valeur >= 30 & Valeur < 40)  {LD8 = 1; LD9 = 1; LD10 = 1;}
     if (Valeur >= 40 & Valeur < 50)  {LD7 = 1; LD8= 1; LD9 = 1; LD10 = 1;}
     if (Valeur >= 50 & Valeur < 60)  {LD6 = 1;LD7 = 1; LD8= 1; LD9 = 1; LD10 = 1; }
     if (Valeur >= 60 & Valeur < 70)  {LD5 = 1; LD6 = 1;LD7 = 1; LD8= 1; LD9 = 1; LD10 = 1;;}
     if (Valeur >= 70 & Valeur < 80)  {LD4= 1;LD5 = 1; LD6 = 1;LD7 = 1; LD8= 1; LD9 = 1; LD10 = 1;}
     if (Valeur >= 80 & Valeur < 90)  {LD3 = 1;LD4= 1;LD5 = 1; LD6 = 1;LD7 = 1; LD8= 1; LD9 = 1; LD10 = 1;  Wait (10);}
     if (Valeur >= 90 & Valeur < 100) { LATD = 0b11111110; LD9 = 1; LD10 = 1; }
     if (Valeur >= 100) { LD1 = 1; LD2 = 1; LD3 = 1; LD4= 1; LD5 = 1; LD6 = 1; LD7 = 1; LD8= 1; LD9 = 1; LD10 = 1; }
}

void Affichage_Valeur (unsigned char Valeur)
{
 char Chaine_ASCII[7];
 IntToStr(Valeur, Chaine_ASCII);
 Lcd_Out(2,9, Chaine_ASCII);
}
