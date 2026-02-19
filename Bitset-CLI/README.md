Designed a BITSET class, that allows the user to store a large number of Boolean values (0 or 1). The purpose of this lab is to use bitwise operators to solve a problem.
The user interface for this lab is fairly straight forward. The program will ask the user for a command and get the user's input using scanf. Some commands have parameters, and others do not. The command is a single character and can be as follows:

Command	Description
t <bit>	Tests the given bit and outputs 0 or 1. This must be able to span multiple sets.
s <bit>	Sets the given bit to 1. This must be able to span multiple sets.
c <bit>	Clears the given bit to 0. This must be able to span multiple sets.
p <set>	Prints the binary representation of the given set. If the set does not exist, output "Set #xxx does not exist." (Replace xxx with the requested set).
q	Quits and returns to the console.
This program continually ask the user for one of these commands until they either send EOF (Control-D) or type 'q' for quit. Furthermore, all of these commands operate on the same BITSET class instance.
