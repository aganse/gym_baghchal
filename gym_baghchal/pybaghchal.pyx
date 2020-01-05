"""Cython interfaces to the original C level BaghChal functions.
..moduleauthor:: Andy Ganse <andy@ganse.org>
"""
import numpy as np
#from libc.time cimport time,time_t
#from libc.stdlib cimport srand, rand, RAND_MAX


statuses = [ 'SUCCESSFUL', 'FAILED', 'WINNER', 'GAME_OVER', 'INVALID_MOVE' ]


cdef extern from "baghchal.h":
    int validateParams( char *inputline, char *humanplayer, int *skill, int *gameround, 
                        int boardarray[25], int *goatstaken, int move[2] )
    int validate_player_move(char *player, int move[2], int *round, int boardarray[25])
    int place_move_in_boardarray( char *player, int *round, int move[2],
                                  int boardarray[25], int *goatstaken )
    int determine_comp_move( char *player, int boardarray[], int *skill, int move[2],
                             int *round )
    int check_for_win( char *player, int boardarray[], int *goatstaken )
    int playOneTurn( char *humanplayer, int *skill, int *round, int *boardarray,
                     int *move, int *complastmove, int *goatstaken, char *winFlag )
    int initGameMovementRules()
    int outputString( char player, int skill, int round, int boardarray[25],
                      int complastmove[2], int goatstaken, char winFlag )
    int displayTextBoard(char humanplayer, int skill, int round, int boardarray[25],
                         int complastmove[2], int goatstaken)
    int moveStr2Array( char *moveString, int *move, int moveStringLen )


cpdef py_initGameMovementRules():
    """Cython interface to the original C level initGameMovementRules() function.
    """
    status = initGameMovementRules()
    return status


cpdef py_validateParams(str inputline):
    """Cython interface to the original C level validateParams() function.
    """
    cdef char humanplayer
    cdef int skill, goatstaken, gameround, status
    cdef int[2] move
    cdef int[25] boardarray
    status = validateParams( inputline.encode("UTF-8"), &humanplayer, &skill, &gameround, boardarray, &goatstaken, move )
    return humanplayer, skill, gameround, boardarray, goatstaken, move


cpdef py_validate_player_move(char humanplayer, int[:] move, int gameround, int[:] boardarray):
    """Cython interface to the original C level validate_player_move() function.
    """
    cdef int status
    status = validate_player_move( &humanplayer, &move[0], &gameround, &boardarray[0] )
    return status


cpdef py_place_move_in_boardarray(char humanplayer, int gameround, int[:] move, int[:] boardarray, int goatstaken):
    """Cython interface to the original C level place_move_in_boardarray() function.
    """
    cdef int status
    status = place_move_in_boardarray( &humanplayer, &gameround, &move[0], &boardarray[0], &goatstaken )
    if status>0:
        print("Game status msg is %s...\n" % statuses[status])
    cdef int[:] boardarray_view = boardarray
    cdef int[:] move_view = move
    boardarray_py = np.asarray(boardarray_view)
    move_py = np.asarray(move_view)
    return status, humanplayer, gameround, boardarray_py, goatstaken, move_py


cpdef py_determine_comp_move(char humanplayer, int[:] boardarray, int skill, int[:] move, int gameround ):
    """Cython interface to the original C level place_move_in_boardarray() function.
    """
    cdef int status
    status = determine_comp_move( &humanplayer, &boardarray[0], &skill, &move[0], &gameround )
    if status>0:
        print("Game status msg is %s...\n" % statuses[status])
    cdef int[:] boardarray_view = boardarray
    cdef int[:] move_view = move
    boardarray_py = np.asarray(boardarray_view)
    move_py = np.asarray(move_view)
    return status, humanplayer, boardarray_py, skill, move_py, gameround


cpdef py_check_for_win( char humanplayer, int[:] boardarray, int goatstaken ):
    """Cython interface to the original C level check_for_win() function.
    """
    cdef int status
    status = check_for_win( &humanplayer, &boardarray[0], &goatstaken )
    return status


#cpdef py_playOneTurn(char humanplayer, int skill, int gameround, boardarraylist, int goatstaken, movelist, complastmovelist, char winFlag):
cpdef py_playOneTurn(char humanplayer, int skill, int gameround, int[:] boardarray, int goatstaken, int[:] move, int[:] complastmove, char winFlag):
    """Cython interface to the original C level playOneTurn() function.
    This is the central game-playing function that gets called one per turn, covering both tiger and goat moves.
    """
    cdef int status
    #cdef int[:] boardarray, move, complastmove
    #boardarray = np.array(boardarraylist).astype(np.int32)
    #move = np.array(movelist).astype(np.int32)
    #complastmove = np.array(complastmovelist).astype(np.int32)
    status = initGameMovementRules()
    status = playOneTurn( &humanplayer, &skill, &gameround, &boardarray[0], &move[0], &complastmove[0], &goatstaken, &winFlag )
    if status>0:
        print("Game status msg is %s...\n" % statuses[status])
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
        print("Game status msg is %s...\n" % statuses[status])

cpdef py_moveStr2Array( char *moveString ):
    cdef int status
    cdef int[:] move
    cdef int moveStringLen
    move = np.array([0,0]).astype(np.int32)
    moveStringLen = len(moveString)
    status = moveStr2Array( &moveString[0], &move[0], moveStringLen )
    if status>0:
        print("Move input status msg is %s...\n" % statuses[status])
    cdef int[:] move_view = move
    move_py = np.asarray(move_view)
    return move_py

