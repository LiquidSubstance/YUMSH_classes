#include <bits/stdc++.h>

using namespace std;

class Student {
private:
    string name;
    map<string, vector<double>> grades;
public:
    Student(string name) {
        this->name = name;
        this->grades = map<string, vector<double>>();
    }
    string get_name() {
        return name;
    }
    map<string, vector<double>> get_grades() {
        return grades;
    }
    void set_name(string name) {
        this->name = name;
    }
    void add_grade(string subject, double grade) {
        if (grades.find(subject) != grades.end()) {
            grades[subject].push_back(grade);
        } else {
            grades[subject] = {grade};
        }
    }
    double get_mean(string subject) {
        double s = 0;
        if (grades.find(subject) == grades.end()) {
            return -1;
        }
        for (double g : grades[subject]) {
            s += g;
        }
        return s / grades[subject].size();
    }

    void print() {
        cout << name << endl;
        for (auto x : grades) {
            cout << x.first << " ";
            for (auto y : x.second) {
                cout << y << " ";
            }
            cout << endl;
        }
    }

    ~Student() {}
};

class GradeBook {
private:
    vector<Student> students;
public:
    GradeBook(): students({}) {}
    int get_student(string name) {
        for (int i = 0; i < students.size(); i++) {
            if (students[i].get_name() == name) {
                return i;
            }
        }
        return -1;
    }
    void add(string name, double grade, string subject) {
        int i = this->get_student(name);
        if (i == -1) {
            Student s = Student(name);
            students.push_back(s);
            s.add_grade(subject, grade);
            s.print();
        } else {
            students[i].add_grade(subject, grade);
        }
    }

    void get_highest(string subject) {
        double mx = -1e9;
        for (int i = 0; i < students.size(); i++) {
            mx = max(students[i].get_mean(subject), mx);
        }
        for (int i = 0; i < students.size(); i++) {
            if (students[i].get_mean(subject) == mx) {
                cout << students[i].get_name() << " ";
            }
            cout << endl;
        }
    }

    void get_names() {
        for (int i = 0; i < students.size(); i++) {
            cout << students[i].get_name() << " ";
        }
        cout << endl;
    }

    int subject_count() {
        set<string> s;
        for (int i = 0; i < students.size(); i++) {
            for (auto x :students[i].get_grades()) {
                s.insert(x.first);
            }
        }
        return s.size();
    }

    void print() {
        for (int i = 0; i < students.size(); i++) {
            students[i].print();
        }
    }

    ~GradeBook() {}
};

int main() {
    int n;
    cin >> n;
    GradeBook gb = GradeBook();
    for (int i = 0; i < n; i++) {
        string name, subject;
        cin >> name >> subject;
        double grade;
        cin >> grade;
        gb.add(name, grade, subject);
    }
    gb.print();
    cout << "X" << endl;
    gb.get_highest("math");
}