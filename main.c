/* **********************************************************
 * Nom du projet : bargraphe.c
 * fichier: bargraphe.c
 * Auteur: M.Le Fur, 21/11/2022.
 * Description: Augmentation du niveau en fonction d'une variable "Niveau"
 * NOTES:
************************************************************************/

// Variables
#define LD11 LATD.F4
#define LD10 LATD.F5
#define LD9  LATD.F2
#define LD8  LATD.F7
#define LD7  LATD.F6
#define LD6  LATD.F5
#define LD5  LATD.F4
#define LD4  LATD.F3
#define LD3  LATD.F2
#define LD2  LATD.F1
#define LD1  LATD.F0
unsigned char Niveau;
// Switch_Boolean = false;

// Main
void main()
{
 OSCTUNE=0X00; OSCCON=0X72; ADCON1=0x0F;
 TRISA= 0b1110111; TRISC= 0b10011101; TRISD= 0x00; TRISE= 0x00; PORTA=0b11101111;
 
 while (1)
 {
   for (Niveau = 0; Niveau < 110; Niveau++)
   {
     Affiche_Niveau(Niveau);
     Wait(10);
   }
   for(Niveau = 110; Niveau > 0; Niveau--)
   {
     Affiche_Niveau(Niveau);
     Wait(10);
   }
 }
}

// Functions
void Affiche_Niveau (unsigned char Valeur)
{
 /*
   if (Switch_Boolean) {
     switch(Valeur) {
         case Valeur >= 10 & Valeur < 20:
              LD10 = 1;
         case Valeur >= 20 & Valeur < 30:
              LD9 = 1; LD10 = 1;
         case Valeur >= 30 & Valeur < 40:
              LD8 = 1; LD9 = 1; LD10 = 1;
         case Valeur >= 40 & Valeur < 50:
              LD7= 1; LD8 = 1; LD9 = 1; LD10 = 1;
         default:
              LATD = 0x00; LD9 = 0; LD10 = 0;
     }
   else {
*/
     LATD = 0x00; LD9 = 0; LD10 = 0;
   
     if(Valeur >= 10 & Valeur<20) LD10 = 1; // juste D10 allumée
     if (Valeur >= 20 & Valeur <30) { LD9 = 1; LD10 = 1; } // D9 et D10 allumées
     if (Valeur >= 30 & Valeur < 40) {LD8 = 1; LD9 = 1; LD10 = 1;}
     if (Valeur >= 40 & Valeur < 50) {LD7 = 1; LD8= 1; LD9 = 1; LD10 = 1;}
     if (Valeur >= 50 & Valeur < 60) {LD6 = 1;LD7 = 1; LD8= 1; LD9 = 1; LD10 = 1;}
     if (Valeur >= 60 & Valeur < 70) {LD5 = 1; LD6 = 1;LD7 = 1; LD8= 1; LD9 = 1; LD10 = 1;}
     if (Valeur >= 70 & Valeur < 80) {LD4= 1;LD5 = 1; LD6 = 1;LD7 = 1; LD8= 1; LD9 = 1; LD10 = 1;}
     if (Valeur >= 80 & Valeur < 90) {LD3 = 1;LD4= 1;LD5 = 1; LD6 = 1;LD7 = 1; LD8= 1; LD9 = 1; LD10 = 1;}
     if (Valeur >= 90 & Valeur < 100) {LD2= 1; LD3 = 1;LD4= 1;LD5 = 1; LD6 = 1;LD7 = 1; LD8= 1; LD9 = 1; LD10 = 1;}
     if (Valeur => 100) {LD1 = 1; LD2 = 1;LD4= 1;LD5 = 1; LD6 = 1;LD7 = 1; LD8= 1; LD9 = 1; LD10 = 1; }

   // }
}
