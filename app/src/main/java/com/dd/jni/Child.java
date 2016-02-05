package com.dd.jni;

import android.util.Log;

/**
 * Created by dong on 16/2/5.
 */
public class Child extends Father {
    private static final String TAG = "Java[Child]";
    @Override
    public void function() {
        Log.d(TAG, "this is the child class");
    }
}
