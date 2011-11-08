package com.miadzin.neverballme;
/*
 * Copyright (C) 2010 Garen J Torikian
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

import android.content.Context;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.content.pm.PackageManager.NameNotFoundException;

import android.view.Display;
import android.view.WindowManager;

public class NeverballMESupport {

	static public String getAPKPath(Context context)
	{
		String apkFilePath = null;
        ApplicationInfo appInfo = null;
        PackageManager packMgmr = context.getPackageManager();
        try {
            appInfo = packMgmr.getApplicationInfo("com.miadzin.neverballme", 0);
        } 
        catch (NameNotFoundException e) {
            e.printStackTrace();
            throw new RuntimeException("Unable to locate assets, aborting...");
        }

        return appInfo.sourceDir;
	}

	static public int[] getDimensions(Context context)
	{
		int[] d = new int[2];

		Display display = ((WindowManager) context.getSystemService(Context.WINDOW_SERVICE)).getDefaultDisplay();
		d[0] = display.getWidth();
		d[1] = display.getHeight();

		return d;
	}
}
