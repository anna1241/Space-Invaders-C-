# Space Invaders Game in C++

This repository contains a Space Invaders game implemented in C++.

## Features
- Classic arcade-style Space Invaders gameplay
- Player-controlled ship movement and shooting mechanics
- Enemy alien spawning and movement
- Collision detection for bullets and aliens
- Score and lives tracking
- Save and load game functionality
- Simple graphical output using `myconsole.h` and `mygraphics.h`

## Installation & Compilation
### Prerequisites
Ensure you have a C++ compiler (e.g., `g++` or Visual Studio`) installed on your system.

### Compilation (Using g++)
```sh
g++ -o SpaceInvaders SpaceInvaders.cpp -lgraphics
```

### Running the Game
```sh
./SpaceInvaders
```

## Usage
1. Run the compiled executable.
2. Press `G` to start a new game.
3. Press `C` to continue a saved game.
4. Control the ship using arrow keys:
   - Left Arrow: Move left
   - Right Arrow: Move right
   - Up Arrow: Move up
   - Down Arrow: Move down
   - Spacebar: Fire bullets
5. Press `P` to pause the game.
6. Press `S` to save the game.
7. Press `H` to view high scores.
8. Press `ESC` to exit the game.

## Example Gameplay
```
Press G to Start.
Press C to Continue.
Score: 100
Lives: 3
GAME OVER!
```

## Files in This Repository
- `SpaceInvaders.cpp`: Main game logic and implementation.
- `game.txt`: Stores saved game state.
- `SpaceInvaders.sln`: Visual Studio solution file.

## Limitations
- Requires `myconsole.h` and `mygraphics.h` (ensure they are available).
- No support for multiplayer.
- No sound effects.

