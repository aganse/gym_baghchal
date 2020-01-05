import unittest
import numpy as np
import gym_baghchal.pybaghchal as pbc


class TestCfuncAccess(unittest.TestCase):

    # useful in debugging new tests...
        #print('  inputline: '+inputline)
        #print('humanplayer: '+chr(humanplayer))
        #print('      skill: '+str(skill))
        #print('  gameround: '+str(gameround))
        #print(' goatstaken: '+str(goatstaken))
        #print(' boardarray: '+''.join(map(str,boardarray)))
        #print(f'       move: {str(move[0])},{str(move[1])}')
        #print(f'cmplastmove: {str(complastmove[0])},{str(complastmove[1])}')
        #print('    winflag: '+str(winFlag))
        #print('');

    def test_valparams(self):
        """Test the operation of validating parameters from python to the C code."""
        inputline = 'player=T&skill=1&round=002&boardarray=1000100000100002000000001&goatstaken=00&move=a1%2Cb1'
        humanplayer, skill, gameround, boardarray, goatstaken, move = pbc.py_validateParams(inputline)
        self.assertEqual(chr(humanplayer), "T", "Should be 'T'")
        self.assertEqual(skill, 1, "Should be 1")
        self.assertEqual(gameround, 2, "Should be 2")
        self.assertEqual(goatstaken, 0, "Should be 0")
        self.assertEqual("".join(map(str,boardarray)), "1000100000100002000000001", "Should be 1000100000100002000000001")
        self.assertEqual("".join(map(str,move)), "01", "Should be '01'")
    
    
    def test_playoneturn(self):
        """Test the operation of playing one turn from python to the C code."""
        inputline = 'player=T&skill=1&round=002&boardarray=1020100000000000000010001&goatstaken=00&move=a1%2Ca2'
        humanplayer, skill, gameround, boardarray, goatstaken, move = pbc.py_validateParams(inputline)
        status, humanplayer, skill, gameround, boardarray, goatstaken, move, complastmove, winFlag = \
            pbc.py_playOneTurn(humanplayer, skill, gameround, np.array(boardarray).astype(np.int32), goatstaken, np.array(move).astype(np.int32), np.array([1,-1]).astype(np.int32), 0)
        self.assertEqual(status, 0, "Should be 0")
        self.assertEqual(chr(humanplayer), "T", "Should be 'T'")
        self.assertEqual(skill, 1, "Should be 1")
        self.assertEqual(gameround, 3, "Should be 3")
        self.assertEqual(goatstaken, 0, "Should be 0")
        self.assertEqual(boardarray[5], 1, "Should be 1 (tiger moved to here)")
        self.assertNotEqual(boardarray[0], 1, "Should not be 1 (tiger moved away from here)")
        # move[] contains garbage values because computer was last player
        self.assertEqual(boardarray[complastmove[0]], 2, "Should be 2 (goat added to here)")
    
    
    def test_moveStr2Array(self):
        """Test the operation of converting entry to player-move-array, from python to the C code."""
        moveString = 'a1,a2'
        move = pbc.py_moveStr2Array( moveString.encode('utf-8') )
        self.assertEqual(move[0], 0, "Should be 0 (starting position)")
        self.assertEqual(move[1], 5, "Should be 1 (ending position)")


if __name__ == '__main__':
    unittest.main()
