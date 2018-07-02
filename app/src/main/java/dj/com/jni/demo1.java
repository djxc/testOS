package dj.com.jni;

import android.util.Log;

/**
 * Created by Administrator on 2018/7/2.
 */

public class demo1 {
    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    public void show(){
        Log.i("dj", getStringFromNative());
    }

    public static native String getStringFromNative();
}
