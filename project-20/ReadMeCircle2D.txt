Circle2D class has 3 data fields:
    
      * double x, y
      * double radius

Beside the getters and constructors, this class includes following methods:
    
      * getArea(): double
      * getPerimeter(): double
      * contains(x: double, y: double): boolean
      * contains(circle: Circle2D): boolean
      * overlaps(circle: Circle2D): boolean

getArea() returns the area of the circle.
    
getPerimeter() returns the perimeter of the circle.

contains(x, y) returns true if the specified point (x, y) is inside this circle.

contains(circle) returns true if the specified circle is inside this circle.

overlaps(circle) returns true if the specified circle overlaps with this circle.

TESTING THE CLASS
In Driver.Java, we have a method 'DriverCircle2D' which is called in the main method. 

