I have divided the program in 8 functions.

>First of all, I call a function get_random_shape to generate random shape
 between !-% using rand() and srand(), then I use this function in another
function create_board to fill the array of 10x10 with these random shapes.
(i also call check_board function to see if at the starting there are 3 pairs
or no)

>Secondly, after filling the 10x10 board I use the swapping function which 
(with cout rules) swaps the desired symbols, by using coordinates of the 
symbol and then press W/A/S/D for swapping with neighbouring symbols.

[NOTE : I have created a function refresh_board that Clearn screens and 
displays the board when i call it]

i use refresh_board whenever the user swap and then give a 800Millisecond
(0.8sec) pause then check for revert_swapping which i take from check_board; 

[NOTE : the function check_board returns a bool revert_swapping. it basically
checks the whole board if it founds combo of 3 it bools revert_swapping to
false, otherwise if it doesnt finds any combo it turns revert_swapping to
true.]

Now if the swapping is done successfully, it scores +10 points.However, if u 
combine a 3-combo symbol and in a result futher in the board some combos 
automatically get destroyed you dont get extra credit for those combos since u 
only destroyed a 3-combo by yourself. You still will get +10 scores.

Then,I ask the user to enter 'S','L','X',Y' for Save,Load,Quit,Continue respectively.
Entering 'S' saves the game into "SymphonyOfSymbols.txt" and Entering 'L'
will load the Board in the .txt file.

Then, I have applied my logic (I save the start index and end index in the 2d array combo) in check_board function. I have used 2x2 array named
combo to fill like this           i      j
                                  i      j+2   (for horizontal)
and 
                                  i       j
                                 i+2      j    (for vertical)
Then, i applied a loop condition to replace symbols with "-" to show the user
the breaking of symbols. Then again i refresh_board. 
Now, i use another nested loop to drop the symbols down and get random shapes
in upper tiles. Then again it checks board for possible 3-pair combos.




 

