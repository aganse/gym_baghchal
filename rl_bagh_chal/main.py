from random import random
import sys
import numpy as np
import rl_bagh_chal.pybaghchal as pbc


# Ask player for skill level and whether they want to be tiger or goat
# (just hardwiring these answers for now)
inputline = 'player=T&skill=1&round=000&boardarray=1000100000000000000010001&goatstaken=00&move=a1%2Ca1'
humanplayer, skill, gameround, boardarray, goatstaken, move = pbc.py_validateParams(inputline)
#humanplayer = 'T'
#skill = 1
#gameround = 0
#boardarray = np.array([1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1])
#goatstaken = 0
#move = np.array([-1, -1])
complastmove = np.array([-1, -1])
winflag = 0

# display initial state of board
#pbc.py_displayTextBoard(humanplayer,
#                        skill,
#                        gameround,
#                        np.array(boardarray).astype(np.int32),
#                        goatstaken,
#                        np.array(complastmove).astype(np.int32)
#)

# now loop over turns of the game
while winflag==0:

    status, humanplayer, skill, gameround, boardarray, goatstaken, move, complastmove, winflag = \
        pbc.py_playOneTurn(humanplayer,
                           skill,
                           gameround,
                           np.array(boardarray).astype(np.int32),
                           goatstaken,
                           np.array(move).astype(np.int32),
                           np.array(complastmove).astype(np.int32),
                           winflag,
        )
    pbc.py_displayTextBoard(humanplayer,
                           skill,
                           gameround,
                           np.array(boardarray).astype(np.int32),
                           goatstaken,
                           np.array(complastmove).astype(np.int32)
    )

    if winflag==0:
        # request move
        moveStr = input('Enter next move:')
        if moveStr == 'q':
            # quit game
            sys.exit()

        # validate entered move, and set "move" array out of that
        # could use C invalidMoveEntry and moveStr2Array functions?
        move = pbc.py_moveStr2Array( moveStr.encode('utf-8') )       

    else:
        print('   %s won!' % ('tiger' if winflag=='T' else 'goat'))

#if __name__ == '__main__':
#    blah
