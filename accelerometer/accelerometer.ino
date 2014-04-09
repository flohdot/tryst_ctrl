int xAcc;
int yAcc;
int zAcc;

int xPrev;
int yPrev;
int zPrev;

/* zero values as determined w/ code below */
int xStart = 396;
int yStart = 321;
int zStart = 363;

int trigger= 5;


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
 // //wait
//

  // diff = abs(xPrev-xAcc);

  // /* inspect raw values */
//   Serial.print("xAcc ");
//   Serial.println(xStart-xAcc);
//  Serial.print("yAcc ");
//   Serial.println(yStart-yAcc);
//   Serial.print("zAcc ");
//   Serial.println(zStart-zAcc);

//   Serial.print("DIFF IS ");
//   Serial.println(diff);
//   delay(1000);//wait

   /* end */

  /* set a random sensitivity for testing */
  // if (diff > 40) {
  //   Serial.println(1);
  //   xPrev = xAcc;
  // } else {
  //   Serial.println(0);
  // }

// south -45 y axis
// east-45 
// north +45 y axis
// west +45


   int current = 0;
   if (yStart-yAcc < -40) {
     current = 1; //east
   } 
   if (yStart-yAcc > 30) {
     current = 2; //west
   } 
   if (zStart-zAcc < -25) {
     current = 3; //south
   } 
   if (zStart-zAcc > 60) {
     current = 4; //north
   } 

   Serial.println(current);
  
   delay(1000);//wait

}

