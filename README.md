## Use instructions:

Use make to compile. \
commans working, re, clean, fclean, bonus. \

#### Initialize the server you want.
<code>./server</code> \
<code>./server_bonus</code> \

#### Run the client acording to the rules.
<code>./client</code> \
<code>./client_bonus</code> \
-this will give you further instructions for correct use. \

## Explanation

This project will make you learn about bit operations and signals in c. \
My choice was to use sigaction for both the mandatory and bonus. \
Sigaction's structur makes it have a solid comportment in most softwere version and signal would be more prone to errors. \
\
To use sigaction first initialize it. \
<code>.struct sigaction name; </code> \
After that i set sigactions component sa_sigaction to the &function. \
<code>name.sa_sigaction = &your_function;  </code>  \
This function is declared by me and it handles each character of the message to be sent \
It will send each bit by bit, See how in the BIT PROCESSING part down below. \
\
To keep the server up i used. \
<code> pause(); </code>  \
Inside a while(true) loop. \
This keeps the program at rest until a signal is received. \
The signal action is turned on once the signal is received. \
<code>Sigaction(SIGUSR1, &name, NULL); </code> \
<code>Sigaction(SIGUSR2, &name, NULL); </code> \
These will run everytime a signal is received and start processing signal in the server one at a time while the client keeps sending them. \
Keep in mind computers are fast give some spacing between signals using </code> usleep(50); </code> \ 
The variables are set as static conserving value and scope for multiple "executions" of the function <code> &your_function;  </code>  \
One byte is 8 bits so when the bit counter is 8 a condition checkings it and prints the char and resets the variables. \
Make sure you handle errors smoothly. \
\
The Bonus client will send the null char of the string to the server and that trigers the server to send SIGUSR1 Signal to the client. \
The client receives it, and with the same mechanism as the server executes the  <code> sigactions.sa_sigaction  </code>  associated function. \
Printing the aknowledgement message and exiting the program properly.

## BIT manipulations in minitalk
1 byte == 8 bits \
100 chars are 800 bits, 1 000 000u (microseconds) using 50u as spacing lets you send theoretically 2500 chars per secund. \
\
Bit literals \
<code>0b00000000</code> == 0 \
<code>0b00000001</code> == 1 \
Hexadecimal \
<code>0x00</code> == 0 \
<code>0x01</code> == 1 \
Or you can just use 0 or 1 \
When operating bits the format you show them in your code is your choice, in the end they will all be 0s or 1s . \
For this project i used the bitwise operator  <code> | </code> (or)  and  <code> & </code> (and). \
\
<code> 0b000000001  |  0b00000000 </code>  is the same as saying (1 | 0) it works much like 1 + 0. \
<code> 0b000000001  &  0b00000000 </code>  is the same as saying (1 & 0) the result is 0 (trick just think & compares if the bits are equal and if they are not it the bit is set to zero. \
Else.... the bit remains 1. This will come in handy in boolean functions or statements. \
\
<code> char c = 0b000000001  </code>  the same as saying c = 1; or c = 0x01; \
<code> c  &  0b00000000 </code>  is the same as saying <code>c & 0;</code> or <code>c & 0x00;</code> \
all this expression have one thing in common. None of them changes the value of c.  \
Just like <code> x = 1 and y = 2  </code>    if you do <code> x + y </code> you access the operation value but you dont change any of the imputs. \
\
Let c = 0; \
<code> c |= 1 </code>  c is now 1 we set the LSB (the bit at the right end) to 1. \
We changed it! \
The same as saying <code> c |= 0b0000 0001 </code> \
\
The space in the midle is just to make it easy to read. \
\
now we can do this using other operator like the shiffting ones. \
<code> 0b0000 0001 >> 1 </code> shifts one slot to the right, all are set to 0 now;
<code> 0b0000 0001 << 1 </code> is now <code> 0b0000 0010 </code> remember not defenitive.  \  
If we wanted to change it and keep it changed we would be using <<= or >>= . \
<code> 0b0000 00001 << 4 </code> is like saying <code> 0b00001 0000 </code> \
<code> 0b0000 00001 << 7 </code> is like saying <code> 0b1000 0000 </code> \

# send the char
To send the char bits one by one:  \
<code>while the string isnt over
c = *stringchar;
bit = 0;
now, while bit is not 8
if(C & 0b0000 0001)
      send SIGUSR1
else
      send the SIGUSR2
bit++;
c >> 1;
</code>
this will always access and compare the the bit most at right from c with 1. (LSB) \
if they are both 1 then the if statement is true and we send the SIGUSR1 else w send the other;
then we shift c by one for the next bit of the char to be compared.

# build the char
<code> c = 0b00000000    or   c = 0  </code>  \
<code>if i receive SIGUSR1
c |= (1 << bit )</code>
bit will range from 0 to 7 placing the accessed shifted bit in the position corresponding to the bit number. \
<code>bits  -  0000 0000   total bits= 8
position 7654 3210   total pos = 8 </code> \
when the char is fully built, that means the bit incremented from 0 to 7 and in the last iteration increments once more ending at 8. \
when the signal received is SIGUSR2 we just need to increment the bit or make c |= 0; since that wont change anything. \
and the incrementation of bit will skip the place where 0 is suposed to be keeping it as a zero. \
if bit == 8 \
Print the char and reset the variables to 0, they are now ready to build another char. \
c = 0; \
bit = 0; \
\
Reach me if you think something isnt clear enough pls! Luis-ffe on 42 slack!


