
#include "MicroBit.h"
#include <string>
#include <vector>
#include "btree.hpp"

/**
 * Copies to MicroBit
 * cp build/$(yt --plain target | head -n 1 | cut -f 1 -d' ')/source/$(yt --plain ls | head -n 1 | cut -f 1 -d' ')-combined.hex  /Volumes/"MICROBIT"
 */

MicroBit uBit;
MicroBitButton buttonA(MICROBIT_PIN_BUTTON_A, MICROBIT_ID_BUTTON_A);
MicroBitPin P0(MICROBIT_ID_IO_P0, MICROBIT_PIN_P0, PIN_CAPABILITY_ALL);
MicroBitImage antenna("255,0,255,0,255\n 0,255,255,255,0\n 0,0,255,0,0\n 0,0,255,0,0\n 0,0,255,0,0\n");
btree morse_tree;

using namespace std;

char dot = '.';
char dash = '-';
std::string dot_or_dash = "";
std::string word = "";

/**
* Function: sending
* Purpose: sends a pulse via the P0 pin to the receiver based on timing delta
* Digital value is set to 1 to send morse via wire then reset to 0
* Returns: N/A
*/
void sending()
{
    uBit.display.scroll("Sender"); //You are S (Sender)

    bool pressed = false;
    bool transmit = false;

    while (1)
    {
        uint64_t reading = system_timer_current_time();

        while(!buttonA.isPressed())
        {

            uint64_t wait = system_timer_current_time() - reading;

            // Space between inputted chars based on morse
            if(wait > 750 && transmit == true)
            {
                uBit.display.print(antenna);
                // Digital Value set to 1 to send pulse over wire
                P0.setDigitalValue(1);
                uBit.sleep(1700);
                uBit.display.clear();
                // Set to 0 to stop sending pulse over wire
                P0.setDigitalValue(0);
                transmit = false;

                break;
            }

        }

        reading = system_timer_current_time();

        while (buttonA.isPressed())
        {
            pressed = true;
        }

        // Delta is assigned loop time - reading
        uint64_t delta = system_timer_current_time() - reading;

        if (pressed)
        {
            if (delta < 500)
            {
                P0.setDigitalValue(1);
                uBit.display.print(".");
                uBit.sleep(250);
                P0.setDigitalValue(0);
                transmit = true;
            }
            else if (delta > 500 && delta < 1500)
            {
                P0.setDigitalValue(1);
                uBit.display.print("-");
                uBit.sleep(500);
                P0.setDigitalValue(0);
                transmit = true;
            }
            else if (delta > 2000)
            {
                //Send pulse
                P0.setDigitalValue(1);
                uBit.display.scroll("Sent");
                uBit.sleep(750);
                P0.setDigitalValue(0);
                break;
            }

            pressed = false;
            uBit.display.clear();
        }
    }
}

/**
* Function: receive
* Purpose: Records and processes the pulse form the sender via the P0.
* Traverses the struct binary tree, passes the string dot or dash into the function "code" in the binary tree hpp file
* Returns: N/A
*/
void receive()
{
    uBit.display.scroll("Receiver");

    bool pressed = false;

    while (1)
    {

        uint64_t reading = system_timer_current_time();

        while (P0.getDigitalValue() == 1)
        {
            pressed = true;
        }

        uint64_t delta = system_timer_current_time() - reading;

        if (pressed)
        {
            if(delta < 500)
            {
                uBit.display.print(".");
                dot_or_dash += dot;
                uBit.sleep(200);
                uBit.display.clear();
            }
            else if (delta > 500 && delta < 1500)
            {
                uBit.display.print("-");
                dot_or_dash += dash;
                uBit.sleep(200);
                uBit.display.clear();
            }
            else if(delta > 1500 && delta < 2000){
                // The string is passed into the struct "btree" into the function "code" assigned to "letter".
                char letter = morse_tree.code(dot_or_dash.c_str());
                // The letter is appended to a string "word"
                word += letter;
                letter = NULL;
                // "dot_or_dash" to be cleared for next letter to be passed in struct
                dot_or_dash.clear();
            }

            else if (delta > 2000)
            {
                uBit.display.scroll(word.c_str());
                word.clear();
                uBit.sleep(300);
                break;
            }

            pressed = false;
            uBit.display.clear();

        }

    }
}

/**
* Function: mode
* Purpose: Allows the users to choose a mode depending on which button is pressed
* Returns: N/A
*/
void mode()
{

    while (1)
    {
        uBit.display.print(antenna);
        if (uBit.buttonA.isPressed())
        {
            sending();
        }
        if (uBit.buttonB.isPressed())
        {
            receive();
        }
    }
}


int main()
{
    uBit.init();
    mode();
    release_fiber();
}

