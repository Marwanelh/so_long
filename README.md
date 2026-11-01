_This project has been created as part of the 42 curriculum by mael-hou._

# So_long - 2D Game Project

<p align="center">
  <img src="https://img.shields.io/badge/Score-Pending-yellow" alt="Score">
  <img src="https://img.shields.io/badge/Language-C-blue" alt="Language">
  <img src="https://img.shields.io/badge/Graphics-MLX42-green" alt="Graphics">
  <img src="https://img.shields.io/badge/Norminette-Passing-success" alt="Norminette">
</p>

## Description

**So_long** is a small 2D game developed as part of the 42 school curriculum. The project focuses on window management, event handling, textures, and sprites using the **MLX42** graphics library.

### Project Goal

Build a functional game where the player must:

- Collect all collectibles on the map
- Navigate through a maze-like environment
- Reach the exit after collecting all items
- Avoid obstacles and enemies (bonus)

This project introduces fundamental concepts in:

- **Graphics programming** using MLX42
- **Event handling** (keyboard input)
- **Map parsing and validation**
- **Pathfinding algorithms** (flood fill)
- **Memory management** in C
- **Sprite animation** (bonus)

### Features

#### Mandatory Part

- ✅ Parse and validate `.ber` map files
- ✅ Render 2D top-down view with textures
- ✅ Smooth player movement (WASD/Arrow keys)
- ✅ Collectible items (coins)
- ✅ Exit door unlocked after collecting all items
- ✅ Move counter displayed in terminal
- ✅ Map validation with flood fill algorithm
- ✅ Proper error handling and memory management

#### Bonus Part

- 🎮 Animated sprites (player, coins, enemies)
- 👾 Enemy AI with collision detection
- 📊 On-screen move counter
- 🎵 Background music
- 🎬 Start and game over screens
- 🔑 Additional collectibles (keys, traps)
- ✨ Visual effects and transitions

---

## Instructions

### Prerequisites

The following dependencies are required:

```bash
# On Ubuntu/Debian
sudo apt-get update
sudo apt-get install build-essential libglfw3-dev libglfw3 xorg-dev

# On macOS
brew install glfw cmake
```

### Compilation

#### Mandatory Version

```bash
make
```

This will compile the mandatory version of the game, creating the `so_long` executable.

#### Bonus Version

```bash
make bonus
```

This will compile the bonus version with additional features, creating the `so_long_bonus` executable.

#### Clean Build Files

```bash
make clean   # Remove object files
make fclean  # Remove object files and executables
make re      # Rebuild from scratch
```

### Execution

#### Running the Game

```bash
# Mandatory version
./so_long maps/test_simple.ber

# Bonus version
./so_long_bonus maps/monster_arena.ber
```

#### Map File Format

Maps must follow the `.ber` format with these rules:

- **Characters**:
  - `1` - Wall
  - `0` - Empty space
  - `P` - Player starting position (exactly 1)
  - `C` - Collectible/Coin (at least 1)
  - `E` - Exit (exactly 1)
  - `M` - Enemy (bonus only)
  - `K` - Key (bonus only)
  - `T` - Trap (bonus only)

- **Requirements**:
  - Map must be rectangular
  - Map must be surrounded by walls (`1`)
  - Must contain exactly 1 player and 1 exit
  - Must contain at least 1 collectible
  - All collectibles and exit must be reachable from player start

**Example Map**:

