

#include <SoftwareSerial.h>
#include <DFMiniMp3.h>

// implement a notification class,
// its member methods will get called
//
class Mp3Notify
{
  public:
    static void PrintlnSourceAction(DfMp3_PlaySources source, const char* action)
    {
      if (source & DfMp3_PlaySources_Sd)
      {
        Serial.print("SD Card, ");
      }
      if (source & DfMp3_PlaySources_Usb)
      {
        Serial.print("USB Disk, ");
      }
      if (source & DfMp3_PlaySources_Flash)
      {
        Serial.print("Flash, ");
      }
      Serial.println(action);
    }
    static void OnError(uint16_t errorCode)
    {
      // see DfMp3_Error for code meaning
      Serial.println();
      Serial.print("Com Error ");
      Serial.println(errorCode);
    }
    static void OnPlayFinished(DfMp3_PlaySources source, uint16_t track)
    {
      Serial.print("Play finished for #");
      Serial.println(track);
    }
    static void OnPlaySourceOnline(DfMp3_PlaySources source)
    {
      PrintlnSourceAction(source, "online");
    }
    static void OnPlaySourceInserted(DfMp3_PlaySources source)
    {
      PrintlnSourceAction(source, "inserted");
    }
    static void OnPlaySourceRemoved(DfMp3_PlaySources source)
    {
      PrintlnSourceAction(source, "removed");
    }
};

// instance a DFMiniMp3 object,
// defined with the above notification class and the hardware serial class
//DFMiniMp3<HardwareSerial, Mp3Notify> mp3(Serial1);

// Some arduino boards only have one hardware serial port, so a software serial port is needed instead.
// comment out the above definition and uncomment these lines
SoftwareSerial secondarySerial(9, 8 ); // RX, TX
DFMiniMp3<SoftwareSerial, Mp3Notify> mp3(secondarySerial);
int botones[] = {2, 3, 4, 5, 6, 12};
int vol_prev;
void setup()
{

  for (int i = 0; i < 6; i++) {
    pinMode(botones[i], INPUT_PULLUP);
  }
  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);

  mp3.begin();
  Serial.begin(9600);

  uint16_t volume = mp3.getVolume();

  mp3.setVolume(20);

  uint16_t count = mp3.getTotalTrackCount(DfMp3_PlaySource_Sd);

}

void waitMilliseconds(uint16_t msWait)
{
  uint32_t start = millis();

  while ((millis() - start) < msWait)
  {
    // calling mp3.loop() periodically allows for notifications
    // to be handled without interrupts
    mp3.loop();
    delay(1);
  }
}

void loop()
{
int vol=analogRead(A0);
vol=map(vol,0,1023,35,0);
if(vol!=vol_prev){
  vol_prev=vol;
  mp3.begin();
  mp3.pause();
  mp3.setVolume(vol);
  mp3.start();
}
  if (!digitalRead(botones[0])) {
    mp3.begin();
    mp3.setVolume(vol);
    mp3.loopGlobalTrack(1);


  }


  else if (!digitalRead(botones[1])) {
    mp3.begin();
    mp3.setVolume(vol);
    mp3.loopGlobalTrack(2);

  }

  else if (!digitalRead(botones[2])) {
    mp3.begin();
    mp3.setVolume(vol);
    mp3.loopGlobalTrack(3);


  }

  else if (!digitalRead(botones[3])) {
    mp3.begin();
    mp3.setVolume(vol);
    mp3.loopGlobalTrack(4);

  }

  else if (!digitalRead(botones[4])) {
    mp3.begin();
    mp3.setVolume(vol);
    mp3.loopGlobalTrack(5);

  }

  else if (!digitalRead(botones[5])) {
    mp3.begin();
    mp3.setVolume(vol);
    mp3.loopGlobalTrack(6);

  }
  digitalWrite(8, 0);
  delay(1);
}
