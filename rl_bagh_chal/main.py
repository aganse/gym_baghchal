import numpy as np
import rl_bagh_chal.pybaghchal as pbc


# Ask player for skill level and whether they want to be tiger or goat
# (just hardwiring these answers for now)
inputline = 'player=T&skill=1&round=001&boardarray=1000100000000000000010001&goatstaken=00&move=a1%2Ca2'
humanplayer, skill, gameround, boardarray, goatstaken, move = pbc.py_validateParams(inputline)

# Actually play the game - loop over rounds
winflag = False
while not winflag:

    status, humanplayer, skill, gameround, boardarray, goatstaken, move, complastmove, winFlag = \
        pbc.py_playOneTurn(humanplayer,
                           skill,
                           gameround,
                           np.array(boardarray).astype(np.int32),
                           goatstaken,
                           np.array(move).astype(np.int32),
                           np.array([1,-1]).astype(np.int32),
                           0
        )
    pbc.py_displayTextBoard(humanplayer,
                           skill,
                           gameround,
                           np.array(boardarray).astype(np.int32),
                           goatstaken,
                           np.array([1,-1]).astype(np.int32)
    )

    if not winflag or gameround>5:
        # request move
        moveStr = input('Enter next move:')

        # validate entered move, and set "move" array out of that
        # could use C invalidMoveEntry and moveStr2Array functions?
        move = pbc.py_moveStr2Array( moveStr.encode('utf-8') )       

    else:
        print('   %s won!' % ('tiger' if winflag=='T' else 'goat'))

#if __name__ == '__main__':
#    blah
