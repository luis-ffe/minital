## Use Instructions:

Use the provided makefile for compilation. The following commands are available: `make`, `re`, `clean`, `fclean`, and `bonus`.

### Initialize the server:

To start the server, use one of the following commands:

- `./server`
- `./server_bonus`

### Run the client:

Execute the client according to the rules using one of these commands:

- `./client`
- `./client_bonus`

The client will provide further instructions for correct use.

## Explanation

This project will help you understand bit operations and signal handling in C. My choice was to use `sigaction` for both the mandatory and bonus parts. `sigaction`'s structure ensures reliable behavior across different software versions, whereas using signals directly might be more error-prone.

To use `sigaction`, start by initializing it:

struct sigaction name;

After that, set the `sa_sigaction` component of the `sigaction` structure to point to your custom function:
name.sa_sigaction = &your_function;

This custom function, declared by me, handles each character of the message to be sent. It sends each bit one by one, as described in the "Bit Processing" section below.

To keep the server running, I used a loop with the pause() function inside it. This keeps the program in a resting state until a signal is received. The signal action is activated once a signal is received:

sigaction(SIGUSR1, &name, NULL);
sigaction(SIGUSR2, &name, NULL);

These signal actions run every time a signal is received and start processing signals in the server one at a time while the client keeps sending them. Be mindful that computers are fast, so consider adding some spacing between signals using `usleep(50)`.

The variables are set as static, preserving their values and scope for multiple "executions" of the `your_function`. One byte consists of 8 bits, so when the bit counter reaches 8, a condition checks it and prints the character. After that, the variables are reset. It's essential to handle errors gracefully.

### Bonus Client

The bonus client sends the null character of the string to the server, triggering the server to send a `SIGUSR1` signal back to the client. The client receives it and uses the same mechanism as the server to execute the `sigaction.sa_sigaction` associated function, printing the acknowledgment message and exiting the program correctly.

## Bit Manipulations in Minitalk

1 byte is equivalent to 8 bits. 100 characters are 800 bits, and with a 1,000,000μs (microseconds) delay using 50μs as spacing, you can theoretically send 2500 characters per second.

### Bit Literals and Hexadecimal

You can represent bits in code using binary literals or hexadecimal notation:

- Binary: `0b00000000` is equivalent to 0, and `0b00000001` is equivalent to 1.
- Hexadecimal: `0x00` is 0, and `0x01` is 1.

You can also use 0 and 1 directly.

### Bitwise Operators

In this project, bitwise operators such as `|` (OR) and `&` (AND) are used for bit manipulation.

- `0b00000001 | 0b00000000` is the same as `1 | 0`, which is similar to 1 + 0.
- `0b00000001 & 0b00000000` is the same as `1 & 0`, resulting in 0.

The `&` operator compares if the bits are equal and sets the bit to 0 if they are not. Otherwise, the bit remains 1, which is useful for boolean functions or statements.

### Sending a Character

To send the bits of a character one by one:

while the string isn't over:
    c = *stringchar;
    bit = 0;
    
    while bit is not 8:
        if (c & 0b00000001)
            send SIGUSR1;
        else
            send SIGUSR2;
        bit++;
        c >> 1;

This code accesses and compares the rightmost bit (LSB) of `c` with 1. If they are both 1, the `if` statement is true, and `SIGUSR1` is sent. Otherwise, `SIGUSR2` is sent. Then, `c` is shifted by one to compare the next bit of the character.

### Building the Character

Start with `c = 0b00000000` (or `c = 0`). If you receive `SIGUSR1`, update `c` as follows:

```c
c |= (1 << bit)

Here, `bit` ranges from 0 to 7, placing the shifted bit in the corresponding position. When `bit` reaches 8, the character is fully built. If `SIGUSR2` is received, increment `bit`, or set `c |= 0`, as it won't change anything. When `bit` equals 8, print the character, and reset the variables to 0 to prepare for building another character:

```markdown
c = 0;
bit = 0;

Feel free to reach out if you find any part unclear or have questions. You can contact me on 42 slack or via email. User: luis-ffe

