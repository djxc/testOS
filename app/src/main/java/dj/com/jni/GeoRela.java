package dj.com.jni;

import android.util.Log;

import dj.com.myGeometry.Line;
import dj.com.myGeometry.Point;

/**
 * Created by Administrator on 2018/7/3.
 */

public class GeoRela {

    static {
        System.loadLibrary("native-lib");
    }

    public int getIntFromC(int a, int b){
        return getNumFromNative(a, b);
    }

    public String getStringFromC(String str){
        return getStringFromNative(str);
    }

    public boolean eqPoints(Point p1, Point p2){
        int equal = equalPoints(p1.getX(), p1.getY(), p2.getX(), p2.getY());
        return equal == 1;
    }

    public boolean isOnline(Point p, Line l)
    {
        double[] xy = {p.getX(), p.getY(), l.getStartP().getX(), l.getStartP().getY(),l.getEndP().getX(), l.getEndP().getY()};
        return online(xy) == 1;
    }

    public static native String getStringFromNative(String name);
    public static native int getNumFromNative(int a, int b);
    public static native int equalPoints(double p1x, double p1y, double p2x, double p2y);
    public static native int online(double[] xy);

}
