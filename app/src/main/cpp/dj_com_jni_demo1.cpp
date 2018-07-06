//
// Created by Administrator on 2018/7/2.
//
#include <jni.h>
#include "dj_com_jni_demo1.h"

JNIEXPORT jstring JNICALL Java_dj_com_jni_demo1_getStringFromNative
        (JNIEnv *env, jclass )
{
    return env -> NewStringUTF("This just a test for Android Studio NDK JNI developer!");
}
