# ParallelFibonacci
###Fibonacci code with OpenMP in C

The code is made with a special library called GMP, which proves 
telescopic numbers and functions to operate them.

with commands to install the library in ubuntu
                            
    sudo apt-get install libgmp3-dev
    
The principal file to ejecute the code is **main.c**


I tried to do the code using reduction but due to the 
GMP variables, I was not allowed, also most of what is 
used to modify the GMP variables are dedicated 
functions from the library.