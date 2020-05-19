 #include <LiquidCrystal.h>
int val;
LiquidCrystal lcd(53, 52, 50, 51, 48, 49);//pins of lcd (RS, E, D4, D5, D6, D7)
 const int speakerPin = 2;
int length = 28; 

char notes[] = "GGAGcB GGAGdc GGxecBA yyecdc";
int beats[] = { 2, 2, 8, 8, 8, 16, 1, 2, 2, 8, 8,8, 16, 1, 2,2,8,8,8,8,16, 1,2,2,8,8,8,16 };
int tempo = 150;

void playTone(int tone, int duration)
{
    for (long i = 0; i < duration * 1000L; i += tone * 2) 
       {   
           digitalWrite(speakerPin, HIGH);
           delayMicroseconds(tone);
           digitalWrite(speakerPin, LOW);
           delayMicroseconds(tone);
        }
   }
void playNote(char note, int duration) {
char names[] = {'C', 'D', 'E', 'F', 'G', 'A', 'B',          
                 'c', 'd', 'e', 'f', 'g', 'a', 'b',
                 'x', 'y' };

int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014,
                 956,  834,  765,  593,  468,  346,  224,
                655 , 715 };

int SPEE = 5;



for (int i = 0; i < 17; i++) 
{
   if (names[i] == note) 
    {
         int newduration = duration/SPEE;
         playTone(tones[i], newduration);
    }
}
}
void setup() {
    Serial.begin(9600);
    lcd.begin(16, 2);
    pinMode(9,INPUT_PULLUP);
    pinMode(speakerPin, OUTPUT);
}





void loop() {
  val=digitalRead(9);
  if (val==1){
    lcd.clear();
    lcd.print(" Happy Birthday");
    lcd.setCursor(0,1);
    delay(400);
    lcd.print("     CHITTY");
    

for (int i = 0; i < length; i++) {
  
   if (notes[i] == ' ') {
     delay(beats[i] * tempo); 
   }
    
    else {
     playNote(notes[i], beats[i] * tempo);
    }
    delay(tempo);
   
}
for (int i = 0; i < length; i++) {
  
   if (notes[i] == ' ') {
     delay(beats[i] * tempo); 
   }
    
    else {
     playNote(notes[i], beats[i] * tempo);
    }
    delay(tempo);
   
   }
 }


}
