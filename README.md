# Hangman-game
# About the game
For making this game I worked with classes. For the game I used the class "Cuvant". For each object in this class we will have a word, word'slength, the hidden word and a maximum of 5 wrong guesses. I used encapsulation so for each attribute we will have a get and a set method. For this class we have a text file with words in it. I did a randomiser where random words are read from the text file. The writing operator overloading is being used for having the hidden word displayed on screen. I also have a class "User" for rankings. For this class we have 2 attributes: a name and a maximum score. For the reading one I'm reading a name, moment when it opens the text file
with rankings and searches game history for that name. The writing operator overloading is being used for writing into my ranking, at the end of the game (when the life variable reaches 0 value), the player's name, score and how many words he managed to guess. My third class named "Citire" is used for the reading part, where the player can introduce the whole word or letter by letter. When you reach 5 wrong guesses the game ends.
# Menu
![Game menu](https://i.imgur.com/lh29MYb.png)
Option 1 is for starting the game, 2 is for searching a name into the scoreboard, 3 is to see the full scoreboard, 4 is for a short tutorial and 0 is for quitting the application.
# Making guesses in the game
![Guesses](https://i.imgur.com/4vEkzG9.png)
By inserting one letter at a time or by inserting the whole word.
# Searching a person in the scoreboard and see his history of plays.
![Searching](https://i.imgur.com/bUgxYOS.png)
# Scoreboard
![Scoreboard](https://i.imgur.com/dTCcp5B.png)
