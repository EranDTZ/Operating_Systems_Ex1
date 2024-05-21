```markdown
**Poisson Calculator**

**Description:**
This program calculates the probability of Poisson given an lambda (λ) and value of k. 
utilizes the Poisson probability formula: 

```
px(k) = (λ^k * e^(-λ)) / k!
```
## Installations:
1. **Download the code**: Download the program code from the project.
2. **Building the program**: In the terminal, run the command 'make all' to compile the program.
3. **Running**: To run the program Run in Bash: `./main` .
4. **Output**: The program will calculates the probability  `px(k)` of five valus.

**Files:**
- `main.c`: Contains the main function to interact with the user and execute the calculations.
- `poisson.c`: Implements functions to calculate the Poisson distribution probability.
- `poisson.h`: Header file containing function declarations and necessary includes.
- `makefile`: Automates the compilation process.

**Example Usage:**
```
$ ./main
px(1) = 0.2707
px(10) = 0.0000
px(2) = 0.2707
px(3) = 0.2240
px(3) = 0.0000
```
```