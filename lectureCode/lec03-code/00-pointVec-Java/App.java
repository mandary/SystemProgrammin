
public class App {
  public static void main(String args[]) {
    Point myPoint = new Point(0.0, 0.0);
    Vector unitX = new Vector(1.0, 0.0);
    Vector unitY = new Vector(0.0, 1.0);

    System.out.print( myPoint.toString() + 
                      " + " +
                      unitX.toString() + 
                      " + " +
                      unitY.toString() + 
                      " = "
                    );
    myPoint.addVector(unitX).addVector(unitY);
    System.out.println(myPoint.toString());
  }
}
