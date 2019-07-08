

cdef extern from "baghchal.h":
    int validateParams( char *inputline, char *humanplayer, int *skill, int *gameround, 
                        int boardarray[25], int *goatstaken, int move[2] )


cpdef py_validateParams(str inputline):
    cdef char[1] humanplayer
    cdef int[1] skill, goatstaken, gameround
    cdef int move[2]
    cdef int boardarray[25]
    cdef int status
    #print('inputline: '+inputline)
    status = validateParams( inputline.encode("UTF-8"), humanplayer, skill, gameround, boardarray, goatstaken, move )
    return humanplayer[0], skill[0], gameround[0], boardarray, goatstaken[0], move

#cpdef py_playOneTurn(name: bytes) -> None:
#    cdef int[1] x
#    playOneTurn(name)
#
#def py_outputString(name: bytes) -> None:
#    outputString(name)

def testme():
    inputline = 'player=T&skill=1&round=002&boardarray=1000100000100002000000001&goatstaken=00&move=a1%2Cb1'
    humanplayer, skill, gameround, boardarray, goatstaken, move = py_validateParams(inputline)
    print('humanplayer='+str(humanplayer))
    print('skill='+str(skill))
    print('gameround='+str(gameround))
    print('goatstaken='+str(goatstaken))
    #print(boardarray, move)

