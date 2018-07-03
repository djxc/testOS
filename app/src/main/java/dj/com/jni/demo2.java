package dj.com.jni;

import android.util.Log;

/**
 * Created by Administrator on 2018/7/3.
 */

public class demo2 {

    static {
        System.loadLibrary("native-lib");
    }

    public void getIntFromC(){
        int sum = getNumFromNative(3, 5);
        Log.i("dj", sum + "");
    }

    public void getStringFromC(){
        Log.i("dj", getStringFromNative("dj"));
    }

    public static native String getStringFromNative(String name);
    public static native int getNumFromNative(int a, int b);
}
