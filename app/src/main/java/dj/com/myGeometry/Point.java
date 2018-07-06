package dj.com.myGeometry;

/**
 * Created by Administrator on 2018/7/6.
 */

public class Point {
    double x;
    double y;

    public Point(double _x, double _y){
        this.x = _x;
        this.y = _y;
    }

    public double getY() {
        return y;
    }

    public void setY(double y) {
        this.y = y;
    }

    public double getX() {
        return x;
    }

    public void setX(double x) {
        this.x = x;
    }
}
