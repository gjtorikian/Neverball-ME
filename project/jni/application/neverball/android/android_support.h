/*
 * Copyright (C) 2011 Garen J. Torikian
 *
 * NEVERBALL is  free software; you can redistribute  it and/or modify
 * it under the  terms of the GNU General  Public License as published
 * by the Free  Software Foundation; either version 2  of the License,
 * or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT  ANY  WARRANTY;  without   even  the  implied  warranty  of
 * MERCHANTABILITY or  FITNESS FOR A PARTICULAR PURPOSE.   See the GNU
 * General Public License for more details.
 */

#ifndef ANDROID_SUPPORT_H
#define ANDROID_SUPPORT_H

// GJT: Android helper definitions

#include <android/log.h>
#include <jni.h>

#define  LOG_TAG    "libneverball"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

// GJT: Why can't I define this here? stdio.h seems to complain. It must be defined in all 
// files it's being used.
//#define  fprintf(f, fmt, ...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, fmt, __VA_ARGS__) 

#define RELEASE 1 // GJT: Comment ONLY this line out if you're building this on your own
#define ENABLE_NLS 1 // GJT: Controls localization
#define ENABLE_OPENGLES 1
#define GL_VERSION_ES_CM_1_1 1
#define PHYSFS_SUPPORTS_ZIP 1 // GJT: For PhysFS zip/apk support
#define ANDROID_DATA "assets/data/"

const char* apkPath;
const char* sdCardPath;

int deviceWidth;
int deviceHeight;
#define HDPI_SIZE 320000 // GJT: Literally, 800 * 400. Shitty way to detect large phone v. tablet (which affects GUI options)

void Java_com_miadzin_neverballme_DemoRenderer_setDataPaths(JNIEnv* env, jclass clazz, jstring apkPath, jstring sdcard);
void Java_com_miadzin_neverballme_DemoRenderer_setDimensions(JNIEnv* env, jclass clazz, jint width, jint height);

#endif
