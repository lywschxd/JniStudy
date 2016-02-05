package com.dd.jnistudy;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;

import com.dd.jni.StringCommon;

public class MainActivity extends Activity {
    private static final String TAG = "Java[MainActivity]";
    StringCommon common;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        common = new StringCommon();
    }

    public void printNative(View v) {
        common.printf("hello world");
    }

    public void getNatvieMsg(View v) {
        ((Button)v).setText(common.getNativeMsg("show"));
    }

    public void ChangeAttr(View v) {
        common.setNativeCount();
        Log.e(TAG, ""+common.getCount());
    }

    public void CallFunction(View v) {
        common.callNativeSetCount(100);
        Log.e(TAG, ""+common.getCount());
    }

    public void CallFunctionDiffType(View v) {
        common.callNativeDiffType(20, 2.3f, "Hello", StringCommon.JNI_METHOD_TYPE_2);
        Log.e(TAG, common.toString());
    }

    public void CallSuperFunction(View v) {
        common.callFatherFunction();
    }

}
