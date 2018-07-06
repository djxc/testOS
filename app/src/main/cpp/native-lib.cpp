#include <jni.h>
#include <string>
#include <math.h>

extern "C"
JNIEXPORT jstring JNICALL
Java_dj_com_testso2_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {

    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
