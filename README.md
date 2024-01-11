
# Repository  Deatails                             
Repository                                   : https://github.com/sathmipeiris/MINE-SWEEPER-GAME
- [G.N.K LAKSHAN  21/ENG/031]                  : https://github.com/gnklakshan
- [Manavi Amanda Hettiarachchi  21/ENG/077 ]   : https://github.com/Mani-Amanda
- [Sathmi Vihansa Peiris    21/ENG/035  ]      : https://github.com/sathmipeiris


  
# MINE SWEEPER GAME
Mine Sweeper is a console-based game where players identify and flag mine locations in a field. The game offers three field sizes, each with a different number of mines. Players interact with the game by entering commands to place a flag or reveal a location. The game ends when a player reveals a mine or correctly flags all mines.

## Game Features

- Three field options with varying grid sizes and mine counts:
  1. 10-by-10 Field with 12 Mines
  2. 15-by-15 Field with 18 Mines
  3. 20-by-20 Field with 24 Mines

- Players start with a number of flags equivalent to the number of mines in the selected field.

## How to Play

1. **Select Field Size:** Choose the desired field size at the beginning of the game.
2. **Initial Display:** The field is displayed with all locations covered (indicated by 'c'). Mines are randomly buried in the field.
3. **Game Commands:** Enter commands in the format `<row letter><column letter><command>`:
   - **Row Letter:** A, B, C, etc.
   - **Column Letter:** A, B, C, etc.
   - **Command:**
     - `F`: Place a flag on the location.
     - `R`: Reveal the uncovered location.

4. **Game Iterations:** After each iteration, the updated field is displayed to the player.
   - If a flag is placed, the location will be marked with 'F'.
   - If a location is revealed and contains no mine, the number of mines in the eight neighbors is indicated. A dot (.) is displayed if no mines are present in the neighbors.

5. **Winning:** The player wins when all mines are correctly flagged.
6. **Losing:** If a mine is uncovered, the game stops, and the mine locations are revealed.

## Example Field

After a few iterations, a 10-by-10 field might look like this:

|   | `A` | `B` | `C` | `D` | `E` | `F` | `G` | `H` | `I` | `J` |
|---|---|---|---|---|---|---|---|---|---|---|
| `A` | c | c | c | c | c | c | c | c | c | c |
| `B` | c | c | c | c | c | c | c | c | c | c |
| `C` | c | c | c | c | c | c | c | c | c | c |
| `D` | c | c | . | . | . | c | c | c | c | c |
| `E` | c | c | . | 1 | F | c | c | c | c | c |
| `F` | c | c | . | 2 | . | 2 | c | c | c | c |
| `G` | c | c | F | 1 | . | c | c | c | c | c |
| `H` | c | c | . | . | . | c | c | c | c | c |
| `I` | c | c | c | c | c | c | c | c | c | c |
| `J` | c | c | c | c | c | c | c | c | c | c |


In this example, the player strategically places flags and reveals locations based on the number of mines in neighboring cells.

## Contributors [![GitHub contributors](https://img.shields.io/github/contributors/sathmipeiris/MINE-SWEEPER-GAME.svg)](https://github.com/sathmipeiris/MINE-SWEEPER-GAME/graphs/contributors)
- [G.N.K LAKSHAN](https://github.com/gnklakshan)
- [Manavi Amanda Hettiarachchi](https://github.com/Mani-Amanda)
- [Sathmi Vihansa Peiris](https://github.com/sathmipeiris)
