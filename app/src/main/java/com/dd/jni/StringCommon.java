package com.dd.jni;

/**
 * Created by dong on 16/2/4.
 */
public class StringCommon {
    static {
        System.loadLibrary("string-common");
    }

    public static final int JNI_METHOD_TYPE_0 = 0;
    public static final int JNI_METHOD_TYPE_1 = 1;
    public static final int JNI_METHOD_TYPE_2 = 2;

    private int count = 0;
    private int param1 = 1;
    private float param2 = 2.0f;
    private String param3 = "common";
    private Father father = new Child();

    public int getCount() {
        return count;
    }

    public void setCount(int count) {
        this.count = count;
    }

    public void setParam(int p1, float p2, String p3) {
        param1 = p1;
        param2 = p2;
        param3 = p3;
    }

    @Override
    public String toString() {
        return "count:"+count+", param1:"+param1+", param2:"+param2+", param3:"+param3;
    }

    public native void printf(String msg);
    public native String getNativeMsg(String msg);

    public native void setNativeCount();
    public native void callNativeSetCount(int count);
    public native void callNativeDiffType(int p1, float p2, String p3, int type);
    public native void callFatherFunction();
}
