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

    void setMarkStudent(Student &student) {

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

    cout << "студент 3: ";
    s3.printMarks();

    cout << "студент 4: ";
    s4.printMarks();

    Teacher t;
    t.setMood(0);

    Lesson math;
    math.addStudent(s1);
    math.addStudent(s2);
    math.addStudent(s3);
    math.addStudent(s4);

    math.setAllMarks(t);

    cout << "Новые оценки после урока математики:" << endl;
    math.printNewMarks();

    return 0;
}
