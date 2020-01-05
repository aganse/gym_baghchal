.. Gym_BaghChal documentation master file, created by
   sphinx-quickstart on Tue Dec  3 21:44:44 2019.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

.. automodule:: gym_baghchal.pybaghchal
   :members:
.. automodule:: tests.test_pybaghchal
   :members:

.. toctree::
   :maxdepth: 2
   :caption: Contents:

Welcome to Bagh Chal, the Nepali game of tigers and goats.
==========================================================

The board layout is the following, with array position reference #'s as well
as letter/number positions as used in the game:

::

                         A     B     C     D     E

                     1   0  -- 1  -- 2  -- 3  -- 4
                         | \   |   / | \   |   / |
                         |   \ | /   |   \ | /   |
                     2   5  -- 6  -- 7  -- 8  -- 9
                         |   / | \   |   / | \   |
                         | /   |   \ | /   |   \ |
                     3   10 -- 11 -- 12 -- 13 -- 14
                         | \   |   / | \   |   / |
                         |   \ | /   |   \ | /   |
                     4   15 -- 16 -- 17 -- 18 -- 19
                         |   / | \   |   / | \   |
                         | /   |   \ | /   |   \ |
                     5   20 -- 21 -- 22 -- 23 -- 24

Game Rules
----------

Equipment:
~~~~~~~~~~
One player is the tiger (bagh) player with four tiger pieces, and the
other is the goat (bakhri) with 20 goat pieces. The gameboard consists of
a grid of 25 points with lines of valid movement connecting them (see
graphic above).  Player movement is along these lines from point to point,
but notice there aren't lines between every point so there are some
restrictions to this movement.

The game could be played on a computer screen, on a specially made Bagh
Chal board with its game pieces, or even on a piece of notebook paper with
the gameboard pattern scrawled on it and with pennies and nickels for game
pieces.

Setup:
~~~~~~
The four tigers are placed in the four corner points of the gameboard.
(But the goat will go first - see below.)

Object:
~~~~~~~
There is a different object for each of the two players:

The tiger must jump ("capture") five goats to win.  See Game Play for
details on tigers jumping goats. In some versions of the game the tiger
player must jump and capture all the goats to win, not just five, but
friends and I have found that once you've captured five goats, you've no
problem capturing the rest. So the five goats rule probably just came out
of an interest in shortening an inevitably lost game.  Myself I prefer the
five-goat rule.

The goat player must try to make it so there is no valid move left for any
tiger before the tiger eats five of his goats (or all of them, if you
prefer the long and tedious version of the game), by using the goats to
crowd in on the tigers and prevent both jumping and regular movement.  
This can become particularly difficult if more than a few goats have been
captured.

Game Play:
~~~~~~~~~~
Players take turns, moving or placing one piece per turn. The goat player
goes first.

Goat movement:
~~~~~~~~~~~~~~
There are two phases of the game.  In the first, the "setup" phase, the
goat player sets one goat on the gameboard per turn, but cannot move any
goats once they are on the board until all 20 goats have been played.  In
the second phase, the "take-down" phase, which begins after the goat
player has played all 20 goats, the goat player may move one goat on the
board per turn along a movement line to an available, adjacent point on
the gameboard.

Tiger movement:
~~~~~~~~~~~~~~~
The tiger player may move one tiger per turn, either along a movement line
to an available, adjacent point on the gameboard, or by jumping a goat
that is accessible along a movement line and which has an open point on
its far side to land in.  Goat-jumping may only be over a single goat.  
When a goat is jumped it is removed from the gameboard and considered
"captured".

Play continues until one of the players wins by reaching their object (see
Object section).




Indices and tables
------------------

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`
