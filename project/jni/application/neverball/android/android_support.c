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

#include "android_support.h"
#include "SDL_main.h"

void Java_com_miadzin_neverballme_DemoRenderer_setDataPaths(JNIEnv* env, jclass clazz, jstring apk, jstring sdcard)
{
    jboolean isCopy;
    apkPath = (*env)->GetStringUTFChars(env, apk, &isCopy);
	sdCardPath = (*env)->GetStringUTFChars(env, sdcard, &isCopy);
}

void Java_com_miadzin_neverballme_DemoRenderer_setDimensions(JNIEnv* env, jclass clazz, jint width, jint height)
{
	deviceWidth = width;
	deviceHeight = height;

	if (deviceWidth * deviceHeight <= HDPI_SIZE)
	{
		#define IS_PHONE 1
	}
	else
	{
		#define IS_PHONE 0
	}
}