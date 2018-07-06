package dj.com.myGeometry;

/**
 * Created by Administrator on 2018/7/6.
 */

public class Line {
    private Point startP;
    private Point endP;

    public Line(Point sp, Point ep)
    {
        this.startP = sp;
        this.endP = ep;
    }

    public Point getStartP() {
        return startP;
    }

    public void setStartP(Point startP) {
        this.startP = startP;
    }

    public Point getEndP() {
        return endP;
    }

    public void setEndP(Point endP) {
        this.endP = endP;
    }
}
