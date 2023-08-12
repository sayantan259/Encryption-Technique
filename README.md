# Text Encryption and Decryption Program

This repository contains a simple C++ program that demonstrates text encryption and decryption using a substitution cipher. The program offers basic functionalities to encrypt and decrypt the contents of a text file, providing a hands-on example of encryption techniques.

## Introduction

The program showcases a basic encryption and decryption technique for text files using a substitution cipher. It allows users to encrypt a given text file and subsequently decrypt it, all within a terminal-based interface. The encryption process involves character substitution and noise addition, with corresponding steps during decryption.

## Encryption Process

1. **Character Substitution:** The program employs a predefined character mapping to substitute each character in the input text, ensuring the encrypted text is substantially different from the original.

2. **Noise Addition:** For added security, the program inserts random noise into the encrypted text. This noise is generated using a random string generator and is added at regular intervals.

3. **Compressing Keywords:** To optimize encryption, common words like "the" and "and" are replaced with special symbols before encryption. This step is reversed during decryption.

## Decryption Process

1. **Noise Removal:** The added noise is stripped from the encrypted text to retrieve the original encrypted content.

2. **Character Reversal:** Utilizing the predefined character substitution mapping in reverse, the encrypted text is transformed back to its intermediate form.

3. **Decompressing Keywords:** The special symbols used for common word replacement are restored to their original forms.

## Usage

1. **Encryption:**
    - Select option 1 from the main menu.
    - Input the name of the target text file (in `.txt` format) for encryption.
    - The program will read the content from the file, perform encryption, and overwrite the file with the encrypted content.

2. **Decryption:**
    - Choose option 2 from the main menu.
    - Enter the name of the text file (in `.txt` format) that you want to decrypt.
    - The program will read the encrypted content, perform decryption, and overwrite the file with the decrypted content.

3. **Exit:**
    - Opt for option 3 from the main menu to exit the program.

## File Structure

- `encryption system.cpp`: The core C++ program containing the encryption, decryption, and user interaction logic.
- `README.md`: This documentation file explains the program's functionality.

