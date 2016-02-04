//
// Created by 东东 on 16/2/4.
//
#include "com_dd_jni_StringCommon.h"
#include "stdio.h"
#include "string.h"
#include "android/log.h"

#define TAG "JNI[StringCommon]"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__)
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__)

/*
 * Class:     com_dd_jni_StringCommon
 * Method:    printf
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_dd_jni_StringCommon_printf
        (JNIEnv *env, jobject obj, jstring msg) {
    char *str = (*env)->GetStringUTFChars(env, msg, JNI_FALSE);
    LOGE("this is the native print:%s\n", str);
    (*env)->ReleaseStringUTFChars(env, msg, str);
}

/*
 * Class:     com_dd_jni_StringCommon
 * Method:    getNativeMsg
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_dd_jni_StringCommon_getNativeMsg
        (JNIEnv *env, jobject obj, jstring msg) {
    char *str = (*env)->GetStringUTFChars(env, msg, JNI_FALSE);
    strcat(str, ":native!");
    jstring ret = (*env)->NewStringUTF(env, str);
    (*env)->ReleaseStringUTFChars(env, msg, str);
    return ret;
}

/*
 * Class:     com_dd_jni_StringCommon
 * Method:    setNativeCount
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_dd_jni_StringCommon_setNativeCount
        (JNIEnv *env, jobject obj) {
    jclass clazz = (*env)->GetObjectClass(env, obj);
    jfieldID countId = (*env)->GetFieldID(env, clazz, "count", "I");
    jint count = (*env)->GetIntField(env, obj, countId);
    LOGE("the attr count is :%d\n", count);
    (*env)->SetIntField(env, obj, countId, 10);
}

/*
 * Class:     com_dd_jni_StringCommon
 * Method:    callNativeSetCount
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_dd_jni_StringCommon_callNativeSetCount
        (JNIEnv *env, jobject obj, jint num) {
    jclass clazz = (*env)->GetObjectClass(env, obj);
    jmethodID setCountId = (*env)->GetMethodID(env, clazz, "setCount", "(I)V");
    (*env)->CallVoidMethod(env, obj, setCountId, num);
}


/*
 * Class:     com_dd_jni_StringCommon
 * Method:    callNativeDiffType
 * Signature: (IFLjava/lang/String;I)V
 */
JNIEXPORT void JNICALL Java_com_dd_jni_StringCommon_callNativeDiffType
        (JNIEnv *env, jobject obj, jint p1, jfloat p2, jstring p3, jint type) {
    jclass clazz = (*env)->GetObjectClass(env, obj);
    jfieldID type0Id = (*env)->GetStaticFieldID(env, clazz, "JNI_METHOD_TYPE_0", "I");
    jfieldID type1Id = (*env)->GetStaticFieldID(env, clazz, "JNI_METHOD_TYPE_1", "I");
    jfieldID type2Id = (*env)->GetStaticFieldID(env, clazz, "JNI_METHOD_TYPE_2", "I");
    jint type0 = (*env)->GetStaticIntField(env, clazz, type0Id);
    jint type1 = (*env)->GetStaticIntField(env, clazz, type1Id);
    jint type2 = (*env)->GetStaticIntField(env, clazz, type2Id);
    jmethodID setParamId = (*env)->GetMethodID(env, clazz, "setParam", "(IFLjava/lang/String;)V");
    if (type == type0) {
        LOGE("use CallVoidMethod to call Java");
        (*env)->CallVoidMethod(env, obj, setParamId);
    } else if (type == type1) {
    } else if (type == type2) {
        LOGE("use CallVoidMethodA to call Java");
        jvalue args[3];
        args[0].i = p1;
        args[1].f = p2;
        args[2].l = p3;
        (*env)->CallVoidMethodA(env, obj, setParamId, args);
    }
}

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    return JNI_VERSION_1_4;
}

