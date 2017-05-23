package com.example.ourapp;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.content.Intent;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.ProgressBar;
import android.widget.TextView;

import com.example.ourapp.DbHelper.DbHelper;
import com.example.ourapp.Model.Ranking;

public class Done extends AppCompatActivity {
    Button btnTryAgain;
    TextView txtResultScore;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_done);

        DbHelper db = new DbHelper(this);


        txtResultScore = (TextView) findViewById(R.id.txtTotalScore);
        btnTryAgain = (Button) findViewById(R.id.btnTryAgain);
        btnTryAgain.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                startActivity(intent);
                finish();
            }
        });


        Bundle extra = getIntent().getExtras();
        if (extra != null) {
            int score = extra.getInt("SCORE");


            int playCount = 0;

            double subtract = (((float)score)*100)*(playCount-1); //-1 because we playCount++ before we calculate result
            double finalScore = score - subtract;

            txtResultScore.setText(String.format("SCORE : %.1f ", finalScore,(playCount-1)));


        }
    }
}
