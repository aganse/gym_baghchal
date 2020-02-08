from random import random
import sys
import numpy as np
import gym_baghchal.pybaghchal as pbc
from gym_baghchal.playTurn import playTurn


# Ask player for skill level and whether they want to be tiger or goat
# (just hardwiring these answers for now)
humanplayer = ord('T')
skill = 1
gameround = 0
boardarray = [1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1]
boardarray = np.array(boardarray).astype(np.int32)  # to ease cython
goatstaken = 0
move = [-1, -1]  # required default for game start
move = np.array(move).astype(np.int32)  # to ease cython
complastmove = [-1, -1]
complastmove = np.array(complastmove).astype(np.int32)  # to ease cython
winflag = 0


# loop over turns of the game
while winflag==0:

    status, humanplayer, skill, gameround, boardarray, goatstaken, move, complastmove, winflag = \
        playTurn(
        #pbc.py_playOneTurn(
            humanplayer,
            skill,
            gameround,
            boardarray,
            goatstaken,
            move,
            complastmove,
            winflag
        )

    pbc.py_displayTextBoard(
            humanplayer,
            skill,
            gameround,
            boardarray,
            goatstaken,
            complastmove
    )

    if winflag==0:
        moveStr = input('Enter next move:')
        if moveStr == 'q':
            # quit game
            sys.exit()

        # validate entered move, and set "move" array out of that.
        move = pbc.py_moveStr2Array( moveStr.encode('utf-8') )       

    else:
        print('   %s won!' % ('tiger' if winflag==ord('T') else 'goat'))
