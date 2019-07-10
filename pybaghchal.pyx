

cdef extern from "baghchal.h":
    int validateParams( char *inputline, char *humanplayer, int *skill, int *gameround, 
                        int boardarray[25], int *goatstaken, int move[2] )
    int playOneTurn( char *humanplayer, int *skill, int *round, int *boardarray,
                        int *move, int *complastmove, int *goatstaken, int *winFlag )
    int outputString( char player, int skill, int round, int boardarray[25],
                        int complastmove[2], int goatstaken, int winFlag )


cpdef py_validateParams(str inputline):
    cdef char[1] humanplayer
    cdef int[1] skill, goatstaken, gameround
    cdef int move[2]
    cdef int boardarray[25]
    cdef int status
    status = validateParams( inputline.encode("UTF-8"), humanplayer, skill, gameround, boardarray, goatstaken, move )
    return humanplayer[0], skill[0], gameround[0], boardarray, goatstaken[0], move

#cpdef py_playOneTurn(humanplayer, skill, gameround, boardarray, move, complastmove, goatstaken, winFlag):
#    cdef char[1] humanplayer
#    cdef int[1] skill, goatstaken, gameround
#    cdef int move[2]
#    cdef int boardarray[25]
#    cdef int status
#    status = playOneTurn( humanplayer, skill, gameround, boardarray, move, complastmove, goatstaken, winFlag )
#    return humanplayer[0], skill[0], gameround[0], boardarray, goatstaken[0], move, complastmove, winFlag[0]

#def py_outputString(name: bytes) -> None:
#    outputString(name)

def test1():
    inputline = 'player=T&skill=1&round=002&boardarray=1000100000100002000000001&goatstaken=00&move=a1%2Cb1'
    humanplayer, skill, gameround, boardarray, goatstaken, move = py_validateParams(inputline)
    print('  inputline: '+inputline)
    print('humanplayer: '+chr(humanplayer))
    print('      skill: '+str(skill))
    print('  gameround: '+str(gameround))
    print(' goatstaken: '+str(goatstaken))
    print(' boardarray: '+''.join(map(str,boardarray)))
    print(f'       move: {str(move[0])},{str(move[1])}')


def test2():
    inputline = 'player=T&skill=1&round=001&boardarray=1020100000000000000010001&goatstaken=00&move=a1%2Cb1'
    humanplayer, skill, gameround, boardarray, goatstaken, move = py_validateParams(inputline)
    print('  inputline: '+inputline)
    print('humanplayer: '+chr(humanplayer))
    print('      skill: '+str(skill))
    print('  gameround: '+str(gameround))
    print(' goatstaken: '+str(goatstaken))
    print(' boardarray: '+''.join(map(str,boardarray)))
    print(f'       move: {str(move[0])},{str(move[1])}')

