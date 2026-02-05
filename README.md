This project has been created as part of the 42 curriculum by malavaud.

Minitalk
Description
MiniTalk is a project from the 42 curriculum that consists of developing a simple communication system between two processes: a server and a client.

The communication must rely only on UNIX signals, specifically:

SIGUSR1

SIGUSR2

The client encodes characters into a sequence of bits and sends them to the server through these signals. The server then decodes the signal sequence to reconstruct and display the original message.

This project focuses on:

UNIX signals and low-level process communication

Signal handlers (sigaction)

Synchronization between processes

How it works
Client
The client:

Reads the input string
Converts each character into its binary representation
Sends :
SIGUSR1 -> bit 0
SIGUSR2 -> BIT 1
Pauses briefly (usleep) to avoid signal loss
Server
The server:

Receives the incoming signals
Builds the character bit by bit
Prints the resulting message
Outputs a newline at the end of the transmission
Instructions
Requirements
macOS OR lINUX
A C compiler (gcc)
Compilation
Compile the project with:

make
This creates two executables:

./server
./client
Cleanup commands:

make fclean
make clean
make re
Execution
Start the server:

./server
The server prints its PID, exemple:

12345
Send a message from the client:

./client <PID> "Your message"
Exemple:

./client 12345 hello
Example Error Output
If the PID is invalid, the program must display an error message, exemple:

Invalid PID
Ressources
Man of:
signal
kill
getpid
uslepp
pause
General documentation on UNIX signals
Bitwise operations tutorials
42 subject PDF
How AI Was Used
AI (ChatGPT) was used to:

Rephrase and structure the README
Provide examples of wording and organization
Suggest conventional sections and descriptions
AI was not used to write core code logic, algorithms, map parsing, or game mechanics. All implementation decisions and coding were done manually.
