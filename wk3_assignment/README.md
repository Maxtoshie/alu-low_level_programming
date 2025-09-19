# ATM Machine (C Week3 Assignment)

## Description
This is a simple command-line ATM simulation program written in C.  
It allows a user to:
- Check account balance  
- Deposit money  
- Withdraw money (with validation for insufficient funds)  
- Exit safely  

The project was developed as part of the ALU Low-Level Programming curriculum, and it follows ANSI C and Betty coding style guidelines.

---

## Files
- `atm.c` → Source code for the ATM program  
- `atm` → Compiled binary executable  
- `README.md` → Project documentation  

---

## Compilation
To compile the program, run:

```bash
gcc -std=c2x -Wall -pedantic atm.c -o atm
````

This will generate the executable `atm`.

---

## Usage

Clone the Repo

git clone git@github.com:Maxtoshie/alu-low_level_programming.git

change directory to wk3_assignment

cd wk3_assignment

Run the ATM program:

```bash
./atm
```

---

## Demo Output

Example interaction with the program:

```
=== ATM Menu ===
1. Check Balance
2. Deposit
3. Withdraw
4. Exit

Enter your choice (1-4): 1
Current balance: $1000.00

=== ATM Menu ===
1. Check Balance
2. Deposit
3. Withdraw
4. Exit

Enter your choice (1-4): 2
Enter amount to deposit: $45
Deposited $45.00. New balance: $1045.00

=== ATM Menu ===
1. Check Balance
2. Deposit
3. Withdraw
4. Exit

Enter your choice (1-4): 3
Enter amount to withdraw: $320.2
Withdrew $320.20. New balance: $724.80

=== ATM Menu ===
1. Check Balance
2. Deposit
3. Withdraw
4. Exit

Enter your choice (1-4): 4
Thank you for using the ATM. Goodbye!
```

---

## Betty Style Compliance

The code was checked with the Betty linter:

```bash
betty atm.c
```

No errors or warnings.

---

## Author

**Maxwel Okoth**
GitHub: [@Maxtoshie](https://github.com/Maxtoshie)

```
