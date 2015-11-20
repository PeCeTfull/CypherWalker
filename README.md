# Cypher Walker #

Cypher Walker is a dynamic logic game designed for both vintage and modern computers (as an experiment) where your task is to fill the board consisting of randomly generated digits (from 1 to 9) with as many zeros as you simply can. It was written in C++ and uses wxWidgets GUI library. This game was created in order to celebrate the 20th Anniversary of Windows 95!

### How to play? ###

When you start the game, you are given a board which is of size 25x25. The first zero is located at coordinates 13x13 (the centre of the game board) and thus, this is your starting point. In the beginning, you have four directions available until the probable movement in any case would cause the board boundary to be surpassed or your path basically becomes an obstacle. The neighbouring digit represents the number of steps – if all conditions are met and you decide to go there, you are obviously away that number of steps from your previous position and gain the same amount of points. The game finishes once no movements are possible while in order to appear in the high score list, you must reach at least the amount of points the fifth person has. Good luck!

Tip: Right after you launch Cypher Walker, if you click the left mouse button on "Play" or press the Tab key and then Enter on your keyboard, you will be able to use it for making decisions with the following keyboard controls: I for going up, J for going left, L for going right and K for going down.

### Game options ###

There, you can change sounds that are played during the game, such as when a new game is started, a movement is made, the game is lost or the player qualified to the top 5 of high scores. To mute any of them, just clear its corresponding text box. You can also choose another language.

### Recommended programming setup ###

Source and target OS: Windows

IDE: Code::Blocks Release 13.12 rev 9501 (2013/12/25 19:25:45) gcc 4.7.1 Windows/unicode - 32 bit

wxWidgets version: 2.8.12 (SHARED=0 MONOLITHIC=1 UNICODE=0)

Additional info: The post-build script for Release contains the line that launches UPX (if it exists) in order to compress the executable file. Please change UPX directory to your desired one or simply remove the line if you do not have the program, otherwise the files from the "common" directory may not be successfully copied after compiling.

### Program licence ###

Cypher Walker is published under The MIT License. Please refer to the LICENSE.txt file of this repository for more information regarding it.