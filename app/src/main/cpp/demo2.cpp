//
// Created by Administrator on 2018/7/3.
//
#include "../jni/dj_com_jni_demo2.h"
#include <iostream>
using namespace std;

/*
 * Class:     dj_com_jni_demo2
 * Method:    getStringFromNative
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_dj_com_jni_demo2_getStringFromNative
        (JNIEnv *env, jclass , jstring jstr){

    char *result = NULL;

    //  先找到JAVA/String类
    jclass strCls = env->FindClass("java/lang/String");
    jstring encodeMothed = env->NewStringUTF("UTF8");

    jmethodID java_getBytes = env->GetMethodID(strCls, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray)env->CallObjectMethod(jstr, java_getBytes, encodeMothed);
    jsize length = env->GetArrayLength(barr);

    jbyte *ba = env->GetByteArrayElements(barr, JNI_FALSE);
    if (length > 0) {
        result = (char *)malloc(length + 1);
        memcpy(result, ba, length);
        result[length] = 0;

        env->ReleaseByteArrayElements(barr, ba, 0);
    }
    jstring rtstr = env->NewStringUTF(result);
    return rtstr;
    }

/*
 * Class:     dj_com_jni_demo2
 * Method:    getNumFromNative
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_dj_com_jni_demo2_getNumFromNative
        (JNIEnv *env, jclass, jint b, jint a){
    return a + b;
}

