#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


class Student {

private:
    vector<int> marks;


public:

    // Метод для добавления отметки
    void addMark(int mark) {
        marks.push_back(mark);
    }

    void printMarks() {
        for (int i = 0; i < marks.size(); i++) {
            cout << marks[i] << ", ";
        }
        cout << endl;
    }

    // Метод для вычисления РАУ
    double calculateRAU() const {
        if (marks.empty()) {
            return 0.0;
        }

        double sum = 0.0;
        for (int mark : marks) {
            sum += mark;
        }

        return sum / marks.size();
    }

    // Метод для определения является ли студент отличником
    bool isExcellentStudent() const {

        if (calculateRAU() >= 4.8) {
            cout << "Студент отличник" << endl;
            return 1;
        }

        else {
            cout << "Студент не отличник" << endl;
            return 0;
        }
    }

};



class Teacher {
private:
    bool mood = rand() % 2;

public:

    void setMood(bool m) {
        mood = m;
        if (mood == 0) cout << "Плохое настроение" << endl;
        else cout << "Хорошее настроение" << endl;
    }

    virtual void setMarkStudent(Student &student) {

        bool isExcellent = student.isExcellentStudent();

        if (mood == 1) {
            if (isExcellent) {
                student.addMark(5);
            }

            else {
                student.addMark(4);
            }
        }

        else {
            if (isExcellent) {
                student.addMark((rand() % 2 == 0) ? 4 : 5);
            }

            else {
                student.addMark((rand() % 2 == 0) ? 2 : 3);
            }
        }
    }

    void setMarkStudent(Student& student, int mark) {
        student.addMark(mark);
    }

};



class KindTeacher: public Teacher {

public:

    void setMarkStudent(Student &student) override {
        student.addMark(5);
    }

};



class EvilTeacher: public Teacher {

public:

    void setMarkStudent(Student &student) override {
        student.addMark(2);
    }

};



class Lesson {

public:

    void addStudent(Student &student) {
        groupList.push_back(student);
    }

    void setAllMarks(Teacher &teacher) {
        for (int i = 0; i < groupList.size(); i++) {
            teacher.setMarkStudent(groupList[i]);
        }
    }

    void printNewMarks() {
        int n = 0;

        for (int i = 0; i < groupList.size(); i++) {
            n++;
            cout << n << " студент: ";
            groupList[i].printMarks();
        }
        cout << endl;
    }


private:
    vector<Student> groupList;

};




int main() {

    srand(time(NULL));

    Student s1, s2, s3, s4;

    s1.addMark(5);
    s2.addMark(2);
    s3.addMark(3);
    s4.addMark(4);

    cout << "студент 1: ";
    s1.printMarks();

    cout << "студент 2: ";
    s2.printMarks();

    cout << "Оценки доброго учителя:" << endl;
    KindTeacher t1;
    Lesson fizra;
    fizra.addStudent(s1);
    fizra.addStudent(s2);
    fizra.setAllMarks(t1);
    fizra.printNewMarks();


    cout << "Оценки злого учителя:" << endl;
    EvilTeacher t2;
    Lesson music;
    music.addStudent(s1);
    music.addStudent(s2);
    music.setAllMarks(t2);
    music.printNewMarks();

    return 0;
}
