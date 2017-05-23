package com.example.ourapp;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.CountDownTimer;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.ProgressBar;
import android.widget.TextView;

import java.util.ArrayList;
import java.util.List;

import com.example.ourapp.DbHelper.DbHelper;

public class Playing extends AppCompatActivity {

    final static long INTERVAL = 1000; // 1 second
    final static long TIMEOUT = 7000; // 7 sconds
    int progressValue = 0;

    CountDownTimer mCountDown; // for progressbar
    DbHelper db;
    int index=0,score=0;
    String mode="";

    //Control
    ProgressBar progressBar;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_playing);

        //Get Data from MainActivity
        Bundle extra = getIntent().getExtras();
        if(extra != null)
            mode=extra.getString("MODE");

        db = new DbHelper(this);

    }

    @Override
    protected void onResume() {
        super.onResume();

    }

    }