```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

### Controls

#### Mandatory Version

- `W` / `↑` - Move up
- `A` / `←` - Move left
- `S` / `↓` - Move down
- `D` / `→` - Move right
- `ESC` - Exit game

#### Bonus Version

- Same movement controls
- `SPACE` - Start game / Restart after game over
- `ESC` - Exit game

---

## Project Structure

```
so_long/
├── src/                      # Mandatory source files
│   ├── main.c               # Entry point and cleanup
│   ├── map.c                # Map file reading
│   ├── check_map.c          # Map validation
│   ├── flood_fill.c         # Pathfinding algorithm
│   ├── init.c               # Game initialization
│   ├── render.c             # Rendering system
│   ├── hooks.c              # Event handling
│   ├── movement.c           # Player movement logic
│   ├── animation.c          # Animation system
│   ├── utils.c              # Utility functions
│   └── get_next_line/       # File reading utility
│
├── bonus/                    # Bonus source files
│   ├── main_bonus.c         # Bonus entry point
│   ├── enemy_init.c         # Enemy spawning
│   ├── enemy_move.c         # Enemy AI
│   ├── menu.c               # Game state management
│   ├── music.c              # Audio system
│   └── ...
│
├── include/                  # Header files
│   └── MLX42/               # MLX42 library headers
│
├── libft/                    # Custom C library
├── maps/                     # Map files (.ber)
├── textures/                 # Sprite images (PNG)
├── sound/                    # Audio files
├── so_long.h                # Main header
├── so_long_bonus.h          # Bonus header
├── Makefile                 # Build configuration
└── README.md                # This file
```

---

## Technical Implementation

### Key Algorithms

#### 1. Flood Fill Algorithm

Used for map validation to ensure all collectibles and the exit are reachable:

```c
// Recursive depth-first search
void flood(char **map, int x, int y, t_map *info)
{
    if (out_of_bounds || is_wall || already_visited)
        return;

    if (is_collectible)
        info->coins--;

    mark_as_visited(map[y][x]);

    flood(map, x+1, y, info);  // Check all 4 directions
    flood(map, x-1, y, info);
    flood(map, x, y+1, info);
    flood(map, x, y-1, info);
}
```

**Purpose**: Validates that the player can reach all game objectives before the game starts.

#### 2. Animation System

Frame-based sprite animation using image instances:

- Multiple frame images stored in arrays
- Frame counter controls animation speed
- Toggle visibility between frames for smooth animation
- Same system used for player, coins, and enemies

#### 3. Enemy AI (Bonus)

Simple patrol-based movement:

- Enemies move horizontally or vertically
- Reverse direction when hitting obstacles
- Check collision with player each frame
- Trigger game over on contact

### Memory Management

- **No memory leaks**: Verified with Valgrind
- Proper cleanup on all exit paths
- `mlx_terminate()` handles MLX resource cleanup
- Dynamic map allocation with proper freeing

---

## Resources

### Documentation

- [MLX42 Official Documentation](https://github.com/codam-coding-college/MLX42)
- [MLX42 API Reference](https://github.com/codam-coding-college/MLX42/wiki)
- [GLFW Documentation](https://www.glfw.org/documentation.html)
- [42 So_long Subject](https://cdn.intra.42.fr/pdf/pdf/xxxxx/so_long.en.pdf)

### Learning Resources

- **Flood Fill Algorithm**:
  - [Wikipedia - Flood Fill](https://en.wikipedia.org/wiki/Flood_fill)
  - [GeeksforGeeks - Flood Fill Algorithm](https://www.geeksforgeeks.org/flood-fill-algorithm/)
- **Graphics Programming**:
  - [Learn OpenGL - Getting Started](https://learnopengl.com/Getting-started/OpenGL)
  - [Game Programming Patterns](https://gameprogrammingpatterns.com/)

- **C Programming**:
  - [Beej's Guide to C Programming](https://beej.us/guide/bgc/)
  - [Modern C (Jens Gustedt)](https://modernc.gforge.inria.fr/)

### Tutorials Referenced

- [MLX42 Tutorial Series](https://harm-smits.github.io/42docs/libs/minilibx)
- [2D Game Development Basics](https://www.youtube.com/watch?v=3zffie-H-hY)
- [Sprite Animation Techniques](https://www.youtube.com/watch?v=8-JBIqBTNPU)

### AI Usage Disclosure

AI tools were utilized in the following aspects of this project:

#### Code Development

- **Debugging assistance**: AI helped identify and explain memory leaks and segmentation faults
- **Algorithm optimization**: Suggestions for improving flood fill efficiency and readability
- **Error handling**: Best practices for defensive programming in C
- **Code explanations**: Understanding MLX42 API behavior and proper usage

#### Documentation

- **Code comments**: AI assisted in writing clear, concise function documentation
- **README structure**: Formatting and organization suggestions for this README
- **Evaluation guide**: AI helped create comprehensive code explanation for defense

#### Learning

- **Concept clarification**: Understanding graphics pipeline, texture management, and event loops
- **Best practices**: Modern C programming standards and memory safety patterns
- **Algorithm analysis**: Time/space complexity of flood fill and pathfinding

**Note**: All core logic, algorithms, and implementation were written and understood by the student. AI was used as a learning tool and documentation assistant, not for code generation.

---

## Testing

### Memory Leak Testing

```bash
# Test with Valgrind
valgrind --leak-check=full --show-leak-kinds=all ./so_long maps/test_simple.ber

# Expected output on error cases:
# "All heap blocks were freed -- no leaks are possible"
```

### Map Validation Testing

The project includes test maps for various scenarios:

- ✅ `test_simple.ber` - Valid simple map
- ✅ `test_minimal.ber` - Smallest valid map
- ❌ `test_empty.ber` - Empty file (should fail)
- ❌ `test_invalid.ber` - Missing walls (should fail)
- ❌ `test_no_path.ber` - Unreachable collectibles (should fail)

---

## Bonus Features Showcase

### Game States

1. **Start Screen**: Press SPACE to begin
2. **Playing**: Collect coins, avoid enemies
3. **Game Over**: Collision with enemy
4. **Victory**: Collect all coins and reach exit

### Enemy System

- Spawned from `M` tiles in map
- Patrol patterns (horizontal/vertical)
- Collision detection with player
- Animated sprites

### Visual Enhancements

- Smooth fade transitions between states
- Animated sprites for all entities
- On-screen move counter
- Visual feedback for collectibles

### Audio

- Background music using system audio player
- Process-based audio management
- Graceful fallback if audio unavailable

---

## Known Issues & Limitations

- **Audio**: Music may not work on systems without audio libraries (mpg123, aplay)
- **Performance**: Large maps (>50x50) may experience frame drops on older hardware
- **Portability**: Tested on Linux (Ubuntu) and macOS; Windows compatibility uncertain

---

## Acknowledgments

- **42 School** for the project subject and learning framework
- **MLX42 Team** (Codam) for the modern graphics library
- **Peers** for code reviews and testing feedback
- **42 Community** for shared knowledge and resources

---

## License

This project is part of the 42 school curriculum and is intended for educational purposes only.

---

## Author

**mael-hou** - [42 Intra Profile](https://profile.intra.42.fr/users/mael-hou)

_Project completed: January 2026_

---

**Final Score**: _125_

_Feel free to reach out for questions or feedback!_
