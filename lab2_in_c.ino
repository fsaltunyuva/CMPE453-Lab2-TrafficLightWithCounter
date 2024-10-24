#include <avr/io.h>
#include <util/delay.h>

// Red LED corresponds to PORTB's 0th bit
// Yellow LED corresponds to PORTB's 1st bit
// Green LED corresponds to PORTB's 2nd bit

// 7 Segment Display's a-b-c-d-e-f-g for numbers 0-9 (https://media.geeksforgeeks.org/wp-content/uploads/20200413202916/Untitled-Diagram-237.png)
// a corresponds to PORTD's 5th bit
// b corresponds to PORTD's 7th bit
// c corresponds to PORTB's 4th bit (Only this one requires different PORT)
// d corresponds to PORTD's 3rd bit
// e corresponds to PORTD's 2nd bit
// f corresponds to PORTD's 4th bit
// g corresponds to PORTD's 6th bit
// dot corresponds to PORTB's 3rd bit

int main(){

  DDRB=0xff; // Set all ports of PORTB as output
  DDRD=0xff; // Set all ports of PORTD as output

  // The anode implementation of 7 segment display is used
  // So, the bits are set to 1 to turn off the display
  while(1)
  {
    // ========= Circle 1 ========= //
    
    PORTB=0b00001001; // Turn off the dot and turn on the red LED
    PORTD=0b00001100; // Turn on all bits except e (for 9)
    _delay_ms(1000); // Wait for 1 second
     
    PORTD=0b00000000; // Turn on all bits (for 8)
    _delay_ms(1000); // Wait for 1 second

    PORTD=0b01011100; // Turn on a, b, and c bits (for 7) 
    _delay_ms(1000); // Wait for 1 second

    PORTD=0b10000000; // Turn on all bits except b (for 6)
    _delay_ms(1000); // Wait for 1 second

    PORTB=0b00001011; // Turn on both the red and yellow LEDs
    PORTD=0b10000100; // Turn on all bits except b and e (for 5)
    _delay_ms(1000); // Wait for 1 second

    PORTD=0b00101100; // Turn on b, c, f, and g bits (for 4)
    _delay_ms(1000); // Wait for 1 second

    PORTD=0b00010100; // Turn on all bits except c and f (for 3)
    _delay_ms(1000); // Wait for 1 second

    PORTB=0b00011011; // Turning off the c bit (it requires different PORT)
    PORTD=0b00010000; // Turn on all bits except c and f (for 2)
    _delay_ms(1000); // Wait for 1 second

    PORTB=0b00001011; // Turnin off the c bit (it requires different PORT)
    PORTD=0b01111111; // Turn on b and c bits (for 1)
    _delay_ms(1000); // Wait for 1 second

    PORTB=0b00001100; // Turn off the red and yellow LEDs and turn on the green LED
    PORTD=0b01000000; // Turn on all bits except g (for 0)
    _delay_ms(1000); // Wait for 1 second

    PORTD=0b01011100; // Turn on a, b, and c bits (for 7)
    _delay_ms(7000); // Wait for 7 seconds

    // ========= Circle 2 ========= //
        
    PORTD=0b00000000; // Turn on all bits (for 8)
    _delay_ms(1000); // Wait for 1 second

    PORTD=0b01011100; // Turn on a, b, and c bits (for 7)
    _delay_ms(1000); // Wait for 1 second

    PORTD=0b10000000; // Turn on all bits except b (for 6)
    _delay_ms(1000); // Wait for 1 second

    PORTD=0b10000100; // Turn on all bits except b and e (for 5)
    _delay_ms(1000); // Wait for 1 second

    PORTB=0b00001010; // Turn off the green LED and turn on the yellow LED
    PORTD=0b00101100; // Turn on b, c, f, and g bits (for 4)
    _delay_ms(1000); // Wait for 1 second

    PORTD=0b00010100; // Turn on all bits except c and f (for 3)
    _delay_ms(1000); // Wait for 1 second

    PORTB=0b00011010; // Turning off the c bit (it requires different PORT)
    PORTD=0b00010000; // Turn on all bits except c and f (for 2)
    _delay_ms(1000); // Wait for 1 second

    PORTB=0b00001010; // Turning off the c bit (it requires different PORT)
    PORTD=0b01111111; // Turn on b and c bits (for 1)
    _delay_ms(1000); // Wait for 1 second

    PORTB=0b00001001; // Turn on the red LED and turn off the others
    PORTD=0b01000000; // Turn on all bits except g (for 0)
    _delay_ms(1000); // Wait for 1 second
  }

  return 1;
}
