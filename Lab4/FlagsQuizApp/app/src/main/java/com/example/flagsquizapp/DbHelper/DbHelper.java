package com.example.flagsquizapp.DbHelper;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteException;
import android.database.sqlite.SQLiteOpenHelper;
import android.os.Build;
import android.util.Log;

import com.example.flagsquizapp.Model.Question;
import com.example.flagsquizapp.Model.Ranking;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by pc on 30/04/2017.
 */

public class DbHelper extends SQLiteOpenHelper {
    private static String DB_NAME = "MyDB.db";
    private static String DB_PATH = "";
    private SQLiteDatabase mDataBase;
    private Context mContext = null;

    public DbHelper(Context context) {
        super(context, DB_NAME, null, 1);

        DB_PATH = context.getApplicationInfo().dataDir + "/databases/";
        File file = new File(DB_PATH+"MyDB.db");
        if(file.exists())
            openDataBase(); // Add this line to fix db.insert can't insert values
        this.mContext = context;
    }

    public void openDataBase() {
        String myPath = DB_PATH + DB_NAME;
        mDataBase = SQLiteDatabase.openDatabase(myPath, null, SQLiteDatabase.OPEN_READWRITE);
    }

    public void copyDataBase() throws IOException {
        try {
            InputStream myInput = mContext.getAssets().open(DB_NAME);
            String outputFileName = DB_PATH + DB_NAME;
            OutputStream myOutput = new FileOutputStream(outputFileName);

            byte[] buffer = new byte[1024];
            int length;
            while ((length = myInput.read(buffer)) > 0)
                myOutput.write(buffer, 0, length);

            myOutput.flush();
            myOutput.close();
            myInput.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private boolean checkDataBase() {
        SQLiteDatabase tempDB = null;
        try {
            String myPath = DB_PATH + DB_NAME;
            tempDB = SQLiteDatabase.openDatabase(myPath, null, SQLiteDatabase.OPEN_READWRITE);
        } catch (SQLiteException e) {
            e.printStackTrace();
        }
        if (tempDB != null)
            tempDB.close();
        return tempDB != null ? true : false;
    }

    public void createDataBase() throws IOException {
        boolean isDBExists = checkDataBase();
        if (isDBExists) {

        } else {
            this.getReadableDatabase();
            try {
                copyDataBase();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    @Override
    public synchronized void close(){
if(mDataBase != null)
    mDataBase.close();
        super.close();
    }

    @Override
    public void onCreate(SQLiteDatabase db) {

    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {

    }

    //CRUD For Table
    public List<Question> getAllQuestion() {
        List<Question> listQuestion = new ArrayList<>();
        SQLiteDatabase db = this.getWritableDatabase();
        Cursor c;
        try {
            c = db.rawQuery("SELECT * FROM Question ORDER BY Random()", null);
            if (c == null) return null;
            c.moveToFirst();
            do {
                int Id = c.getInt(c.getColumnIndex("ID"));
                String Image = c.getString(c.getColumnIndex("Image"));
                String AnswerA = c.getString(c.getColumnIndex("AnswerA"));
                String AnswerB = c.getString(c.getColumnIndex("AnswerB"));
                String AnswerC = c.getString(c.getColumnIndex("AnswerC"));
                String AnswerD = c.getString(c.getColumnIndex("AnswerD"));
                String CorrectAnswer = c.getString(c.getColumnIndex("CorrectAnswer"));

                Question question = new Question(Id, Image, AnswerA, AnswerB, AnswerC, AnswerD, CorrectAnswer);
                listQuestion.add(question);
            }
            while (c.moveToNext());
            c.close();
        } catch (Exception e) {
            e.printStackTrace();
        }

        db.close();
        return listQuestion;
    }

    //Insert Score to Ranking table
    public void insertScore(int Score){

            SQLiteDatabase db = this.getWritableDatabase();
            ContentValues contentValues = new ContentValues();
            contentValues.put("Score", Score);
            db.insert("Ranking", null, contentValues);
        }

    //Get Score and sort ranking
    public List<Ranking> getRanking() {
        List<Ranking> listRanking = new ArrayList<>();
        SQLiteDatabase db = this.getReadableDatabase();
        Cursor c;
        try {
            c = db.rawQuery("SELECT * FROM Ranking Order By Score DESC;", null);
            if (c == null) return null;
            c.moveToNext();
            do {
                int Id = c.getInt(c.getColumnIndex("Id"));
                double Score = c.getDouble(c.getColumnIndex("Score"));

                Ranking ranking = new Ranking(Id, Score);
                listRanking.add(ranking);
            } while (c.moveToNext());
            c.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        db.close();
        return listRanking;

    }

}
