import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

import static java.util.Collections.sort;
//最后一个点超时,c++能过
class student implements Comparable {
    private String name;
    private int points;
    private int midScore;
    private int finalScore;
    private int score;
    student(){
        this.points = -1;
        this.midScore = -1;
        this.finalScore = -1;
        this.score = -1;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getPoints() {
        return points;
    }

    public void setPoints(int points) {
        this.points = points;
    }

    public int getMidScore() {
        return midScore;
    }

    public void setMidScore(int midScore) {
        this.midScore = midScore;
    }

    public int getFinalScore() {
        return finalScore;
    }

    public void setFinalScore(int finalScore) {
        this.finalScore = finalScore;
    }

    public int getScore() {
        return score;
    }

    public void setScore(int score) {
        this.score = score;
    }

    @Override
    public int compareTo(Object o) {
        student s = (student) o;
        return this.getScore() == s.getScore() ? this.getName().compareTo(s.getName()) : s.getScore() - this.getScore();
    }
}

public class Main {
    /**
     * pat advanced 1137
     * @param args
     */

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext())
        {
            List<student> res = new ArrayList<student>();
            int pNumber = sc.nextInt();
            int mNumber = sc.nextInt();
            int nNumber = sc.nextInt();
            Map<String, student> students = new HashMap<String, student>();
            for(int i = 0; i < pNumber; i++)
            {
                String name = sc.next();
                int score = sc.nextInt();
                if(students.containsKey(name))
                {
                    student temp = students.get(name);
                    temp.setPoints(score);
                    students.put(name, temp);
                }
                else
                {
                    student temp = new student();
                    temp.setName(name);
                    temp.setPoints(score);
                    students.put(name, temp);
                }
            }
            for(int i = 0; i < mNumber; i++)
            {
                String name = sc.next();
                int score = sc.nextInt();
                if(students.containsKey(name))
                {
                    student temp = students.get(name);
                    temp.setMidScore(score);
                    students.put(name, temp);
                }
                else
                {
                    student temp = new student();
                    temp.setName(name);
                    temp.setMidScore(score);
                    students.put(name, temp);
                }
            }
            for(int i = 0; i < nNumber; i++)
            {
                String name = sc.next();
                int score = sc.nextInt();
                if(students.containsKey(name))
                {
                    student temp = students.get(name);
                    temp.setFinalScore(score);
                    students.put(name, temp);
                    //System.out.printf(String.format("%s %d %d %d %d\n", temp.getName(), temp.getPoints(), temp.getMidScore(), temp.getFinalScore(), s.getScore()));
                }
                else
                {
                    student temp = new student();
                    temp.setName(name);
                    temp.setFinalScore(score);
                    students.put(name, temp);
                }
            }
            for(Map.Entry<String, student> s : students.entrySet())
            {
                student temp = s.getValue();
                if(temp.getPoints() < 200)
                {
//                    students.remove(s.getKey());
                    continue;
                }
                if(temp.getMidScore() > temp.getFinalScore())
                {
                    temp.setScore((int)((double)temp.getMidScore() * 0.4 + (double)temp.getFinalScore() * 0.6 + 0.5));
                }
                else
                {
                    temp.setScore(temp.getFinalScore());
                }
                if(temp.getScore() < 60) continue;
                res.add(temp);
            }
            sort(res);
            for(student s: res)
            {
                System.out.printf(String.format("%s %d %d %d %d\n", s.getName(), s.getPoints(), s.getMidScore(), s.getFinalScore(), s.getScore()));
            }

        }
    }

}
