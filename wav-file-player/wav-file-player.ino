//https://github.com/TMRh20/TMRpcm/wiki

//need 8-bit unsigned WAV @ 32k Hz

#include <SD.h>
#define SD_ChipSelectPin 10  //using digital pin 4 on arduino nano 328
#include <TMRpcm.h>

TMRpcm tmrpcm;
char mychar;

void setup()
{
  Serial.begin(9600);

  tmrpcm.speakerPin = 9;

  Serial.begin(9600);
  if (!SD.begin(SD_ChipSelectPin)) {  // see if the card is present and can be initialized:
    Serial.println("SD fail");  
    return;   // don't do anything more if not
  }
  
  tmrpcm.play("geese.wav");
}


void loop(void) {

}
