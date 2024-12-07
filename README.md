# Right Wing Game (Modèle de Droite)

A puzzle game developed in C using the SDL library where players fill a grid with diagonal lines following numerical constraints.

---

## Table of Contents

1. [Introduction](#1-introduction)
2. [Features](#2-features)
3. [How to Play](#3-how-to-play)
4. [Game Modes](#4-game-modes)
5. [Installation](#5-installation)
6. [Technical Details](#6-technical-details)
7. [Screenshots](#7-screenshots)
8. [References](#8-references)

---

## 1. Introduction

The **Right Wing Game** is a logic puzzle game played on a 6×6 grid. Each corner point of a cell contains a number (0-4) that indicates how many diagonal lines should connect to that point. The objective is to fill the grid with diagonal lines while satisfying all numerical constraints.

---

## 2. Features

- Three distinct game modes (Single Player, AI Mode, Player vs AI)
- Save/Load functionality
- Timer and best time tracking
- Top 5 leaderboard system
- Pause/Resume capability
- Interactive mouse-based gameplay

---

## 3. How to Play

### Basic Rules
1. The game is played on a 6×6 grid
2. Each corner point has a number (0-4)
3. These numbers indicate how many diagonal lines should connect to that point
4. All cells must be filled with diagonal lines
5. The game is won when all constraints are satisfied

### Controls
- **First Click**: Places a diagonal line from top-left to bottom-right (↘)
- **Second Click**: Places a diagonal line from top-right to bottom-left (↙)
- **Third Click**: Removes the diagonal line from the cell

### Game Interface
- **Save Button**: Saves current game progress
- **Continue Button**: Resumes a saved game
- **Replay Button**: Starts a new game
- **Pause Button**: Temporarily stops the game

---

## 4. Game Modes

### Single Player Mode
- Classic puzzle-solving experience
- Track your completion time
- Save progress and continue later

### AI Mode
- Watch the computer solve the puzzle
- Study optimal solving strategies
- Automated demonstration of solutions

### Player vs AI Mode
- Compete against the computer
- Side-by-side gameplay
- Race to complete the puzzle first

---

## 5. Installation

### Prerequisites
- GCC compiler
- SDL2 library
- SDL2 development files

### Build Instructions
1. Clone the repository:
```bash
git clone https://github.com/yourusername/right-wing-game.git
cd right-wing-game
```

2. Install SDL2 dependencies:

```bash
# For Ubuntu/Debian
sudo apt-get install libsdl2-dev

# For Fedora
sudo dnf install SDL2-devel

# For macOS
brew install sdl2
```

3. Compile the game:

```bash
make
```

4. Run the game:

```bash
./right-wing-game
```

---

## 6. Technical Details

- Written in C
- Uses SDL2 for graphics rendering
- Matrix-based game logic
- AI implementation using [specific algorithm]
- Save system using file I/O

---

## 7. Screenshots

[Add screenshots of:
- Main menu
- Gameplay
- Different game modes
- Victory screen]

---

## 8. References

- [SDL Documentation](https://wiki.libsdl.org/)
- [SDL Animation Tutorial](http://sdz.tdct.org/sdz/les-animations-optimisees-avec-sdl.html)
- [SDL Installation Guide](http://alexandre-laurent.developpez.com/tutoriels/sdl-2/installation-et-configuration/)
