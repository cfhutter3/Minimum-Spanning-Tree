# Miminum-Spanning-Tree
# When I first looked at this assignment, I instantly made a very poor decision.  I decided to try to implement the algorithm recursively…  I’ll come back to that.

# I made a class called MSTMaker, and the first two functions I implemented were functions to read in the graph from a file and write out the MST to a file.  I later modified the write function to also output the MST to the screen, and I added a function to output the inputted graph to the screen.

# After I wrote main() and got the structure of the program working smoothly, I started on the MST algorithm.  Now, remember when I said I would try to implement the MST algorithm recursively?  Well, the very fact that I tried to do that shows that I did not fully understand the algorithm because the algorithm is not recursive in nature at all.  So, after the most complex and junky recursive algorithm I’ve ever written, I scrapped the entire thing and went back to square one.

# I pulled up the slides from class and studied Primm’s algorithm more closely, and with some careful, methodical programming, I managed to correctly reproduce an MST algorithm in C++.
