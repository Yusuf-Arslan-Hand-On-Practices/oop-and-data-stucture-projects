We have a class named Point2D which represents a point in 2D space (x, y).

In the main function, I asked the user enter the coordinates of 4 point which will represent 2 lines.

Before calculation of intersection we need to check if the lines are parallel or not.
This is calculated by the formula:
    (y2 - y1) / (x2 - x1) = (y4 - y3) / (x4 - x3)


Then by the formulas that are:
    x = ((x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4))
    y = ((x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4))
I calculated the intersection point of the 2 lines.


