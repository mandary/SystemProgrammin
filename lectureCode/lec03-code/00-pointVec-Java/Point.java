
public class Point {
  public double x;
  public double y;

  public Point(double initialX, double initialY) {
    x = initialX;
    y = initialY;
  }

  public String toString() {
    return "Point(" + x + ", " + y + ")";
  }

  public Point addVector(Vector v) {
    x += v.x;
    y += v.y;
    return this;
  }

}
