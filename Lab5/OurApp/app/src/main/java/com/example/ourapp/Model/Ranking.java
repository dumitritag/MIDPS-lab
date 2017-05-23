package com.example.ourapp.Model;

/**
 * Created by pc on 23/05/2017.
 */

public class Ranking {
    private int Id;
    private double Score;

    public Ranking(int id, double score) {
        Id = id;
        Score = score;
    }

    public int getId() {
        return Id;
    }

    public void setId(int id) {
        Id = id;
    }

    public double getScore() {
        return Score;
    }

    public void setScore(double score) {
        Score = score;
    }
}
