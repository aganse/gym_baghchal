import pybaghchal

# Write out instructions

# Ask player for skill level and whether they want to be tiger or goat

# Actually play the game - loop over rounds
winflag = False
while not winflag:

    status = py_playOneTurn()
    if not status:
        print('invalid move for %s. try again.' % ('tiger' if humanplayer=='T' else 'goat'))
    else:  # ie if turn was valid
        # Display the resulting gameboard

    if not winflag:
        # request move

        # validate entered move, and set "move" array out of that
        # could use C invalidMoveEntry and moveStr2Array functions?

    else:
        print('   %s won!' % ('tiger' if winflag=='T' else 'goat'))


