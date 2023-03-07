// Implementation of the Circle2D class
public class Circle2D {

  private double x;
  private double y;
  private double radius;

  // This is a default constructor that sets the instance variables to 0 and 1.
  public Circle2D() {
    x = 0;
    y = 0;
    radius = 1;
  }

  // This is a constructor that takes in three parameters and sets the instance variables to the
  // parameters.
  public Circle2D(double x, double y, double radius) {
    this.x = x;
    this.y = y;
    this.radius = radius;
  }

  // Getters
  public double getX() {
    return x;
  }

  public double getY() {
    return y;
  }

  public double getRadius() {
    return radius;
  }

  
  /**
   * Returns the area of the circle
   */
  public double getArea() {
    return Math.PI * radius * radius;
  }

  /**
   * Returns the perimeter of the circle
   */
  public double getPerimeter() {
    return 2 * Math.PI * radius;
  }

  /**
   * If the distance between the point and the center of the circle is less than the radius, the point
   * is inside the circle
   */
  public boolean contains(double x, double y) {
    return Math.sqrt((x - this.x) * (x - this.x) +
                     (y - this.y) * (y - this.y)) < radius;
  }

  /**
   * The function returns true if the specified circle is inside this circle
   */
  public boolean contains(Circle2D circle) {
    double distance = Math.sqrt(Math.pow(x - circle.x,2) + Math.pow(y - circle.y,2));
    return distance + circle.radius <= radius;
  }

  /**
   * If the distance between the centers of the two circles is less than the sum of the two radii, then
   * the circles overlap
   */
  public boolean overlaps(Circle2D circle) {
    double distance = Math.sqrt(Math.pow(x - circle.x,2) + Math.pow(y - circle.y,2));
    return distance < radius + circle.radius;
  }
}