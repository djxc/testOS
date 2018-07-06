//
// Created by Administrator on 2018/7/3.
//
#include "dj_com_jni_GeoRela.h"
#include <iostream>
#include "GeoRelation.h"

using namespace std;

/*
 * Class:     dj_com_jni_demo2
 * Method:    getStringFromNative
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_dj_com_jni_GeoRela_getStringFromNative
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
JNIEXPORT jint JNICALL Java_dj_com_jni_GeoRela_getNumFromNative
        (JNIEnv *env, jclass, jint b, jint a){
    return a + b;
}

JNIEXPORT jint JNICALL Java_dj_com_jni_GeoRela_equalPoints
        (JNIEnv *env, jclass,  jdouble p1x, jdouble p1y, jdouble p2x, jdouble p2y)
{
    POINT p1(p1x, p1y), p2(p2x, p2y);
    GeoRelation geoRelation;
    bool equal = geoRelation.equal_point(p1, p2);
    return equal ? 1 : 0;
}

JNIEXPORT jint JNICALL Java_dj_com_jni_GeoRela_online
        (JNIEnv *env, jclass, jdoubleArray arr)
{
    jint i, sum = 0;
    jdouble *c_array;
    jsize arr_len;
    //获取数组的指针
    c_array = env->GetDoubleArrayElements(arr, 0);
    if (c_array == NULL) {
        return NULL;   // JVM复制原始数据到缓冲区失败
    }
    //获取数组的大小
    arr_len = env->GetArrayLength(arr);
    POINT p(c_array[0], c_array[1]), ls(c_array[2], c_array[3]), le(c_array[4], c_array[5]);
    LINESEG line(ls, le);
    GeoRelation geoRelation;
    bool equal = geoRelation.online(line, p);
    return equal ? 1 : 0;
}

void test(int a, int b){
    int c = max(a, b);
}
