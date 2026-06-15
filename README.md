# C++ Programming Projects

A collection of C++ programs developed during the Diploma of Information Technology at Swinburne University of Technology (UniLink Pathway), demonstrating core programming concepts including algorithms, data structures, graphics, and file handling.

---

## Projects

### Assignment 1 — Foundational C++ Programs

#### 1. Product Invoice Calculator
A console-based point-of-sale program that calculates shopping invoices.

**Features:**
- Accepts product codes and quantities in a loop until the user exits
- Validates input (rejects negative quantities, invalid product codes)
- Calculates per-item cost and running total
- Prints a formatted invoice summary

**Concepts used:** Functions, loops, switch statements, input validation

---

#### 2. Star Pattern Visualiser
A graphical program that draws a triangle pattern of colourful stars using the SplashKit library.

**Features:**
- Renders a 10-row triangular grid of stars
- Each star is built from a rectangle and four triangles
- Colours are assigned randomly from red, green, blue, and yellow
- Runs in a graphical window

**Concepts used:** Graphics library (SplashKit), nested loops, functions, randomisation

---

#### 3. Dice Game
A console dice game where a player rolls three dice and wins or loses based on the outcome.

**Features:**
- First roll: win immediately on 13+, lose on 6 or under, otherwise set a "point"
- Subsequent rolls: win by matching the point, lose by rolling 15+
- Uses `rand()` seeded with system time for true randomness each run

**Concepts used:** Functions, randomisation, game logic, while loops

---

#### 4. Interactive Shape Drawer
A graphical GUI app where the user selects a shape and colour, then draws it to screen.

**Features:**
- Click to select from: Square, Rectangle, Circle, Triangle
- Click to select from: Blue, Red, Black, Green
- Press "Click to Draw" button to render the chosen shape at full size
- Live display of current selection

**Concepts used:** SplashKit graphics, mouse event handling, conditional rendering, constants

---

### Assignment 2 — Intermediate C++ Programs

#### 1. Credit Card Validator (Luhn Algorithm)
Validates a credit card number using the real-world Luhn checksum algorithm.

**Features:**
- Accepts card digits one at a time until the user enters `-1`
- Implements both Sum 1 (doubled alternating digits) and Sum 2 (remaining digits)
- Calculates checksum and compares it to the last digit
- Outputs whether the card number is valid or invalid

**Concepts used:** Arrays, pointer parameters, algorithm implementation, loops

> The Luhn algorithm is the actual validation method used by Visa, Mastercard, and other card networks.

---

#### 2. Music Album Manager
A text-based music application that reads album data from a file and lets users browse and play tracks.

**Features:**
- Loads albums from an external `.txt` file at runtime
- Display all albums or filter by genre (Pop, Rock, HipHop, Classical)
- Select an album and track to play (opens with system media player)
- Update an album's title or genre
- Menu-driven interface

**Concepts used:** Structs, enums, arrays, file I/O (`ifstream`), functions, `system()` calls

---

#### 3. Sorting Algorithm Visualiser
A graphical visualiser that shows Bubble Sort and Selection Sort running on 800 random bars.

**Features:**
- Generates 800 bars with random heights and HSB-colour-mapped colours
- Three buttons: Draw (randomise), Sort 1 (Bubble Sort), Sort 2 (Selection Sort)
- Sorting result displayed as a colour-gradient bar chart
- Red separator line between controls and visualisation area

**Concepts used:** Structs, sorting algorithms, SplashKit graphics, button click detection

---

## Technologies Used

| Tool | Purpose |
|------|---------|
| C++17 | Core language |
| SplashKit | Graphics and window management |
| Standard Library | I/O, file handling, randomisation |

---

## About

**Student:** Sehan Madusha Jayasuriya  
**Program:** Diploma of Information Technology (UniLink) — Swinburne University of Technology  
**Unit:** COS10029 Fundamentals of Programming  
**Year:** 2025
