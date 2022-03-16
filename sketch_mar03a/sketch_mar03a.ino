void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("Let's provoke the s/w wdt firing...");
  //
  // provoke an OOM, will be recorded as the last occurred one
  char* out_of_memory_failure = (char*)malloc(1000000);
  //
  // wait for s/w wdt in infinite loop below
  while(true);
  //
  Serial.println("This line will not ever print out");
}

void loop(){}
