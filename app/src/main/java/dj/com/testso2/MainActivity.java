package dj.com.testso2;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import dj.com.jni.demo1;
import dj.com.jni.GeoRela;
import dj.com.myGeometry.Line;
import dj.com.myGeometry.Point;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    TextView tv = null;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        tv = (TextView) findViewById(R.id.sample_text);
        Button btn = (Button) findViewById(R.id.btn1);

        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tv.setText(stringFromJNI());
                demo1 demo = new demo1();
                demo.show();
                GeoRela do2 = new GeoRela();
                int sum = do2.getIntFromC(4, 6);
                String str = do2.getStringFromC("dj and xc");
                Point p1 = new Point(10.0, 12.0);
                Point p2 = new Point(10.0, 13.0);
                Point p3 = new Point(10.0, 14.0);
                Line line = new Line(p1, p2);
                boolean pointsEqual = do2.eqPoints(p1, p2);
                boolean online = do2.isOnline(p1, line);
                Log.i("dj",str + "*****" + sum + "********" + pointsEqual + "********" + online);
            }
        });

    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}
