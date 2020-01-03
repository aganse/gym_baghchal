import rl_bagh_chal.pybaghchal as pbc


def playTurn(humanplayer, skill, gameround, boardarray, goatstaken, move, complastmove, winflag):

    compplayer = ord('G') if humanplayer==ord('T') else ord('T')  # opposite of humanplayer
    status = pbc.py_initGameMovementRules()

    if not (gameround==0 and humanplayer==ord('G')):  # (goat always goes first)

        if not gameround==0:
            # play human player
            if pbc.statuses[
                pbc.py_validate_player_move(humanplayer,
                                        move,
                                        gameround,
                                        boardarray)
            ] == 'FAILED':
                print('INVALID MOVE')
                status = 4
                return status, humanplayer, skill, gameround, boardarray, goatstaken, move, complastmove, winflag 

            # place that move into the boardarray
            status, humanplayer, gameround, boardarray_py, goatstaken, move_py = \
                pbc.py_place_move_in_boardarray(humanplayer, gameround, move, boardarray, goatstaken)

            # check for win condition
            if pbc.statuses[
                pbc.py_check_for_win(humanplayer, boardarray, goatstaken )
            ] == 'WINNER':
                winflag = humanplayer
                print('GAME OVER')
                status = 3
                return status, humanplayer, skill, gameround, boardarray, goatstaken, move, complastmove, winflag 

        # play computer player
        status, compplayer, boardarray_py, skill, move_py, gameround = \
            pbc.py_determine_comp_move(compplayer, boardarray, skill, move, gameround )

        # place that move into the boardarray
        status, compplayer, gameround, boardarray_py, goatstaken, move_py = \
            pbc.py_place_move_in_boardarray(compplayer, gameround, move, boardarray, goatstaken)

        # check for win condition
        if pbc.statuses[
            pbc.py_check_for_win(compplayer, boardarray, goatstaken )
        ] == 'WINNER':
            winflag = compplayer
            print('GAME OVER')
            status = 3
            return status, humanplayer, skill, gameround, boardarray, goatstaken, move, complastmove, winflag 

    complastmove = move
    gameround = gameround + 1
    status = 0  # successful

    return status, humanplayer, skill, gameround, boardarray, goatstaken, move, complastmove, winflag
