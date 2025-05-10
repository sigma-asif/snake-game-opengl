# snake-game-opengl
My first university project—a simple Snake Game made in OpenGL.reviving the nostalgia of childhood gaming. Smooth movement, retro vibes, and pure coding joy!

# Snake Game

My first university project—a simple Snake Game made in OpenGL.reviving the nostalgia of childhood gaming. Smooth movement, retro vibes, and pure coding joy!
Control a snake, eat food, grow longer, and avoid collisions with walls and yourself.

![Snake Game](https://github.com/sigma-asif/snake-game-opengl/blob/958901a4ad784faac5a4ab77ded8534df4818ea0/screenshots/gameplay.png)

## Features

- **Interactive Menu System** with Play, Help, and Exit options
- **Multiple Difficulty Levels** (Easy, Medium, Hard)
- **Real-time Snake Movement** controlled via arrow keys
- **Progressive Gameplay** where the snake grows with each food item eaten
- **Score Tracking** displayed at the end of each game

## Gameplay

### Controls
- **Arrow Up**: Move snake upward
- **Arrow Down**: Move snake downward
- **Arrow Left**: Move snake left
- **Arrow Right**: Move snake right
- **ESC**: Return to menu (during gameplay)

### How to Play
1. Start the game by selecting "Play" from the main menu
2. Control the snake to collect food items that appear randomly
3. Avoid collisions with walls and the snake's own body
4. Your score increases with each food item collected
5. The game ends when the snake collides with a wall or itself

## Difficulty Levels

- **Easy**: Slower snake speed for beginners
- **Medium**: Moderate speed for casual players
- **Hard**: Fast speed for experienced players

## Requirements

- OpenGL
- GLUT (OpenGL Utility Toolkit)
- C/C++ compiler

## Installation

### Prerequisites
- OpenGL and GLUT libraries
- C/C++ development environment

### Steps

1. **Install dependencies**:
   - **Windows**: Install MinGW/Visual Studio with OpenGL support
   - **Linux**: `sudo apt-get install freeglut3-dev`
   - **macOS**: `brew install freeglut`

2. **Clone the repository**:
   ```bash
   git clone https://github.com/sigma-asif/snake-game-opengl.git
   cd snake-game
   ```

3. **Compile the game**:
   - **Windows** (using MinGW):
     ```bash
     g++ -o snake_game main.cpp -lopengl32 -lfreeglut
     ```
   - **Linux/macOS**:
     ```bash
     g++ -o snake_game main.cpp -lGL -lGLU -lglut
     ```

4. **Run the game**:
   ```bash
   ./snake_game
   ```

## Screenshots

![Main Menu](https://github.com/sigma-asif/snake-game-opengl/blob/958901a4ad784faac5a4ab77ded8534df4818ea0/screenshots/menu.png)
![Main Menu](https://github.com/sigma-asif/snake-game-opengl/blob/958901a4ad784faac5a4ab77ded8534df4818ea0/screenshots/menu2.png)
![Gameplay](https://github.com/sigma-asif/snake-game-opengl/blob/958901a4ad784faac5a4ab77ded8534df4818ea0/screenshots/gameplay.png)
![Game Over](https://github.com/sigma-asif/snake-game-opengl/blob/958901a4ad784faac5a4ab77ded8534df4818ea0/screenshots/gameover.png)

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Special thanks to the OpenGL and GLUT communities
