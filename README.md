<div align="center">

# CipherLock

![C++](https://img.shields.io/badge/C++-17-blue?style=flat&logo=c%2B%2B)
![License](https://img.shields.io/badge/License-MIT-green)
![Type](https://img.shields.io/badge/Type-Cryptography-red)

<p>
  <strong>A lightweight CLI file encryption tool utilizing XOR logic.</strong>
</p>

[Report Bug](https://github.com/your-username/cipherlock/issues) · [Request Feature](https://github.com/your-username/cipherlock/issues)

</div>

---

## Description

**CipherLock** is a C++ based command-line tool that demonstrates the fundamentals of binary file manipulation and symmetric encryption.

It uses the **XOR (Exclusive OR)** operation to obfuscate file contents. In the context of cybersecurity and malware analysis, XOR is the most common method used for basic obfuscation. This tool allows users to encrypt any file type (text, images, executables) with a custom key and decrypt it by running the process again.

### Key Features

 **Fast & Low Level:** Written in C++ for direct memory manipulation and high performance.
 **Symmetric Encryption:** The same key is used for both locking and unlocking.
 **Binary Compatible:** Safely handles non-text files (like `.jpg`, `.exe`, `.pdf`) using binary streams.
 **Linux Native:** Designed for smooth integration with Linux terminal workflows.

---

## Installation & Compilation

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/your-username/cipherlock.git](https://github.com/your-username/cipherlock.git)
   cd cipherlock
   ```

2. **Compile using Make:**
   Ensure you have `g++` installed (`sudo dnf install gcc-c++` on Fedora).
   ```bash
   make
   ```
   *This will create an executable named `cipherlock`.*

---

## 💻 Usage

The syntax requires an input file, an output destination, and a secret key.

**To Encrypt:**
```bash
./cipherlock secret.txt encrypted.dat "MySuperSecretKey"
```

**To Decrypt:**
(Simply run it again on the encrypted file with the **same** key)
```bash
./cipherlock encrypted.dat decrypted.txt "MySuperSecretKey"
```

### Example Scenario
1. You have a photo `evidence.jpg`.
2. You run: `./cipherlock evidence.jpg evidence.lock "fedora43"`
3. The `evidence.lock` file is now unreadable noise.
4. To restore: `./cipherlock evidence.lock restored.jpg "fedora43"`

---

## ⚠️ Disclaimer

This tool uses **Simple XOR encryption**, which is **NOT** cryptographically secure against modern cryptanalysis. It is intended for **educational purposes** (learning C++ file I/O and logic operations) and basic file obfuscation. Do not use it to protect highly sensitive data like bank passwords or state secrets.

---

## License

Distributed under the MIT License. See `LICENSE` for more information.
