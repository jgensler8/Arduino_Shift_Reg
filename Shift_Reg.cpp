/*
 * AUTHOR: Jeffrey Gensler
 * DATE: 10/17/2013
 * 
 *    USING THE SHIFT REGISTER: understanding powers of two and logic
 *
 *    The data sheet for the MM74HC595, the shift register supplied with the Arduino UNO
 *    http://datasheet.octopart.com/MM74HC595N-Fairchild-datasheet-12735.pdf
 *
 */

const int analogInPin = 0;
const int data = 4;
const int latch = 3;
const int clock = 2;

/*
 * USE THIS TO SET THE DELAY TIME
 */
int delayTime;
const int tierOne = 25;
const int tierTwo = 25;

/*
 * TRY OTHER FORMS OF SUM:
 * char sum **BEWARE** ;D
 * int sum
 * unsigned int sum
 * long sum
 * unsigned long sum
 *
 * then try to change the counter limit in 'Module_1'
 */
int sum;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  Serial.println("STARTING");
  pinMode(data, OUTPUT);
  pinMode(latch, OUTPUT);
  pinMode(clock, OUTPUT);
}

void loop() {
  module_1();
  delay(2000);
  module_2();
  delay(2000);                    
}

void Serial_print_char_val( char text, int val){
 Serial.print( text); Serial.print( val);
}

void module_1(){
  Serial.print("The size of an char on this device: ");
  Serial.println(sizeof(char));
  Serial.print("The size of an int on this device: ");
  Serial.println(sizeof(int));
  Serial.print("The size of an unsigned int on this device: ");
  Serial.println(sizeof(unsigned int));
  Serial.print("The size of an long int on this device: ");
  Serial.println(sizeof(long int));
  Serial.print("The size of an unsigned long int on this device: ");
  Serial.println(sizeof(unsigned long int));
  
  for( int counter = 0; counter < 16; counter += 4){
    Serial_print_char_val(' ', pow( 2, counter) );
    Serial_print_char_val(' ', pow( 2, counter+1) );
    Serial_print_char_val(' ', pow( 2, counter+2) );
    Serial_print_char_val(' ', pow( 2, counter+3) );
    Serial.print("  :  ");
  }
  Serial.println("");
}


void shift_micro( int val){
  digitalWrite( latch, LOW);
  shiftOut( data, clock, MSBFIRST, val);
  digitalWrite( latch, HIGH);
}

void shift_by_Q(int _0, int _1, int _2, int _3, int _4, int _5, int _6, int _7, int _8){
  Serial_print_char_val(' ', _0);
  Serial_print_char_val(' ', _1);
  Serial_print_char_val(' ', _2);
  Serial_print_char_val(' ', _3);
  Serial_print_char_val(' ', _4);
  Serial_print_char_val(' ', _5);
  Serial_print_char_val(' ', _6);
  Serial_print_char_val(' ', _7);
  Serial_print_char_val(' ', _8);
  
  sum = 0;
  if( _0) sum += pow( 2, 0);
  if( _1) sum += pow( 2, 1);
  if( _2) sum += pow( 2, 2);
  if( _3) sum += pow( 2, 3);
  if( _4) sum += pow( 2, 4);
  if( _5) sum += pow( 2, 5);
  if( _6) sum += pow( 2, 6);
  if( _7) sum += pow( 2, 7);
  if( _8) sum += pow( 2, 8);
  if( sum != 0) shift_micro( sum);
  
  Serial_print_char_val(' ', sum);
  Serial.println();
}


void module_2(){
  delayTime = tierOne;
  for( int c_8 = 0; c_8 <= 1; ++c_8){
   for( int c_7 = 0; c_7 <= 1; ++c_7){
     for( int c_6 = 0; c_6 <= 1; ++c_6){
       for( int c_5 = 0; c_5 <= 1; ++c_5){
         for( int c_4 = 0; c_4 <= 1; ++c_4){
           for( int c_3 = 0; c_3 <= 1; ++c_3){
             for( int c_2 = 0; c_2 <= 1; ++c_2){
               for( int c_1 = 0; c_1 <= 1; ++c_1){
                for( int c_0 = 0; c_0 <= 1; ++c_0){
                  
                  //oscilate from low to high
                  shift_by_Q( c_0, c_1, c_2, c_3, c_4, c_5, c_6, c_7, c_8);
                  
                  //oscilate all sorts of fun!
                  //shift_by_Q( c_8, c_7, c_6, c_5, c_4, c_3, c_2, c_1, c_0);
                  
                  delay( delayTime);  
                 } //end c_0
               } // end c_1
             } //end c_2
           } // end c_3
         } // end c_4
        } // end c_5
       } // end c_6
       delayTime = tierTwo;
     } //end c_7
  } //end c_8
}
