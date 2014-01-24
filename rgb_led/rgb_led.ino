// to test a RGB led using analog control out

// Pin declaration
int redPin = 11;
int greenPin = 10;
int bluePin = 9;

// actual color
float R_value=0;
float G_value=0;
float B_value=0;

float R_increment=0;
float G_increment=0;
float B_increment=0;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
}

void loop() {
  R_value += 1;
  G_value += 1.1;
  B_value += 1.2;
  if (R_value > 255) R_value = 0;
  if (G_value > 255) G_value = 0;
  if (B_value > 255) B_value = 0;
  
  setColor((int)R_value, (int)G_value, (int)B_value);
  delay(10);
}

void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}

float new_color(float color, float* increment) {
}

toRGB: function ( ) {
      this._normalise();

      var rgb = factories.RGB();
      var i;
      var f, p, q, t;

      if( this.saturation === 0 ) {
        // achromatic (grey)
        rgb.red = this.value;
        rgb.green = this.value;
        rgb.blue = this.value;
        rgb.alpha = this.alpha;
        return rgb;
      }

      var h = this.hue / 60;                        // sector 0 to 5
      i = Math.floor( h );
      f = h - i;                        // factorial part of h
      p = this.value * ( 1 - this.saturation );
      q = this.value * ( 1 - this.saturation * f );
      t = this.value * ( 1 - this.saturation * ( 1 - f ) );

      switch( i ) {
        case 0:
          rgb.red = this.value;
          rgb.green = t;
          rgb.blue = p;
          break;
        case 1:
          rgb.red = q;
          rgb.green = this.value;
          rgb.blue = p;
          break;
        case 2:
          rgb.red = p;
          rgb.green = this.value;
          rgb.blue = t;
          break;
        case 3:
          rgb.red = p;
          rgb.green = q;
          rgb.blue = this.value;
          break;
        case 4:
          rgb.red = t;
          rgb.green = p;
          rgb.blue = this.value;
          break;
        default:                // case 5:
          rgb.red = this.value;
          rgb.green = p;
          rgb.blue = q;
          break;
      }

      rgb.alpha = this.alpha;

      return rgb;
    }
