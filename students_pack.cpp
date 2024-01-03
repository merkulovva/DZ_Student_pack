#include <iostream>
#include <vector>

using namespace std;


class Student {

private:
    vector<int> marks;


public:

    // Метод для добавления отметки
    void addMark(int mark) {
        marks.push_back(mark);
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

public:
    // Метод для выставления отметки студенту
    void setMarkStudent(Student& student, int mark) {
        student.addMark(mark);
    }

};



int main() {
    Student student1;
    Teacher teacher;

    teacher.setMarkStudent(student1, 3);
    teacher.setMarkStudent(student1, 3);
    teacher.setMarkStudent(student1, 4);

    student1.isExcellentStudent();

    return 0;
}