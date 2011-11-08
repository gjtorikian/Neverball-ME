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



import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.Window;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class UsernameActivity extends Activity {

	/*private Button saveButton;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
				
		setContentView(R.layout.username_dialog);
		
		setTitle(R.string.username_title);
				
		final EditText username = (EditText) findViewById(R.id.username);

		saveButton = (Button) this.findViewById(R.id.save_button);
		saveButton.setOnClickListener(new OnClickListener() {

			public void onClick(View v) {
				final String enteredText = username.getText().toString();
				
				if(enteredText.matches("[a-zA-z]+")) 
				{
					Intent outData = new Intent();
					outData.putExtra("username", username.getText().toString());
					setResult(MainActivity.RESULT_OK, outData);

					finish();
				}
				else
				{
					Toast.makeText(getApplicationContext(), R.string.alpha_only, Toast.LENGTH_SHORT).show();
				}
			}
		});
	}*/
}
