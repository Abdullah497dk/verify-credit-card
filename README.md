# verify-credit-card 

## 🏦 Credit Card Validator (CS50x)  
This project is a **credit card validator** built as part of the [Harvard CS50](https://cs50.harvard.edu/) course. It checks whether a given credit card number is valid using **Luhn’s Algorithm** and identifies the card type (Visa, Mastercard, or American Express).  

### 🚀 Features  
✅ Validates credit card numbers using **Luhn’s Algorithm**  
✅ Identifies card type (Visa, Mastercard, or AMEX)  
✅ Written in **C** with a focus on efficiency  

### 📜 How It Works  
The program:  
1. Takes a credit card number as input.  
2. Uses **Luhn's Algorithm** to verify its validity.  
3. Determines the card type based on the starting digits and length.  

### 🛠️ Installation & Usage  
1. Clone the repository:  
   ```bash
   git clone https://github.com/Abdullah497dk/verify-credit-card.git
   cd verify-credit-card
   ```  
2. Compile the program:  
   ```bash
   clang -o app app.c
   ```  
3. Run the program:  
   ```bash
   ./app
   ```  
4. Enter a credit card number and get instant validation results.  

### 📌 Example  
```
Enter credit card number: 378282246310005  
AMEX  
```

### 🧠 What I Learned  
✅ Algorithm design & optimization  
✅ Input validation in C  
✅ Efficient memory management  

### 📎 References  
- [Luhn Algorithm](https://en.wikipedia.org/wiki/Luhn_algorithm)  
- [CS50 Course](https://cs50.harvard.edu/)  
