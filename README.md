# Boundary-finder
We can build a quadtree from a two-dimensional area implementing the following steps

*The current two dimensional space is divided into four boxes as specified in the file.
*If a box consists of one or more points in it, build a child object, storing in it the two dimensional space of the box.
*If a box does not contain any points, do not build a child for it.
*Perform recursion for each of the children.

Insert Function:

The insert functions is implemented to insert a node into an existing Quad Tree. 
This function first verifies whether the given node is within the boundaries of the current quad.
If it is not, then we immediately cancel the insertion. If it is within the boundaries, we choose the appropriate child to contain this node based on its location.
This function is O(Log N) where N indicates the size of distance.


Search Function:
The search function is implemented to locate a node in the given quad.
It can also be edited to return the closest node to the given point. 
This function is applied by taking the given point, comparing with the boundaries of the child quads and recursing. 
This function is O(Log N) where N indicates the size of distance.

Point Quadtrees:
Given the next point to insert, we compute the cell in which it lies and add it to the tree.

The new point is added such that the cell that contains it is divided into quadrants by the vertical and horizontal lines that run through the point.

The below steps will be carried out:
1. The extent rectangle will be read from a text file.
2. The query point (x,y) will be taken from standard input.
3. The intersection of the point with the rectangle will be displayed

The tree will organize the two dimensional information.
