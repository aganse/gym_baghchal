"""Cython interfaces to the original C level BaghChal functions.
..moduleauthor:: Andy Ganse <andy@ganse.org>
"""

import numpy as np

cdef extern from "baghchal.h":
    int validateParams( char *inputline, char *humanplayer, int *skill, int *gameround, 
                        int boardarray[25], int *goatstaken, int move[2] )
    int playOneTurn( char *humanplayer, int *skill, int *round, int *boardarray,
                        int *move, int *complastmove, int *goatstaken, int *winFlag )
    int initGameMovementRules()
    int outputString( char player, int skill, int round, int boardarray[25],
                        int complastmove[2], int goatstaken, int winFlag )
    int displayTextBoard(char humanplayer, int skill, int round, int boardarray[25],
                           int complastmove[2], int goatstaken)
    int moveStr2Array( char *moveString, int *move, int moveStringLen )


cpdef py_validateParams(str inputline):
    """Cython interface to the original C level validateParams() function.
    """
    cdef char humanplayer
    cdef int skill, goatstaken, gameround, status
    cdef int[2] move
    cdef int[25] boardarray
    status = validateParams( inputline.encode("UTF-8"), &humanplayer, &skill, &gameround, boardarray, &goatstaken, move )
    return humanplayer, skill, gameround, boardarray, goatstaken, move

cpdef py_playOneTurn(char humanplayer, int skill, int gameround, int[:] boardarray, int goatstaken, int[:] move, int[:] complastmove, int winFlag):
    """Cython interface to the original C level playOneTurn() function.
    This is the central game-playing function that gets called one per turn, covering both tiger and goat moves.
    """
    cdef int status
    status = initGameMovementRules()
    status = playOneTurn( &humanplayer, &skill, &gameround, &boardarray[0], &move[0], &complastmove[0], &goatstaken, &winFlag )
    if status>0:
        print("uh oh, playOneTurn() exit status was %d...\n" % status)
    cdef int[:] boardarray_view = boardarray
    cdef int[:] move_view = move
    cdef int[:] complastmove_view = complastmove
    boardarray_py = np.asarray(boardarray_view)
    move_py = np.asarray(move_view)
    complastmove_py = np.asarray(complastmove_view)
    return status, humanplayer, skill, gameround, boardarray_py, goatstaken, move_py, complastmove_py, winFlag

cpdef py_displayTextBoard(char humanplayer, int skill, int gameround, int[:] boardarray, int goatstaken, int[:] complastmove):
    """Cython interface to the original C level displayTextBoard() function."""
    cdef int status
    status = displayTextBoard( humanplayer, skill, gameround, &boardarray[0], &complastmove[0], goatstaken )
    if status>0:
        print("uh oh, playOneTurn() exit status was %d...\n" % status)

cpdef py_moveStr2Array( char *moveString ):
    cdef int status
    cdef int[:] move
    cdef int moveStringLen
    move = np.array([0,0]).astype(np.int32)
    moveStringLen = len(moveString)
    status = moveStr2Array( &moveString[0], &move[0], moveStringLen )
    if status>0:
        print("uh oh, moveStr2Array() exit status was %d...\n" % status)
    cdef int[:] move_view = move
    move_py = np.asarray(move_view)
    return move_py

