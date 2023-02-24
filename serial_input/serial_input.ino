// The input/output (user interface) is via the serial monitor
// > Tools > Serial Monitor
// In the serial monitor, select "carriage return"
// make sure the baud rate is set same as in the sketch (code)
// such as 115200 or whatever.

void setup (void)
{
    Serial.begin (115200);
}

void loop (void)
{
    int len;
    char buffer[32];  // in this case, maximum input length is 32
    Serial.print ("\r\nPlease type something: ");
    len = readline (buffer, 32);   // in this case, maximum input length is 32
    Serial.print ("\r\nYou typed: \"");
    Serial.print (buffer);
    Serial.print ("\" which contains ");
    Serial.print ((int) len);
    Serial.print (" characters.\r\n");
}

// read a line from user into buffer, return char count
int readline (char *buf, int limit)
{
    int x;
    int ptr = 0;
    *buf = 0;

    while (1) {
        if (Serial.available()) {
            x = Serial.read();

            if (x == 0x0D) { // cr == end of line
                buf[ptr] = 0; // flag end of line
                return ptr; // return char count
            }

            if (x == 0x08) { // backspace
                if (ptr > 0) {
                    ptr--;
                    buf[ptr] = 0;
                    Serial.print ("\b \b"); // erase bs'd char
                }

            } else {
                if (ptr < (limit - 1)) {
                    Serial.print ((char) x); // echo char
                    buf[ptr] = x; // store in buffer
                    ptr++;
                }
            }
        }
    }
}
