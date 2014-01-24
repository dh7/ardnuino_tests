/*
Simple test using led matrix : random partern
inspire from code from "message"
 */
 
byte col = 0;
byte leds[8][8];

// pin[xx] on led matrix connected to nn on Arduino (-1 is dummy to make array start at pos 1)
int pins[17]= {
  -1, 17, 8, 7, 19, 9, 13, 4, 10, 6, 5, 18, 3, 2, 11, 12, 16};

// col[xx] of leds = pin yy on led matrix
int cols[8] = {
  pins[13], pins[3], pins[4], pins[10], pins[06], pins[11], pins[15], pins[16]};

int rows[8] = {
  pins[9], pins[14], pins[8], pins[12], pins[1], pins[7], pins[2], pins[5]};


void setup() {
  // sets the pins as output
  for (int i = 1; i <= 16; i++) {
    pinMode(pins[i], OUTPUT);
  }

  // set up cols and rows
  for (int i = 1; i <= 8; i++) {
    digitalWrite(cols[i - 1], LOW);
  }

  for (int i = 1; i <= 8; i++) {
    digitalWrite(rows[i - 1], LOW);
  }

 clearLeds();
}

void loop() {
  randomOneLeds();
  for (int i=0;i<1;i++) {
    display();
  }
}

void clearLeds() {
  // Clear display array
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      leds[i][j] = 0;
    }
  }
}

void lightsLeds() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      leds[i][j] = 1;
    }
  }
}

void randomAllLeds() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (random(10)<5) {
        leds[i][j]=0;
      } else {
        leds[i][j]=1;
      }
    }
  }
}

void randomOneLeds() {
  int x = (int)random(8);
  int y = (int)random(8);
  if (random(10)<5) {
    leds[x][y]=0;
  } else {
    leds[x][y]=1;
  }
}

void display() {
  digitalWrite(cols[col], LOW);  // Turn whole previous column off
  col++;
  if (col == 8) {
    col = 0;
  }
  for (int row = 0; row < 8; row++) {
    //    if (leds[col][7 - row] == 1) {
    if (leds[col][ row] == 1) {
      digitalWrite(rows[row], LOW);  // Turn on this led
    }
    else {
      digitalWrite(rows[row], HIGH); // Turn off this led
    }
  }
  digitalWrite(cols[col], HIGH); // Turn whole column on at once (for equal lighting times)*/
}

