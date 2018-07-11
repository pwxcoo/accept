class ExamRoom {
    int N;
    TreeSet<Integer> students;

    public ExamRoom(int N) {
        this.N = N;
        students = new TreeSet();
    }

    public int seat() {
        int student = 0;
        if (students.size() > 0) {
            int dist = students.first();
            Integer prev = null;
            for (Integer s: students) {
                if (prev != null) {
                    int d = (s - prev) / 2;
                    if (d > dist) {
                        dist = d;
                        student = prev + d;
                    }
                }
                prev = s;
            }

            // Considering the right-most seat.
            if (N - 1 - students.last() > dist)
                student = N - 1;
        }

        students.add(student);
        return student;
    }

    public void leave(int p) {
        students.remove(p);
    }
}
/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */