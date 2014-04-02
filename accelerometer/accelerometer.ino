int xAcc;
int yAcc;
int zAcc;

int xPrev;
int yPrev;
int zPrev;

/* zero values as determined w/ code below */
int xStart = 330;
int yStart = 326;
int zStart = 403;

int diff;


void setup() {
  Serial.begin(9600);//set up serial
}

void loop() {

  //read values
  xAcc = analogRead(A0);
  yAcc = analogRead(A1);
  zAcc = analogRead(A2);
  xPrev = xStart;


  /*  print zero point when lying flat */
 // Serial.print("xAcc ");
 // Serial.println(xAcc);
 // Serial.print("yAcc ");
 // Serial.println(yAcc);
 // Serial.print("zAcc ");
 // Serial.println(zAcc);
 // Serial.println(" ");
 // delay(500);//wait
//

  diff = abs(xPrev-xAcc);

  // /* inspect */
   // Serial.print("xAcc ");
   // Serial.println(xStart-xAcc);
   // Serial.print("yAcc ");
   // Serial.println(yStart-yAcc);
   // Serial.print("zAcc ");
   // Serial.println(zStart-zAcc);

   // Serial.print("DIFF IS ");
   // Serial.println(diff);
   // delay(2000);//wait

  /* set a random sensitivity for testing */
  if (diff > 40) {
    Serial.println(1);
    xPrev = xAcc;
  } else {
    Serial.println(0);
  }

}

